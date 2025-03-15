#include <stdint.h>

#define MAX_ELEMENTS 100
#define ELEMENT_SIZE 32

// Estrutura do nó da DLL
typedef struct DLLNode {
    uint16_t key; // Unique identifier for the node
    uint8_t data[ELEMENT_SIZE]; // Data storage
    struct DLLNode* prev; // Pointer to the previous node
    struct DLLNode* next; // Pointer to the next node
} DLLNode;

// Estrutura da DLL
typedef struct {
    DLLNode nodes[MAX_ELEMENTS];
    DLLNode* head;
    DLLNode* tail;
    int count;
} DLL;

/* Inicialização do modulo, com alocação estática. Para a função são passados como argumentos o número máximo de elementos e o tamanho de cada argumento.*/
void MyDLLInit(DLL *dll);

/* Adição de um elemento à DLL ... . É passado como argumento uma key, que indica a posição da DLL a ser inserido. E a função retorna um valor a indicar se foi possível ou  não fazer a adição pretendida.*/
int MyDLLInsert(DLL *dll, uint16_t key, uint8_t data[]);


/* A função remove um elemento da DLL. O elemento a remover é identificado por uma key passada como argumento para a função. A função retorna um valor consoante o sucesso, ou não, remover o elemento com pretendido.*/
int MyDLLRemove(DLL *dll,uint16_t key);

/* Função para verificar os dados relativos a um elemento. Fazendo o retorno do dados, identificados pela sua key, ou um erro caso não existam dados.*/
int MyDLLFind(DLL *dll,uint16_t key);


int MyDLLFindNext(DLL *dll,uint16_t key);


int MyDLLFindPrevious(DLL *dll,uint16_t key);

