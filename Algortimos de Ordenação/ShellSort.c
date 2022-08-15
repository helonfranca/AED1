#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50000

void main(){

    int vet[MAX];
    int n, i;

    printf("Digite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet, n);

    printf("\n");

    shellSort(vet,n);

    return 0;
}

void PreenchendoVetor(int vet[MAX] ,int n){
    int i;

    srand(time(NULL));

    for(i=0; i<n; i++){
        vet[i] = 1 + rand() % 999;
    }

    printf("Vetor Preenchido: ");
    for(int i=0;i < n;i++){
        printf("%5d ",vet[i]);
    }
}

void shellSort(int *vet, int n) {
    int i , j , value;
    int gap = 1;
    double time_spent = 0.0;
 
    clock_t begin = clock();
    
    while(gap < n) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < n; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }

    clock_t end = clock();

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("Vetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d  ",vet[i]);
    }

    printf("\nO tempo decorrido eh de %f segundos", time_spent);
}