#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} no;

no* inicio = NULL;  

void inserir_inicio(int valor) {
    no* novoNo = (no*)malloc(sizeof(no));  
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->prox = inicio;  
    inicio = novoNo; 
}

void inserir_meio(int pos, int valor) {
    no* atual = inicio;
    no* anterior = NULL;
    no* novoNo = (no*)malloc(sizeof(no));  
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;

    if (pos == 0) {  
        inserir_inicio(valor);
        return;
    }

    for (int i = 0; i < pos && atual != NULL; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        printf("Posição inválida.\n");
        free(novoNo); 
        return;
    }

    novoNo->prox = atual;  
    anterior->prox = novoNo;  
}

void inserir_fim(int valor) {
    no* novoNo = (no*)malloc(sizeof(no));  
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (inicio == NULL) {
        inicio = novoNo; 
        return;
    }

    no* atual = inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novoNo; 
}

void busca(int valor) {
    no* atual = inicio;
    int pos = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("Valor %d encontrado na posição %d\n", valor, pos);
            return;
        }
        atual = atual->prox;
        pos++;
    }

    printf("Valor %d não encontrado.\n", valor);
}

void remove_inicio() {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    no* temp = inicio;
    inicio = inicio->prox; 
    free(temp);  
}

void remove_fim() {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    if (inicio->prox == NULL) {
        free(inicio); 
        inicio = NULL;
        return;
    }

    no* atual = inicio;
    no* anterior = NULL;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = NULL;  
    free(atual);  
}

void imprime_lista() {
    no* atual = inicio;
    printf("Lista atual: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    int escolha, valor, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no meio\n");
        printf("3. Inserir no fim\n");
        printf("4. Buscar valor\n");
        printf("5. Remover do início\n");
        printf("6. Remover do fim\n");
        printf("7. Mostrar lista\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor para inserir no início: ");
                scanf("%d", &valor);
                inserir_inicio(valor);
                break;
            case 2:
                printf("Digite a posição para inserir: ");
                scanf("%d", &pos);
                printf("Digite o valor para inserir no meio: ");
                scanf("%d", &valor);
                inserir_meio(pos, valor);
                break;
            case 3:
                printf("Digite o valor para inserir no fim: ");
                scanf("%d", &valor);
                inserir_fim(valor);
                break;
            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                busca(valor);
                break;
            case 5:
                remove_inicio();
                printf("Removido do início.\n");
                break;
            case 6:
                remove_fim();
                printf("Removido do fim.\n");
                break;
            case 7:
                imprime_lista();
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 8);

    return 0;
}
