#include <stdio.h>
#include <stdlib.h>

void ler(int n, int *vetor);
void ordenacao(int n, int *vetor);
int buscar_primeiro(int *vetor, int n, int numero);
int buscar_ultimo(int *vetor, int n, int numero);
void buscar_intervalo(int *vetor, int n);

int main(){
    int *vetor;
    int n;
 

    printf("Digite a quantidade de numeros que voce quer ordenar: \n");
    scanf("%d", &n);

    vetor = (int*) malloc(n * sizeof(int));

    if(vetor == NULL){
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    ler(n, vetor);
    ordenacao(n, vetor);
    buscar_intervalo(vetor, n);

    free(vetor);
    return 0;
}

// Aqui o programa pede os números ao usuário e eles irão preencher o vetor de números.
void ler(int n, int *vetor){
    int i;
    for(i = 0; i < n; i++){
        printf("Digite o %dº numero: \n", i + 1);
        scanf("%d", &vetor[i]);
    }
}

// Aqui o programa faz a ordenação dos números dois a dois.
void ordenacao(int n, int *vetor){
    int temp, i, j;

    for(i = 0; i < n; i ++){
        for(j = i + 1; j < n; j++){
            if(vetor[i] > vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
            
        }


    }
    for(i = 0; i < n; i++){
    printf("%d ", vetor[i]);
    }
    printf("\n");

}
// Busca binária para encontrar a primeira ocorrência
int buscar_primeiro(int *vetor, int n, int numero) {
    int inicio = 0, fim = n - 1, meio, resultado = -1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == numero) {
            resultado = meio;
            fim = meio - 1; // continua procurando à esquerda
        } else if (vetor[meio] < numero) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return resultado;
}

// Busca binária para encontrar a última ocorrência
int buscar_ultimo(int *vetor, int n, int numero) {
    int inicio = 0, fim = n - 1, meio, resultado = -1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == numero) {
            resultado = meio;
            inicio = meio + 1; // continua procurando à direita
        } else if (vetor[meio] < numero) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return resultado;
}
// Aqui o programa informa o intervalo ao usuário.
void buscar_intervalo(int *vetor, int n){
    int numero;

    while(1){
        printf("Digite o numero que voce quer ver qual o intervalo: \n");
        scanf("%d", &numero);

        int primeiro = buscar_primeiro(vetor, n, numero);
        int ultimo = buscar_ultimo(vetor, n, numero);

        if(primeiro != -1){
            printf("O intervalo eh de %d ate %d.\n", primeiro, ultimo);
            break;
        }else{
            printf("Numero nao encontrado no vetor de numeros.\n");
        }
    }

}