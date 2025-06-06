#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    struct node *esquerda;
    struct node *direita;
    int dado;
}node;

node *criar(int num){
    node* novo = malloc(sizeof(node));
    if(novo){
        novo->direita=NULL;
        novo->esquerda=NULL;
        novo->dado=num;
    }
    return(novo);
}

node *remocao(node *raiz, int num){
    if(raiz->dado==NULL){
        return NULL;
    }
    if(raiz->dado>num){
        raiz->esquerda=remocao(raiz->esquerda, num);
    }
    else{
        raiz->direita=remocao(raiz->direita, num);
    }

    if(raiz->direita == NULL){
        node* temp = raiz->esquerda;
        free(raiz);
        return temp;
    }
    else if(raiz->esquerda == NULL){
        node* temp = raiz->direita;
        free(raiz);
    }
    else if(raiz->direita == NULL && raiz->esquerda == NULL){
        free(raiz);
        return NULL;
    }

    node* temp = encontrarMinimo(raiz->direita);
    raiz->dado = temp->dado;
    raiz->direita = remocao(raiz->direita, temp->dado); 
    return(temp);

}

node* encotrarMinimo(node *raiz){
    while(raiz->esquerda !=NULL){
        raiz = raiz->esquerda;
    }
    return raiz;

}

int main(){
    setlocale(LC_ALL, "Portuguese");



    return(0);
}