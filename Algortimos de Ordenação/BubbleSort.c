#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 1000

//Ordenação por troca - útil para ordenação de vetores pequenos (desempenho ruim).

int main(){
    int vet[MAX];
    int n;

    printf("Digite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet, n);

    printf("\n");
    
    double time_spent = 0.0;
 
    clock_t begin = clock();

    BubbleSort(vet,n);

    clock_t end = clock();

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\nO tempo decorrido eh de %.4f segundos", time_spent);
    
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
