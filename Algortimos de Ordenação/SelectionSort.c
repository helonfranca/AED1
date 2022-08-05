#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 1000

//Ordenação por seleção - Um dos algoritmos mais simples de ordenação.
//Selecione o menor item do vetor.
//Troque o com o item da primeira posição do vetor
//Repita essas duas operações com os n - 1 itens restantes,
//depois com os n - 2 itens, até que reste apenas um
//elemento.

int main(){
    int vet[MAX];
    int i, j, n;
    int aux = 0;

    printf("Digite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet, n);

    printf("\n");

    selection_sort(vet,n);
    
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
 