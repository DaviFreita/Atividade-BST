#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    struct node *esquerda;
    struct node *direita;
    int dado;
}node;

node *criar(){
    node *novo = malloc(sizeof(node));
    if(novo){
        novo->direita=NULL;
        novo->esquerda=NULL;
    }
    return novo;
}

int main(){
    setlocale(LC_ALL, "Portuguese");


    return(0);
}