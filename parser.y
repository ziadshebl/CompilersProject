%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <string>
#include <iostream>
#include <fstream>
#include "symbolTable.h"
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;

#define YYDEBUG 1

/* prototypes */
int yylex(void);
void yyerror(char *s);
void appendErrorToFile(std::string line);
void addText (std::string myTxt);
void appendLineToFile(std::string line);
symbolTable symbolTableList[MAX_SCOPES];
dataTypeEnum varType;
bool isFunctionParam = false;
bool isBracketScope = false;
bool isClosedBracketScope = false;
bool isForScope = false;
bool isSwitchScope = false;
bool notInitialized = false;
int paramList [5];
int paramListIndex = 0;
int argumentList [5];
int argumentListIndex = 0;
int labelNumber = 0;
dataTypeEnum functionDataType; 
dataTypeEnum switchDataType; 
%}

%union {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    char * stringValue;
    struct symbolTableEntry * entry;
};


%token <entry> STRING INTEGER
%token <entry> VARIDENTIFIER
%type <entry> functionDeclaration
%type <entry> constDeclaration
%type <entry> varDeclaration
%type <entry> variable
%type <entry> lValue
%type <entry> consValues
%type <entry> expr
%type <entry> caseStmt
%token <entry> TRUEBOOL FALSEBOOL 
%token INT STR BOOL VOID SWITCH CASE DEFAULT CONST  DO  NIL OR AND NOT FUNCTION RETURN
%token INC DEC INCASSIGNMENT DECASSIGNMENT MULTIPLYASSIGNMENT DIVIDEASSIGNMENT
%token <entry> FUNCIDENTIFIER
%token WHILE IF PRINT FOR CONTINUE BREAK
 

%nonassoc VARFX 
%nonassoc IFX 
%nonassoc ELSE 
%nonassoc ';' 
%nonassoc '=' 
%left GE LE EQ NE '>' '<' OR AND 
%left '+' '-' 
%left '*' '/' '%'
%nonassoc INCASSIGNMENT DECASSIGNMENT MULTIPLYASSIGNMENT DIVIDEASSIGNMENT INC DEC
%nonassoc UMINUS NOT





%%
program:
        function                {       
                                        for(int j=0; j<totalNumberOfScopes; j++){
                                                symbolTable symb= symbolTableList[j];
                                                symbolTableEntry* traverser;
                                                display_symbol_table(j,symb.symbolTable);
                                                for(int i=0; i < MAX_IDENTIFIERS; i++)
                                                {
                                                        traverser = symb.symbolTable[i];
                                                        while( traverser != NULL)
                                                        {
                                                                if(!traverser->isUsed && strcmp(traverser->lexeme,"Main")){
                                                                        printf("The variable/function %s is not used\n", traverser->lexeme);
                                                                        
                                                                }
                                                                traverser = traverser->next;
                                                        }
                                                }
                                        }
                                       
                                        printf("Exiting");
                                }    
        ;

function:
        function  functionDeclaration         { }
        | function varDeclaration 
        | function constDeclaration 
        | /* NULL */
        ;
type:   INT                     {varType = dataTypeEnum::typeInt;}
        | STR                   {varType = dataTypeEnum::typeString;} 
        | BOOL                  {varType = dataTypeEnum::typeBool;}
        ;
   
functionParam:
        variable                        {
                                                  
                                        }
        | variable                      {
                                                 
                                        } 
        ',' functionParam
        |  /* NULL */
        ;
functionArgs: 
        expr                            {       
                                                if($1!=NULL){

                                                        argumentList[argumentListIndex] = $1->dataType;
                                                         std::string  stringToAdd = "pop r";
                                                         stringToAdd += to_string(argumentListIndex);  
                                                         appendLineToFile(stringToAdd);  
                                                        argumentListIndex++;
                                                }else{
                                                        argumentList[argumentListIndex] = -1;
                                                        argumentListIndex++;      
                                                }
                                        }        
        | expr                          {
                                                if($1!=NULL){

                                                        argumentList[argumentListIndex] = $1->dataType;
                                                        std::string  stringToAdd = "pop r";
                                                         stringToAdd += to_string(argumentListIndex);  
                                                         appendLineToFile(stringToAdd);  
                                                        argumentListIndex++;
                                                }else{
                                                        argumentList[argumentListIndex] = -1;
                                                        argumentListIndex++;      
                                                }
                                        } 
        ',' functionArgs
        | /* NULL */
        ;
varDeclaration:
         variable ';'                   {
                                              
                                                if($1 !=NULL){
                                                        $1->entryType = entryTypeEnum::isVariable;
                                                        $$=$1;

                                                }else{
                                                        $$=NULL;  
                                                }
                                                
                                                
                                        }         
        | variable '=' expr ';'         {

                                                if($1 !=NULL && $3 != NULL){
                                                        $1->entryType = entryTypeEnum::isVariable;
                                                        if($1->dataType != $3->dataType){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                                $$=NULL;
                                                        }else{
                                                                $1->isInitialized = true;
                                                                std::string  stringToAdd = "pop ";
                                                                stringToAdd += $1->lexeme;  
                                                                appendLineToFile(stringToAdd);       
                                                                $$=$1;    
                                                        }
                                                        
                                                }else{
                                                        $$=NULL;
                                                } 
                                               
                                        }
        ;
constDeclaration:
        CONST variable '='  expr  ';'   {
                                                if($4!=NULL){

                                                        $2->entryType = entryTypeEnum::isConstantVariable;
                                                        if($2->dataType != $4->dataType){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        }else{
                                                                $2->isInitialized = true;     
                                                                std::string  stringToAdd = "pop ";
                                                                stringToAdd += $2->lexeme;  
                                                                appendLineToFile(stringToAdd);       
                                                                $$=$2;         
                                                        }
                                                }
                                               
                                               
                                        }
        ;
variable: 
        type VARIDENTIFIER              {
                                               
                                                $2 = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,varType);
                                                
                                                if(isFunctionParam == true){
                                                        $2->entryType = entryTypeEnum::isParameter;
                                                        paramList[paramListIndex] = varType;
                                                        std::string  stringToAdd = "mov r";
                                                        stringToAdd +=  to_string(paramListIndex);
                                                        stringToAdd += " , ";  
                                                        stringToAdd += $2->lexeme;
                                                        appendLineToFile(stringToAdd); 
                                                        paramListIndex++;
                                                        $2->isInitialized = true;
                                                }               
                                                $$ = $2;
                                                                                             
                                        }
        ;
functionDeclaration: 
        type FUNCTION  FUNCIDENTIFIER  {
                                                isFunctionParam=true;
                                                $3 = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,varType); 
                                                $3->entryType = entryTypeEnum::isFunction; 
                                                std::string temp = $3->lexeme;
                                                temp+=":";
                                                appendLineToFile(temp);    
                                                                                                                           
                                        }
        '('                             {       
                                                currentScope = createNewScope();
                                                isBracketScope = true;
                                        }
        functionParam ')'               {       
                                                int*temp = (int*) malloc(sizeof(int)*(paramListIndex+1));
                                                for(int i=0; i<paramListIndex; i++){
                                                        temp[i] = paramList[i];
                                                }
                                                $3->functionParametersList=temp;
                                                $3->functionsParametersNumber=paramListIndex;
                                                isFunctionParam=false;
                                                paramListIndex=0;
                                        }
        openScope                       {       
                                                functionDataType = $3->dataType;
                                                isBracketScope = false;
                                        }
        stmtList closeScope             {
                                           $$ = $3;
                                        }

        | VOID FUNCTION FUNCIDENTIFIER {        
                                                $3 = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,dataTypeEnum::typeVoid); 
                                                $3->entryType = entryTypeEnum::isFunction;
                                                isFunctionParam=true;
                                                std::string temp = $3->lexeme;
                                                temp+=":";
                                                appendLineToFile(temp);  
                                               
                                        }
        '('                             {
                                                isBracketScope = true;  
                                                currentScope = createNewScope();
                                        }
        functionParam ')'               {
                                                int*temp = (int*) malloc(sizeof(int)*(paramListIndex+1));
                                                for(int i=0; i<paramListIndex; i++){
                                                        temp[i] = paramList[i];
                                                }
                                                $3->functionParametersList=temp;
                                                $3->functionsParametersNumber=paramListIndex;
                                                isFunctionParam=false;
                                                paramListIndex=0;
                                        }
        openScope                       {       functionDataType = dataTypeEnum::typeVoid;
                                                isBracketScope = false;
                                        } 
        stmtList  closeScope            {
                                                $$ = $3;
                                        }
;

stmtBlock: 
        openScope stmtList closeScope
        ;
stmt:
          ';'                                 { }
        | expr ';'                            { }
        | PRINT '(' expr ')' ';'              { }
        | whileStmt                           { }
        | doStmt                              { }
        | forStmt                             { }
        | continueStmt                        { }
        | breakStmt                           { }
        | ifStmt                              { }
        | stmtBlock                           { }
        | varDeclaration                      { }
        | constDeclaration                    { }
        | returnStmt                          { }
        | switchStmt                          { }
        ;
ifStmt: IF '(' expr ')' stmt %prec IFX        {/*TODO:CHECK BOOL EXPRESSION*/}
        | IF '(' expr ')' stmt ELSE stmt      {/*TODO:CHECK BOOL EXPRESSION*/}
        ;
returnStmt:
        RETURN expr ';'                         {
                                                         if (functionDataType!=$2->dataType){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        }

                                                        std::string stringToAdd = "pop ";
                                                        stringToAdd += "R0";
                                                        appendLineToFile(stringToAdd);
                                                        stringToAdd = "pop ";
                                                        stringToAdd += "R1";
                                                        appendLineToFile(stringToAdd); 
                                                        stringToAdd = "push ";
                                                        stringToAdd += "R0";
                                                        appendLineToFile(stringToAdd); 
                                                        stringToAdd = "push ";
                                                        stringToAdd += "R1";
                                                        appendLineToFile(stringToAdd); 
                                                        stringToAdd = "ret ";
                                                        appendLineToFile(stringToAdd); 
                                                }  
        | RETURN ';'                            {
                                                        if (functionDataType!=dataTypeEnum::typeVoid){
                                                                appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                        }else{
                                                                std::string stringToAdd = "ret ";
                                                                appendLineToFile(stringToAdd);
                                                        } 
                                                } 
        ;
breakStmt:
        BREAK   ';'                             {
                                                        if(!isForScope && !isSwitchScope){
                                                               
                                                                appendErrorToFile("Break couldn't be called outside the scope of a loop/switch at line "+ to_string(yylineno)); 
                                                                        
                                                        }
                                                }
        ;
continueStmt:
        CONTINUE ';'                            { 
                                                        if(!isForScope){
                                                                appendErrorToFile("Continue couldn't be called outside the scope of a loop/switch at line "+ to_string(yylineno)); 
                                                                
                                                        }
                                                }
        ;
switchStmt:
        SWITCH '(' expr ')' openScope   {
                                                isSwitchScope = true;
                                                switchDataType = $3->dataType;
                                        }
         caseStmts closeScope           {
                                                isSwitchScope = false;
                                        }
        ;
caseStmts:
        caseStmt caseStmts
        | caseStmt
        ;
caseStmt:
        CASE expr ':' stmtList          {
                                                if($2!=NULL){
                                                        if($2->dataType != switchDataType){
                                                               appendErrorToFile("Type mismatch at line"+ to_string(yylineno));
                                                        }
                                                }
                                        }
        | DEFAULT ':' stmtList          {}
        ;
whileStmt: WHILE '('                                            {    
                                                                        currentScope = createNewScope();
                                                                        isBracketScope = true;
                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;          
                                                                        
                                                                }
           expr ')' openScope                                   {
                                                                        isForScope = true;
                                                                        isBracketScope = false;
                                                                        std::string stringToAdd = "JZ ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        appendLineToFile(stringToAdd);
                                                                              
                                                                }
           stmtList closeScope                                  {
                                                                         isForScope = false;
                                                                        std::string stringToAdd = "JMP ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labelNumber-1);
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;      
                                                                }
        ;

forStmt:  FOR '('                                               {       
                                                                       
                                                                        currentScope = createNewScope();
                                                                        isBracketScope = true;
                                                                         
                                                                        
                                                                }
          loopExpression ')' openScope                          {
                                                                        isForScope = true;
                                                                        isBracketScope = false;   
                                                                
                                                                }
          stmtList closeScope                                   {       
                                                                        isForScope = false;
                                                                        std::string stringToAdd = "JMP L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        appendLineToFile(stringToAdd);  
                                                                }
        ;
doStmt: 
        DO openScope                                            {       
                                                                        isClosedBracketScope = true;
                                                                        isForScope = true;
                                                                        std::string stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;          
                                                                }
        stmtList closeScope                                     {
                                                                        isClosedBracketScope = false;        
                                                                        isForScope = false;
                                                                }
        WHILE '(' expr ')' ';'                                  {      
                                                                        std::string stringToAdd = "JNZ ";
                                                                        stringToAdd += "L";
                                                                        stringToAdd += to_string(labelNumber-1);
                                                                        appendLineToFile(stringToAdd);  

                                                                        stringToAdd = "L";
                                                                        stringToAdd += to_string(labelNumber);
                                                                        stringToAdd += ": ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        labelNumber++;          
                                                                }
        ;
loopExpression: 
        INT VARIDENTIFIER               {
                                                $2 = insert(symbolTableList[currentScope].symbolTable,yylval.stringValue,dataTypeEnum::typeInt);
                                                $2->isInitialized = true;
                                                std::string stringToAdd = "pop ";
                                                stringToAdd += $2->lexeme;
                                                appendLineToFile(stringToAdd); 
                                                stringToAdd = "JMP L";
                                                stringToAdd += to_string(labelNumber+1);
                                                appendLineToFile(stringToAdd);  
                                                
                                       }
        '=' expr ';' expr ';' expr      
        |  VARIDENTIFIER                {
                                                $1 = isAvailable(yylval.stringValue);
                                                if($1==NULL){
                                        
                                                        
                                                        std::string temp = yylval.stringValue;
                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                        
                                                        $1->isInitialized = true;
                                                }
                                        }
        '=' expr ';' expr ';'  expr  
        ; 
stmtList:
        stmt                   { }
        | stmtList stmt        { }
        ;
expr:
        lValue '=' expr                         {       
                                                        if($1!=NULL){
                                                                if($1->dataType != $3->dataType){
                                                                        appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                                }else{
                                                                        $1->isInitialized = true;
                                                                        std::string stringToAdd = "pop ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);                                                                      
                                                                }

                                                        }
                                                        
                                                        $$=$1;
                                                        
                                                }
        | lValue                                {       
                                                        if(!$1->isInitialized){
                                                                std::string temp= $1->lexeme; 
                                                                appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                        }else{
                                                                std::string  stringToAdd = "push ";
                                                                stringToAdd += $1->lexeme;
                                                                appendLineToFile(stringToAdd); 
                                                        }
                                                        //notInitialized=false;
                                                        $$=$1;
                                                }
        | consValues                            {
                                                        $$=$1;
                                                }

        | '-' expr %prec UMINUS                 {
                                                        if($2!=NULL){
                                                                if($2->dataType != dataTypeEnum::typeInt){
                                                                        appendLineToFile("Can't - on a non integer value");
                                                                
                                                                }
                                                        }else{
                                                                std::string  stringToAdd = "neg ";
                                                                appendLineToFile(stringToAdd);  
                                                                $2->lexeme = '-'+$2->lexeme;

                                                        }

                                                        $$=$2;    
                                                }
        | FUNCIDENTIFIER                        { 

                                                        $1 = isAvailable(yylval.stringValue);
                                                        if($1==NULL)
                                                        {       std::string temp = yylval.stringValue;
                                                                std::string error = "Function" + temp +" not defined at line " + to_string(yylineno);
                                                                appendErrorToFile(error);
                                                                
                                                        }
                                                           
                                                                     
                                                }
         '(' functionArgs ')'                   {
                                                        if($1->functionsParametersNumber!=argumentListIndex){
                                                                
                                                                std::string error = "Expected" + to_string($1->functionsParametersNumber) +"arguments, but found" +to_string(argumentListIndex)+ "at line" + to_string(yylineno);
                                                                appendErrorToFile(error);
                                                              
                                                                $$=NULL;
                                                        }else{
                                                                bool flag = false;
                                                                for(int i=0; i<argumentListIndex; i++){
                                                                        if($1->functionParametersList[i] != argumentList[i]){
                                                                                appendErrorToFile("Calling arguments type are not matching at line "+ to_string(yylineno));
                                                                                flag = true;
                                                                                break;
                                                                                $$=NULL;
                                                                        }
                                                                }
                                                                if(!flag){
                                                                        $$=$1; 
                                                                }
                                                        }   
                                                        std::string  stringToAdd = "call ";
                                                         stringToAdd += $1->lexeme;  
                                                         appendLineToFile(stringToAdd);  
                                                        argumentListIndex=0;
                                                
                                                }
        | expr '+' expr                         {
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType==dataTypeEnum::typeBool || $3->dataType==dataTypeEnum::typeBool){
                                                                        
                                                                        appendErrorToFile("Failed to add bool expression at line "+ to_string(yylineno));
                                                                        $$=NULL;
                                                                }
                                                                else if($1->dataType != $3->dataType){
                                                                        appendErrorToFile("Type mismatch at line "+ to_string(yylineno));
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "add ";
                                                                        appendLineToFile(stringToAdd);  
                                                                        $$ = $1;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                       
                                                }
        | expr '-' expr                         {        
                                                        
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                        appendErrorToFile("Failed to subtract non integer variables at line "+ to_string(yylineno));
                                                                        $$=NULL;
                                                                }
                                                                else{
                                                                        std::string  stringToAdd = "sub ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "neg ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        $$=$1;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr '*' expr                         {
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                          
                                                                          appendErrorToFile("Failed to multiply non integer variables at line "+ to_string(yylineno));
                                                                          $$=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "mul ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        $$=$1;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr '/' expr                         {
                                                         if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                    
                                                                        appendErrorToFile("Failed to divide non integer variables at line "+ to_string(yylineno));    
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "div ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        $$=$1;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                        
                                                }
        | expr '<' expr                         {
                                                         if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno));
                                                                        
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpLT ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                             $$=NULL;    
                                                        }
                                                       
                                                }
        | expr '>' expr                         {
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum::typeInt){
                                                                       
                                                                        appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno));
                                                                        
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpGT ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr '%' expr                         {
                                                         if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                        appendErrorToFile("Failed to mod non integer variables at line "+ to_string(yylineno));
                                                                        
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "mod ";
                                                                        appendLineToFile(stringToAdd); 
                                                                        $$=$1;
                                                                        
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr OR expr                          {
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeBool || $3->dataType != dataTypeEnum:: typeBool){
                                                                        appendErrorToFile("Failed to OR non boolean variables at line "+ to_string(yylineno));
                                                                        
                                                                          $$=NULL;
                                                                }else{  
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "or ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr AND expr                         {
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeBool || $3->dataType != dataTypeEnum:: typeBool){
                                                                        appendErrorToFile("Failed to and non boolean variables at line "+ to_string(yylineno));
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "and ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | NOT expr                              {
                                                        if($2!=NULL){
                                                                if($2->dataType != dataTypeEnum:: typeBool){
                                                                        
                                                                        appendErrorToFile("Failed to Not non boolean variables at line "+ to_string(yylineno));
                                                                        
                                                                        $$=NULL;
                                                                }else{
                                                                        $2->dataType = dataTypeEnum::typeBool;
                                                                        $$=$2; 
                                                                        std::string  stringToAdd = "not ";
                                                                        appendLineToFile(stringToAdd); 
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | lValue INCASSIGNMENT expr             {
                                                        if($1!=NULL && $3!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                if(!$1->isInitialized){
                                                                       
                                                                        std::string temp = $1->lexeme;
                                                                        appendErrorToFile("Variable" +temp +"is used and not initialized at line "+ to_string(yylineno));
                                                                          
                                                                }
                                                                notInitialized=false;
                                                                if($1->dataType==dataTypeEnum::typeBool || $3->dataType==dataTypeEnum::typeBool){
                                                                        appendErrorToFile("Failed to add bool expression at line " + to_string(yylineno));
                                                                        $$=NULL;
                                                                }
                                                                else if($1->dataType != $3->dataType){
                                                                        
                                                                        appendErrorToFile("Type mismatch at line " + to_string(yylineno));
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "add ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);      
                                                                        $$=$1;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | lValue DECASSIGNMENT expr             {
                                                        if($1!=NULL && $3!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!$1->isInitialized){
                                                                         
                                                                        std::string temp = $1->lexeme;
                                                                        appendErrorToFile("Variable " + temp +"is used and not initialized at line"+ to_string(yylineno));
                                                                }
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Can't subtract non integer variables at line "+ to_string(yylineno));
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "sub ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);      
                                                                        $$=$1;
                                                                      
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                        
                                                }
        | lValue DIVIDEASSIGNMENT expr          {
                                                          if($1!=NULL && $3!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!$1->isInitialized){
                                                                        
                                                                        std::string temp = $1->lexeme;
                                                                        appendErrorToFile("Variable "+temp+ " not Initialized at line"+ to_string(yylineno));  
                                                                }
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                       
                                                                        appendErrorToFile("Can't divide non integer varaibles at line"+ to_string(yylineno));
                                                                        $$=NULL;
                                                                }else{
                                                                        
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "div ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        $$=$1;     
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | lValue MULTIPLYASSIGNMENT expr        {
                                                        if($1!=NULL && $3!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!$1->isInitialized){
                                                                        std::string temp = $1->lexeme;
                                                                        appendErrorToFile("Variable "+temp+ "  is not initialized at line "+ to_string(yylineno));   
                                                                }
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Failed to multiply non integer variables at line "+ to_string(yylineno)); 
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "mul ";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        $$=$1;       
                                                                        
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | lValue INC                            {
                                                        if($1!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!$1->isInitialized){
                                                                        std::string temp = $1->lexeme;
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if($1->dataType != dataTypeEnum:: typeInt){
                                                                         
                                                                          appendErrorToFile("Failed to increment non integer variable at line "+ to_string(yylineno)); 
                                                                        
                                                                          $$=NULL;

                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "add";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                           
                                                                        $$=$1;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | INC lValue                            {
                                                        if($2!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $2->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!$2->isInitialized){
                                                                      
                                                                        std::string temp = $2->lexeme;
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if($2->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                        appendErrorToFile("Failed to increment non integer variable at line "+ to_string(yylineno)); 
                                                                        $$=NULL;
                                                                }else{
                                                                      
                                                                        std::string  stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += $2->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "add";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $2->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += $2->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        $$=$2;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                       
                                                }
        | lValue DEC                            {
                                                        if($1!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $1->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                if(!$1->isInitialized){
                                                                        std::string temp = $1->lexeme; 
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if($1->dataType != dataTypeEnum:: typeInt){
                                                                        
                                                                          appendErrorToFile("Failed to decrement non integer variable at line "+ to_string(yylineno)); 
                                                                        
                                                                          $$=NULL;
                                                                }else{
                                                                        std::string stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd); 
                                                                        stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "sub";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $1->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        $$=$1;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | DEC lValue                            {
                                                        if($2!=NULL){
                                                                // if(notInitialized){
                                                                //         printf("Variable %s not isInitialized\n", $2->lexeme);   
                                                                // }
                                                                // notInitialized=false;
                                                                 if(!$2->isInitialized){
                                                                        std::string temp = $2->lexeme;
                                                                        appendErrorToFile("Variable"+temp+ " not initialized at line "+ to_string(yylineno));
                                                          
                                                                }
                                                                if($2->dataType != dataTypeEnum:: typeInt){
                                                                          appendErrorToFile("Failed to decrement non integer variable at line "+ to_string(yylineno)); 
                                                                        
                                                                          $$=NULL;
                                                                }else{
                                                                        std::string  stringToAdd = "push 1";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += $2->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "sub";
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "pop ";
                                                                        stringToAdd += $2->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        stringToAdd = "push ";
                                                                        stringToAdd += $2->lexeme;
                                                                        appendLineToFile(stringToAdd);
                                                                        $$=$2;
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr GE expr                          {
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                          
                                                                          appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno)); 
                                                                        
                                                                          $$=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpGE ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr LE expr                          {      
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != dataTypeEnum:: typeInt || $3->dataType != dataTypeEnum:: typeInt){
                                                                         
                                                                          appendErrorToFile("Failed to compare non integer variables at line "+ to_string(yylineno)); 
                                                                        
                                                                          $$=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpLE ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr NE expr                          {
                                                       if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != $3->dataType){
                                                                        appendErrorToFile("Failed to compare variables from different types at line "+ to_string(yylineno)); 
                                                                        
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpNE ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                $$=NULL;
                                                        }
                                                }
        | expr EQ expr                          {
                                                        if($1!=NULL && $3!=NULL){
                                                                if($1->dataType != $3->dataType){
                                                                        appendErrorToFile("Failed to compare variables from different types at line "+ to_string(yylineno)); 
                                                                        
                                                                        $$=NULL;
                                                                }else{
                                                                        std::string temp = "temp";
                                                                        int n = temp.length();
                                                                        char charArray[n+1];
                                                                        strcpy(charArray, temp.c_str());
                                                                        $$ = createEntry(charArray, dataTypeEnum::typeBool);
                                                                        std::string  stringToAdd = "cmpEQ ";
                                                                        appendLineToFile(stringToAdd);
                                                                }
                                                        }else{
                                                                $$=NULL;   
                                                        }
                                                      
                                                }
        | '(' expr ')'                          {$$=$2;}
        ;
lValue: VARIDENTIFIER           {  
                                        $1 = isAvailable(yylval.stringValue);
                                        if($1==NULL){
                                                
                                                std::string temp = yylval.stringValue;
                                                appendErrorToFile("Variable "+temp+" at line "+ to_string(yylineno)); 
                                                                        
                                                $$=NULL;
                                        }else{
                                               
                                                // if(!$1->isInitialized){
                                                //         notInitialized=true;
                                                // }
                                                $$ = $1;     
                                        }

                                        
                                        
                                }
        ;
consValues: 
        INTEGER                 { 

                                        $1 = createEntry(yylval.stringValue, dataTypeEnum::typeInt);
                                        $1->entryType = entryTypeEnum::isConstant;
                                        $$=$1;
                                        std::string stringToAdd = "push ";
                                        stringToAdd += yylval.stringValue;
                                        appendLineToFile(stringToAdd);
                                }
        | STRING                {
                                        $1 = createEntry(yylval.stringValue, dataTypeEnum::typeString);
                                        $1->entryType = entryTypeEnum::isConstant;
                                        $$=$1;
                                        std::string stringToAdd = "push ";
                                        stringToAdd += yylval.stringValue ;
                                        appendLineToFile(stringToAdd);
                                }
        | FALSEBOOL             {
                                        $1 = createEntry(yylval.stringValue, dataTypeEnum::typeBool);
                                        $1->entryType = entryTypeEnum::isConstant;
                                        $$=$1;
                                        std::string stringToAdd = "push 0";
                                        appendLineToFile(stringToAdd);
                                }
        | TRUEBOOL              {
                                        $1 = createEntry(yylval.stringValue, dataTypeEnum::typeBool);
                                        $1->entryType = entryTypeEnum::isConstant;
                                        $$=$1;
                                        std::string stringToAdd = "push 1";
                                        appendLineToFile(stringToAdd);
                                }  
        ;


openScope: '{'                  {
                                       
                                        if(!isBracketScope){
                                                currentScope = createNewScope();
                                        }
                                      
                                };       
closeScope: '}'                 {
                                        if(!isClosedBracketScope){
                                             currentScope = exitScope();   
                                        }
                                        
                                };
%%

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

#define LEN 256
void appendLineToFile(std::string line)
{
    std::ofstream file;
    file.open ("./output.txt", std::ios::out | std::ios::app );
    file << line << std::endl;
}

void appendErrorToFile(std::string line)
{
    std::ofstream file;
    file.open ("./error.txt", std::ios::out | std::ios::app );
    file << line << std::endl;
}

int main (int argc, char *argv[]){
	// parsing
        std::ofstream file1;
        file1.open ("./error.txt", std::ios::out);
        file1<<"";
        std::ofstream file2;
        file2.open ("./output.txt", std::ios::out);
        file2<<"";
        symbolTableList[0].symbolTable = createTable();
        symbolTableList[0].parent = -1;
	yyin = fopen(argv[1], "r");
        // yyparse();
        if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
		printf("\nPARSING FAILED!\n\n\n");
	}
	fclose(yyin);
        //display_symbol_table(symbolTableList[2].symbolTable);

}