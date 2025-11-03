#include <stdio.h>
#include <stdlib.h>

void ler(int n, int *vetor);
void ordenacao(int n, int *vetor);
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

void ler(int n, int *vetor){
    int i;
    for(i = 0; i < n; i++){
        printf("Digite o %d numero: \n", i + 1);
        scanf("%d", &vetor[i]);
    }
}

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

void buscar_intervalo(int *vetor, int n){
    int numero;
    int primeiro = -1, ultimo = -1;
    while(1){
        printf("Digite o numero que voce quer ver qual o intervalo: \n");
        scanf("%d", &numero);

        // Aqui o programa verifica qual o intervalo e se o número está no vetor dos numeros.
        for(int i = 0; i < n; i++){
            if(vetor[i] == numero){
                if(primeiro == -1){
                    primeiro = i; // salva o primeiro
                }
                ultimo = i; // Após encontrar o primeiro ele fica rodando até encontrar o último.

            }


        }
        if(primeiro != -1){
            printf("O intervalo eh de %d ate %d.\n", primeiro, ultimo);
            break;
        }else{
            printf("Numero nao encontrado no vetor de numeros.\n");
        }
    }

}