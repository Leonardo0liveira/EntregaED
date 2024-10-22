#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
    struct no* ant;
} no;

no* inicio = NULL;
no* fim = NULL;  

void inserir_inicio(int valor) {
    no* novoNo = (no*)malloc(sizeof(no)); 
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->prox = inicio;
    novoNo->ant = NULL;  

    if (inicio != NULL) {
        inicio->ant = novoNo;
    } else {
        fim = novoNo;  
    }
    inicio = novoNo;
}

void inserir_meio(int pos, int valor) {
    if (inicio == NULL && pos > 0) {
        printf("Lista está vazia.\n");
        return;
    }

    no* atual = inicio;
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;

    for (int i = 0; i < pos && atual != NULL; i++) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Posição inválida.\n");
        free(novoNo);
        return;
    }

    novoNo->prox = atual;
    novoNo->ant = atual->ant;

    if (atual->ant != NULL) {
        atual->ant->prox = novoNo;
    } else {
        inicio = novoNo; 
    }
    atual->ant = novoNo;
}

void inserir_fim(int valor) {
    no* novoNo = (no*)malloc(sizeof(no));  
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->prox = NULL;
    novoNo->ant = fim;

    if (fim != NULL) {
        fim->prox = novoNo;
    } else {
        inicio = novoNo; 
    }
    fim = novoNo;
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

    if (inicio != NULL) {
        inicio->ant = NULL;
    } else {
        fim = NULL;
    }
    free(temp);
    printf("Removido do início.\n");
}

void remove_fim() {
    if (fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    no* temp = fim;
    fim = fim->ant;

    if (fim != NULL) {
        fim->prox = NULL;
    } else {
        inicio = NULL;  
    }
    free(temp);
    printf("Removido do fim.\n");
}

void imprime_lista() {
    no* atual = inicio;
    printf("Lista atual (do início ao fim): ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void imprime_lista_inversa() {
    no* atual = fim;
    printf("Lista atual (do fim ao início): ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->ant;
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
        printf("8. Mostrar lista inversa\n");
        printf("9. Sair\n");
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
                break;
            case 6:
                remove_fim();
                break;
            case 7:
                imprime_lista();
                break;
            case 8:
                imprime_lista_inversa();
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 9);

    return 0;
}
