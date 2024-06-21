#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    struct TreeNode* raiz = NULL;

    raiz = inserir(raiz, 120);
    raiz = inserir(raiz, 21);
    raiz = inserir(raiz, 33);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 130);
    raiz = inserir(raiz, 80);
    raiz = inserir(raiz, 70);

    printf("Percorrendo em ordem simetrica: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("Percorrendo pre-ordem: ");
    percorrerPreOrdem(raiz);
    printf("\n");

    printf("Percorrendo pos-ordem: ");
    percorrerPosOrdem(raiz);
    printf("\n");


int valorBusca = 33;
    if (buscar(raiz, valorBusca)) {
        printf("%d encontrado na arvore.\n", valorBusca);
    } else {
        printf("%d não encontrado na arvore.\n", valorBusca);
    }

    int valorRemover = 21;
    raiz = remover(raiz, valorRemover);
    printf("Depois de remover %d:\n", valorRemover);
    percorrerEmOrdem(raiz);
    printf("\n");

    liberarArvore(raiz);

    return 0;
}