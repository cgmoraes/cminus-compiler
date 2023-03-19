/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t)
{ switch (t->nodekind)
  { case StmtK:
      switch (t->kind.stmt)
      { case VarK:
        {
          BucketList l = st_lookup_decl(t->attr.scope, t->attr.name);
          if (l == NULL) {
            if (t->type == VoidK)typeError(t, "Error 3: Invalid declaration. Variable can't be void.");
            else if (!strcmp(t->attr.scope, t->attr.name)) typeError(t, "Error 7: Invalid declaration. Already declared as a function.");
            else st_insert(l, t->attr.scope, t->attr.name, t->lineno, location++);
          
          } else typeError(t, "Error 4: Invalid declaration. Already declared.");
        }
        break;
      case FunK:
        {
          BucketList l = st_lookup_decl(t->attr.scope, t->attr.name);
          if (l == NULL) st_insert(l, t->attr.scope, t->attr.name, t->lineno, location++);
          else typeError(t, "Error 4: Invalid declaration. Already declared.");
        }
        break;
      case CallK:
        {
          BucketList l = st_lookup(t->attr.scope, t->attr.name);
          if (l == NULL){
            if (strcmp(t->attr.name, "input") != 0 & strcmp(t->attr.name, "output") != 0)
              typeError(t, "Error 5: Invalid call. Not declared.");
          } else st_insert(l, t->attr.scope, t->attr.name, t->lineno, location++);
        }
        break;
      case ReturnK:
        break;
      default:
        break;
      }
    break;
    case ExpK:
      switch (t->kind.exp)
      {case IdK:
          {
            BucketList l = st_lookup(t->attr.scope, t->attr.name);
            if (l == NULL) typeError(t, "Error 1: Not declared");
            else st_insert(l, t->attr.scope, t->attr.name, t->lineno, 0);
          } 
          break;
        case ArrK:
          {
            BucketList l = st_lookup(t->attr.scope, t->attr.name);
            if (l == NULL) typeError(t, "Error 1: Not declared");
            else st_insert(l, t->attr.scope, t->attr.name, t->lineno, 0);
          }
          break;
        // case ParK:
        //   {
        //     BucketList l = st_lookup_decl(t->attr.scope, t->attr.name);
        //     if (l == NULL) {
        //       if (t->type == VoidK)typeError(t, "Error 3: Invalid declaration. Variable can't be void.");
        //       else if (!strcmp(t->attr.scope, t->attr.name)) typeError(t, "Error 7: Invalid declaration. Already declared as a function.");
        //       else st_insert(l, t->attr.scope, t->attr.name, t->lineno, location++);
            
        //     } else typeError(t, "Error 4: Invalid declaration. Already declared.");
        //   }
        //   break;
        case TypeK:
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ switch (t->nodekind)
  { case ExpK:
      switch (t->kind.exp)
      { case OpK:
          if ((t->child[0]->type != IntegerK) ||
              (t->child[1]->type != IntegerK))
            typeError(t,"Op applied to non-integer");
          if ((t->attr.op == IGUAL) || (t->attr.op == MENORQ))
            t->type = BooleanK;
          else
            t->type = IntegerK;
          break;
        case ConstK:
        case IdK:
          t->type = IntegerK;
          break;
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { case IfK:
          if (t->child[0]->type == IntegerK)
            typeError(t->child[0],"if test is not Boolean");
          break;
        case AssignK:
          if (t->child[0]->type != IntegerK)
            typeError(t->child[0],"assignment of non-integer value");
          break;
        default:
          break;
      }
      break;
    default:
      break;

  }
}

static void traverseInsertNode(TreeNode *t)
{
  if (t != NULL)
  {
    insertNode(t);
    {
      int i;
      for (i = 0; i < MAXCHILDREN; i++)
        traverseInsertNode(t->child[i]);
    }
    traverseInsertNode(t->sibling);
  }
}


static void traverseCheckNode(TreeNode *t)
{
  if (t != NULL)
  {
    {
      int i;
      for (i = 0; i < MAXCHILDREN; i++)
        traverseCheckNode(t->child[i]);
    }
    checkNode(t);
    traverseCheckNode(t->sibling);
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{
  traverseInsertNode(syntaxTree);
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverseCheckNode(syntaxTree);
}
