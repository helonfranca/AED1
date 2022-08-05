#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 1000

//Ordenação por troca - útil para ordenação de vetores pequenos (desempenho ruim).

int main(){
    int vet[MAX];
    int i, j, n;
    int aux = 0;

    printf("Digite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet, n);

    printf("\n");

    BubbleSort(vet,n);
    
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
        printf("%5d",vet[i]);
    }
}

void BubbleSort(int vet[MAX], int n){
    int i, j;
    int aux = 0;

    for(j = n - 1; j > 0; j--){    
        for(i = 0; i < j; i++){
            if(vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }
    
    printf("Vetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d  ",vet[i]);
    }
}
