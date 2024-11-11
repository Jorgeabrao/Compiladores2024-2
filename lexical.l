%{
#include "hashtbl.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

int line_num = 1;
int col_num = 1;
char *escopo = "global";
int categoria = 0;

void update_position(const char *text);
struct hashMap *sym_table;

%}

digit       [0-9]
letter      [A-Za-z]
symbol      [~`!@#$%^&*()_\-+=\\/\[\]|'?><.,:=]
whitespace  [ \t\r]

%%
"funcao" { 
    categoria = 1; 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return FUNCAO; 
}
"fimfuncao" { 
    update_position(yytext); 
    yylval.str = strdup(yytext); 
    escopo = "global";
    return FIMFUNCAO; 
}
"chama" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return CHAMA; 
}
"retorna" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return RETORNA; 
}
"tipo" { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return TIPO; 
}
"args" { 
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
        insert_symbol(sym_table, yytext, "funcao", escopo);
        escopo = strdup(yytext);
    } else if(categoria == 2){
        insert_symbol(sym_table, yytext, "chamada", escopo);
    } else if(categoria == 3){
        insert_symbol(sym_table, yytext, "inteiro", escopo);
    } else if(categoria == 4){
        insert_symbol(sym_table, yytext, "real", escopo);
    } else if(categoria == 5){
        insert_symbol(sym_table, yytext, "literal", escopo);
    } else {
        insert_symbol(sym_table, yytext, "void", escopo);
    }
    return ID_OU_FUNC;
}
{digit}+(\.{digit}+)?(E|e+|-?{digit}+)? { 
    yylval.str = strdup(yytext); 
    update_position(yytext);
    return NUMERO;
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
