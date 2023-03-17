/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the scope hash function */
static int scopeHash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = (((temp << SHIFT) + key[i]) % (SIZE-1))+1;
    ++i;
  }
  return temp;
}

/* the hash table */
static BucketList hashTable[SIZE][SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( BucketList l, char * scope, char * name, int lineno, int loc )
{ int row = (!strcmp(scope, "global")) ? 0: scopeHash(scope);
  int col = hash(name);
  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->scope = scope;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = hashTable[row][col];
    hashTable[row][col] = l; }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

BucketList st_lookup_decl(  char *scope, char*name)
{
  int row = (!strcmp(scope, "global")) ? 0: scopeHash(scope);
  int col = hash(name);
  BucketList l =  hashTable[row][col];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  return l;
}

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
BucketList st_lookup ( char * scope, char * name )
{ int row = (!strcmp(scope, "global")) ? 0: scopeHash(scope);
  int col = hash(name);
  int i;
  for(i = 0; i<2; i++){
    BucketList l =  hashTable[row][col];
    while ((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    row = 0;
    if (l != NULL) return l;
  }
  return NULL;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)
{ int i, j;
  fprintf(listing,"Variable Name  Scope       Location   Line Numbers\n");
  fprintf(listing,"-------------  ----------  --------   ------------\n");
  for (i=0;i<SIZE;++i){
    for (j=0;j<SIZE;++j)
    { if (hashTable[i][j] != NULL)
      { BucketList l = hashTable[i][j];
        while (l != NULL)
        { LineList t = l->lines;
          fprintf(listing,"%-14s ",l->name);
          fprintf(listing,"%-10s  ",l->scope);
          fprintf(listing,"%-8d  ",l->memloc);
          while (t != NULL)
          { fprintf(listing,"%4d ",t->lineno);
            t = t->next;
          }
          fprintf(listing,"\n");
          l = l->next;
        }
      }
    }
  }
} /* printSymTab */