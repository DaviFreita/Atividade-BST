#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *esquerda;
    struct node *direita;
    int dado;
}node;

node *criar(int num);
node *insercao(node *raiz,int num);
node *remocao(node *raiz, int num);
node* buscar(node* raiz,int num);
node* encontrarMinimo(node *raiz);

int main(){
    setlocale(LC_ALL, "Portuguese");
    node *raiz = NULL;

    raiz = insercao(raiz, 50);
    raiz = insercao(raiz, 40);
    raiz = insercao(raiz, 60);
    raiz = insercao(raiz, 30);
    raiz = insercao(raiz, 45);
    raiz = insercao(raiz, 55);
    raiz = insercao(raiz, 70);

    raiz = remocao(raiz, 70);
    raiz = remocao(raiz, 60);
    raiz = remocao(raiz, 50);

    node* res = buscar(raiz, 40);

    return(0);
}

node *criar(int num){
    node* novo = malloc(sizeof(node));
    if(novo){
        novo->direita=NULL;
        novo->esquerda=NULL;
        novo->dado=num;
    }
    return(novo);
}

node *insercao(node *raiz,int num){
    if(raiz==NULL){
        return criar(num);
    }

    if(raiz->dado>num){
        raiz->esquerda=insercao(raiz->esquerda, num);
        return raiz;
    }
    else{
        raiz->direita=insercao(raiz->direita, num);
        return raiz;
    }
}

node *remocao(node *raiz, int num){
    if(raiz==NULL){
        return NULL;
    }
    if(raiz->dado>num){
        raiz->esquerda=remocao(raiz->esquerda, num);
    }
    else if(raiz->dado<num){
        raiz->direita=remocao(raiz->direita, num);
    }
    else{
        if(raiz->direita == NULL){
            node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        else if(raiz->esquerda == NULL){
            node* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if(raiz->direita == NULL && raiz->esquerda == NULL){
            free(raiz);
            return NULL;
        }

        node* temp = encontrarMinimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = remocao(raiz->direita, temp->dado); 
    }
    return raiz;

}

node* buscar(node* raiz,int num){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->dado == num){
        return raiz;
    }
    else if(raiz->dado > num){
        return raiz=buscar(raiz->esquerda,num);
    }
    return buscar(raiz->direita, num);
}

node* encontrarMinimo(node *raiz){
    while(raiz->esquerda !=NULL){
        raiz = raiz->esquerda;
    }
    return raiz;

}