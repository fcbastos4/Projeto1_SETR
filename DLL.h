#include <stdio.h>

struc node {
    int id;
    int size;
    struc node *next;
    struc node *prev;
}

/* Inicialização do modulo, com alocação estática. Para a função são passados como argumentos o número máximo de elementos e o tamanho de cada argumento.*/
void MyDLLInit(uint_16t key, uint16 es);

/* Adição de um elemento à DLL ... . É passado como argumento uma key, que indica a posição da DLL a ser inserido. E a função retorna um valor a indicar se foi possível ou  não fazer a adição pretendida.*/
int MyDLLInsert();


/* A função remove um elemento da DLL. O elemento a remover é identificado por uma key passada como argumento para a função. A função retorna um valor consoante o sucesso, ou não, remover o elemento com pretendido.*/
int MyDLLRemove();

/* Função para verificar os dados relativos a um elemento. Fazendo o retorno do dados, identificados pela sua key, ou um erro caso não existam dados.*/
int MyDLLFind();

int MyDLLFindNext();

int MyDLLFindPrevious();
