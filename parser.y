%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtbl.h"
#include "hashtbl.c"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
void production_print(const char* production);
void yyerror(const char *s);
extern struct hashMap *sym_table;

int verb = 1; //1 to activate verbose mode
char* aux;
int i = 0;
int error = 0;
extern int line_num;
extern int col_num;
extern int eof;
extern int func;

%}

%union {
    char *str;
    int num;
    float fnum;
}

%token <str>  FUNCAO FIMFUNCAO CHAMA RETORNA TIPO
%token <str>  ARGS FIMARGS ESCREVA INTEIRO REAL 
%token <str>  CARACTERE SE ENTAO FIMSE ENQUANTO
%token <str>  FACA FIMENQUANTO CHAMADA SENAO
%token <str>  ID_OU_FUNC NUMERO LITERAL OP_RELACIONAL
%token <str>  OP_ARITMETICO ATRIBUICAO ABRE_PAR FECHA_PAR
%token <str>  VIRGULA PONTO_E_VIRG COMENTARIO FIM_DE_ARQ

%type <str> assinatura error

%right ATRIBUICAO
%left OP_RELACIONAL
%left '+' '-'
%left '*' '/'

%verbose
%start programa

%%
programa:
    FUNCAO assinatura { func--; production_print("programa -> FUNCAO assinatura");if(eof == 1 && func == 0) return 0;}
    | error assinatura{
        yyerrok;
        yyclearin;if(eof == 1) return 0;}
    ;

assinatura:
    nome_funcao args {production_print("assinatura -> nome_funcao args");}
    | nome_funcao TIPO tipo_funcao args {production_print("assinatura -> nome_funcao TIPO tipo_funcao args");}
    | nome_funcao error tipo_funcao args {
        yyerrok;
        yyclearin;}
    ;

tipo_funcao:
    CARACTERE {production_print("tipo_funcao -> CARACTERE");}
    | INTEIRO {production_print("tipo_funcao -> INTEIRO");}
    | REAL {production_print("tipo_funcao -> REAL");}
    ;

args:
    ARGS lista_vars FIMARGS codigo {production_print("args -> ARGS lista_vars FIMARGS codigo");}
    | codigo {production_print("args -> codigo");}
    | ARGS lista_vars error codigo {
        yyerrok;
        yyclearin;}
    ;

lista_vars:
    vars {production_print("lista_vars -> vars");}
    | lista_vars vars {production_print("lista_vars -> lista_vars vars");}
    ;

vars:
    tipo ID_OU_FUNC PONTO_E_VIRG {production_print("vars -> tipo ID_OU_FUNC PONTO_E_VIRG");}
    | tipo ID_OU_FUNC VIRGULA vars_cont {production_print("vars -> tipo ID_OU_FUNC VIRGULA vars_cont");}
    | tipo ID_OU_FUNC ATRIBUICAO atribuido {production_print("vars -> tipo ID_OU_FUNC ATRIBUICAO atribuido");}
    | tipo error PONTO_E_VIRG {
        yyerrok;
        yyclearin;}
    | tipo ID_OU_FUNC error{
        yyerrok;
        yyclearin;}
    | error ID_OU_FUNC PONTO_E_VIRG{
         yyerrok;
        yyclearin;}
    ;

vars_cont:
    ID_OU_FUNC VIRGULA vars_cont {production_print("vars_cont -> ID_OU_FUNC VIRGULA vars_cont");}
    | ID_OU_FUNC PONTO_E_VIRG {production_print("vars_cont -> ID_OU_FUNC PONTO_E_VIRG");}
    | error VIRGULA vars_cont{
        yyerrok;
        yyclearin;}
    | ID_OU_FUNC error{
        yyerrok;
        yyclearin;}
    ;

tipo:
    CARACTERE {production_print("tipo -> CARACTERE");}
    | INTEIRO {production_print("tipo -> INTEIRO");}
    | REAL {production_print("tipo -> REAL");}
    ;

codigo:
    vars codigo {production_print("codigo -> vars codigo");}
    | ESCREVA LITERAL PONTO_E_VIRG codigo {production_print("codigo -> ESCREVA LITERAL PONTO_E_VIRG codigo");}
    | ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo {production_print("codigo -> ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo");}
    | ID_OU_FUNC ATRIBUICAO atribuido codigo {production_print("codigo -> ID_OU_FUNC ATRIBUICAO atribuido codigo");}
    | CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo {production_print("codigo -> CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo");}
    | se_entao codigo {production_print("codigo -> se_entao codigo");}
    | ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo {production_print("codigo -> ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo");}
    | RETORNA ID_OU_FUNC PONTO_E_VIRG codigo {production_print("codigo -> RETORNA ID_OU_FUNC PONTO_E_VIRG codigo");}
    | FIMFUNCAO eof {production_print("codigo -> FIMFUNCAO");}
    | FIMFUNCAO programa {production_print("codigo -> FIMFUNCAO");}
    | {production_print("codigo -> epsilon");}
    | ESCREVA ID_OU_FUNC error codigo{
        yyerrok;
        yyclearin;}
    | ESCREVA LITERAL error codigo{
        yyerrok;
        yyclearin;}
    | RETORNA ID_OU_FUNC error {
        yyerrok;
        yyclearin;}
    | error PONTO_E_VIRG codigo{
        yyerrok;
        yyclearin;}
    | error eof {
        yyerrok;
        yyclearin;}
    | error programa {
        yyerrok;
        yyclearin;}
    ;

atribuido:
    LITERAL PONTO_E_VIRG {production_print("atribuido -> LITERAL PONTO_E_VIRG");}
    | NUMERO PONTO_E_VIRG {production_print("atribuido -> NUMERO PONTO_E_VIRG");}
    | ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG");}
    | ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG");}
    | ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG");}
    | CHAMA CHAMADA lista_id PONTO_E_VIRG {production_print("atribuido -> CHAMA CHAMADA lista_id PONTO_E_VIRG");}
    | error PONTO_E_VIRG {
        yyerrok;
        yyclearin;}
    | ID_OU_FUNC error {
        yyerrok;
        yyclearin;}
    | ID_OU_FUNC OP_ARITMETICO error {
        yyerrok;
        yyclearin;}
    ;

lista_id:
    ID_OU_FUNC lista_id {production_print("lista_id -> ID_OU_FUNC lista_id");}
    | {production_print("lista_id -> epsilon");}
    | error lista_id
    ;

se_entao:
    SE ABRE_PAR cond FECHA_PAR ENTAO codigo senao_op FIMSE {production_print("se_entao -> SE ABRE_PAR cond FECHA_PAR ENTAO codigo senao_op FIMSE");}
    | SE error cond FECHA_PAR ENTAO codigo senao_op FIMSE {
        yyerrok;
        yyclearin;}
    | SE ABRE_PAR cond error ENTAO codigo senao_op FIMSE {
        yyerrok;
        yyclearin;}
    | SE ABRE_PAR cond FECHA_PAR error codigo senao_op FIMSE {
        yyerrok;
        yyclearin;}
    ;

senao_op:
    SENAO codigo {production_print("senao_op -> SENAO codigo");}
    | {production_print("senao_op -> epsilon");}
    ;

cond:
    ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC {production_print("cond -> ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC");}
    | ID_OU_FUNC OP_RELACIONAL NUMERO {production_print("cond -> ID_OU_FUNC OP_RELACIONAL NUMERO");}
    | ID_OU_FUNC OP_RELACIONAL LITERAL {production_print("cond -> ID_OU_FUNC OP_RELACIONAL LITERAL");}
    | NUMERO OP_RELACIONAL ID_OU_FUNC {production_print("cond -> NUMERO OP_RELACIONAL ID_OU_FUNC");}
    | NUMERO OP_RELACIONAL NUMERO {production_print("cond -> NUMERO OP_RELACIONAL NUMERO");}
    | NUMERO OP_RELACIONAL LITERAL {production_print("cond -> NUMERO OP_RELACIONAL LITERAL");}
    | LITERAL OP_RELACIONAL ID_OU_FUNC {production_print("cond -> LITERAL OP_RELACIONAL ID_OU_FUNC");}
    | LITERAL OP_RELACIONAL NUMERO {production_print("cond -> LITERAL OP_RELACIONAL NUMERO");}
    | LITERAL OP_RELACIONAL LITERAL {production_print("cond -> LITERAL OP_RELACIONAL LITERAL");}
    | error OP_RELACIONAL ID_OU_FUNC {
        yyerrok;
        yyclearin;}
    | ID_OU_FUNC error ID_OU_FUNC {
        yyerrok;
        yyclearin;}
    | ID_OU_FUNC OP_RELACIONAL error {
        yyerrok;
        yyclearin;}
    | error OP_RELACIONAL NUMERO {
        yyerrok;
        yyclearin;}
    | NUMERO error NUMERO {
        yyerrok;
        yyclearin;}
    | NUMERO OP_RELACIONAL error {
        yyerrok;
        yyclearin;}
    | error OP_RELACIONAL LITERAL {
        yyerrok;
        yyclearin;}
    | LITERAL error LITERAL {
        yyerrok;
        yyclearin;}
    | LITERAL OP_RELACIONAL error {
        yyerrok;
        yyclearin;}
    ;

nome_funcao:
    ID_OU_FUNC {production_print("nome_funcao -> ID_OU_FUNC");}
    ;

eof:
    FIM_DE_ARQ
    ;
%%


void yyerror(const char *s) {
    printf("\033[31mSyntax error: Erro de sintaxe na linha %d, coluna %d: %s\033[0m\n", line_num, col_num, s);
}

void production_print(const char* production) {
    if(verb == 1){
        fprintf(stdout, "Produção utilizada: %s\n", production);
    }
}

int main(int argc, char **argv) {
    int out;
    sym_table = (struct hashMap*) malloc(sizeof(struct hashMap));
    initializeHashMap(sym_table);
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
        if (yyin == NULL) {
            printf("File not found!\n");
            exit(1);
        }
    }
    out=yyparse();

    if(!out) {// yyparse == 0 - parsing completed
        printf("Syntax analyzer finished succesfully.\n");
        fclose(yyin);
        printf("File closed succesfully\n");
    }
    else { //yyparse()==1 - could not complete parsing
        printf("Syntax analyzer failed\n");
        fclose(yyin); // close input file
        printf("File closed succesfully\n");
    }

    free_symbol_table(sym_table);

    return 0;
}
