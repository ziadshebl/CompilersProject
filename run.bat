flex lexer.l
bison --yacc --defines --debug --verbose parser.y
g++ symbolTable.h y.tab.c lex.yy.c
a.exe code.txt