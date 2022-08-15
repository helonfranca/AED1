#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 50000

//Ordenação por seleção - Um dos algoritmos mais simples de ordenação.
//Selecione o menor item do vetor.
//Troque o com o item da primeira posição do vetor
//Repita essas duas operações com os n - 1 itens restantes,
//depois com os n - 2 itens, até que reste apenas um
//elemento.

int main(){
    int vet[MAX];
    int n;

    printf("Digite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet, n);

    printf("\n");

    double time_spent = 0.0;
 
    clock_t begin = clock();

    selection_sort(vet,n);

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


void selection_sort(int vet[], int n){
    int i, j, min, aux;

    for (i = 0; i < (n-1); i++) {
        min = i;

        for (j = (i+1); j < n; j++){
            if(vet[j] < vet[min]){
                min = j; 
            } 
        }   
               
        if(i != min){
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux; 
        }
    }

    printf("Vetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d  ",vet[i]);
    }
}
 