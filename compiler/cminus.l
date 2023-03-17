%option noyywrap
%option nounput

%{

#include "stdio.h"
#include "globals.h"
#include "string.h"
#include "scan.h"
#include "util.h"
char tokenString[MAXTOKENLEN + 1];

%}

digito         [0-9]
letra          ([a-z]|[A-Z])
numero         {digito}+
identificador  {letra}+({digito}|[_])*
novalinha      \n
espacobranco   [ \t\r]+


%%

"else" {return ELSE;}
"if" {return IF;}
"int" {return INT;}
"return" {return RETURN;}
"void" {return VOID;}
"while" {return WHILE;}
"+" {return MAIS;}
"-" {return MENOS;}
"*" {return VEZES;}
"/" {return SOBRE;}
"<" {return MENORQ;}
"<=" {return MENORI;}
">" {return MAIORQ;}
">=" {return MAIORI;}
"==" {return IGUAL;}
"!=" {return DIF;}
"=" {return RECEBE;}
";" {return PONVIR;}
"," {return VIRG;}
"(" {return EPAREN;}
")" {return DPAREN;}
"[" {return ECOLCH;}
"]" {return DCOLCH;}
"{" {return ECHAVE;}
"}" {return DCHAVE;}
{espacobranco}  {}
{novalinha} {lineno++;}
{identificador} {return ID;}
{numero}  {return NUM;}
"/*" { char c;
      int line=lineno;
      while (1) {
        c = input();
        if (c == ENDFILE) return ACOM;
        if (c == '\n') line++;
        while ((c = input()) == '*');
        if (c == '/') break;
      }
      lineno=line;
    }
. {return ERROR;}


%%

TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  Error = (currentToken == ERROR || currentToken == ACOM);
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}
