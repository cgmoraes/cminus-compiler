import pandas as pd 
import re
import sys

def updateMemLoc(row):
    if "global" in row["Scope"]:
        return row["Memloc"]
    elif "main" in row["Scope"]:
        return row["Memloc"] - df.loc[df["Variable Name"] == row["Scope"],"Memloc"].values[0] - 1
    else:
        return row["Memloc"] - df.loc[df["Variable Name"] == row["Scope"],"Memloc"].values[0] + 1
    
def deallocateReg(f):
    global reg, range_reg, params_reg

    index = set()

    for r in params_reg:
        index.add(int(r))

    pos = f.tell()
    while (nextLine := f.readline().strip()) != "":
        if "$t" in nextLine: 
            for i, r in enumerate(reg[range_reg[0]:range_reg[1]]):
                i += range_reg[0]
                if i == range_reg[0] or i == range_reg[1]-4: continue
                if r is not None and re.search(r"{}(?![0-9])".format(re.escape(r)), nextLine) and i not in index: index.add(i)

    for i in range(range_reg[0]+1,range_reg[1]-4):
        if i not in index: reg[i] = None

    f.seek(pos)

def checkOcc(scope, var):
    if df.loc[df['Scope'] == scope, 'Variable Name'].isin([var]).any(): return True
    return False

def getMemLoc(scope, var):
    return df.loc[((df['Scope'] == scope) & (df['Variable Name'] == var)), 'Scope Memloc'].values[0]

def getLen(scope, var):
    return df.loc[((df['Scope'] == scope) & (df['Variable Name'] == var)), 'Length'].values[0]

def genAsm(file):
    global reg, range_reg, params_reg, numregs

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
                        if not aux in reg[range_reg[0]:range_reg[1]]: reg[reg[range_reg[0]:range_reg[1]].index(None)+range_reg[0]]=aux
                

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
                            asm.write(f"SW $r{range_reg[1]-3} $r{range_reg[1]-1} 1\n")
                            asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-2} 1\n")
                        else:
                            asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-3} 0\n")

                    case "RET":
                        asm.write(f"ADDI $t{reg.index(quad[1])} $t{range_reg[1]-4} 0\n")
                        asm.write(f"J {scope}:END\n")
                        

                    case "ALLOC":
                        asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-2} 1\n")

                    case "AARR":
                        size = int(quad[1].split("(")[1][:-1])
                        asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-2} {size}\n")

                    case "ARG":
                        asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-2} 1\n")

                    case "PARAM":
                        params_reg.insert(0, f"{reg.index(quad[1])}")
                        
                        if len(quad) > 2:
                            if checkOcc(scope, quad[2]) and getLen(scope, quad[2]) > 0:
                                asm.write(f"ADDI $r{range_reg[1]-3} $t{reg.index(quad[1])} {getMemLoc(scope, quad[2])}\n")
                            elif checkOcc('global', quad[2]) and getLen('global', quad[2]) > 0:
                                asm.write(f"ADDI $t{range_reg[0]} $t{reg.index(quad[1])} {getMemLoc('global', quad[2])}\n")

                    case "CALL":
                        match quad[2]:
                            case "Call_Process":
                                for i in range(16):
                                    asm.write(f"LW $t{params_reg[0]} $t{i+16} {i}\n")
                                asm.write(f"CALLPROCESS $t{params_reg[1]} $t{params_reg[0]}\n")
                                for i in range(16):
                                    asm.write(f"SW $t{params_reg[0]} $t{i+16} {i}\n")
                                asm.write(f"GETADDR $t{range_reg[1]-4}\n")
                                params_reg.pop(0)
                                params_reg.pop(0)
                            case "Set_LCD":
                                asm.write(f"SETLCD $t{params_reg[0]}\n")
                                params_reg.pop(0)
                            case "Set_Quantum":
                                asm.write(f"SETQUANTUM $t{params_reg[0]}\n")
                                params_reg.pop(0)
                            case "Clear_Ram":
                                for i in range(16):
                                    asm.write(f"SW $t{params_reg[0]} $t{range_reg[0]} {i}\n")
                                params_reg.pop(0)
                            case "Print":
                                word = " ".join(quad[3:-2]).replace("'", "").upper()
                                word_id = []
                                
                                for w in word:
                                    if ord(w) == 32:
                                        word_id.append(0)
                                    elif ord(w) < 65:
                                        word_id.append(ord(w)-21)
                                    else:
                                        word_id.append(ord(w)-64)

                                y = int(quad[-2])
                                x = int(quad[-1])

                                for i, idx in enumerate(word_id):
                                    if i != 0 and x > 0: asm.write(f"ADDI $t{params_reg[0]} $t{params_reg[0]} {1}\n")
                                    asm.write(f"SETPOS $t{params_reg[1]} $t{params_reg[0]}\n")
                                    asm.write(f"ADDI $t{range_reg[0]} $t{params_reg[2]} {idx}\n")
                                    asm.write(f"PRINT $t{params_reg[2]}\n")

                                    x += 1
                                    if x == 80:
                                        if y == 59: break
                                        x = 0
                                        y += 1
                                        asm.write(f"ADDI $t{range_reg[0]} $t{params_reg[0]} 0\n")
                                        asm.write(f"ADDI $t{params_reg[1]} $t{params_reg[1]} 1\n")

                                params_reg.pop(0)
                                params_reg.pop(0)
                                params_reg.pop(0)
                            case _:
                                ## Empilha
                                for i, r in enumerate(reg[range_reg[0]:range_reg[1]].copy()):
                                    i += range_reg[0]
                                    if i > range_reg[0] and i < range_reg[1]-4 and r is not None:
                                        asm.write(f"SW $r{range_reg[1]-2} $t{i} 0\n")
                                        asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-2} 1\n")

                                ## Call
                                asm.write(f"SW $r{range_reg[1]-2} $r{range_reg[1]-3} 0\n")
                                asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-3} 0\n")
                                asm.write(f"ADDI $r{range_reg[1]-2} $r{range_reg[1]-2} 1\n")

                                for i, r in enumerate(params_reg):
                                    asm.write(f"SW $r{range_reg[1]-3} $t{r} {getMemLoc(quad[2], params[quad[2]][i])}\n")
                                
                                params_reg = []
                                asm.write(f"JAL {quad[2]}\n")
                                asm.write(f"ADDI $r{range_reg[1]-3} $r{range_reg[1]-2} 0\n")
                                asm.write(f"LW $r{range_reg[1]-3} $r{range_reg[1]-3} 0\n")

                                ## Desempilha
                                for i, r in enumerate(reversed(reg[range_reg[0]:range_reg[1]].copy())):
                                    index = range_reg[0] + len(reg[range_reg[0]:range_reg[1]]) - 1 - i
                                    if index > range_reg[0] and index < range_reg[1]-4 and r is not None:
                                        asm.write(f"SUBI $r{range_reg[1]-2} $r{range_reg[1]-2} 1\n")
                                        asm.write(f"LW $r{range_reg[1]-2} $t{index} 0\n")

                    case "LOAD":
                        scopevar = scope
                        var = quad[2].strip().split("(")[0]
                        if not checkOcc(scopevar, var): scopevar = 'global' 
                        
                        if "(" in quad[2]: 
                            regoff = quad[2].split("(")[1][:-1]

                            if "global" in scopevar:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {getMemLoc(scopevar, var)}\n")
                                asm.write(f"LW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")

                            elif var in params[scopevar] and getLen(scopevar, var) == -1:
                                asm.write(f"LW $r{range_reg[1]-3} $t{reg.index(quad[1])} {getMemLoc(scopevar, var)}\n")
                                asm.write(f"ADD $t{reg.index(quad[1])} $t{reg.index(regoff)} $t{reg.index(quad[1])}\n")
                                asm.write(f"LW $t{reg.index(quad[1])} $t{reg.index(quad[1])} 0\n")
                            
                            else:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {getMemLoc(scopevar, var)}\n")
                                asm.write(f"ADD $r{range_reg[1]-3} $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"LW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")
                        
                        else:
                            if "global" in scopevar: 
                                asm.write(f"LW $t{range_reg[0]} $t{reg.index(quad[1])} {getMemLoc(scopevar, var)}\n")
                            else: 
                                asm.write(f"LW $r{range_reg[1]-3} $t{reg.index(quad[1])} {getMemLoc(scopevar, var)}\n")


                    case "STORE":
                        scopevar = scope
                        var = quad[2].strip().split("(")[0]
                        
                        if not checkOcc(scopevar, var): scopevar = 'global' 
                        
                        if "(" in quad[2]: 
                            regoff = quad[2].split("(")[1][:-1]

                            if "global" in scopevar:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {getMemLoc(scopevar, var)}\n")
                                asm.write(f"SW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")

                            elif var in params[scopevar] and getLen(scopevar, var) == -1:
                                asm.write(f"LW $r{range_reg[1]-3} $t{reg[range_reg[0]:range_reg[1]].index(None)+range_reg[0]} {getMemLoc(scopevar, var)}\n")
                                asm.write(f"ADD $t{reg[range_reg[0]:range_reg[1]].index(None)+range_reg[0]} $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"SW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")

                            else:
                                asm.write(f"ADDI $t{reg.index(regoff)} $t{reg.index(regoff)} {getMemLoc(scopevar, var)}\n")
                                asm.write(f"ADD $r{range_reg[1]-3} $t{reg.index(regoff)} $t{reg.index(regoff)}\n")
                                asm.write(f"SW $t{reg.index(regoff)} $t{reg.index(quad[1])} 0\n")
                        
                        else:
                            if "global" in scopevar: 
                                asm.write(f"SW $t{range_reg[0]} $t{reg.index(quad[1])} {getMemLoc(scopevar, var)}\n")
                            else: 
                                asm.write(f"SW $r{range_reg[1]-3} $t{reg.index(quad[1])} {getMemLoc(scopevar, var)}\n")

                    case "LAB":
                        asm.write(f".{quad[1]}\n")

                    case "MAIS":
                        if f"$r{range_reg[1]-3}" in quad[2]: asm.write(f"ADD $r{range_reg[1]-3} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")
                        else: asm.write(f"ADD $t{reg.index(quad[2])} $t{reg.index(quad[3])} $t{reg.index(quad[1])}\n")
                    
                    case "ADDI":
                        scopevar = scope
                        var = quad[3].strip()
                        if df['Variable Name'].isin([var]).any():
                            if not checkOcc(scopevar,var): scopevar = 'global'
                            asm.write(f"ADDI $t{reg.index(quad[2])} $t{reg.index(quad[1])} {getMemLoc(scopevar,var)}\n")
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
                        asm.write(f"BEQ $t{range_reg[0]} $t{reg.index(quad[1])} {quad[2]}\n")

                    case "GOTO":
                        asm.write(f"J {quad[1]}\n")

                    case "END":
                        if quad[1] != "main":
                            asm.write(f".{quad[1]}:END\n")
                            asm.write(f"LW $r{range_reg[1]-3} $r{range_reg[1]-1} 1\n")
                            asm.write(f"JR $r{range_reg[1]-1}\n")

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

process_type = sys.argv[1]
file = sys.argv[2]
df = pd.read_csv("compiler/symtab.csv")
df["Scope Memloc"] = df.apply(updateMemLoc, axis=1)
df.sort_values(by='Memloc')

reg = [None]*32
range_reg = [0,16] if int(process_type) else [16,32]
reg[range_reg[0]] = f"$t0"
reg[range_reg[1]-1] = f"$r{range_reg[1]-1}"
reg[range_reg[1]-2] = f"$r{range_reg[1]-2}"
reg[range_reg[1]-3] = f"$r{range_reg[1]-3}"
reg[range_reg[1]-4] = f"$t28"
params_reg = []
asm = []

genAsm(file)
genLabels(file)