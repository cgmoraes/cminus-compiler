import pandas as pd 
import re
import sys

def getMemLoc(row):
    if "global" in row["Scope"]:
        return row["Memloc"]
    elif "main" in row["Scope"]:
        return row["Memloc"] - df.loc[df["Variable Name"] == row["Scope"],"Memloc"].values[0] - 1
    else:
        return row["Memloc"] - df.loc[df["Variable Name"] == row["Scope"],"Memloc"].values[0] + 1
    
def deallocateReg(f):
    global reg, params_reg

    index = set()

    for r in params_reg:
        index.add(int(r))

    pos = f.tell()
    while (nextLine := f.readline().strip()) != "":
        if "$t" in nextLine: 
            for i, r in enumerate(reg):
                if i == 0 or i == 28: continue
                if r is not None and re.search(r"{}(?![0-9])".format(re.escape(r)), nextLine) and i not in index: index.add(i)

    for i in range(len(reg)):
        if i > 0 and i < 28 and i not in index: reg[i] = None

    f.seek(pos)

def genAsm(file):
    global reg, params_reg, numregs

    scope = 'global'
    params = {}
    jump = False

    with open(f"{file}.asm", "w") as asm:

        with open(f"{file}.ic", "r") as f:

            while (line := f.readline().strip()) != '':
                quad = line.split(" ")

                for i in quad:
                    if "$t" in i: 
                        aux = i.split("(")[1][:-1] if "(" in i else i
                        if not aux in reg: reg[reg.index(None)]=aux

                match quad[0]:
                    case "INPUT":
                        asm.write(f"IN $t{reg.index(quad[1])}\n")

                    case "OUTPUT":
                        asm.write(f"OUT $t{reg.index(quad[1])}\n")

                    case "FUN":
                        if not jump: 
                            asm.write("J main\n")
                            jump = True

                        scope = quad[2]
                        params[scope] = []
                        

                        pos = f.tell()
                        while (nextLine := f.readline().strip().split(' '))[0] == "ARG":
                            params[scope].insert(0, nextLine[2])
                        f.seek(pos)

                        asm.write(f".{quad[2]}\n")

                        if quad[2] != "main":
                            asm.write("SW $r29 $r31 1\n")
                            asm.write("ADDI $r30 $r30 1\n")
                        else:
                            asm.write("ADDI $r30 $r29 0\n")

                    case "RET":
                        asm.write(f"ADDI $t{reg.index(quad[1])} $t28 0\n")
                        asm.write(f"J {scope}:END\n")
                        

                    case "ALLOC":
                        asm.write("ADDI $r30 $r30 1\n")

                    case "AARR":
                        size = int(quad[1].split("(")[1][:-1])
                        asm.write(f"ADDI $r30 $r30 {size}\n")

                    case "ARG":
                        asm.write("ADDI $r30 $r30 1\n")

                    case "PARAM":
                        params_reg.insert(0, f"{reg.index(quad[1])}")
                        if len(quad) > 2:
                            # print(scope, quad, df.loc[((df['Scope'] == 'global') & (df['Variable Name'] == quad[2])), 'Length'].values[0])
                            if df.loc[df['Scope'] == scope, 'Variable Name'].isin([quad[2]]).any() and df.loc[((df['Scope'] == scope) & (df['Variable Name'] == quad[2])), 'Length'].values[0] > 0:
                                asm.write(f"ADDI $r29 $t{reg.index(quad[1])} {df.loc[((df['Scope'] == scope) & (df['Variable Name'] == quad[2])), 'Scope Memloc'].values[0]}\n")
                            elif df.loc[df['Scope'] == 'global', 'Variable Name'].isin([quad[2]]).any() and df.loc[((df['Scope'] == 'global') & (df['Variable Name'] == quad[2])), 'Length'].values[0] > 0:
                                asm.write(f"ADDI $t0 $t{reg.index(quad[1])} {df.loc[((df['Scope'] == 'global') & (df['Variable Name'] == quad[2])), 'Scope Memloc'].values[0]}\n")

                    case "CALL":

                        ## Empilha
                        # saveds_reg = [None]*numregs
                        # saveds_reg[0] = 0
                        for i, r in enumerate(reg.copy()):
                            if i > 0 and i < 28 and r is not None:
                                asm.write(f"SW $r30 $t{i} 0\n")
                                asm.write("ADDI $r30 $r30 1\n")
                                # saveds_reg[i] = r
                            
                        # reg = [None]*numregs
                        # reg[0] = 0

                        ## Call
                        asm.write("SW $r30 $r29 0\n")
                        asm.write("ADDI $r30 $r29 0\n")
                        asm.write("ADDI $r30 $r30 1\n")

                        for i, r in enumerate(params_reg):
                            asm.write(f"SW $r29 $t{r} {df.loc[((df['Scope'] == quad[2]) & (df['Variable Name'] == params[quad[2]][i])), 'Scope Memloc'].values[0]}\n")
                        
                        params_reg = []
                        asm.write(f"JAL {quad[2]}\n")

                        # asm.write(f"ADDI $t{saveds_reg.index(quad[1])} $r31 0\n")
                        asm.write("ADDI $r29 $r30 0\n")
                        asm.write("LW $r29 $r29 0\n")

                        ## Desempilha
                        # reg = saveds_reg
                        for i, r in enumerate(reversed(reg.copy())):
                            index = len(reg) - 1 - i
                            if index > 0 and index < 28 and r is not None:
                                asm.write("SUBI $r30 $r30 1\n")
                                asm.write(f"LW $r30 $t{index} 0\n")


                    case "LOAD":
                        scopevar = scope
                        var = quad[2].strip().split("(")[0]
                        if not df.loc[df['Scope'] == scopevar, 'Variable Name'].isin([var]).any(): scopevar = 'global' 
                        
                        if "(" in quad[2]: 
                            regoff = quad[2].split("(")[1][:-1]

                            if "global" in scopevar:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                                # asm.write(f"ADD $t0 $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"LW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")

                            elif var in params[scopevar] and df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Length'].values[0] == -1:
                                asm.write(f"LW $r29 $t{reg.index(quad[1])} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                                asm.write(f"ADD $t{reg.index(quad[1])} $t{reg.index(regoff)} $t{reg.index(quad[1])}\n")
                                asm.write(f"LW $t{reg.index(quad[1])} $t{reg.index(quad[1])} 0\n")
                            
                            else:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                                asm.write(f"ADD $r29 $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"LW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")
                        
                        else:
                            if "global" in scopevar: 
                                asm.write(f"LW $t0 $t{reg.index(quad[1])} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                            else: 
                                asm.write(f"LW $r29 $t{reg.index(quad[1])} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")


                    case "STORE":
                        scopevar = scope
                        var = quad[2].strip().split("(")[0]
                        
                        if not df.loc[df['Scope'] == scopevar, 'Variable Name'].isin([var]).any(): scopevar = 'global' 
                        
                        if "(" in quad[2]: 
                            regoff = quad[2].split("(")[1][:-1]

                            if "global" in scopevar:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                                # asm.write(f"ADD $t0 $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"SW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")

                            elif var in params[scopevar] and df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Length'].values[0] == -1:
                                asm.write(f"LW $r29 $t{reg.index(None)} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                                asm.write(f"ADD $t{reg.index(None)} $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"SW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")

                            else:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                                asm.write(f"ADD $r29 $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"SW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")
                        
                        else:
                            if "global" in scopevar: 
                                asm.write(f"SW $t0 $t{reg.index(quad[1])} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                            else: 
                                asm.write(f"SW $r29 $t{reg.index(quad[1])} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")

                    case "LAB":
                        asm.write(f".{quad[1]}\n")

                    case "MAIS":
                        if "$r29" in quad[2]: asm.write(f"ADD $r29 $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")
                        else: asm.write(f"ADD $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")
                    
                    case "ADDI":
                        scopevar = scope
                        var = quad[3].strip()
                        if df['Variable Name'].isin([var]).any():
                            if not df.loc[df['Scope'] == scopevar, 'Variable Name'].isin([var]).any(): scopevar = 'global'
                            asm.write(f"ADDI $t{reg.index(quad[2])} $t{reg.index(quad[1])} {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                        else: asm.write(f"ADDI $t{reg.index(quad[2])} $t{reg.index(quad[1])} {quad[3]}\n")

                    case "MENOS":
                        asm.write(f"SUB $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")

                    case "VEZES":
                        asm.write(f"MULT $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")
                    
                    case "SOBRE":
                        asm.write(f"DIV $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")

                    case "MENORQ":
                        asm.write(f"SLT $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")

                    case "MENORI":
                        asm.write(f"SLET $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")

                    case "MAIORQ":
                        asm.write(f"SGT $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")

                    case "MAIORI":
                        asm.write(f"SGET $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")

                    case "IGUAL":
                        asm.write(f"SET $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")
                    
                    case "DIF":
                        asm.write(f"SDT $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")
                    
                    case "IFF":
                        asm.write(f"BEQ $t0 $t{reg.index(quad[1])} {quad[2]}\n")

                    case "GOTO":
                        asm.write(f"J {quad[1]}\n")

                    case "END":
                        if quad[1] != "main":
                            asm.write(f".{quad[1]}:END\n")
                            asm.write("LW $r29 $r31 1\n")
                            asm.write("JR $r31\n")

                    case "HALT":
                        asm.write("HALT\n")

                    case _: asm.write(f"Unknown - {quad[0]}\n")
                
                deallocateReg(f)

def getAddr():
    global asm

    for i, l in enumerate(asm):
        if l[0] == ".":
            return i
    
    return None

def searchLabel(labels, line, asm, addr, lineno, beq=False):
    for l in labels.keys(): 
        if l == addr.strip(): 
            labelno = str(labels[l]-lineno-1) if beq else str(labels[l])
            asm[lineno] = line.replace(l, labelno) 
            break

def genLabels(file):
    global asm
    labels = {}

    with open(f"{file}.asm", "r") as f:
        for line in f:
            asm.append(line)

    while (i := getAddr()) != None:
        labels[asm[i][1:].strip()] = i
        asm.pop(i)

    beq = False
    with open(f"{file}.asm", "w") as f:
        for i, line in enumerate(asm.copy()):
            for addr in line.split(" "):
                if addr == "BEQ": beq = True
                searchLabel(labels, line, asm, addr, i, beq)
            beq = False
            f.write(asm[i])

file = sys.argv[1]
df = pd.read_csv("compiler/symtab.csv")
df["Scope Memloc"] = df.apply(getMemLoc, axis=1)
df.sort_values(by='Memloc')
df.to_csv("compiler/symtab.csv")

reg = [None]*29
reg[0] = "$t0"
reg[28] = "$t28"
params_reg = []
asm = []

genAsm(file)
genLabels(file)