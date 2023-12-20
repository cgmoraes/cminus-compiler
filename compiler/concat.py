import sys

file = sys.argv[1]
with open("program.bin", "a") as f:
    with open(f"{file}.bin", "r") as b:
        f.write(f"{b.read()}")