#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    struct node *esquerda;
    struct node *direita;
    int dado;
}node;

int main(){
    setlocale(LC_ALL, "Portuguese");


    return(0);
}