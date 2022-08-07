#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

/*Ordenação por Inserção:
Em cada passo a partir de i=2 faça:
Selecione o i-ésimo item da seqüência fonte.
Coloque-o no lugar apropriado na seqüência
destino de acordo com o critério de ordenação.

O número mínimo de comparações e movimentos
ocorre quando os itens estão originalmente em ordem.
 O número máximo ocorre quando os itens estão
originalmente na ordem reversa.
 É o método a ser utilizado quando o arquivo está
“quase” ordenado
 É um bom método quando se deseja adicionar uns
poucos itens a um arquivo ordenado, pois o custo é
linear.*/

int main(){
    int vet[MAX];
    int i, j, n;
    int aux = 0;

    printf("Digite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet, n);

    printf("\n");

    InsertionSort(vet,n);
    
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

void InsertionSort(int vet[], int n){
    int i, j, aux;

    for (i = 1; i < n; i++){
        aux = vet[i];
        j = i - 1;
    
        while ((j>=0) && (aux < vet[j])){
            vet[j+1] = vet[j];
            j--;
        }

        vet[j+1] = aux;
    }

    printf("Vetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d  ",vet[i]);
    }
}
 