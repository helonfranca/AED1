#include "TempExe.h"

int main(){
    int vet[MAX];
    int n,i;

    do{
    printf("\t ------------------------------------------------------------ \n");
    printf("\t|        Algortimos de Ordenacao com tempo de execucao!      |\n");
    printf("\t|------------------------------------------------------------|\n");
	printf("\t|               - Escolha o tamanho do vetor!                |\n");
    printf("\t ------------------------------------------------------------ \n");
    printf("\n\t Tamanho ate 100000: "); 
    scanf("%d",&n);

    PreenchendoVetor(vet, n);
    BubbleSort(vet, n);
    
    PreenchendoVetor(vet, n);
    selection_sort(vet, n);
    
    
    PreenchendoVetor(vet, n);
    InsertionSort(vet, n);
    
    
    PreenchendoVetor(vet, n);
    q_sort(vet, n);
   
    
    PreenchendoVetor(vet, n);
    shellSort(vet, n);
    

    printf("\nDigite 2 para sair ou qualquer outro valor para continuar: "); 
    scanf("%d", &n);
    system("cls");

    }while(n != 2);

    return 0;
}

