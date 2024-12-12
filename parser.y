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
void yyerror(const char *s);
int checkType( char *name, char *encounteredType);
int idsCheckType( char *name, char *name2);
char* mathCheck(char *ar1, char *ar2, char *op);
char* idMathCheck(char *ar1, char *ar2, char *op, char *ar2type);
char* idsMathCheck(char *ar1, char *ar2, char *op);

int verb = 0; //1 to activate verbose mode
int verbose = 1;
char* aux;
int i = 0;
int error = 0;
extern int line_num;
extern int col_num;
extern int eof;
extern int func;
extern char *escopo;

%}

%union {
    char *str;
    int num;
    float fnum;
}

%token <str>  FUNCAO FIMFUNCAO CHAMA RETORNA TIPO
%token <str>  ARGS FIMARGS ESCREVA REAL 
%token <str>  CARACTERE SE ENTAO FIMSE ENQUANTO
%token <str>  FACA FIMENQUANTO CHAMADA SENAO
%token <str>  ID_OU_FUNC INTEIRO LITERAL OP_RELACIONAL
%token <str>  OP_ARITMETICO ATRIBUICAO ABRE_PAR FECHA_PAR
%token <str>  VIRGULA PONTO_E_VIRG COMENTARIO FIM_DE_ARQ
%token <str> RNUMERO
%token <str>  NUMERO

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
    tipo ID_OU_FUNC PONTO_E_VIRG {production_print("vars -> tipo ID_OU_FUNC PONTO_E_VIRG"); }
    | tipo ID_OU_FUNC VIRGULA vars_cont {production_print("vars -> tipo ID_OU_FUNC VIRGULA vars_cont");}
    | tipo ID_OU_FUNC ATRIBUICAO atribuido {production_print("vars -> tipo ID_OU_FUNC ATRIBUICAO atribuido"); aux = get_type(sym_table, $2, escopo);}
    | tipo ID_OU_FUNC atribuido {}
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
    | ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo {production_print("codigo -> ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo");
        if(get_type(sym_table, $2, escopo) != "literal") printf("\033[31mErro:%d:%d: 'escreva' espera tipo 'literal' e '%s' é '%s'\n\033[0m", line_num, col_num, $2, get_type(sym_table, $2, escopo));
        error++;
    }
    | ID_OU_FUNC ATRIBUICAO atribuido codigo {production_print("codigo -> ID_OU_FUNC ATRIBUICAO atribuido codigo");aux = get_type(sym_table, $2, escopo);}
    | CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo {production_print("codigo -> CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo");}
    | se_entao codigo {production_print("codigo -> se_entao codigo");}
    | ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo {production_print("codigo -> ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo");}
    | RETORNA ID_OU_FUNC PONTO_E_VIRG codigo {production_print("codigo -> RETORNA ID_OU_FUNC PONTO_E_VIRG codigo");} //criar função para checar tipo da função
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
    LITERAL PONTO_E_VIRG {production_print("atribuido -> LITERAL PONTO_E_VIRG"); checkType(aux, "literal");}
    | NUMERO PONTO_E_VIRG {production_print("atribuido -> NUMERO PONTO_E_VIRG"); checkType(aux, "inteiro");}
    | RNUMERO PONTO_E_VIRG {checkType(aux, "real");}
    | ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG");
        error++; 
        printf("\033[31mError:%d:%d: Operador não pode ser literal: %s: 'literal'\033[0m\n", line_num, col_num, $3);
    }
    | ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG");
        if(checkType(aux, mathCheck($1, "inteiro", $2)) == 0) update_value(sym_table, aux, escopo, get_value(sym_table, $1, escopo));
    }
    | ID_OU_FUNC OP_ARITMETICO RNUMERO PONTO_E_VIRG {
        if(checkType(aux, mathCheck($1, "real", $2)) == 0) update_value(sym_table, aux, escopo, get_value(sym_table, $1, escopo));
    }
    | ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG {production_print("atribuido -> ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG");
        if(checkType(aux, idsMathCheck($1, $3, $2)) == 0) update_value(sym_table, aux, escopo, get_value(sym_table, $1, escopo));
    }
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
    ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC {production_print("cond -> ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC"); idsCheckType($1, $3);}
    | ID_OU_FUNC OP_RELACIONAL NUMERO {production_print("cond -> ID_OU_FUNC OP_RELACIONAL NUMERO"); checkType($1, "inteiro");}
    | ID_OU_FUNC OP_RELACIONAL RNUMERO {checkType($1, "real");}
    | ID_OU_FUNC OP_RELACIONAL LITERAL {production_print("cond -> ID_OU_FUNC OP_RELACIONAL LITERAL"); checkType($1, "literal");}
    | NUMERO OP_RELACIONAL ID_OU_FUNC {production_print("cond -> NUMERO OP_RELACIONAL ID_OU_FUNC"); checkType($3, "inteiro");}
    | NUMERO OP_RELACIONAL NUMERO {production_print("cond -> NUMERO OP_RELACIONAL NUMERO");}
    | NUMERO OP_RELACIONAL RNUMERO {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'inteiro', mas '%s' é: 'real'\n", line_num, col_num, $1, $3);}
    | NUMERO OP_RELACIONAL LITERAL {production_print("cond -> NUMERO OP_RELACIONAL LITERAL");error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'inteiro', mas '%s' é: 'literal'\n", line_num, col_num, $1, $3);}
    | RNUMERO OP_RELACIONAL ID_OU_FUNC {checkType($3, "real");}
    | RNUMERO OP_RELACIONAL NUMERO {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'real', mas '%s' é: 'inteiro'\n", line_num, col_num, $1, $3);}
    | RNUMERO OP_RELACIONAL RNUMERO {}
    | RNUMERO OP_RELACIONAL LITERAL {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'real', mas '%s' é: 'literal'\n", line_num, col_num, $1, $3);}
    | LITERAL OP_RELACIONAL ID_OU_FUNC {production_print("cond -> LITERAL OP_RELACIONAL ID_OU_FUNC");checkType($3, "literal");}
    | LITERAL OP_RELACIONAL NUMERO {production_print("cond -> LITERAL OP_RELACIONAL NUMERO"); error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'literal', mas '%s' é: 'inteiro'\n", line_num, col_num, $1, $3);}
    | LITERAL OP_RELACIONAL RNUMERO {error++;printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: 'literal', mas '%s' é: 'real'\n", line_num, col_num, $1, $3);}
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

int checkType( char *name, char *encounteredType) {
    char *c = get_type(sym_table, name, escopo);
    if(strcmp(c,"error") == 0){
        error++;
        return 1;
    }
    if(strcmp(c,"Não encontrado") == 0){
        error++;
        printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, name);
        return 1;
    }
    if(strcmp(c, encounteredType) == 0){
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com operador\n", line_num, col_num, name);
        }
        return 0;
    }else{
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s', mas encontrado: '%s'\033[0m\n", line_num, col_num, name, c, encounteredType);
        return 2;
    }
}

int idsCheckType( char *name, char *name2) {
    char *c = get_type(sym_table, name, escopo);
    char *t = get_type(sym_table, name2, escopo);
    if(strcmp(c,"Não encontrado") == 0 || strcmp(t,"Não encontrado") == 0){
        if(strcmp(c,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, name);
        }
        if(strcmp(t,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, name2);
        }
        return 1;
    }
    if(strcmp(c, t) == 0){
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s\033", line_num, col_num, name, name2);
        }
        return 0;
    }else{
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s', mas '%s' possui tipo: '%s'\033[0m\n", line_num, col_num, name, c, name2, t);
        return 2;
    }
}
char* idsMathCheck(char *ar1, char *ar2, char *op){
    char *c = get_type(sym_table, ar1, escopo);
    char *t = get_type(sym_table, ar2, escopo);
    char *c1 = get_value(sym_table, ar1, escopo);
    char *t1 = get_value(sym_table, ar2, escopo);
    if(strcmp(c,"Não encontrado") == 0 || strcmp(t,"Não encontrado") == 0){
        if(strcmp(c,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, ar1);
        }
        if(strcmp(t,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, ar2);
        }
        return "error";
    }
    if(strcmp(c, t) != 0){
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s' para realizar a operação: '%s', mas '%s' possui tipo: '%s'\033[0m\n", line_num, col_num, ar1, c, op, ar2, t);
        return "error";
    }else{
        if(strcmp(op,"/") == 0){
            if(strcmp(t1,"0") == 0 || strcmp(t1,"0.0") == 0 ){
                error++;
                printf("\033[31mErro:%d:%d: Divisão por 0 detectada em: %s/%s\033[0m\n", line_num, col_num, ar1, ar2);
                return "error";
            }
            if(c1 == "NULL" || t1 == "NULL"){
                if(c1 == "NULL"){
                    error++;
                    printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
                    return "error";
                }
                if(t1 == "NULL"){
                    error++;
                    printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, t);
                    return "error";
                }
            }
        }
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s e operação aritimética viável\n", line_num, col_num, ar1, ar2);
        }
        return c;
    }
}

char* idMathCheck(char *ar1, char *ar2, char *op, char *ar2type){
    char *c = get_type(sym_table, ar1, escopo);
    char *c1 = get_value(sym_table, ar1, escopo);
    if(strcmp(c,"Não encontrado") == 0){
        if(strcmp(c,"Não encontrado") == 0){
            error++;
            printf("\033[31mErro:%d:%d: Identificador '%s' não declarado\033[0m\n", line_num, col_num, ar1);
        }
        return "error";
    }
    if(strcmp(c, ar2type) != 0){
        error++;
        printf("\033[31mErro:%d:%d: Tipo de '%s' esperado: '%s' para realizar a operação: '%s', mas '%s' possui tipo: '%s'\033[0m\n", line_num, col_num, ar1, c, op, ar2, ar2type);
        return "error";
    }else{
        if(strcmp(op,"/") == 0){
            if(strcmp(ar2,"0") == 0 || strcmp(ar2,"0.0") == 0 ){
                error++;
                printf("\033[31mErro:%d:%d: Divisão por 0 detectada em: %s/%s\033[0m\n", line_num, col_num, ar1, ar2);
                return "error";
            }
            if(strcmp(ar2,"NULL") == 0){                
                error++;
                printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
                return "error";
            }
        }
        if(verbose == 1){
            printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s e operação aritimética viável\n", line_num, col_num, ar1, ar2);
        }
        return c;
    }
}

char* mathCheck(char *ar1, char *ar2, char *op){
    char *c = get_type(sym_table, ar1, escopo);
    char *c1 = get_value(sym_table, ar1, escopo);
    if(strcmp(op,"/") == 0){
        if(strcmp(ar2,"0") == 0 || strcmp(ar2,"0.0") == 0 ){
            error++;
            printf("\033[31mErro:%d:%d: Divisão por 0 detectada em: %s/%s\033[0m\n", line_num, col_num, ar1, ar2);
            return "error";
        }
        if(strcmp(c1 ,"NULL") == 0){                
            error++;
            printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
            return "error";
        }
        if(strcmp(ar2,"NULL") == 0){                
            error++;
            printf("\033[31mErro:%d:%d: %s é NULL\033[0m\n", line_num, col_num, c);
            return "error";
        }
    }
    if(verbose == 1){
        printf("Na linha %d, coluna %d: Tipo de %s compatível com tipo de %s e operação aritimética viável\n", line_num, col_num, ar1, ar2);
    }
    return c;
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
            printf("\033[31mFile not found!\033[0m\n");
            exit(1);
        }
    }
    out=yyparse();

    if(error == 0){
        printf("Compilado com sucesso!\n");
    }else{
        printf("\033[31mCompilador falhou!\033[0m\n");
    }
    

    if(!out) {// yyparse == 0 - parsing completed
        fclose(yyin);
    }
    else { //yyparse()==1 - could not complete parsing
        fclose(yyin); // close input file
    }

    free_symbol_table(sym_table);

    return 0;
}
