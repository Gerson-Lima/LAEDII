#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[100];
    int id;
    float nota;
}Aluno;

typedef struct node{
    Aluno A;
    struct no *dir, *esq;
}No;

Aluno lerAluno(){
    Aluno A;
    printf("\nDigite o ID: ");
    scanf("%d", &A.id);
    printf("Digite o nome da pessoa: ");
    scanf("%s", &A.nome);
    printf("Digite sua nota: ");
    scanf("%f", &A.nota);
    return A;
}

void imprimirAluno( Aluno A){
    printf("ID: %d | Nome: %s | Nota: %.2f\n", A.id, A.nome, A.nota);
}

void criarAluno(No **raiz, Aluno A){
    No *aux = *raiz;
    while(aux){
        if(A.id < aux->A.id)
            raiz = &aux->esq;
        else
            raiz = &aux->dir;
        aux = *raiz;
    }
    aux = malloc(sizeof(No));
    aux->A = A;
    aux->esq = NULL;
    aux->dir = NULL;
    *raiz = aux;
}

void posordemIter(No *raiz){ 
    if(raiz){
        posordemIter(raiz->esq);
        posordemIter(raiz->dir);
        imprimirAluno(raiz->A);
        
    }
}

int main(){

    No *raiz = NULL;
    int op;

    do{
        printf("\n==== Informe a opcao desejada ====\n");
        printf("1 - Inserir\n2 - Imprimir\n0 - Sair \n");
        printf("==================================\n");
        scanf("%d", &op);
        system("cls");

        switch(op){
        case 1:
            criarAluno(&raiz, lerAluno());
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\n\tAPOS POS-ORDEM: \n");
            posordemIter(raiz);
            printf("\n");
            system("pause");
            system("cls");
            break;
        default:
            if(op != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(op != 0);

    return 0;
}