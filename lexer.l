%option yylineno
digit  [0-9]
smallLetter [a-z]
capitalLetter [A-Z]
underscore [_]

%{
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "y.tab.h"
#include <cstring>

extern FILE *yyin;
extern FILE *yyout;
void yyerror(char *);
int scopeNumber = 0;
%}

%%
"int"           return INT; 
"string"        return STR;
"bool"          return BOOL;
"void"          return VOID;
"switch"        return SWITCH;
"case"          return CASE;
"default"       return DEFAULT;
"const"         return CONST;
"break"         return BREAK;
"continue"      return CONTINUE;
"do"            return DO;          
">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"++"            return INC;
"--"            return DEC;
"+="            return INCASSIGNMENT;
"-="            return DECASSIGNMENT;
"/="            return DIVIDEASSIGNMENT;
"*="            return MULTIPLYASSIGNMENT;
"nil"           return NIL;
"or"            return OR;
"and"           return AND;
"not"           return NOT;
"for"           return FOR;
"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;
"func"          return FUNCTION;
"true"          {       
                    yylval.stringValue = strdup("1");                                                        
                    return TRUEBOOL;
                }
"false"         {       
                    yylval.stringValue = strdup("0");                                                        
                     return FALSEBOOL;
                }
"return"        return RETURN;

{smallLetter}(({smallLetter}|{capitalLetter}|{underscore}|{digit}){0,15})   {   
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return VARIDENTIFIER;
                                                                            }
                                                                    
{capitalLetter}(({smallLetter}|{capitalLetter}|{digit}){0,15})              {    
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return FUNCIDENTIFIER;
                                                                            }

                                                                                             
{digit}+                                                                    {
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return INTEGER;
                                                                            }
\"[^"\n]*["\n]                                                              {   
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return STRING;
                
                                                                            }
[{]         {   
                scopeNumber++;
                return *yytext;
            }

[}]         {   
                scopeNumber--;
                return *yytext;
            }            

[-()<>=+*/;^:%."",]     {
                        return *yytext;
                    }

[ \t\n]+        ;       /* ignore whitespace */
.             {
                    std::string notError = "Unknown Error";
                    int n = notError.length();
                    char char_array[n+1];
                    strcpy(char_array, notError.c_str());
                    yyerror(char_array);
            }


%%
int yywrap(void) {
    return 1;
}
void yyerror (char const* s) {
   fprintf (stderr, "%s\n", s);
 }
