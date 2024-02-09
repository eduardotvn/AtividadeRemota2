#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int i;
    int N = -1; 
    int scalar; 
    while(N <= 0)
    {
        printf("Digite um valor (maior que 0) para o tamanho do vetor:");
        scanf("%d", &N);
    }

    printf("Agora, digite um escalar: ");
    scanf("%d", &scalar);

    int vetor[N];
    int maximo = 0;

    for (i = 0; i < N; i++) {
        vetor[i] = rand() % 100;  
    }

    printf("Vetor: ");
    for (i = 0; i < N; i++) {
        printf(" %d ", vetor[i]);  
    }
    printf("\n");

    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        vetor[i] *= scalar;
    }

    #pragma omp parallel for reduction(max:maximo)
    for (i = 0; i < N; i++) {
        if (vetor[i] > maximo) {
            maximo = vetor[i];
        }
    }

    printf("Maior Elemento: %d\n", maximo);

    return 0;
}
