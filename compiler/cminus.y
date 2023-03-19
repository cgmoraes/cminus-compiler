%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *msg);

%}

%token ELSE IF INT RETURN VOID WHILE IN OUT
%token MAIS MENOS VEZES SOBRE
%token MENORQ MENORI MAIORQ MAIORI IGUAL DIF
%token PONVIR VIRG EPAREN DPAREN ECOLCH DCOLCH ECHAVE DCHAVE RECEBE
%token ID NUM
%token ACOM ERROR

%% /* Grammar for Cminus */
programa : decl_lista {savedTree = $1;}
         ;
decl_lista : decl_lista decl
                  {
                    YYSTYPE t = $1;
                    if(t != NULL){
                      while(t->sibling != NULL) t = t->sibling;
                      t->sibling = $2;
                      $$ = $1;
                    }
                    else $$ = $2;
                  }
                 | decl {$$ = $1;}
                 ;
decl : var_decl {$$ = $1;}

           | fun_decl {$$ = $1;}

           ;
var_decl : tipo_espec ident PONVIR 
              {
                $$ = newExpNode(TypeK);
                $$->type = $1->type;
                $$->attr.name = $1->attr.name;
                $$->child[0] = $2;
                $2->nodekind = StmtK;
                $2->kind.stmt = VarK;
                $2->type = $1->type;
                $2->attr.type = $1->attr.name;
						  }
               | tipo_espec ident ECOLCH num DCOLCH PONVIR
                {
                  $$ = newExpNode(TypeK);
                  $$->type = $1->type;
                  $$->attr.name = $1->attr.name;
                  $$->child[0] = $2;
                  $2->nodekind = StmtK;
                  $2->kind.stmt = VarK;
                  $2->type = $1->type;
                  $2->attr.len = $4->attr.val;
                  $2->attr.type = $1->attr.name;
                }
                ;
fun_decl : tipo_espec ident EPAREN params DPAREN comp_decl
                {
                  $$ = newExpNode(TypeK);
                  $$->type = $1->type;
                  $$->attr.name = $1->attr.name;
                  $$->child[0] = $2;
                  $2->child[0] = $4;
                  $2->child[1] = $6;
                  $2->nodekind = StmtK;
                  $2->kind.stmt = FunK;
                  $2->type = $1->type;
                  $2->attr.type = $1->attr.name;
                  addScope($2->child[0], $2->attr.name);
                  addScope($2->child[1], $2->attr.name);
                }
               ;
params : param_lista {$$ = $1;}
       | VOID
        {
				  $$ = newExpNode(TypeK);
          $$->attr.name = "void";
          $$->child[0] = NULL;
				}
       ;
param_lista : param_lista VIRG param 
            {
              YYSTYPE t = $1;
              if(t != NULL){
                while(t->sibling != NULL)
                t = t->sibling;
                t->sibling = $3;
                $$ = $1;
              }else $$ = $3;
            }
            | param {$$ = $1;}
            ;
tipo_espec : INT
            {
              $$ = newExpNode(TypeK);
              $$->attr.name = "inteiro";
              $$->type = IntegerK;
            }
            | VOID
            {
              $$ = newExpNode(TypeK);
              $$->attr.name = "void";
              $$->type = VoidK;
            }
            ;
param : tipo_espec ident
      {
        $$ = newExpNode(TypeK);
        $$->type = $1->type;
        $$->attr.name = $1->attr.name;
        $$->child[0] = $2;
        $2->nodekind = StmtK;
        $2->kind.stmt = VarK;
        $2->type = $1->type;
        $2->attr.type = $1->attr.name;
      }
      | tipo_espec ident ECOLCH DCOLCH
      {
        $$ = newExpNode(TypeK);
        $$->type = $1->type;
        $$->attr.name = $1->attr.name;
        $$->child[0] = $2;
        $2->nodekind = StmtK;
        $2->kind.stmt = VarK;
        $2->type = $1->type;
        $2->attr.len = -1;
        $2->attr.type = $1->attr.name;
      }
      | tipo_espec ident ECOLCH num DCOLCH
      {
      $$ = newExpNode(TypeK);
      $$->type = $1->type;
      $$->attr.name = $1->attr.name;
      $$->child[0] = $2;
      $2->nodekind = StmtK;
      $2->kind.stmt = VarK;
      $2->type = $1->type;
      $2->attr.len = $4->attr.val;
      $2->attr.type = $1->attr.name;
      }
      ;
comp_decl : ECHAVE local_decl stmt_lista DCHAVE
              {
                YYSTYPE t = $2;
                if(t != NULL){
                  while(t->sibling != NULL)
                  t = t->sibling;
                  t->sibling = $3;
                  $$ = $2;
                } 
                else $$ = $3;
              }
              | ECHAVE local_decl DCHAVE 
              {
                $$ = $2;
              }
              | ECHAVE stmt_lista DCHAVE
              {
                $$ = $2;
              }
              | ECHAVE DCHAVE {}            
              ;
local_decl : local_decl var_decl 
                  {
                    YYSTYPE t = $1;
                    if(t != NULL){
                      while(t->sibling != NULL) t = t->sibling;
                      t->sibling = $2;
                      $$ = $1;
                    }else $$ = $2;
                  }
                  | var_decl
                  {
                    $$ = $1;
                  }
                  ;
stmt_lista : stmt_lista stmt 
                {
                    YYSTYPE t = $1;
                    if(t != NULL){
                      while(t->sibling != NULL)
                      t = t->sibling;
                      t->sibling = $2;
                      $$ = $1;
                    }else $$ = $2;
                  }
                  | stmt
                  {
                    $$ = $1;
                  }
                ;
stmt : exp_decl
          {
            $$ = $1;
          }
          | comp_decl 
          {
            $$ = $1;
          }
          | selec_decl 
          {
            $$ = $1;
          }
          | it_decl 
          {
            $$ = $1;
          }
          | retorno_decl
          {
            $$ = $1;
          }
          | input_decl
          {
            $$ = $1;
          }
          | output_decl
          {
            $$ = $1;
          }
          ;
exp_decl : exp PONVIR 
                {
                  $$ = $1;
                }
               | PONVIR
               ;
selec_decl : IF EPAREN exp DPAREN stmt 
              {
                $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
              }
             | IF EPAREN exp DPAREN stmt ELSE stmt
             {
                $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7;
             }
             ;
it_decl : WHILE EPAREN exp DPAREN stmt
              {
                $$ = newStmtNode(WhileK);
                $$->child[0] = $3;
                $$->child[1] = $5;
              }
              ;
retorno_decl : RETURN PONVIR 
              {
                $$ = newStmtNode(ReturnK);
              }
             | RETURN exp PONVIR
              {
                $$ = newStmtNode(ReturnK);
                $$->child[0] = $2;
              }
             ;
input_decl   : IN EPAREN DPAREN
                 { $$ = newStmtNode(InK);
                   $$->attr.name =
                     copyString(tokenString);
                 }
            ;
output_decl  : OUT EPAREN var DPAREN
                 { $$ = newStmtNode(OutK);
                   $$->attr.name = copyString(tokenString);
                   $$->child[0] = $3;
                 }
            | OUT EPAREN DPAREN
                 { $$ = newStmtNode(OutK);
                   $$->attr.name = copyString(tokenString);
                 }
            ;
exp : var RECEBE exp 
          {
            $$ = newStmtNode(AssignK);
            $$->attr.name = $1->attr.name;
            $$->child[0] = $1;
            $$->child[1] = $3;
          }
          | var RECEBE ativ
          {
            $$ = newStmtNode(AssignK);
            $$->attr.name = $1->attr.name;
            $$->child[0] = $1;
            $$->child[1] = $3;
          }
          | var RECEBE input_decl
          {
            $$ = newStmtNode(AssignK);
            $$->attr.name = $1->attr.name;
            $$->child[0] = $1;
            $$->child[1] = $3;
          }
          | simp_exp
          {
            $$ = $1;
          }
          ;
var : ident 
    {
      $$ = $1;
    }
    | ident ECOLCH exp DCOLCH
    {
      $$ = $1;
      $$->child[0] = $3;
      $$->kind.exp = ArrK;
    }
    ;
simp_exp : soma_exp relacional soma_exp 
                  {
                      $$ = $2;
                      $$->child[0] = $1;
                      $$->child[1] = $3;
                  }
                  | soma_exp
                  {
                    $$ = $1;
                  }
                  ;
relacional : MENORI 
            {
              $$ = newExpNode(OpK);
              $$->attr.op = MENORI;                            
              $$->type = BooleanK;
            }
           | MENORQ 
           {
            $$ = newExpNode(OpK);
            $$->attr.op = MENORQ;                            
						$$->type = BooleanK;
           }
           | MAIORQ 
           {
            $$ = newExpNode(OpK);
            $$->attr.op = MAIORQ;                            
						$$->type = BooleanK;
           }
           | MAIORI 
           {
            $$ = newExpNode(OpK);
            $$->attr.op = MAIORI;                            
						$$->type = BooleanK;
           }
           | IGUAL 
           {
            $$ = newExpNode(OpK);
            $$->attr.op = IGUAL;                            
						$$->type = BooleanK;
           }
           | DIF
           {
            $$ = newExpNode(OpK);
            $$->attr.op = DIF;                            
						$$->type = BooleanK;
           }
           ;
soma_exp : soma_exp soma termo 
              {
                $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3;
              }
               | termo
               {
                $$ = $1;
               }
               ;
soma : MAIS 
      {
        $$ = newExpNode(OpK);
        $$->attr.op = MAIS;  
      }
     | MENOS
     {
      $$ = newExpNode(OpK);
      $$->attr.op = MENOS;  
     }
     ;
termo : termo mult fator
      {
        $$ = $2;
        $$->child[0] = $1;
        $$->child[1] = $3;
      }
      | fator
      {
        $$ = $1;
      }
      ;
mult : VEZES 
      {
        $$ = newExpNode(OpK);
        $$->attr.op = VEZES; 
      }
      | SOBRE
      {
        $$ = newExpNode(OpK);
        $$->attr.op = SOBRE; 
      }
     ;
fator : EPAREN exp DPAREN 
      {
        $$ = $2;
      }
      | var 
      {
        $$ = $1;
      }
      | ativ 
      {
        $$ = $1;
      }
      | num
      {
        $$ = $1;
      }
      ;
ativ : ident EPAREN arg_lista DPAREN
          {
            $$->attr.name = $1->attr.name;
            $$ = $1;
            $$->child[0] = $3;
            $$->nodekind = StmtK;
            $$->kind.stmt = CallK;
          }
          | ident EPAREN DPAREN
          {
            $$->attr.name = $1->attr.name;
            $$ = $1;
            $$->nodekind = StmtK;
            $$->kind.stmt = CallK;
          }
          ;
arg_lista : arg_lista VIRG exp 
          {
            YYSTYPE t = $1;
            if(t != NULL){
              while(t->sibling != NULL)
              t = t->sibling;
              t->sibling = $3;
              $$ = $1;
            } else $$ = $3;
          }
          | exp
          {
            $$ = $1;
          }
          ;
ident : ID
      {
      $$ = newExpNode(IdK);
      $$->attr.name = copyString(tokenString);
      }
;
num : NUM
      {
        $$ = newExpNode(ConstK);
        $$->attr.val = atoi(tokenString);
        $$->type = IntegerK;
      }
;

%%


/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

int yyerror(char * message)
{ 
  char * errortype;

  if (Error) {errortype="lexico"; message = (!(*tokenString) ? "comentario inacabado":"lexema invalido");}
  else {errortype = "sintatico"; Error=TRUE;}

  fprintf(listing,"Erro %s na linha %d: %s\n",errortype,lineno,message);
  fprintf(listing,"Token: ");
  printToken(yychar,tokenString);
  return 0;
}

TreeNode * parse(void){
  yyparse();
  return savedTree;
}
