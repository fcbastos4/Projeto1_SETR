/** \file DLL.h
* \brief Funções e estruturas de dados relativos ao modulo DLL, e seus comentários.
*
* Está inicializada a estrutura de um nodo e as funções de inicialização da lista ligada,
* de inserção e remoção de elemntos, de verificação de dados de um elemento, tal como dos
* dados de um proximo/anterior elemento 
*
* \author Guilherme Santos, 103143
* \date 15/03/2025
* \bug Sem bugs encontrdaos
*/

#include <stdio.h>

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

/* \brief Inicialização do modulo DLL
*
* Inicialização do modulo, com alocação estática. Para a função são passados como 
* argumentos o número máximo de elementos e o tamanho de cada argumento
*
* \author Francisco Bastos, 103359
* \param[ne,es] ne, argumento que indica o número de elementos da DLL 
* \param[ne,es] es, argumento que indica o tamanho dos elementos da DLL
* \date 15/03/2025
*/
void MyDLLInit(DLL *dll);

/* \brief Adição de dados a um elemento da linked list
*
* Adição de um elemento à DLL ... . É passado como argumento uma key, que indica a
* posição da DLL a ser inserido. E a função retorna um valor a indicar se foi possível ou
* não fazer a adição pretendida.
*
* \author Francisco Bastos, 103359
* \param[key] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder.
* \return Retorno do valor 0 ou 1
* \date 15/03/2025
*/
int MyDLLInsert(DLL *dll, uint16_t key, uint8_t data[]);


/* \brief Remoção dos dados de um elemento da linked list
*
* A função remove um elemento da DLL. O elemento a remover é identificado por uma key
* passada como argumento para a função. A função retorna um valor consoante o sucesso, ou
* não, remover o elemento com pretendido.
*
* \author Francisco Bastos, 103359
* \param[key] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return Retorno do valor 0 ou 1 
* \date 15/03/2025
*/
int MyDLLRemove(DLL *dll,uint16_t key);

/* \brief Função para verificar os dados relativos a um elemento
*
* Acesso a um elemento da DLL através de uma key. Fazendo o retorno do dados,
* identificados pela sua key, ou um erro caso não existam dados.
*
* \author Francisco Bastos, 103359
* \param[key] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return Retorno dos dados relativos ao elemento ou 0 
* \date 15/03/2025
*/
int MyDLLFind(DLL *dll,uint16_t key);

/* \brief Função para verificar os dados relativos de um próximo elemento
*
* Acesso ao próximo elemento da DLL, relativo à key. Fazendo o retorno do dados,
* identificados pela sua key, ou um erro caso não existam dados.
*
* \author Francisco Bastos, 103359
* \param[key] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return Retorno dos dados relativos ao elemento ou 0
* \date 15/03/2025
*/
int MyDLLFindNext(DLL *dll,uint16_t key);

/* \brief Função para verificar os dados relativos de um elemento anterior
*
* Acesso ao elemento anterior da DLL, relativo à key. Fazendo o retorno do dados,
* identificados pela sua key, ou um erro caso não existam dados.
*
* \author Francisco Bastos, 103359
* \param[key] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return Retorno dos dados relativos ao elemento ou 0
* \date 15/03/2025
*/
int MyDLLFindPrevious(DLL *dll,uint16_t key);









