#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matricula;
    float nota;
    char nome[50];
    struct aluno *esquerda;
    struct aluno *direita;
}aluno;

aluno *criar(int matricula, float nota, const char *name);
aluno *insercao(aluno *raiz,int matricula, float nota, const char *nome);
aluno *busca(aluno *raiz, const char *nome);
void *media(aluno *raiz, float *soma, int *quantidade);

int soma=0, quantidade=0;

int main(){
    setlocale(LC_ALL, "Portuguese");
    aluno *raiz = NULL;

    raiz = insercao(raiz, 2020,9.0, "Vitor");
    raiz = insercao(raiz, 2021,10.0, "Davi");
    raiz = insercao(raiz, 2022,8.5, "Leo");
    raiz = insercao(raiz, 2023,9.8, "Ruan");
    raiz = insercao(raiz, 2024,7.2, "Ana");
    raiz = insercao(raiz, 2025,8.6, "Vitoria");
    raiz = insercao(raiz, 2026,9.5, "fabiola");

    return(0);
}

aluno *criar(int mat, float not, const char *name){
    aluno* novo = malloc(sizeof(aluno));
    if(novo){
        novo->matricula=mat;
        novo->nota=not;
        strcpy(novo->nome, name);
        novo->direita=NULL;
        novo->esquerda=NULL;
    }
    return(novo);
}

aluno *insercao(aluno *raiz,int mat, float not, const char *nome){
    if(raiz == NULL){
        return criar(mat, not, nome);
    }
    int comp = strcmp(nome, raiz->nome);
    if(comp < 0){
        raiz->esquerda = insercao(raiz->esquerda, mat, not, nome);
    }
    else if(comp > 0){
        raiz->direita = insercao(raiz->direita, mat, not, nome);
    }
    return raiz;
}

aluno *busca(aluno *raiz, const char *nome){
    if(raiz == NULL){
        return NULL;
    }
    int comp = strcmp(nome, raiz->nome);
    if(comp == 0){
        return raiz;
    }
    else if(comp>0){
        return busca(raiz->direita, nome);
    }
    else{
        return busca(raiz->esquerda, nome);
    }

}

void *media(aluno *raiz, float *soma, int *quantidade){
    if(raiz != NULL){
        media(raiz->esquerda, soma, quantidade);
        *soma+=raiz->nota;
        (*quantidade)++;
        media(raiz->direita, soma, quantidade);
    }
}

