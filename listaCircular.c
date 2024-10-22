#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char musica[100];
    struct Node* next;
} Node;

Node* head = NULL;

void insere_inicio(char* valor) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    strcpy(novo_node->musica, valor);
    
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

void insere_meio(int pos, char* valor) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    strcpy(novo_node->musica, valor);
    
    if (head == NULL || pos == 0) {
        insere_inicio(valor);
        return;
    }

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

void insere_fim(char* valor) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    strcpy(novo_node->musica, valor);
    
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

void busca(char* valor) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    Node* temp = head;
    do {
        if (strcmp(temp->musica, valor) == 0) {
            printf("Música %s encontrada.\n", valor);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Música %s não encontrada.\n", valor);
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

    Node* temp = head;
    if (pos == 0) {
        remove_inicio();
        return;
    }

    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
        if (temp->next == head) {
            printf("Posição inválida!\n");
            return;
        }
    }

    Node* node_a_remover = temp->next;
    if (node_a_remover == head) {
        remove_inicio();
    } else {
        temp->next = node_a_remover->next;
        free(node_a_remover);
    }
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
        printf("Música: %s\n", temp->musica);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    insere_inicio("Música 1");
    insere_fim("Música 2");
    insere_meio(1, "Música 3");
    insere_fim("Música 4");

    printf("Lista atual de músicas:\n");
    imprime_lista();

    busca("Música 3");

    remove_meio(1);
    remove_inicio();
    remove_fim();

    printf("\nLista após as remoções:\n");
    imprime_lista();

    return 0;
}
