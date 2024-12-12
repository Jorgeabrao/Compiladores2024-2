#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de nó da tabela de símbolos (node)
struct node {
    char* name;   // Nome do identificador (variável, função, etc.)
    char* type;   // Tipo do identificador (variável, função, número, etc.)
    char* scope;  // Escopo do identificador (global, local, etc.)
    char* value;  // Valor associado ao identificador
    struct node* next;  // Ponteiro para o próximo nó (para lidar com colisões)
};

// Função para inicializar um nó (símbolo)
void setNode(struct node* node, char* name, char* type, char* scope);

// Estrutura da tabela de símbolos (hashMap)
struct hashMap {
    int numOfElements, capacity;  // Número de elementos e capacidade da tabela
    struct node** arr;  // Array de listas encadeadas (ponteiros para nodes)
};

// Inicializar a tabela de símbolos
void initializeHashMap(struct hashMap* mp);

// Função hash para calcular o índice da tabela usando nome e escopo
int hashFunction(struct hashMap* mp, char* name, char* scope);

// Inserir um símbolo na tabela de símbolos
void insert_symbol(struct hashMap* mp, char* name, char* type, char* scope);

// Buscar um símbolo na tabela de símbolos
struct node* lookup_symbol(struct hashMap* mp, char* name, char* scope);

// Deletar um símbolo da tabela de símbolos
void delete_symbol(struct hashMap* mp, char* name, char* scope);

// Imprimir todos os símbolos da tabela
void print_symbol_table(struct hashMap* mp);

// Liberar memória da tabela de símbolos
void free_symbol_table(struct hashMap* mp);

char* get_type(struct hashMap* mp, char* name, char* scope);

void update_value(struct hashMap* mp, char* name, char* scope, char* newValue);

char* get_value(struct hashMap* mp, char* name, char* scope);

void update_type(struct hashMap* mp, char* name, char* scope, char* newValue);
#endif
