%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtbl.h"
#include "hashtbl.c"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);
extern struct hashMap *sym_table;

int verb = 0; //1 to activate verbose mode
int i = 0;
int error = 0;
extern int line_num;
extern int col_num;

%}

%union {
    char *str;
    int num;
}

%token <str>  FUNCAO FIMFUNCAO CHAMA RETORNA TIPO
%token <str>  ARGS FIMARGS ESCREVA INTEIRO REAL 
%token <str>  CARACTERE SE ENTAO FIMSE ENQUANTO
%token <str>  FACA FIMENQUANTO CHAMADA SENAO
%token <str>  ID_OU_FUNC NUMERO LITERAL OP_RELACIONAL
%token <str>  OP_ARITMETICO ATRIBUICAO ABRE_PAR FECHA_PAR
%token <str>  VIRGULA PONTO_E_VIRG COMENTARIO FIM_DE_ARQ

%verbose
%start programa

%%
programa:
    FUNCAO assinatura {print_production("programa -> FUNCAO assinatura");}
    ;

assinatura:
    nome_funcao args {print_production("assinatura -> nome_funcao args");}
    | nome_funcao TIPO tipo_funcao args {print_production("assinatura -> nome_funcao TIPO tipo_funcao args");}
    ;

tipo_funcao:
    CARACTERE {print_production("tipo_funcao -> CARACTERE");}
    | INTEIRO {print_production("tipo_funcao -> INTEIRO");}
    | REAL {print_production("tipo_funcao -> REAL");}
    ;

args:
    ARGS lista_vars FIMARGS codigo {print_production("args -> ARGS lista_vars FIMARGS codigo");}
    | codigo {print_production("args -> codigo");}
    ;

lista_vars:
    vars {print_production("lista_vars -> vars");}
    | lista_vars vars {print_production("lista_vars -> lista_vars vars");}
    ;

vars:
    tipo ID_OU_FUNC PONTO_E_VIRG {print_production("vars -> tipo ID_OU_FUNC PONTO_E_VIRG");}
    | tipo ID_OU_FUNC VIRGULA vars_cont {print_production("vars -> tipo ID_OU_FUNC VIRGULA vars_cont");}
    | tipo ID_OU_FUNC ATRIBUICAO atribuido {print_production("vars -> tipo ID_OU_FUNC ATRIBUICAO atribuido");}
    ;

vars_cont:
    ID_OU_FUNC VIRGULA vars_cont {print_production("vars_cont -> ID_OU_FUNC VIRGULA vars_cont");}
    | ID_OU_FUNC PONTO_E_VIRG {print_production("vars_cont -> ID_OU_FUNC PONTO_E_VIRG");}
    ;

tipo:
    CARACTERE {print_production("tipo -> CARACTERE");}
    | INTEIRO {print_production("tipo -> INTEIRO");}
    | REAL {print_production("tipo -> REAL");}
    ;

codigo:
    vars codigo {print_production("codigo -> vars codigo");}
    | ESCREVA LITERAL PONTO_E_VIRG codigo {print_production("codigo -> ESCREVA LITERAL PONTO_E_VIRG codigo");}
    | ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo {print_production("codigo -> ESCREVA ID_OU_FUNC PONTO_E_VIRG codigo");}
    | ID_OU_FUNC ATRIBUICAO atribuido codigo {print_production("codigo -> ID_OU_FUNC ATRIBUICAO atribuido codigo");}
    | CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo {print_production("codigo -> CHAMA CHAMADA ID_OU_FUNC PONTO_E_VIRG codigo");}
    | se_entao codigo {print_production("codigo -> se_entao codigo");}
    | ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo {print_production("codigo -> ENQUANTO ABRE_PAR cond FECHA_PAR FACA codigo FIMENQUANTO codigo");}
    | RETORNA ID_OU_FUNC PONTO_E_VIRG codigo {print_production("codigo -> RETORNA ID_OU_FUNC PONTO_E_VIRG codigo");}
    | FIMFUNCAO eof {print_production("codigo -> FIMFUNCAO");}
    | FIMFUNCAO programa {print_production("codigo -> FIMFUNCAO");}
    | {print_production("codigo -> epsilon");}
    ;

atribuido:
    LITERAL PONTO_E_VIRG {print_production("atribuido -> LITERAL PONTO_E_VIRG");}
    | NUMERO PONTO_E_VIRG {print_production("atribuido -> NUMERO PONTO_E_VIRG");}
    | ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG {print_production("atribuido -> ID_OU_FUNC OP_ARITMETICO LITERAL PONTO_E_VIRG");}
    | ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG {print_production("atribuido -> ID_OU_FUNC OP_ARITMETICO NUMERO PONTO_E_VIRG");}
    | ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG {print_production("atribuido -> ID_OU_FUNC OP_ARITMETICO ID_OU_FUNC PONTO_E_VIRG");}
    | CHAMA CHAMADA lista_id PONTO_E_VIRG {print_production("atribuido -> CHAMA CHAMADA lista_id PONTO_E_VIRG");}
    ;

lista_id:
    ID_OU_FUNC lista_id {print_production("lista_id -> ID_OU_FUNC lista_id");}
    | {print_production("lista_id -> epsilon");}
    ;

se_entao:
    SE ABRE_PAR cond FECHA_PAR ENTAO codigo senao_op FIMSE {print_production("se_entao -> SE ABRE_PAR cond FECHA_PAR ENTAO codigo senao_op FIMSE");}
    ;

senao_op:
    SENAO codigo {print_production("senao_op -> SENAO codigo");}
    | {print_production("senao_op -> epsilon");}
    ;

cond:
    ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC {print_production("cond -> ID_OU_FUNC OP_RELACIONAL ID_OU_FUNC");}
    | ID_OU_FUNC OP_RELACIONAL NUMERO {print_production("cond -> ID_OU_FUNC OP_RELACIONAL NUMERO");}
    | ID_OU_FUNC OP_RELACIONAL LITERAL {print_production("cond -> ID_OU_FUNC OP_RELACIONAL LITERAL");}
    | NUMERO OP_RELACIONAL ID_OU_FUNC {print_production("cond -> NUMERO OP_RELACIONAL ID_OU_FUNC");}
    | NUMERO OP_RELACIONAL NUMERO {print_production("cond -> NUMERO OP_RELACIONAL NUMERO");}
    | NUMERO OP_RELACIONAL LITERAL {print_production("cond -> NUMERO OP_RELACIONAL LITERAL");}
    | LITERAL OP_RELACIONAL ID_OU_FUNC {print_production("cond -> LITERAL OP_RELACIONAL ID_OU_FUNC");}
    | LITERAL OP_RELACIONAL NUMERO {print_production("cond -> LITERAL OP_RELACIONAL NUMERO");}
    | LITERAL OP_RELACIONAL LITERAL {print_production("cond -> LITERAL OP_RELACIONAL LITERAL");}
    ;

nome_funcao:
    ID_OU_FUNC {print_production("nome_funcao -> ID_OU_FUNC");}
    ;

eof:
    FIM_DE_ARQ {return 0;}
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
