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
node *buscar(node *raiz,int num);
node *encontrarMinimo(node *raiz);
void emOrdem(node *raiz);
void preOrdem(node *raiz);
void posOrdem(node *raiz);
int quant(node *raiz);
int altura(node *raiz);
int profun(node *raiz, int num);
int nivel(node *raiz, int num);
int quantNo(node *raiz);
int quantFo(node *raiz);

int soma=0, no=0;

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

    printf("Arvore em ordem:\n");
    emOrdem(raiz);
    printf("\n\n");

    printf("Arvore em pre-ordem:\n");
    preOrdem(raiz);
    printf("\n\n");

    printf("Arvore em pos-ordem:\n");
    posOrdem(raiz);
    printf("\n\n");

    printf("Altura da arvore: ");
    int h = altura(raiz);
    printf("%d \n\n", h);

    printf("Profundidade do no 70: ");
    int p = profun(raiz, 70);
    printf("%d ", p);
    printf("\n\n");

    printf("Soma dos nós: ");
    int q = quant(raiz);
    printf("%d ", q);
    printf("\n\n");

    printf("Nível do no 70: ");
    int n = nivel(raiz, 70);
    printf("%d ", n);
    printf("\n\n");

    printf("Quantidade de Nós: ");
    int qn = quantNo(raiz);
    printf("%d", qn);
    printf("\n\n");

    printf("Quantidade de Folhas: ");
    int qf = quantFo(raiz);
    printf("%d", qf);
    printf("\n\n");

    raiz = remocao(raiz, 70);
    raiz = remocao(raiz, 60);
    raiz = remocao(raiz, 50);

    printf("\nApós remoção\n");
    printf("Arvore em ordem:\n");
    emOrdem(raiz);
    printf("\n\n");

    node* res = buscar(raiz, 40);

    return(0);
}

void emOrdem(node *raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direita);
    }
}

void preOrdem(node *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(node *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->dado);

    }
}

int altura(node *raiz){
    if(raiz != NULL){
        int Esq = altura(raiz->esquerda);
        int Dir = altura(raiz->direita);
        return (Esq>Dir?Esq:Dir) + 1;
    }
    return -1;
}

int profun(node *raiz, int num){
    int p=0;
    if(raiz == NULL){
        printf("Numero nâo encontrado");
        return 0;
    }

    if(raiz->dado == num){
        return 0;
    }

    if(num>raiz->dado){
        p = profun(raiz->direita, num);
    }
    else{
        p = profun(raiz->esquerda, num);
    }

    if(p >= 0){
        return p + 1;
    }

    return -1;
}

int quant(node *raiz){
    if(raiz != NULL){
        soma = quant(raiz->esquerda);
        soma+=raiz->dado;
        soma = quant(raiz->direita);
    }
    return(soma);
}

int nivel(node *raiz, int num){
    int p=0;
    if(raiz == NULL){
        printf("Numero nâo encontrado");
        return 0;
    }

    if(raiz->dado == num){
        return 0;
    }

    if(num>raiz->dado){
        p = profun(raiz->direita, num);
    }
    else{
        p = profun(raiz->esquerda, num);
    }

    if(p >= 0){
        return p + 1;
    }

    return -1;
}

int quantNo(node *raiz){
    if(raiz != NULL){
        no++;
        quantNo(raiz->esquerda);
        quantNo(raiz->direita);
    }
    return no;
}

int quantFo(node *raiz){
    if(raiz == NULL){
        return 0;
    }

    if(raiz->esquerda == NULL && raiz->direita == NULL){
        return 1;
    }

    return quantFo(raiz->esquerda) + quantFo(raiz->esquerda);
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
    if(raiz->dado>num){
    return buscar(raiz->direita, num);
    }
}

node* encontrarMinimo(node *raiz){
    while(raiz->esquerda !=NULL){
        raiz = raiz->esquerda;
    }
    return raiz;

}