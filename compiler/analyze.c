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

/* Procedure traverse is a generic recursive
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc
 * in postorder to tree pointed to by t
 */
static void traverse(TreeNode *t,
                     void (*preProc)(TreeNode *),
                     void (*postProc)(TreeNode *))
{
  if (t != NULL)
  {
      preProc(t);
      {
        int i;
        for (i = 0; i < MAXCHILDREN; i++)
          traverse(t->child[i], preProc, postProc);
      }
      postProc(t);
      traverse(t->sibling, preProc, postProc);
    }
}

/* nullProc is a do-nothing procedure to
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode *t)
{
    if (t == NULL)
        return;
    else
        return;
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
            
            if (st_lookup_fun(t->attr.name)) typeError(t, "Error 7: Invalid declaration. Already declared as a function.");
            else st_insert(l, t->attr.scope, t->attr.name, t->attr.type, t->lineno, location++);
          
          } else typeError(t, "Error 4: Invalid declaration. Already declared.");
        }
        break;
      case FunK:
        {
          BucketList l = st_lookup_decl(t->attr.scope, t->attr.name);
          if (l == NULL) st_insert(l, t->attr.scope, t->attr.name, t->attr.type, t->lineno, location++);
          else typeError(t, "Error 4: Invalid declaration. Already declared.");
        }
        break;
      case CallK:
        {
          BucketList l = st_lookup(t->attr.scope, t->attr.name);
          if (l == NULL) typeError(t, "Error 5: Invalid call. Not declared.");
          else st_insert(l, t->attr.scope, t->attr.name, t->attr.type, t->lineno, location++);
        }
        break;
      case ReturnK:
          // if (!strcmp(t->attr.scope,"global")) typeError(t, "Error 5: Invalid return. Function not declared.");
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
            else st_insert(l, t->attr.scope, t->attr.name, t->attr.type, t->lineno, 0);
          } 
          break;
        case ArrK:
          {
            BucketList l = st_lookup(t->attr.scope, t->attr.name);
            if (l == NULL) typeError(t, "Error 1: Not declared");
            else st_insert(l, t->attr.scope, t->attr.name, t->attr.type, t->lineno, 0);
          }
          break;
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
  { case StmtK:
      switch (t->kind.stmt)
      { case VarK:
          if (t->type == VoidK) typeError(t, "Error 3: Invalid declaration. Variable can't be void.");
          break;
        case IfK:
          if (t->child[0]->kind.stmt == AssignK) typeError(t->child[0], "Error 8: Invalid condition. If condition is not Boolean.");
          break;
        case AssignK:
          {
            if (t->child[1]->attr.name != NULL){
              BucketList l = st_lookup(t->attr.scope, t->child[1]->attr.name);
              if (l != NULL && t->child[1]->kind.stmt == CallK && 
              !strcmp(l->type, "void")) typeError(t->child[1], "Error 2: Invalid assignment. Assignment of void return.");
            }
          }
          break;
        default:
          break;
        case ReturnK:
        {
          BucketList l = st_lookup(t->attr.scope, t->attr.scope);
          if (l != NULL){
          
            if (!strcmp(l->type,"inteiro") && 
            t->child[0] == NULL) typeError(t, "Error 2: Invalid return. Wrong type return.");
            else if (!strcmp(l->type,"void") && 
            t->child[0] != NULL) typeError(t, "Error 2: Invalid return. Wrong type return.");
          
          }
        }
      }
      break;
    default:
      break;

  }
}

void checkMain(TreeNode * t){
  if(!st_lookup_fun("main")) typeError(t, "Error 6: Main function not declared.");
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ traverse(syntaxTree, insertNode, nullProc);
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree, nullProc, checkNode);
  checkMain(syntaxTree);  
}