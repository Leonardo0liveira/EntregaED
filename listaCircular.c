#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
void insere_inicio(int valor) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->data = valor;
    
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

void insere_meio(int pos, int valor) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->data = valor;

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

void insere_fim(int valor) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->data = valor;

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

void busca(int valor) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    Node* temp = head;
    do {
        if (temp->data == valor) {
            printf("Música %d encontrada.\n", valor);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Música %d não encontrada.\n", valor);
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
        printf("Música %d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    insere_inicio(1);
    insere_fim(2);
    insere_meio(1, 3);
    insere_fim(4);

    printf("Lista atual de músicas:\n");
    imprime_lista();

    busca(3);

    remove_meio(1);
    remove_inicio();
    remove_fim();

    printf("\nLista após as remoções:\n");
    imprime_lista();

    return 0;
}