#include <stdio.h>

#define TAMANHO 5

void insere_inicio(int v[], int tamanho, int valor){
    for (int i = tamanho - 1; i > 0; i--){  
        v[i] = v[i - 1];  
    }
    v[0] = valor;  
}

void insere_meio(int v[], int tamanho, int pos, int valor){
    if (pos >= 0 && pos < tamanho) {  
        v[pos] = valor;
    }
}

void insere_fim(int v[], int tamanho, int valor){
    v[tamanho - 1] = valor;  
}

void busca(int v[], int tamanho, int valor){
    for (int i = 0; i < tamanho; i++){
        if (v[i] == valor){
            printf("Valor %d achado na posicao %d\n", valor, i);
            return;
        }
    }
    printf("Valor nao encontrado\n");
}

void remove_inicio(int v[], int tamanho){
    for (int i = 0; i < tamanho - 1; i++){
        v[i] = v[i + 1]; 
    }
    v[tamanho - 1] = 0;  
}

void remove_fim(int v[], int tamanho){
    v[tamanho - 1] = 0;  
}

void imprime_array(int v[], int tamanho){
    printf("Array atual:\n");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int v[TAMANHO] = {0}; 
    int escolha, valor, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no meio\n");
        printf("3. Inserir no fim\n");
        printf("4. Buscar valor\n");
        printf("5. Remover do início\n");
        printf("6. Remover do fim\n");
        printf("7. Mostrar array\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor para inserir no início: ");
                scanf("%d", &valor);
                insere_inicio(v, TAMANHO, valor);
                break;
            case 2:
                printf("Digite a posição (0 a 4) para inserir: ");
                scanf("%d", &pos);
                if (pos >= 0 && pos < TAMANHO) {
                    printf("Digite o valor para inserir no meio: ");
                    scanf("%d", &valor);
                    insere_meio(v, TAMANHO, pos, valor);
                } else {
                    printf("Posição inválida.\n");
                }
                break;
            case 3:
                printf("Digite o valor para inserir no fim: ");
                scanf("%d", &valor);
                insere_fim(v, TAMANHO, valor);
                break;
            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                busca(v, TAMANHO, valor);
                break;
            case 5:
                remove_inicio(v, TAMANHO);
                printf("Removido do início.\n");
                break;
            case 6:
                remove_fim(v, TAMANHO);
                printf("Removido do fim.\n");
                break;
            case 7:
                imprime_array(v, TAMANHO);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao inválida!\n");
        }
    } while (escolha != 8);

    return 0;
}
