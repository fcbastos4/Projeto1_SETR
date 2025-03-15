#include <stdio.h>
#include "DLL.h"

int main() {
    DLL myDLL;
    MyDLLInit(&myDLL);

    int choice;
    uint16_t key;
    uint8_t data[ELEMENT_SIZE];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Encontrar elemento\n");
        printf("4. Encontrar próximo elemento\n");
        printf("5. Encontrar elemento anterior\n");
        printf("6. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a chave: ");
                scanf("%hu", &key);
                printf("Digite os dados: ");
                scanf("%s", data);
                if (MyDLLInsert(&myDLL, key, data) == 0) {
                    printf("Elemento inserido!\n");
                } else {
                    printf("Falha ao inserir!\n");
                }
                break;

            case 2:
                printf("Digite a chave a remover: ");
                scanf("%hu", &key);
                if (MyDLLRemove(&myDLL, key) == 0) {
                    printf("Elemento removido!\n");
                } else {
                    printf("Elemento não encontrado!\n");
                }
                break;

            case 3:
                printf("Digite a chave para encontrar: ");
                scanf("%hu", &key);
                MyDLLFind(&myDLL, key);
                break;

            case 4:
                printf("Digite a chave para encontrar o próximo: ");
                scanf("%hu", &key);
                MyDLLFindNext(&myDLL, key);
                break;

            case 5:
                printf("Digite a chave para encontrar o anterior: ");
                scanf("%hu", &key);
                MyDLLFindPrevious(&myDLL, key);
                break;

            case 6:
                return 0;

            default:
                printf("Opção inválida!\n");
        }
    }
}
