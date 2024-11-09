#include "hashtbl.h"

// Função hash que usa nome e escopo para gerar o índice
int hashFunction(struct hashMap* mp, char* name, char* scope)
{
    int bucketIndex;
    int sum = 0, factor = 31;

    // Concatena o nome e o escopo para criar uma única string
    char* combined = (char*)malloc(strlen(name) + strlen(scope) + 1);
    strcpy(combined, name);
    strcat(combined, scope);

    // Calcula o valor do hash baseado na string concatenada (nome + escopo)
    for (int i = 0; i < strlen(combined); i++) {
        sum = ((sum % mp->capacity) + (((int)combined[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }

    bucketIndex = sum;  // Define o índice do bucket com base no valor do hash

    // Libera a memória alocada para a string combinada
    free(combined);

    return bucketIndex;
}

// Função para inicializar um nó (símbolo)
void setNode(struct node* node, char* name, char* type, char* scope)
{
    node->name = strdup(name);  // Copia o nome do identificador
    node->type = strdup(type);  // Copia o tipo do identificador
    node->scope = strdup(scope);  // Copia o escopo do identificador
    node->next = NULL;  // Inicializa o próximo nó como NULL
    return;
}

// Inicializar a tabela de símbolos
void initializeHashMap(struct hashMap* mp)
{
    mp->capacity = 100;  // Capacidade inicial da tabela
    mp->numOfElements = 0;  // Número de elementos começa em 0
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);  // Aloca a tabela

    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;  // Inicializa todos os buckets como NULL
    }
}

// Função para inserir um símbolo na tabela de símbolos
void insert_symbol(struct hashMap* mp, char* name, char* type, char* scope)
{
    // Calcula o índice na tabela hash usando nome e escopo
    int bucketIndex = hashFunction(mp, name, scope);

    // Verifica se o símbolo já existe para evitar duplicatas
    struct node* current = mp->arr[bucketIndex];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && strcmp(current->scope, scope) == 0) {
            // Se o símbolo já existir no mesmo escopo, não insere duplicata
            return;
        }
        current = current->next;
    }

    // Cria um novo nó para o símbolo
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, name, type, scope);

    // Adiciona o novo nó na lista encadeada do bucket correspondente
    newNode->next = mp->arr[bucketIndex];
    mp->arr[bucketIndex] = newNode;

    mp->numOfElements++;
}

// Função para buscar um símbolo na tabela de símbolos
struct node* lookup_symbol(struct hashMap* mp, char* name, char* scope)
{
    // Calcula o índice na tabela hash usando nome e escopo
    int bucketIndex = hashFunction(mp, name, scope);
    struct node* bucketHead = mp->arr[bucketIndex];

    // Percorre a lista encadeada no bucket
    while (bucketHead != NULL) {
        if (strcmp(bucketHead->name, name) == 0 && strcmp(bucketHead->scope, scope) == 0) {
            return bucketHead;  // Retorna o símbolo se for encontrado
        }
        bucketHead = bucketHead->next;
    }
    return NULL;  // Retorna NULL se o símbolo não for encontrado
}

// Função para deletar um símbolo da tabela de símbolos
void delete_symbol(struct hashMap* mp, char* name, char* scope)
{
    // Calcula o índice na tabela hash usando nome e escopo
    int bucketIndex = hashFunction(mp, name, scope);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(name, currNode->name) == 0 && strcmp(currNode->scope, scope) == 0) {
            // Se o símbolo for encontrado, remove-o da lista
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }

            free(currNode->name);
            free(currNode->type);
            free(currNode->scope);
            free(currNode);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Função para exibir a tabela de símbolos (para debug)
void print_symbol_table(struct hashMap* mp)
{
    printf("Tabela de Símbolos:\n");
    for (int i = 0; i < mp->capacity; i++) {
        struct node* current = mp->arr[i];
        if (current != NULL) {
            while (current != NULL) {
                printf("  Nome: %s, Categoria: %s, Escopo: %s\n", current->name, current->type, current->scope);
                current = current->next;
            }
        }
    }
}

// Função para liberar a memória da tabela de símbolos
void free_symbol_table(struct hashMap* mp)
{
    for (int i = 0; i < mp->capacity; i++) {
        struct node* current = mp->arr[i];
        while (current != NULL) {
            struct node* temp = current;
            current = current->next;
            free(temp->name);
            free(temp->type);
            free(temp->scope);
            free(temp);
        }
    }
    free(mp->arr);
    free(mp);
}