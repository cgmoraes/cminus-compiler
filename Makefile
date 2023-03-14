#
# Makefile for TINY
# Gnu C Version
# K. Louden 2/3/98
#

CC = gcc

FLX = flex

BSN = bison

OBJS = main.o cminus.tab.o lex.yy.o util.o # symtab.o analyze.o code.o cgen.o 

cminus: $(OBJS)
	$(CC) $(OBJS) -o cminus

main.o: main.c globals.h util.h scan.h parse.h analyze.h cgen.h
	$(CC) -c main.c

cminus.tab.o: parse.h scan.h globals.h util.h
	$(BSN) -d cminus.y
	$(CC) -c cminus.tab.c

lex.yy.o: scan.h util.h globals.h
	$(FLX) cminus.l
	$(CC) -c lex.yy.c

util.o: util.c util.h globals.h
	$(CC) -c util.c

# symtab.o: symtab.c symtab.h
# 	$(CC) -c symtab.c

# analyze.o: analyze.c globals.h symtab.h analyze.h
# 	$(CC) -c analyze.c

# code.o: code.c code.h globals.h
# 	$(CC) -c code.c

# cgen.o: cgen.c globals.h symtab.h code.h cgen.h
# 	$(CC) -c cgen.c

clean:
	-rm cminus
	-rm tm
	-rm $(OBJS)

tm: tm.c
	$(CC) tm.c -o tm

