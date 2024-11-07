#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int idMusica;
    struct Node* next;
    struct Node* prev;
} Node;

Node* insere(Node* head, int idMusica) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node == NULL) {
        printf("Erro ao alocar memória.\n");
        return head;
    }
    novo_node->idMusica = idMusica;

    if (head == NULL) {
        novo_node->next = novo_node;
        novo_node->prev = novo_node;
        head = novo_node;
    } else {
        Node* ultimo = head->prev;

        ultimo->next = novo_node;
        novo_node->prev = ultimo;
        novo_node->next = head;
        head->prev = novo_node;
    }
    return head;
}

Node* insere_apos_valor(Node* head, int idReferencia, int idMusica) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return head;
    }

    Node* temp = head;
    do {
        if (temp->idMusica == idReferencia) {
            Node* novo_node = (Node*)malloc(sizeof(Node));
            if (novo_node == NULL) {
                printf("Erro ao alocar memória.\n");
                return head;
            }
            novo_node->idMusica = idMusica;

            novo_node->next = temp->next;
            novo_node->prev = temp;
            temp->next->prev = novo_node;
            temp->next = novo_node;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    printf("ID %d não encontrado na lista.\n", idReferencia);
    return head;
}

void busca(Node* head, int idMusica) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    Node* temp = head;
    int pos = 0;
    do {
        if (temp->idMusica == idMusica) {
            printf("Música com ID %d encontrada na posição %d.\n", idMusica, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    
    printf("Música com ID %d não encontrada.\n", idMusica);
}

void imprime_lista(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    Node* temp = head;
    do {
        printf("ID da Música: %d\n", temp->idMusica);
        temp = temp->next;
    } while (temp != head);
}

Node* remove_do_fim(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return head;
    }

    Node* ultimo = head->prev;
    if (ultimo == head) { 
        free(head);
        return NULL;
    }

    ultimo->prev->next = head;
    head->prev = ultimo->prev;
    free(ultimo);

    return head;
}

Node* remove_valor(Node* head, int idMusica) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return head;
    }

    Node* temp = head;
    do {
        if (temp->idMusica == idMusica) {
            if (temp == head && temp->next == head) { 
                free(head);
                return NULL;
            } else if (temp == head) { 
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                free(temp);
                return head;
            } else { 
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                return head;
            }
        }
        temp = temp->next;
    } while (temp != head);

    printf("Música com ID %d não encontrada para remoção.\n", idMusica);
    return head;
}

int main() {
    Node* head = NULL;
    int opcao, idMusica, idReferencia;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir no fim\n");
        printf("2. Inserir após valor\n");
        printf("3. Buscar música\n");
        printf("4. Imprimir lista\n");
        printf("5. Remover do fim\n");
        printf("6. Remover valor específico\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID da música para inserir no fim: ");
                scanf("%d", &idMusica);
                head = insere_no_fim(head, idMusica);
                break;
            case 2:
                printf("Digite o ID da música de referência: ");
                scanf("%d", &idReferencia);
                printf("Digite o ID da nova música: ");
                scanf("%d", &idMusica);
                head = insere_apos_valor(head, idReferencia, idMusica);
                break;
            case 3:
                printf("Digite o ID da música para buscar: ");
                scanf("%d", &idMusica);
                busca(head, idMusica);
                break;
            case 4:
                imprime_lista(head);
                break;
            case 5:
                head = remove_do_fim(head);
                printf("Removido do fim.\n");
                break;
            case 6:
                printf("Digite o ID da música para remover: ");
                scanf("%d", &idMusica);
                head = remove_valor(head, idMusica);
                printf("Removido ID %d.\n", idMusica);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
