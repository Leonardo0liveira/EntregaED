#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
} No;

No* head = NULL;

void inserir(int valor){
    No* novoNo = (No*)malloc(sizeof(No));

    if(novoNo == NULL){
        printf("Erro ao alocar memória\n");
        return;
    }

    novoNo->valor = valor;
    novoNo->prox = NULL;

    if(head == NULL){
        head = novoNo;
    } else {
        No* temp = head;
        while (temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novoNo;
    }
}

void inserirPos(int valorPos, int valor){
    No* atual = head;

    while (atual != NULL && atual->valor != valorPos){
        atual = atual->prox;
    }

    if(atual != NULL){
        No* novoNo = (No*)malloc(sizeof(No));
        if (novoNo == NULL) {
            printf("Erro ao alocar memória\n");
            return;
        }
        novoNo->valor = valor;
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    } else {
        printf("Valor %d não encontrado na lista\n", valorPos);
    }
}

void imprimir(){
    No* atual = head;
    while(atual != NULL){
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

void remover(){
    if (head == NULL) {
        printf("A lista está vazia\n");
        return;
    }

    if (head->prox == NULL) {
        free(head);
        head = NULL;
    } else {
        No* atual = head;
        while (atual->prox->prox != NULL){
            atual = atual->prox;
        }
        free(atual->prox);
        atual->prox = NULL;
    }
}

void removerPos(int valor){
    if (head == NULL) {
        printf("A lista está vazia\n");
        return;
    }

    if (head->valor == valor){
        No* temp = head;
        head = head->prox;
        free(temp);
        return;
    }

    No* atual = head;
    while(atual->prox != NULL && atual->prox->valor != valor){
        atual = atual->prox;
    }

    if (atual->prox == NULL){
        printf("Valor %d não encontrado na lista\n", valor);
    } else {
        No* temp = atual->prox;
        atual->prox = temp->prox;
        free(temp);
    }
}

int main(){
    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1 - Inserir no final\n");
        printf("2 - Inserir após um valor específico\n");
        printf("3 - Exibir lista\n");
        printf("4 - Remover último valor\n");
        printf("5 - Remover valor específico\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                int valor;
                printf("Digite o valor que quer inserir: ");
                scanf("%d", &valor);
                inserir(valor);
                break;
            }
            case 2: {
                int valorPos, valor;
                printf("Digite o valor onde quer inserir: ");
                scanf("%d", &valorPos);
                printf("Digite o valor que quer inserir: ");
                scanf("%d", &valor);
                inserirPos(valorPos, valor);
                break;
            }
            case 3:
                imprimir();
                break;
            case 4:
                remover();
                break;
            case 5: {
                int valor;
                printf("Digite o valor que quer remover: ");
                scanf("%d", &valor);
                removerPos(valor);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while(escolha != 0);

    return 0;
}
