#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX 1000

/*Quick Sort

É o algoritmo de ordenação interna mais rápido que se conhece para uma
ampla variedade de situações.

Provavelmente é o mais utilizado.

 A idéia básica é dividir o problema de ordenar um conjunto com
n itens em dois problemas menores.
 Os problemas menores são ordenados independentemente.
 Os resultados são combinados para produzir a solução final.
 A parte mais delicada do método é o processo de partição

O vetor A[Esq..Dir] é rearranjado por meio da
escolha arbitrária de um pivô x.

 O vetor A é particionado em duas partes:
– A parte esquerda com chaves menores ou iguais
a x.
– A parte direita com chaves maiores ou iguais a x.
Ordenação

Algoritmo para o particionamento:

1. Escolha arbitrariamente um pivô x.
2. Percorra o vetor a partir da esquerda até que
A[i] ≥ x.
3. Percorra o vetor a partir da direita até que A[j] ≤ x.
4. Troque A[i] com A[j].
5. Continue este processo até os apontadores i e j se
cruzarem.
*/
void main(){

    int vet[MAX];
    int n, i;

    printf("Digite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet, n);

    printf("\n");

    double time_spent = 0.0;
 
    clock_t begin = clock();

    quick_sort(vet, 0, n - 1);

    printf("Valores ordenados: ");
    for(i = 0; i < n; i++){
        printf("%5d", vet[i]);
    }

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

void quick_sort(int *vet, int left, int right){
    int i, j, x, y;
     
    i = left;
    j = right;
    x = vet[(left + right) / 2];
     
    while(i <= j) {
        while(vet[i] < x && i < right) {
            i++;
        }
        while(vet[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(vet, left, j);
    }
    if(i < right) {
        quick_sort(vet, i, right);
    }
}
