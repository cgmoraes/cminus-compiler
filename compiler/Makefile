#
# Makefile for TINY
# Gnu C Version
# K. Louden 2/3/98
#

CC = gcc

FLX = flex

BSN = bison

TMP = lex.yy.c cminus.tab.c cminus.tab.h

OBJS = main.o cminus.tab.o lex.yy.o util.o symtab.o analyze.o cgen.o

all: cminus clean

cminus: $(OBJS)
	@echo "running: cminus"
	$(CC) $(OBJS) -lfl -o cmc

main.o: cminus.tab.o lex.yy.o main.c globals.h util.h scan.h parse.h analyze.h cgen.h
	@echo "running: main"
	$(CC) -c main.c

cminus.tab.o: cminus.y parse.h scan.h globals.h util.h
	@echo "running: bison"
	$(BSN) -d cminus.y
	$(CC) -c cminus.tab.c

lex.yy.o: cminus.l scan.h util.h globals.h
	@echo "running: flex"
	$(FLX) cminus.l
	$(CC) -c lex.yy.c

util.o: util.c util.h globals.h
	@echo "running: util"
	$(CC) -c util.c

symtab.o: symtab.c symtab.h
	@echo "running: symtab"
	$(CC) -c symtab.c

analyze.o: analyze.c globals.h symtab.h analyze.h
	@echo "running: analyze"
	$(CC) -c analyze.c

 cgen.o: cgen.c globals.h symtab.h cgen.h
	$(CC) -c cgen.c

# tm: tm.c
# 	$(CC) tm.c -o tm

clean:
	-rm $(OBJS) $(TMP)


