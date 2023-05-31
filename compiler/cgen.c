/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "cgen.h"

static int indexR = -1;
static int indexL = -1;
static void cGen( TreeNode * tree);

static int getTempReg()
{
  indexR = (indexR+1)%32;
  return indexR;
}

static void printOp(TreeNode * tree)
{ switch (tree->attr.op) {
    case MAIS : fprintf(code, "MAIS"); break;
    case MENOS : fprintf(code, "MENOS"); break;
    case VEZES : fprintf(code, "VEZES"); break;
    case SOBRE : fprintf(code, "SOBRE"); break;
    case MENORQ : fprintf(code, "MENORQ"); break;
    case MENORI : fprintf(code, "MENORI"); break;
    case MAIORQ : fprintf(code, "MAIORQ"); break;
    case MAIORI : fprintf(code, "MAIORI"); break;
    case IGUAL : fprintf(code, "IGUAL"); break;
    case DIF : fprintf(code, "DIF"); break;
    default: break;
  }

}

/* Procedure genExp generates code at an expression node */
static void genExp( TreeNode * tree)
{ int loc, r1, r2;
  TreeNode * p1, * p2;
  switch (tree->kind.exp) {

    case TypeK:
      if (tree->child[0]->kind.stmt == FunK){
        fprintf(code, "\nFUN %s %s\n", tree->child[0]->attr.type, tree->child[0]->attr.name);
        cGen(tree->child[0]);
      }
      else{
        cGen(tree->child[0]);
      }
      fprintf(code, "\n");
      break;

    case ConstK :
      fprintf(code, " %d", tree->attr.val);
      break; /* ConstK */
    
    case IdK :
      fprintf(code, "LOAD $t%d %s\n", getTempReg(), tree->attr.name);
      break; /* IdK */

    case ArrK :
      !(tree->child[0]->kind.exp == ConstK) ? cGen(tree->child[0]):NULL;
      r1 = indexR;
      if (tree->child[0]->kind.exp == ConstK) fprintf(code, "VEZES $t%d %d 4\n", getTempReg(), tree->child[0]->attr.val);
      else fprintf(code, "VEZES $t%d $t%d 4\n", getTempReg(), r1);
      r2 = indexR;
      fprintf(code, "LOAD $t%d %s($t%d)\n", getTempReg(), tree->attr.name, r2);
      break;

    case OpK :
      p1 = tree->child[0];
      p2 = tree->child[1];
      if(p1->kind.exp == OpK && p2->kind.exp == OpK){
        cGen(p1);
        r1 = indexR;
        cGen(p2);
        r2 = indexR;
        printOp(tree);
        fprintf(code, " $t%d", getTempReg());
        fprintf(code, " $t%d", r1);
        fprintf(code, " $t%d", r2);

      } else if(p1->kind.exp != OpK && p2->kind.exp == OpK){
        cGen(p2);
        r2 = indexR;
        !(p1->kind.exp == ConstK) ? cGen(p1):NULL;
        r1 = indexR;
        printOp(tree);
        fprintf(code, " $t%d", getTempReg());
        (p1->kind.exp == ConstK) ? cGen(p1):fprintf(code, " $t%d", r1);
        fprintf(code, " $t%d", r2);

      } else if(p1->kind.exp == OpK && p2->kind.exp != OpK){
        cGen(p1);
        r1 = indexR;
        !(p2->kind.exp == ConstK) ? cGen(p2):NULL;
        r2 = indexR;
        printOp(tree);
        fprintf(code, " $t%d", getTempReg());
        fprintf(code, " $t%d", r1);
        (p2->kind.exp == ConstK) ? cGen(p2):fprintf(code, " $t%d", r2);

      } else {
        !(p1->kind.exp == ConstK) ? cGen(p1):NULL;
        r1 = indexR;
        !(p2->kind.exp == ConstK) ? cGen(p2):NULL;
        r2 = indexR;
        printOp(tree);
        fprintf(code, " $t%d", getTempReg());
        (p1->kind.exp == ConstK) ? cGen(p1):fprintf(code, " $t%d", r1);
        (p2->kind.exp == ConstK) ? cGen(p2):fprintf(code, " $t%d", r2);
      }
      fprintf(code, "\n");
      break; /* OpK */

    default:
      break;
  }
} /* genExp */

/* Procedure genStmt generates code at a statement node */
static void genStmt( TreeNode * tree)
{ TreeNode * p1, * p2, * p3;
  int savedLoc1,savedLoc2,currentLoc;
  int loc, r1, r2, r3, l1, l2;
  switch (tree->kind.stmt) {

      case IfK :
        {
          p1 = tree->child[0] ;
          p2 = tree->child[1] ;
          p3 = tree->child[2] ;
          
          indexL++;
          l1 = indexL;
          cGen(p1);
          r1 = indexR;
          fprintf(code, "IFF $t%d L%d\n", r1, l1);
          indexL++;
          l2 = indexL;
          cGen(p2);
          fprintf(code, "GOTO L%d\n", l2);
          fprintf(code, "LAB L%d\n", l1);
          cGen(p3);
          fprintf(code, "LAB L%d\n", l2);
          break; /* if_k */
        }

      case WhileK:
        {
          p1 = tree->child[0] ;
          p2 = tree->child[1] ;

          indexL++;
          l1 = indexL;
          fprintf(code, "LAB L%d\n", l1);
          indexL++;
          l2 = indexL;
          cGen(p1);
          r1 = indexR;
          fprintf(code, "WHILE $t%d L%d\n", r1, l2);
          cGen(p2);
          fprintf(code, "GOTO L%d\n", l1);
          fprintf(code, "LAB L%d\n", l2);
          break;
        }

      case AssignK:
        {
          if (tree->child[1]->kind.exp == ConstK){
            fprintf(code, "ASSIGN $t%d", getTempReg());
            r2 = indexR;
            cGen(tree->child[1]);
            fprintf(code, "\n");
          } else {
            cGen(tree->child[1]);
            r1 = indexR;
            fprintf(code, "ASSIGN $t%d", getTempReg());
            r2 = indexR;
            fprintf(code, " $t%d\n", r1);
          }


          if (tree->child[0]->kind.exp == ArrK){
            p1 = tree->child[0];
            r1 = indexR;
            !(p1->child[0]->kind.exp == ConstK) ? cGen(p1->child[0]):NULL;
            r2 = indexR;
            if (p1->child[0]->kind.exp == ConstK) fprintf(code, "VEZES $t%d %d 4\n", getTempReg(), p1->child[0]->attr.val);
            else fprintf(code, "VEZES $t%d $t%d 4\n", getTempReg(), r2);
            r3 = indexR;
            fprintf(code, "STORE %s($t%d) $t%d\n", p1->attr.name, r3, r1);
          } else fprintf(code, "STORE %s $t%d\n", tree->attr.name, r2);
        }
        break; /* assign_k */

      case VarK:
        if (tree->attr.len > 0) fprintf(code, "AARR %s(%d) %s", tree->attr.name, tree->attr.len, tree->attr.scope);
        else fprintf(code, "ALLOC %s %s", tree->attr.name, tree->attr.scope);
        break;

      case FunK :
        p1 = tree->child[0];
        if (p1->child[0] != NULL){
          while(p1 != NULL){
            fprintf(code, "ARG %s %s\n", p1->attr.name, p1->child[0]->attr.name);
            p1 = p1->sibling;
          } 
        }
        cGen(tree->child[1]);
        fprintf(code, "END %s", tree->attr.name);
        break;
      
      case CallK:
        {
          int i = 0;
          p1 = tree->child[0];
          if (p1 != NULL){
            for(i=0;p1 != NULL;i++){
              if (p1->kind.exp == ConstK) fprintf(code, "MAIS $t%d %d 0\n", getTempReg(), p1->attr.val);
              else {
                switch (p1->nodekind) {
                  case StmtK:
                    genStmt(p1);
                    break;
                  case ExpK:
                    genExp(p1);
                    break;
                  default:
                    break;
                }
              }
              r1 = indexR;
              fprintf(code, "PARAM $t%d\n", r1);
              p1 = p1->sibling;
            } 
          }
          fprintf(code, "CALL $t%d %s %d\n", getTempReg(), tree->attr.name, i);
          break;
        }

      case ReturnK:
        if (tree->child[0] == NULL) fprintf(code, "RET");
        else if(tree->child[0]->kind.exp == ConstK) {
          fprintf(code, "RET");
          cGen(tree->child[0]);
        }
        else {
          cGen(tree->child[0]);
          r1 = indexR;
          fprintf(code, "RET $t%d", r1);
        }
        fprintf(code, "\n");
        break;

      case InK:
        fprintf(code, "INPUT $t%d\n", getTempReg());
        break;

      case OutK:
        {
          if ((tree->child[0]->kind.exp == ConstK)){
            fprintf(code, "OUTPUT");
            cGen(tree->child[0]);
            fprintf(code, "\n");
          } else {
            cGen(tree->child[0]);
            r1 = indexR;
            fprintf(code, "OUTPUT $t%d\n", r1);
          }
          break;
        }

      default:
        break;
    }
} /* genStmt */

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen( TreeNode * tree)
{ if (tree != NULL)
  { switch (tree->nodekind) {
      case StmtK:
        genStmt(tree);
        break;
      case ExpK:
        genExp(tree);
        break;
      default:
        break;
    }
    cGen(tree->sibling);
  }
}

/**********************************************/
/* the primary function of the code generator */
/**********************************************/
/* Procedure codeGen generates code to a code
 * file by traversal of the syntax tree. The
 * second parameter (codefile) is the file name
 * of the code file, and is used to print the
 * file name as a comment in the code file
 */
void codeGen(TreeNode * syntaxTree)
{
   cGen(syntaxTree);
   fprintf(code, "HALT");
}
