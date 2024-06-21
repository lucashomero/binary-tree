#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode* criarNo(int chave) {
    struct TreeNode* novoNo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novoNo->chave = chave;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

struct TreeNode* inserir(struct TreeNode* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }

    return raiz;
}

struct TreeNode* remover(struct TreeNode* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        if (raiz->esquerda == NULL) {
            struct TreeNode* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct TreeNode* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
    }
}
int buscar(struct TreeNode* raiz, int chave) {
    if (raiz == NULL) {
        return 0;
    }

    if (chave == raiz->chave) {
        return 1;
    } else if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

void percorrerEmOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        percorrerEmOrdem(raiz->direita);
    }
}

void percorrerPreOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        percorrerPreOrdem(raiz->esquerda);
        percorrerPreOrdem(raiz->direita);
    }
}

void percorrerPosOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->esquerda);
        percorrerPosOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

void liberarArvore(struct TreeNode* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}