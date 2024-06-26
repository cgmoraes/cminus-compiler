/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString )
{ switch (token)
  { case ELSE: fprintf(listing,"%s\n",tokenString); break;
    case IF: fprintf(listing,"%s\n",tokenString); break;
    case INT: fprintf(listing,"%s\n",tokenString); break;
    case RETURN: fprintf(listing,"%s\n",tokenString); break;
    case VOID: fprintf(listing,"%s\n",tokenString); break;
    case WHILE: fprintf(listing,"%s\n",tokenString); break;
    case IN: fprintf(listing,"%s\n",tokenString); break;
    case OUT: fprintf(listing,"%s\n",tokenString); break;
    case MAIS: fprintf(listing,"+\n"); break;
    case MENOS: fprintf(listing,"-\n"); break;
    case VEZES: fprintf(listing,"x\n"); break;
    case SOBRE: fprintf(listing,"/\n"); break;
    case MENORQ: fprintf(listing,"<\n"); break;
    case MENORI: fprintf(listing,"<=\n"); break;
    case MAIORQ: fprintf(listing,">\n"); break;
    case MAIORI: fprintf(listing,">=\n"); break;
    case IGUAL: fprintf(listing,"==\n"); break;
    case DIF: fprintf(listing,"!=\n"); break;
    case RECEBE: fprintf(listing,"=\n"); break;
    case PONVIR: fprintf(listing,";\n"); break;
    case VIRG: fprintf(listing,",\n"); break;
    case EPAREN: fprintf(listing,"(\n"); break;
    case DPAREN: fprintf(listing,")\n"); break;
    case ECOLCH: fprintf(listing,"[\n"); break;
    case DCOLCH: fprintf(listing,"]\n"); break;
    case ECHAVE: fprintf(listing,"{\n"); break;
    case DCHAVE: fprintf(listing,"}\n"); break;
    case ENDFILE: fprintf(listing,"FIMARQV\n"); break;
    case NUM: fprintf(listing,"NUM, val= %s\n",tokenString); break;
    case ID: fprintf(listing,"ID, name= %s\n",tokenString); break;
    case STR: fprintf(listing,"STR, string= %s\n",tokenString); break;
    case ERROR: fprintf(listing,"%s\n",tokenString); break;
    case ACOM: fprintf(listing,"*/\n"); break;
    default: fprintf(listing,"Unknown token: %d\n",token);    
  }
}

/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
    t->attr.scope = "global";
  }
  return t;
}

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = VoidK;
    t->attr.scope = "global";
  }
  return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree )
{ int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->nodekind==StmtK)
    { switch (tree->kind.stmt) {
        case IfK:
          fprintf(listing,"If\n");
          break;
        case WhileK:
          fprintf(listing,"While\n");
          break;
        case AssignK:
          fprintf(listing,"Assign to: %s\n",tree->attr.name);
          break;
        case VarK:
          fprintf(listing,"Var: %s\n",tree->attr.name);
          break;
        case FunK:
          fprintf(listing,"Fun: %s\n",tree->attr.name);
          break;
        case CallK:
          fprintf(listing,"Call: %s\n",tree->attr.name);
          break;
        case ReturnK:
          fprintf(listing,"Return\n");
          break;
        case InK:
          fprintf(listing,"Input\n");
          break;
        case OutK:
          fprintf(listing,"Output\n");
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else if (tree->nodekind==ExpK)
    { switch (tree->kind.exp) {
        case OpK:
          fprintf(listing,"Op: ");
          printToken(tree->attr.op,"\0");
          break;
        case ConstK:
          fprintf(listing,"Const: %d\n",tree->attr.val);
          break;
        case IdK:
          fprintf(listing,"Id: %s\n",tree->attr.name);
          break;
        case ArrK:
          fprintf(listing,"Vet: %s\n",tree->attr.name);
          break;
        case TypeK:
          fprintf(listing,"Type: %s\n",tree->attr.name);
          break;
        case StrK:
          fprintf(listing,"String: %s\n",tree->attr.name);
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    }
    else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}

void addScope(TreeNode *t, char *scope)
{
  int i;
  while (t != NULL){
    for (i = 0; i < MAXCHILDREN; ++i){
      t->attr.scope = scope;
      addScope(t->child[i], scope);
    }
    t = t->sibling;
  }
}