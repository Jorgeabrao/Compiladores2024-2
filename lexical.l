%{
#include "hashtbl.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

int line_num = 1;
int col_num = 1;
char *escopo = "principal";
int categoria = 0;
int categoriaF = 0;
int eof = 0;
int func = 0;
extern int error;

void update_position(const char *text);
struct hashMap *sym_table;

int funcao_tipo(char* t, char* escopoL){
    if(lookup_symbol(sym_table, t, escopoL) == NULL){
        printf("\033[31mErro:%d:%d: '%s' não foi declarado\n\033[0m", line_num, col_num, t);
    }else{
        if(get_type(sym_table, t, escopoL) != get_type(sym_table, escopoL, "principal")){
            printf("\033[31mErro:%d:%d: função '%s' precisa retornar '%s' porem '%s' é '%s'\n\033[0m", line_num, col_num, escopoL, get_type(sym_table, escopoL, "principal"), t, get_type(sym_table, t, escopoL));
        }
    }
}   

%}

digit       [0-9]
letter      [A-Za-z]
symbol      [~`!@#$%^&*()_\-+=\\/\[\]|'?><.,:=]
whitespace  [ \t\r]

%%
"funcao" { 
    func++;
    categoria = 1; 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return FUNCAO; 
}
"fimfuncao" { 
    update_position(yytext); 
    yylval.str = strdup(yytext); 
    escopo = "principal";
    return FIMFUNCAO; 
}
"chama" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return CHAMA; 
}
"retorna" { 
    categoria = 7;
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return RETORNA; 
}
"tipo" {
    categoriaF = 1;
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return TIPO; 
}
"args" { 
    categoria = 6;
    yylval.str = strdup(yytext); 
    update_position(yytext); 
    return ARGS; 
}
"fimargs" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return FIMARGS; 
}
"escreva" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return ESCREVA; 
}
"inteiro" { 
    categoria = 3; 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return INTEIRO; 
}
"real" {
    categoria = 4; 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return REAL; 
}
"caractere" { 
    categoria = 5; 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return CARACTERE; 
}
"se" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return SE; 
}
"entao" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return ENTAO; 
}
"senao" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return SENAO; 
}
"fimse" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return FIMSE; 
}
"enquanto" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return ENQUANTO; 
}
"faca" { 
    yylval.str = strdup(yytext); 
    update_position(yytext); 
    return FACA; 
}
"fimenquanto" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return FIMENQUANTO; 
}
"@" { 
    categoria = 2; 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return CHAMADA; 
}
\n { 
    line_num++; 
    col_num = 1; 
}
{letter}({letter}|{digit}|_)* { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    if(categoria == 1){
        if(lookup_symbol(sym_table, yytext, escopo) != NULL){
            printf("\033[31mErro:%d:%d: Identificador '%s' já declarado em função '%s'\n\033[0m", line_num, col_num, yytext, escopo);
        }else{
            insert_symbol(sym_table, yytext, "funcao", escopo);
        }
        escopo = strdup(yytext);
    } else if(categoria == 2){
        if(lookup_symbol(sym_table, yytext, escopo) == NULL) printf("\033[31mErro:%d:%d: função '%s' não declarada\n\033[0m", line_num, col_num, yytext);
        error++;
    } else if(categoria == 3){
        if(lookup_symbol(sym_table, yytext, escopo) != NULL){
             printf("\033[31mErro:%d:%d: Identificador '%s' já declarado em função '%s'\n\033[0m", line_num, col_num, yytext, escopo);
        }else{
            insert_symbol(sym_table, yytext, "inteiro", escopo);
        }
        if(categoriaF == 1 && escopo != "principal"){
            update_type(sym_table, escopo, "principal", "inteiro");
            categoriaF = 0;
        }
    } else if(categoria == 4){
        if(lookup_symbol(sym_table, yytext, escopo) != NULL){
             printf("\033[31mErro:%d:%d: Identificador '%s' já declarado em função '%s'\n\033[0m", line_num, col_num, yytext, escopo);
        }else{
            insert_symbol(sym_table, yytext, "real", escopo);
        }
        if(categoriaF == 1 && escopo != "principal"){
            update_type(sym_table, escopo, "principal", "real");
            categoriaF = 0;
        }
    } else if(categoria == 5){
        if(lookup_symbol(sym_table, yytext, escopo) != NULL){
             printf("\033[31mErro:%d:%d: Identificador '%s' já declarado em função '%s'\n\033[0m", line_num, col_num, yytext, escopo);
        }else{
            insert_symbol(sym_table, yytext, "literal", escopo);
        }
        if(categoriaF == 1 && escopo != "principal"){
            update_type(sym_table, escopo, "principal", "literal");
            categoriaF = 0;
        }
    }else if(categoria == 6){
        insert_symbol(sym_table, yytext, "arg", escopo);
    }else if(categoria == 7){
        funcao_tipo(yytext, escopo);
    } else {
        insert_symbol(sym_table, yytext, "void", escopo);
    }
    return ID_OU_FUNC;
}
{digit}+ { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return NUMERO;
}
{digit}+(\.{digit}+)?(E|e+|-?{digit}+)? { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return RNUMERO;
}
\"({letter}|{digit}|{symbol}|{whitespace}|;)*\" {
    yylval.str = strdup(yytext); 
    update_position(yytext); 
    return LITERAL; 
}
"<"|">"|"=="|"<="|">="|"<>" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return OP_RELACIONAL;
}
"+"|"-"|"*"|"/" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return OP_ARITMETICO; 
}
"=" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return ATRIBUICAO; 
}
"\(" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return ABRE_PAR; 
}
"\)" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return FECHA_PAR; 
}
"," { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return VIRGULA; 
}
";" { 
    categoria = 0; 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return PONTO_E_VIRG; 
}
{whitespace}+ { 
    update_position(yytext);
}
"{"({letter}|{digit}|{symbol}|{whitespace}|;)*"}" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return COMENTARIO; 
}
<<EOF>> {
    eof = 1;
    return FIM_DE_ARQ; 
}
. { 
    fprintf(stderr, "\033[31mLexical error: Invalid Token, LEXEMA: %s, LINHA: %d, COLUNA: %d\033[0m\n", yytext, line_num, col_num); 
}


%%

void update_position(const char *text) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (text[i] == '\n') {
            line_num++;
            col_num = 1;
        } else {
            col_num++;
        }
    }
}

int yywrap() {}
