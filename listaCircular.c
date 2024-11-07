#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int idMusica;
    struct Node* next;
} Node;

Node* head = NULL;

void insere_inicio(int idMusica) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_node->idMusica = idMusica;
    
    if (head == NULL) {
        head = novo_node;
        novo_node->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = novo_node;
        novo_node->next = head;
        head = novo_node;
    }
}

void insere_meio(int pos, int idMusica) {
    if (pos == 0 || head == NULL) {
        insere_inicio(idMusica);
        return;
    }
    
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_node->idMusica = idMusica;

    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Posição inválida!\n");
            free(novo_node);
            return;
        }
    }

    novo_node->next = temp->next;
    temp->next = novo_node;
}

void insere_fim(int idMusica) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    if (novo_node == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_node->idMusica = idMusica;

    if (head == NULL) {
        head = novo_node;
        novo_node->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = novo_node;
        novo_node->next = head;
    }
}

void busca(int idMusica) {
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

void remove_inicio() {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return;
    }
    
    Node* temp = head;
    if (temp->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* ultimo = head;
        while (ultimo->next != head) {
            ultimo = ultimo->next;
        }
        head = head->next;
        ultimo->next = head;
        free(temp);
    }
}

void remove_meio(int pos) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    if (pos == 0) {
        remove_inicio();
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
        if (temp->next == head) {
            printf("Posição inválida!\n");
            return;
        }
    }

    Node* node_a_remover = temp->next;
    temp->next = node_a_remover->next;
    free(node_a_remover);
}

void remove_fim() {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    Node* temp = head;
    if (temp->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* penultimo = NULL;
        while (temp->next != head) {
            penultimo = temp;
            temp = temp->next;
        }
        penultimo->next = head;
        free(temp);
    }
}

void imprime_lista() {
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

void libera_lista() {
    while (head != NULL) {
        remove_inicio();
    }
}

void menu() {
    int opcao, idMusica, pos;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no meio\n");
        printf("3. Inserir no fim\n");
        printf("4. Buscar música\n");
        printf("5. Remover do início\n");
        printf("6. Remover do meio\n");
        printf("7. Remover do fim\n");
        printf("8. Imprimir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID da música para inserir no início: ");
                scanf("%d", &idMusica);
                insere_inicio(idMusica);
                break;
            case 2:
                printf("Digite a posição para inserir a música: ");
                scanf("%d", &pos);
                printf("Digite o ID da música: ");
                scanf("%d", &idMusica);
                insere_meio(pos, idMusica);
                break;
            case 3:
                printf("Digite o ID da música para inserir no fim: ");
                scanf("%d", &idMusica);
                insere_fim(idMusica);
                break;
            case 4:
                printf("Digite o ID da música para buscar: ");
                scanf("%d", &idMusica);
                busca(idMusica);
                break;
            case 5:
                remove_inicio();
                printf("Removido do início.\n");
                break;
            case 6:
                printf("Digite a posição para remover a música: ");
                scanf("%d", &pos);
                remove_meio(pos);
                printf("Removido da posição %d.\n", pos);
                break;
            case 7:
                remove_fim();
                printf("Removido do fim.\n");
                break;
            case 8:
                imprime_lista();
                break;
            case 0:
                libera_lista();
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
