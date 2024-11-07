#include <stdio.h>
#include <stdlib.h>
#define Tam 5

int v[Tam];
int tamanho = 0;

void insere(int valor){
    if (tamanho < Tam){
        v[tamanho++] = valor;
    }
    else{
        printf("O vetor esta cheio\n");
    }
}

void insereMeio(int pos, int valor){
    if (tamanho>= Tam){
        printf("Vetor esta cheio\n");
    }
    for (int i = tamanho; i> pos; i--){
        v[i] = v[i-1];
    }
    v[pos] = valor;
    tamanho++;
}

void busca(int valor){
    int i = 0;
    int encontrado = 0;
    while (i < Tam){
        if (v[i] == valor){
            encontrado = 1;
            break;
        }
        else{
            i++;
        }
    }
    if (!encontrado){
       printf("Valor nao encontrado");
    }
}

void remove(){
    if (tamanho > 0){
        tamanho--;
    }
    else{
        printf("O vetor esta vazio");
    }
}

void removePos(int pos){
    if (tamanho > 0){
        if (pos < 0 || pos >= tamanho) {
        printf("Posição inválida\n");
        return;
        }
        else{
        for (int i = pos; i<tamanho - 1 ; i++){
            v[i] = v[i+1];
        }
        tamanho--;
        }
    }
    else{
        printf("Vetor esta vazio");
    }
}

void imprime(){
    for (int i = 0; i<tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int opcao, valor, pos;

    do {
        printf("\nMenu:\n");
        printf("1 - Inserir no final\n");
        printf("2 - Inserir em uma posição\n");
        printf("3 - Buscar um valor\n");
        printf("4 - Remover o último valor\n");
        printf("5 - Remover em uma posição\n");
        printf("6 - Imprimir vetor\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor para inserir no final: ");
                scanf("%d", &valor);
                insere(valor);
                break;

            case 2:
                printf("Digite a posição para inserir: ");
                scanf("%d", &pos);
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);
                insereMeio(pos, valor);
                break;

            case 3:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                busca(valor);
                break;

            case 4:
                remove();
                break;

            case 5:
                printf("Digite a posição para remover: ");
                scanf("%d", &pos);
                removePos(pos);
                break;

            case 6:
                imprime();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while(opcao != 0);

    return 0;
}
