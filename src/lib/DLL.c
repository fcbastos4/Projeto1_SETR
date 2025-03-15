/** \file DLL.c
* \brief Implementação das funções relativas ao modulo DLL.
*
* Neste ficheiro são implementadas as funções referidas no ficheiro DLL.h e que mais tarde
* a usar em projetos que necessitem das funções deste módulo 
*
* \author Guilherme Santos, 103143
* \author Francisco Bastos, 103359
* \date 15/03/2025
* \bug Sem bugs encontrdaos
*/
#include "DLL.h"

#include <stdio.h>
#include <string.h>



void MyDLLInit(DLL *dll) {
    dll->head = NULL;
    dll->tail = NULL;
    dll->count = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        dll->nodes[i].key = 0;
        dll->nodes[i].prev = NULL;
        dll->nodes[i].next = NULL;
    }
}

int MyDLLInsert(DLL *dll, uint16_t key, uint8_t data[]) {
    if (dll->count >= MAX_ELEMENTS) return -1;

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (dll->nodes[i].key == 0) {
            dll->nodes[i].key = key;
            strncpy((char*)dll->nodes[i].data, (char*)data, ELEMENT_SIZE - 1);
            dll->nodes[i].data[ELEMENT_SIZE - 1] = '\0';
            dll->nodes[i].prev = dll->tail;
            dll->nodes[i].next = NULL;

            if (dll->tail) {
                dll->tail->next = &dll->nodes[i];
            }
            dll->tail = &dll->nodes[i];

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


