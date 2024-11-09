%{
#include "hashtbl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_num = 1;
int col_num = 1;
char v;
char *escopo = "global";
int categoria = 0;

void update_position(const char *text);
struct hashMap *sym_table;

%}

digit       [0-9]
letter      [A-Za-z]
symbol      [~`!@#$%^&*()_\-+=\\/\[\]|'?><.,:=]
whitespace  [ \t\r\n]

%%

"funcao"          {
 categoria = 1;
 update_position(yytext); 
 printf("Token: FUNCAO, LEXEMA: %s\n", yytext); 
}
"fimfuncao"       { 
    update_position(yytext); 
    printf("Token: FIMFUNCAO, LEXEMA: %s\n", yytext);
    escopo = "global";
}
"chama"           { update_position(yytext); printf("Token: CHAMA, LEXEMA: %s\n", yytext); }
"retorna"         { update_position(yytext); printf("Token: RETORNA, LEXEMA: %s\n", yytext); }
"tipo"            { update_position(yytext); printf("Token: TIPO, LEXEMA: %s\n", yytext); }
"args"            { update_position(yytext); printf("Token: ARGS, LEXEMA: %s\n", yytext); }
"fimargs"         { update_position(yytext); printf("Token: FIMARGS, LEXEMA: %s\n", yytext); }
"escreva"         { update_position(yytext); printf("Token: ESCREVA, LEXEMA: %s\n", yytext); }
"inteiro"         { categoria = 3; update_position(yytext); printf("Token: INTEIRO, LEXEMA: %s\n", yytext); }
"real"            { categoria = 4; update_position(yytext); printf("Token: REAL, LEXEMA: %s\n", yytext); }
"caractere"       { categoria = 5; update_position(yytext); printf("Token: CARACTERE, LEXEMA: %s\n", yytext); }
"se"              { update_position(yytext); printf("Token: SE, LEXEMA: %s\n", yytext); }
"entao"           { update_position(yytext); printf("Token: ENTAO, LEXEMA: %s\n", yytext); }
"fimse"           { update_position(yytext); printf("Token: FIMSE, LEXEMA: %s\n", yytext); }
"enquanto"        { update_position(yytext); printf("Token: ENQUANTO, LEXEMA: %s\n", yytext); }
"faca"            { update_position(yytext); printf("Token: FACA, LEXEMA: %s\n", yytext); }
"fimenquanto"     { update_position(yytext); printf("Token: FIMENQUANTO, LEXEMA: %s\n", yytext); }
"@"               {
 categoria = 2;
 update_position(yytext); 
 printf("Token: CHAMADA, LEXEMA: %s\n", yytext); 
}

{letter}({letter}|{digit}|_)*   { 
 update_position(yytext);
 printf("Token: ID_OU_FUNC, LEXEMA: %s\n", yytext);
 if(categoria == 1){
    insert_symbol(sym_table, yytext, "funcao", escopo);
    escopo = strdup(yytext);
 }else if(categoria == 2){
    insert_symbol(sym_table, yytext, "chamada", escopo);
 }else if(categoria == 3){
    insert_symbol(sym_table, yytext, "inteiro", escopo);
 }else if(categoria == 4){
    insert_symbol(sym_table, yytext, "real", escopo);
 }else if(categoria == 5){
    insert_symbol(sym_table, yytext, "caractere", escopo);
 }else{
    insert_symbol(sym_table, yytext, "void", escopo);
 }
}
{digit}+(\.{digit}+)?(E|e+|-?{digit}+)? {
 update_position(yytext);
 printf("Token: NUMERO, LEXEMA: %s\n", yytext);
}
\"({letter}|{digit}|{symbol}|{whitespace}|;)*\"  { 
 update_position(yytext);
 printf("Token: LITERAL, LEXEMA: %s\n", yytext); 
}
"<"|">"|"=="|"<="|">="|"<>"  { update_position(yytext); printf("Token: OP_RELACIONAL, LEXEMA: %s\n", yytext); }
"+"|"-"|"*"|"/"  { update_position(yytext); printf("Token: OP_ARITMETICO, LEXEMA: %s\n", yytext); }
"="  { update_position(yytext); printf("Token: ATRIBUICAO, LEXEMA: %s\n", yytext); }
"\(" { update_position(yytext); printf("Token: ABRE_PAR, LEXEMA: %s\n", yytext); }
"\)" { update_position(yytext); printf("Token: FECHA_PAR, LEXEMA: %s\n", yytext); }
","  { update_position(yytext); printf("Token: VIRGULA, LEXEMA: %s\n", yytext); }
";"  { categoria = 0; update_position(yytext); printf("Token: PONTO_E_VIRG, LEXEMA: %s\n", yytext); }
{whitespace}+ { update_position(yytext); if(v == 'y' || v == 'Y')printf("Token: VAZIO\n"); }
"{"({letter}|{digit}|{symbol}|{whitespace}|;)*"}" { update_position(yytext); printf("Token: COMENTARIO, LEXEMA: %s\n", yytext);  }
<<EOF>> { printf("Token: FIM_DE_ARQ\n"); return 0; }
.  { printf("Token: Invalid Token, LEXEMA: %s\n", yytext); }

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

int main(int argc, char **argv) {
    sym_table = (struct hashMap*) malloc(sizeof(struct hashMap));
    initializeHashMap(sym_table);

    printf("Deseja imprimir os tokens VAZIO?\n(y/n):");
    scanf("%c", &v);

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    yylex();
    printf("\n");
    print_symbol_table(sym_table);
    free_symbol_table(sym_table);

    return 0;
}
