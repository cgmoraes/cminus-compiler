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
                if i == 0: continue
                if r is not None and re.search(r"{}(?![0-9])".format(re.escape(r)), nextLine) and i not in index: index.add(i)

    for i in range(len(reg)):
        if i > 0 and i not in index: reg[i] = None

    f.seek(pos)

def genAsm(file):
    global reg, params_reg, numregs

    scope = 'global'
    params = {}

    with open(f"{file}.asm", "w") as asm:

        with open(f"{file}.ic", "r") as f:

            asm.write("J main\n")
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
                        # params_reg.pop(0)

                    case "FUN":
                        scope = quad[2]
                        params[scope] = []

                        pos = f.tell()
                        while (nextLine := f.readline().strip().split(' '))[0] == "ARG":
                            params[scope].insert(0, nextLine[2])
                        f.seek(pos)

                        asm.write(f".{quad[2]}\n")

                        if quad[2] != "main":
                            asm.write("SW $r31 $r29 1\n")
                            asm.write("ADDI $r30 $r30 1\n")

                    case "RET":
                        asm.write("ADDI $r28 $r28 0\n")

                    case "ALLOC":
                        asm.write("ADDI $r30 $r30 1\n")

                    case "ARG":
                        asm.write("ADDI $r30 $r30 1\n")

                    case "PARAM":
                        params_reg.insert(0, f"{reg.index(quad[1])}")

                    case "CALL":

                        ## Empilha
                        saveds_reg, saveds_reg[0] = [None]*numregs, 0
                        for i, r in enumerate(reg.copy()):
                            if i > 0 and r is not None:
                                asm.write(f"SW $t{i} $r30 0\n")
                                asm.write("ADDI $r30 $r30 1\n")
                                saveds_reg[i] = r
                            
                        reg, reg[0] = [None]*numregs, 0

                        ## Call
                        asm.write("SW $r29 $r30 0\n")
                        asm.write("ADDI $r29 $r30 0\n")
                        asm.write("ADDI $r30 $r30 1\n")

                        for i, r in enumerate(params_reg):
                            asm.write(f"SW $t{r} $r29 {df.loc[((df['Scope'] == quad[2]) & (df['Variable Name'] == params[quad[2]][i])), 'Scope Memloc'].values[0]}\n")
                        
                        params_reg = []
                        asm.write(f"JAL {quad[2]}\n")

                        # asm.write(f"ADDI $t{saveds_reg.index(quad[1])} $r31 0\n")
                        asm.write("ADDI $r30 $r29 0\n")
                        asm.write("LW $r29 $r29 0\n")

                        ## Desempilha
                        reg = saveds_reg
                        for i, r in enumerate(reversed(reg.copy())):
                            index = len(reg) - 1 - i
                            if index > 0 and r is not None:
                                asm.write("SUBI $r30 $r30 1\n")
                                asm.write(f"LW $t{index} $r30 0\n")


                    case "LOAD":
                        scopevar = scope
                        var = quad[2]
                        if not df.loc[df['Scope'] == scopevar, 'Variable Name'].isin([var]).any(): scopevar = 'global' 

                        if "(" in var: 
                            asm.write(f"Unknown {var}\n")
                        #     addr = quad[2].split('(')
                        #     var = addr[0]
                        #     offset = addr[1].strip(")")
                        # else: 
                        #     offset = 0
                        #     var = quad[2]

                        else: asm.write(f"LW $t{reg.index(quad[1])} $r29 {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")
                    
                    case "STORE":
                        scopevar = scope
                        var = quad[2]
                        if not df.loc[df['Scope'] == scopevar, 'Variable Name'].isin([var]).any(): scopevar = 'global' 

                        if "(" in var: 
                            asm.write(f"Unknown {var}\n")
                        #     addr = quad[2].split('(')
                        #     var = addr[0]
                        #     offset = addr[1].strip(")")
                        # else: 
                        #     offset = 0
                        #     var = quad[2]

                        else: asm.write(f"SW $t{reg.index(quad[1])} $r29 {df.loc[((df['Scope'] == scopevar) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]}\n")

                    case "LAB":
                        asm.write(f".{quad[1]}\n")

                    case "MAIS":
                        asm.write(f"ADD $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")
                    
                    case "ADDI":
                        if quad[2] == "$r0": asm.write(f"ADDI $t{reg.index(quad[1])} {quad[2]} {quad[3]}\n")
                        else: asm.write(f"ADDI $t{reg.index(quad[1])} $t{reg.index(quad[2])} {quad[3]}\n")

                    case "MENOS":
                        asm.write(f"SUB $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")

                    case "VEZES":
                        asm.write(f"MULT $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")
                    
                    case "SOBRE":
                        asm.write(f"DIV $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")

                    case "MENORQ":
                        asm.write(f"LT $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")

                    case "MENORI":
                        asm.write(f"LE $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")

                    case "MAIORQ":
                        asm.write(f"GT $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")

                    case "MAIORI":
                        asm.write(f"GE $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")

                    case "IGUAL":
                        asm.write(f"AND $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")
                    
                    case "DIF":
                        asm.write(f"DF $t{reg.index(quad[1])} $t{reg.index(quad[2])} $t{reg.index(quad[3])}\n")
                    
                    case "IFF":
                        asm.write(f"BEQ $r0 $t{reg.index(quad[1])} {quad[2]}\n")

                    case "GOTO":
                        asm.write(f"J {quad[1]}\n")

                    case "END":
                        if quad[1] != "main":
                            # asm.write(f".END {quad[1]}\n")
                            asm.write("LW $r31 $r29 1\n")
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

def genLabels(file):
    global asm
    labels = {}

    with open(f"{file}.asm", "r") as f:
        for line in f:
            asm.append(line)

    while (i := getAddr()) != None:
        labels[asm[i][1:].strip()] = i
        asm.pop(i)

    with open(f"{file}.asm", "w") as f:
        for i, line in enumerate(asm.copy()):
            for addr in line.split(" "):
                for l in labels.keys(): 
                    if l == addr.strip(): 
                        asm[i] = line.replace(l, str(labels[l]))
                        break
            f.write(asm[i])

file = sys.argv[1]
df = pd.read_csv("compiler/symtab.csv")
df["Scope Memloc"] = df.apply(getMemLoc, axis=1)
df.sort_values(by='Memloc')

numregs = int(sys.argv[2])
reg, reg[0] = [None]*numregs, 0
params_reg = []
asm = []

genAsm(file)
genLabels(file)