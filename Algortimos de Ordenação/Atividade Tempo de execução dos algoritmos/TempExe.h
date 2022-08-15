#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 50000

int menu(void){
	int opt;

	printf("\t ------------------------------------------------------------ \n");
    printf("\t|        Algortimos de Ordenacao com tempo de execucao!      |\n");
    printf("\t|------------------------------------------------------------|\n");
	printf("\t|   Escolha a opcao:                                         |\n");
	printf("\t|   1 - Tempo de execucao do BubbleSort                      |\n");
	printf("\t|   2 - Tempo de execucao do InsertionSort                   |\n");
    printf("\t|   3 - Tempo de execucao do SelectionSort                   |\n");
    printf("\t|   4 - Tempo de execucao do QuickSort                       |\n");
    printf("\t|   5 - Tempo de execucao do ShellSort                       |\n");
    printf("\t|   6 - Sair                                                 |\n");
    printf("\t ------------------------------------------------------------ \n");
    printf("\n\tOpcao: "); 
    scanf("%d", &opt);
	
	return opt;
}

void option(int opt, int vet[MAX], int n){
    system("cls");
    switch (opt){
    case 1:
        BubbleSort(vet, n);
        printf("\n");
        break;
    case 2:
        InsertionSort(vet, n);
        printf("\n");
        break;
    case 3:
        selection_sort(vet, n);
        printf("\n");
        break;
    case 4:
        system("cls");
        printf("\t-----------------------------------------------\n");
        printf("\t| Ordenacao usando o algoritmo SelectionSort!  |\n");
        printf("\t-----------------------------------------------\n\n");
        printf("\tDigite o numero de elementos que deseja ordenar: ");
        scanf("%d",&n);
        PreenchendoVetor(vet , n);
        q_sort(vet, n);
        printf("\n");
        break;
    case 5:
        shellSort(vet, n);
        printf("\n");
        break;
    case 6:
        printf("\tAdeus :*(\n");
        system("pause");
        break;
    default:
        printf("Comando invalido\n");
    }
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
    double time_spent = 0.0;

    system("cls");
    printf("\t-----------------------------------------------\n");
    printf("\t|  Ordenacao usando o algoritmo Bubble Sort!   |\n");
    printf("\t-----------------------------------------------\n\n");
    printf("\tDigite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet , n);

    clock_t begin = clock();

    for(j = n - 1; j > 0; j--){    
        for(i = 0; i < j; i++){
            if(vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }

    clock_t end = clock();

    printf("\nVetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d  ",vet[i]);
    }

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\n\nO tempo decorrido para ordenar o vetor eh de %f segundos\n", time_spent); 

    system("pause");
    system("cls"); 
}

void InsertionSort(int vet[MAX], int n){
    int i, j, aux;
    double time_spent = 0.0;

    system("cls");
    printf("\t-----------------------------------------------\n");
    printf("\t| Ordenacao usando o algoritmo InsertionSort!  |\n");
    printf("\t-----------------------------------------------\n\n");
    printf("\tDigite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet , n);

    clock_t begin = clock();

    for (i = 1; i < n; i++){
        aux = vet[i];
        j = i - 1;
    
        while ((j>=0) && (aux < vet[j])){
            vet[j+1] = vet[j];
            j--;
        }

        vet[j+1] = aux;
    }

    clock_t end = clock();

    printf("\nVetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d ",vet[i]);
    }

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\n\nO tempo decorrido para ordenar o vetor eh de %f segundos\n", time_spent);
    
    system("pause");
    system("cls"); 
}

void selection_sort(int vet[MAX], int n){
    int i, j, min, aux;
    double time_spent = 0.0;

    system("cls");
    printf("\t-----------------------------------------------\n");
    printf("\t| Ordenacao usando o algoritmo SelectionSort!  |\n");
    printf("\t-----------------------------------------------\n\n");
    printf("\tDigite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet , n);

    clock_t begin = clock();

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

    clock_t end = clock();

    printf("\nVetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d ",vet[i]);
    }

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\n\nO tempo decorrido para ordenar o vetor eh de %f segundos\n", time_spent);
    
    system("pause");
    system("cls"); 
}

void quick_sort(int vet[MAX], int left, int right){
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

void q_sort(int vet[MAX], int n){   
    int i;

    double time_spent = 0.0;
    clock_t begin = clock();
    quick_sort(vet, 0, n - 1);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nVetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d ",vet[i]);
    }
    printf("\n\nO tempo decorrido para ordenar o vetor eh de %f segundos\n", time_spent);
    
    system("pause");
    system("cls"); 
    
}

void shellSort(int *vet, int n) {
    int i , j , value;
    int gap = 1;
    double time_spent = 0.0;

    system("cls");
    printf("\t-----------------------------------------------\n");
    printf("\t|   Ordenacao usando o algoritmo ShellSort!    |\n");
    printf("\t-----------------------------------------------\n\n");
    printf("\tDigite o numero de elementos que deseja ordenar: ");
    scanf("%d",&n);

    PreenchendoVetor(vet , n);

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

    printf("\nVetor Ordenado: ");
    for(i = 0; i < n; i++){
        printf("%5d ",vet[i]);
    }

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\n\nO tempo decorrido para ordenar o vetor eh de %f segundos\n", time_spent);
    
    system("pause");
    system("cls"); 
}