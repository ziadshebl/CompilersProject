%option yylineno
digit  [0-9]
smallLetter [a-z]
capitalLetter [A-Z]
underscore [_]

%{
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "y.tab.h"
#include <cstring>

extern FILE *yyin;
extern FILE *yyout;
void yyerror(char *);
void appendErrorToFile3(std::string line);
int scopeNumber = 0;
%}

%%
"int"           return INT; //Integer Data Type
"string"        return STR; //String Data Type
"bool"          return BOOL; //Boolean Data Type
"void"          return VOID; //Void Data Type
"switch"        return SWITCH; //Switch Keyword
"case"          return CASE; //Case Keyword
"default"       return DEFAULT; //Default Keyword in Switch Statement
"const"         return CONST; //Identifies Constant Variables (Which can not be used as LValue)
"break"         return BREAK; //Break Keyword that exits inner-most loop.
"continue"      return CONTINUE; //Continue Keyword just Breaks 1 iteration of the inner-most loop;
"do"            return DO;  //Do Keyword in Do-While Statement          
">="            return GE;  //Greater than or equal comparator used in boolean expressions
"<="            return LE;  //Less than or equal comparator used in boolean expressions
"=="            return EQ;  //Equal comparator used in boolean expressions
"!="            return NE;  //Not Equal comparator used in boolean expressions
"++"            return INC; //Increment Operator
"--"            return DEC; //Decrement Operator
"+="            return INCASSIGNMENT; //Add AND assignment operator, It adds right operand to the left operand and assign the result to left operand
"-="            return DECASSIGNMENT; //Subtract AND assignment operator, It adds right operand to the left operand and assign the result to left operand.
"/="            return DIVIDEASSIGNMENT; //Divide AND assignment operator, It adds right operand to the left operand and assign the result to left operand.
"*="            return MULTIPLYASSIGNMENT; //Multiply AND assignment operator, It adds right operand to the left operand and assign the result to left operand.
"nil"           return NIL; //NULL Pointer (not used because project doesn't include Pointers)
"or"            return OR; //Logical operator for disjunction between two boolean expressions
"and"           return AND; //Logical operator for conjunction between two boolean expressions
"not"           return NOT; //Unary Logical operator for negating a boolean expression
"for"           return FOR; //For loop Keyword
"while"         return WHILE; //While loop Keyword
"if"            return IF; //If Condition Keyword
"else"          return ELSE; //Else Keyword in if conditions
"print"         return PRINT; //Built-in function
"func"          return FUNCTION; //Keyword usef before declaring any function identifier
"true"          {       
                    yylval.stringValue = strdup("1");                                                        
                    return TRUEBOOL;
                } //Boolean Value for true
"false"         {       
                    yylval.stringValue = strdup("0");                                                        
                     return FALSEBOOL;
                } //Boolean Value for false
"return"        return RETURN; //Keyword for return from function

{smallLetter}(({smallLetter}|{capitalLetter}|{underscore}|{digit}){0,15})   {   
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return VARIDENTIFIER;
                                                                            } //Regex for valid variable identifiers (have to start with lowercase)
                                                                    
{capitalLetter}(({smallLetter}|{capitalLetter}|{digit}){0,15})              {    
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return FUNCIDENTIFIER;
                                                                            } //Regex for valid function identifiers (have to start with uppercase)

                                                                                             
{digit}+                                                                    {
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return INTEGER;
                                                                            } //Regex for valid integer values
\"[^"\n]*["\n]                                                              {   
                                                                                yylval.stringValue = strdup(yytext);
                                                                                return STRING;
                
                                                                            } //Regex for valid string values
[{]         {   
                scopeNumber++;
                return *yytext;
            } //Open Scope

[}]         {   
                scopeNumber--;
                return *yytext;
            } //Close Scope            

[-()<>=+*/;^:%."",]     {
                        return *yytext;
                    } //Arithmetic Operators,Brackets,String Quotes

[ \t\n]+        ;       /* ignore whitespace */
.             {
                    std::string notError = "Unknown Error";
                    int n = notError.length();
                    char char_array[n+1];
                    strcpy(char_array, notError.c_str());
                    yyerror(char_array);
            } //White Space


%%
int yywrap(void) {
    return 1;
}
void appendErrorToFile3(std::string line)
{
    std::ofstream file;
    file.open ("./error.txt", std::ios::out | std::ios::app );
    file << line << std::endl;
}
void yyerror(char const*s) {
    std::string temp=s;
    temp+=" at line: "+std::to_string(yylineno);
    appendErrorToFile3(temp);
    fprintf(stdout, "%s\n", s);
}

