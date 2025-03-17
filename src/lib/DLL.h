/** \file DLL.h
* \brief Funções e estruturas de dados relativos ao modulo DLL, e seus comentários
*
* Está inicializada a estrutura de um nó e as funções de inicialização da lista ligada,
* de inserção e remoção de elemntos, de verificação de dados de um elemento, tal como dos
* dados de um proximo/anterior elemento 
* As implementações feitas foram baseadas em exemplos do chatGPT e do site https://www.programiz.com/dsa/doubly-linked-list
*
* \author Guilherme Santos, 103143
* \date 15/03/2025
*/

#include <stdio.h>
#include <stdint.h>

#define MAX_ELEMENTS 4
#define ELEMENT_SIZE 50

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

/** \brief Inicialização do modulo DLL
*
* Inicialização do modulo, com alocação estática. Para a função são passados como 
* argumentos um ponteiro da estrutura da DLL, que contém o número máximo de elementos e o
* primeiro e último nó
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \date 15/03/2025
*/
void MyDLLInit(DLL *dll);

/** \brief Adição de dados a um elemento da linked list
*
* Adição de um elemento à DLL. É passado como argumento uma key, que indica a
* posição da DLL a ser inserido. E a função retorna um valor a indicar se foi possível ou
* não fazer a adição pretendida. Fazendo o retorno de 0 se foi bem sucedido ou -1 se houve
* algum erro.
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \param[in] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder.
* \param[in] data[], dados a inserir no n
* \return 0 ou -1
* \date 15/03/2025
*/
int MyDLLInsert(DLL *dll, uint16_t key, uint8_t data[]);


/** \brief Remoção dos dados de um elemento da linked list
*
* A função remove um elemento da DLL. O elemento a remover é identificado por uma key
* passada como argumento para a função. A função retorna um valor consoante o sucesso, ou
* não, remover o elemento com pretendido. Fazendo o retorno de 0 se foi bem sucedido ou -1
* se houve algum erro.
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \param[in] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return 0 ou -1 
* \date 15/03/2025
*/
int MyDLLRemove(DLL *dll,uint16_t key);

/** \brief Função para verificar os dados relativos a um elemento
*
* Acesso a um elemento da DLL através de uma key. Fazendo o retorno do dados,
* identificados pela sua key, ou um erro caso não existam dados. Fazendo o retorno de 0 se
* foi bem sucedido ou -1 se houve algum erro.
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \param[in] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return 0 ou -1 
* \date 15/03/2025
*/
int MyDLLFind(DLL *dll,uint16_t key);

/** \brief Função para verificar os dados relativos de um próximo elemento
*
* Acesso ao próximo elemento da DLL, relativo à key. Fazendo o retorno do dados,
* identificados pela sua key, ou um erro caso não existam dados. Fazendo o retorno de 0 se
* foi bem sucedido ou -1 se houve algum erro.
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \param[in] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return 0 ou -1
* \date 15/03/2025
*/
int MyDLLFindNext(DLL *dll,uint16_t key);

/** \brief Função para verificar os dados relativos de um elemento anterior
*
* Acesso ao elemento anterior da DLL, relativo à key. Fazendo o retorno do dados,
* identificados pela sua key, ou um erro caso não existam dados. Fazendo o retorno de 0 se
* foi bem sucedido ou -1 se houve algum erro.
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \param[in] key, unsiged int 16, argumento que identifica o elemento da DLL a aceder
* \return 0 ou -1
* \date 15/03/2025
*/
int MyDLLFindPrevious(DLL *dll,uint16_t key);

/** \brief Função para limpar a DLL
*
* A função faz a limpeza dos dados de todos os os ns da lista ligada, sendo a ser
* passada para a função o ponteiro com a lista em questão
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \date 17/03/2025
*/
void MyDLLClear(DLL *dll) ;

/** \brief Função para mostrar os dados de todos os nós
*
* A função irá percorrer todos os ns da lista, passada como argumento, e irá mostrar os
* dados de todos os nós da lista.
* 
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \return Dados do nó
* \date 17/03/2025
*/
uint8_t* MyDLLShowElements(DLL *dll);

/** \brief Função para fazer a ordenação ascendente dos dados da lista
*
* A função ordena os dados na lista, por ordem ascendente, ficando os dados de menor
* key nos primeiros nós e os de maior nos últimos   
*
* \author Francisco Bastos, 103359
* \param[in] *dll, ponteiro da estrutura da DLL
* \date 17/03/2025
*/
void MyDLLSortAscending(DLL *dll);
