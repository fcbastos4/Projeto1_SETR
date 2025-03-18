/** \file DLL.c
* \brief Implementação das funções relativas ao modulo DLL
*
* Neste ficheiro são implementadas as funções referidas no ficheiro DLL.h e que mais tarde
* a usar em projetos que necessitem das funções deste módulo
* As implementações feitas foram baseadas em exemplos do chatGPT e do site https://www.programiz.com/dsa/doubly-linked-list
*
* \author Guilherme Santos, 103143
* \author Francisco Bastos, 103359
* \date 15/03/2025
*/
#include "DLL.h"

#include <stdio.h>
#include <string.h>



void MyDLLInit(DLL *dll) {
    dll->head = NULL;  // Sem elemento inicial
    dll->tail = NULL;  // Sem elemento final
    dll->count = 0;    
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        dll->nodes[i].key = 0;      // Inicialização das key's a 0
        dll->nodes[i].prev = NULL;  // Sem elemento anterior
        dll->nodes[i].next = NULL;  // Sem elemento a seguir
    }
}

int MyDLLInsert(DLL *dll, uint16_t key, uint8_t data[]) {
    // Verificar se a lista já está cheia
    if (dll->count >= MAX_ELEMENTS)
    {
        printf("Erro: A lista já está cheia!\n");
        return -1;
    }
    // Colocar os dados no elemento/nó
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        // Os dados são inseridos no primeiro nó vago
        if (dll->nodes[i].key == 0) {
            dll->nodes[i].key = key;
            memcpy(dll->nodes[i].data, data, ELEMENT_SIZE); 
            dll->nodes[i].data[ELEMENT_SIZE - 1] = '\0';
            dll->nodes[i].prev = dll->tail;
            dll->nodes[i].next = NULL;
            
            //Atualização do elemento final usado 
            if (dll->tail) {
                dll->tail->next = &dll->nodes[i];
            }
            dll->tail = &dll->nodes[i];

            //Atualização do elemento inicial 
            if (!dll->head) {
                dll->head = &dll->nodes[i];
            }

            dll->count++;
            return 0;
        }
    }
    return -1;
}

int MyDLLRemove(DLL *dll, uint16_t key) {
    DLLNode *current = dll->head;
    //Precorrer a lista toda à procura do elemento com a key a remover 
    while (current) {
        if (current->key == key) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                dll->head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                dll->tail = current->prev;
            }

            current->key = 0;
            dll->count--;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

int MyDLLFind(DLL *dll, uint16_t key) {
    DLLNode *current = dll->head;
    //Precorrer a lista toda à procura do elemento
    while (current) {
        if (current->key == key) {
            printf("Elemento encontrado! Key: %hu, Data: %s\n", key, current->data);
            return 0;
        }
        current = current->next;
    }
    printf("Elemento com key %hu não encontrado.\n", key);
    return -1;
}

int MyDLLFindNext(DLL *dll, uint16_t key) {
    DLLNode *current = dll->head;

    // Ciclo para verificar se existe um elemento posterior ao pretendido
    while (current) {
        if (current->key == key) {
            if (current->next) {
                printf("Próximo elemento -> Key: %hu, Data: %s\n", current->next->key, current->next->data);
                return 0;
            } else {
                printf("Não há próximo elemento.\n");
                return -1;
            }
        }
        current = current->next;
    }
    return -1;
}

int MyDLLFindPrevious(DLL *dll, uint16_t key) {
    DLLNode *current = dll->head;

    // Ciclo para verificar se existe um elemento anterior ao pretendido
    while (current) {
        if (current->key == key) {
            if (current->prev) {
                printf("Elemento anterior -> Key: %hu, Data: %s\n", current->prev->key, current->prev->data);
                return 0;
            } else {
                printf("Não há elemento anterior.\n");
                return -1;
            }
        }
        current = current->next;
    }
    return -1;
}

void MyDLLClear(DLL *dll) {

    DLLNode *current = dll->head;

    //Ciclo para percorrer a dll e remover todos os elementos. Todos os nós levam reset
    while (current) {
        DLLNode *next = current->next;
        current->key = 0;
        current->prev = NULL;
        current->next = NULL;
        current = next;
    }

    // Os ponteiros  sáo ajustados e o contador leva reset 
    dll->head = NULL;
    dll->tail = NULL;
    dll->count = 0;
}

uint8_t* MyDLLShowElements(DLL *dll) 
{
    // N=1 para nos prints começar do 1 e não do 0
    int n = 1;
        // Impressáo no terminal do nó e da sua respetiva key e os seus dados 
        DLLNode * current = dll->head;
        printf("Lista: \n");
        while(current != NULL) {
            printf("Node #%d - Key: %d\t Data: %s\n", n++, current->key, current->data);
            current = (DLLNode *)current->next;
        }
    
}

void MyDLLSortAscending(DLL *dll) {

    // Variáveis
    int swapped;
    DLLNode *current;
    DLLNode *last = NULL;       

    // Bubble sort na dll
    do {
        swapped = 0;
        current = dll->head;

        while (current->next != last) {
            if (current->key > current->next->key) {
                // Troca de dados entre os nós
                uint16_t tempKey = current->key;
                uint8_t tempData[ELEMENT_SIZE];
                memcpy(tempData, current->data, ELEMENT_SIZE);

                current->key = current->next->key;
                memcpy(current->data, current->next->data, ELEMENT_SIZE);

                current->next->key = tempKey;
                memcpy(current->next->data, tempData, ELEMENT_SIZE);

                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    printf("A lista foi organizada.\n");
}

