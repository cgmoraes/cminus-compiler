import sys

process_type = int(sys.argv[1])
file = sys.argv[2]
lines = int(sys.argv[3])
range_reg = [0,16] if process_type else [16,32]
regs = {f"$t{i}": format(i, "05b") for i in range(32)}
regs.update({f"$r{i}": format(i, "05b") for i in range(range_reg[1]-3, range_reg[1])})

op = {
        "R": {
                "AND": "100100",
                "OR": "100101",
                "ADD": "100000",
                "SUB": "100010",
                "SLT": "101010",
                "SGT": "111010",
                "MULT": "011000",
                "DIV": "011010",
                "SLL": "000000",
                "SRL": "000001",
                "SLET": "101011",
                "SGET": "111011",
                "SET": "000010",
                "SDT": "000011"
            },
        "I": {
                "ADDI": "001000",
                "SUBI": "001010",
                "NOT": "001100",
                "LW": "100011",
                "SW": "101011",
                "BEQ": "000100",
                "BNE": "000101",
                "BLT": "000110",
                "BGT": "000111"
            },
        "J": {
                "J": "000010",
                "JAL": "000011",
                "JR": "000001"
            },
        "HALT": ["111101","111111"],
        "IN": "100001",
        "OUT": "110001",
        "CALLPROCESS": "101001",
        "SETQUANTUM": "101111",
        "GETADDR": "100111"
    }

with open(f"{file}.bin", "w") as b:
    with open(f"{file}.asm", "r") as asm:
        for num_line, line in enumerate(asm):
            line = line.strip()
            quad = line.split(' ')
            if quad[0] in op["R"].keys():
                b.write(f"000000{regs[quad[1]]}{regs[quad[2]]}{regs[quad[3]]}00000{op['R'][quad[0]]}\n")
            elif quad[0] in op["I"].keys():
                b.write(f"{op['I'][quad[0]]}{regs[quad[1]]}{regs[quad[2]]}{format(int(quad[3]),'016b')}\n")
            elif quad[0] in op["J"].keys():
                if "JR" in quad[0]:
                    b.write(f"{op['J'][quad[0]]}{regs[quad[1]]}{format(0,'021b')}\n")
                else:
                    b.write(f"{op['J'][quad[0]]}{format(int(quad[1]),'026b')}\n")
            else:
                match quad[0]:
                    case "IN": b.write(f"{op[quad[0]]}{format(0,'026b')}\n")
                    case "OUT": b.write(f"{op[quad[0]]}{regs[quad[1]]}{format(0,'021b')}\n")
                    case "HALT": b.write(f"{op[quad[0]][process_type]}{format(0,'026b')}\n")
                    case "CALLPROCESS": b.write(f"{op[quad[0]]}{regs[quad[1]]}{regs[quad[2]]}{format(0,'016b')}\n")
                    case "SETQUANTUM": b.write(f"{op[quad[0]]}{regs[quad[1]]}{format(0,'021b')}\n")
                    case "GETADDR": b.write(f"{op[quad[0]]}{format(0,'026b')}\n")
                    case _: b.write(f"{quad[0]}\n")

    for i in range(num_line+1, lines):
        b.write(f"{format(0,'032b')}\n")