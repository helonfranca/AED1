#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000000

/*Entendendo o problema:

Quick-Sort - 

Inserir tamanho do vetor desejado.
Tempo de inserção.
Tempo de ordenação.
Tempo de busca. (sequencial e binaria)
Com condição de não existir o valor no vetor.

Arvore - 

Inserir tamanho do vetor desejado.
Tempo de inserção
Tempo de busca.
Com condição de não existir o valor na arvore.

Comparação de ambos!! */

struct no{
    int info;
    struct no *esq;
    struct no *dir;
};
typedef struct no no;

void PreenchendoVetor(int *vet,long long int n){
    int i;
    double time_spent = 0.0;
    clock_t begin = clock();

    srand(time(NULL));

    for(i=0; i<n; i++){
        vet[i] = 2 + rand() % 10000;
    }

    clock_t end = clock();
    
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nO tempo de insercao foi de %f segundos\n", time_spent);

}

void quick_sort(int *vet, int left, long long int  right){
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

void q_sort(int *vet, long long int  n){   
    
    double time_spent = 0.0;
    clock_t begin = clock();
    quick_sort(vet, 0, n - 1);
    clock_t end = clock();
    
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("O algoritmo quicksort fez a ordenacao em %f segundos\n", time_spent);
    
}

int BuscaBinaria(int *vet, int x, int low, int high){
    double time_spent = 0.0;
    
    clock_t begin = clock();
    while (low <= high){
        int meio = low + (high - low) / 2;

        if(vet[meio] == x){
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\n\tO tempo de busca no algortimo de busca binaria foi de %f segundos\n", time_spent);
            return meio;
        }

        if(vet[meio] < x){
            low = meio + 1;
        }
        else{
            high = meio - 1;
        }
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\tO tempo de busca no algortimo de busca binaria foi de %f segundos\n", time_spent);
  
    return -1;
}

int BuscaSequencial(int *vet, int n, int x){
    double time_spent = 0.0;
    
    clock_t begin = clock();
    for(int i = 0; i < n; i++){    
        if (vet[i] == x){
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\n\tO tempo de busca no algortimo de busca sequencia foi de %f segundos\n", time_spent);
            return i;
        }  
    }
        
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\tO tempo de busca no algortimo de busca sequencia foi de %f segundos\n", time_spent);

    return -1;  
}

void qs(int *vet){

    int n, x;
    int ResultBusca = 0;

    printf("\t ------------------------------------------------------------ \n");
    printf("\t|                       - Quick Sort -                       |\n");
    printf("\t|------------------------------------------------------------|\n");
    printf("\t|      - Escolha o tamanho do vetor (ate 10000000)!          |\n");
    printf("\t ------------------------------------------------------------ \n");
    printf("\n\t Tamanho: "); 
    scanf("%d",&n);

    vet = (long int *) malloc(MAX*sizeof(long int));

    printf("\nSortindo valores de 0 a 10000...\n");
    PreenchendoVetor(vet, n);
    q_sort(vet, n);  

    printf("\nDigite o valor que deseja buscar: ");
    scanf("%d",&x);

    printf("\nBusca Sequencial:\n");
    ResultBusca = BuscaSequencial(vet, n, x);
    if(ResultBusca == -1){
        printf("Valor nao encontrado no vetor, refaca o processo de insercao!\n");
    }
    else{
        printf("\tPosicao do valor buscado no vetor: %d\n", ResultBusca);
    }

    printf("\nBusca binaria:\n"); 
    ResultBusca = BuscaBinaria(vet, x, 0, n-1); 
    if(ResultBusca == -1){
        printf("Valor nao encontrado no vetor!\n");
    }
    else{
        printf("\tPosicao do valor buscado no vetor: %d\n", ResultBusca);
    }    

    free(vet);
}

void pre_ordem(no *pt){
    printf("\n %d ", pt->info);

    if(pt->esq != NULL){
        pre_ordem(pt->esq);
    }
    if(pt->dir != NULL){
        pre_ordem(pt->dir);
    }
}

no *busca_arvore(no *pt, int x, int *f){

  if (pt == NULL)
  {
    *f = 0;
    return (NULL);
  }
  else if (pt->info == x)
  {
    *f = 1;
    return (pt);
  }
  else if (pt->info > x)
    if (pt->esq == NULL)
    {
      *f = 2;
      return (pt);
    }

    else
    {
      pt = pt->esq;
      busca_arvore(pt, x, f);
    }
  else if (pt->dir == NULL)
  {
    *f = 2;
    return (pt);
  }

  else
  {
    pt = pt->dir;
    busca_arvore(pt, x, f);
  }
}

no *insercao(no *pt, int x){

  no *pt1, *pt2;
  int f;
  pt1 = busca_arvore(pt, x, &f);

  if (f == 1)
  {
    return (NULL);
  }
  else
  {
    pt2 = malloc(sizeof(no));
    pt2->info = x;
    pt2->esq = NULL;
    pt2->dir = NULL;
    if (f == 0)
    {
      return (pt2);
      printf("\n 2 %d f= ", f);
    }
    else if (f == 2)
    {
      if (x < pt1->info)
        pt1->esq = pt2;
      else
        pt1->dir = pt2;
      return (pt2);
    }
  }
}

void pos_ordem(no *pt){
  if(pt->esq != NULL){
    pre_ordem(pt->esq);
  }
  if (pt->dir != NULL){
    pre_ordem(pt->dir);
    printf("\n %d ", pt->info);
  }
}

void insercaoarvore(no *pt, int n){ 
    int i;
    int x;
    int f;
    int elem;
    no *aux;
    no *tet;

    double time_spent = 0.0;
    
    clock_t begin = clock();

    for(i = 0; i < n; i++){
        x = rand() % 10000;

        if (pt == NULL){
            pt = insercao(pt, x);
        }
        else{
            insercao(pt, x);
        }
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nO tempo de insercao na arvore binaria foi de %f segundos\n", time_spent);
    
    printf("\nDigite o valor que deseja buscar: ");
    scanf("%d", &elem);
    clock_t begin1 = clock();
    aux = busca_arvore(pt, elem, &f);
    clock_t end1 = clock();
    printf("\nArvore de Busca Binaria:\n");
    if (f == 1){
        printf("\n\tElemento %d Encontrado", aux->info);
    }
    else{
        printf("\t\nElemento nao encontrado, refaca o processo de insercao!!");  
    }
    time_spent += (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("\n\tO tempo na ABB foi de %f segundos\n", time_spent);
 
}

void av(no *raiz){

    int n;
    printf("\n -------------------------------------------------------------------------------- \n");

    printf("\t -------------------------------------------------------------- \n");
    printf("\t|                       - Arvore -                             |\n");
    printf("\t|--------------------------------------------------------------|\n");
    printf("\t|          - Escolha o tamanho da arvore (ate 10000000)!       |\n");
    printf("\t|  Obs: Coloquei para definir tamanho para limitar a insercao. |\n");
    printf("\t ---------------------------------------------------------------\n");
    printf("\n\t Tamanho: "); 
    scanf("%d",&n);

    printf("\nSortindo valores de 0 a 10000...\n");
    insercaoarvore(raiz,n);

}

void main(){
  int *vet;
  no *raiz = NULL; 
  int tmp;

  printf("\t ------------------------------------------------------------ \n");
  printf("\t|         Nesse algoritmo voce sera capaz de Observar:       |\n");
  printf("\t|------------------------------------------------------------|\n");
  printf("\t|                                                            |\n");
  printf("\t|  Tempo de insercao: (Quick-Sort e Arvore).                 |\n");                
  printf("\t|  Tempo de ordenacao: (Quick-Sort).                         |\n");
  printf("\t|  Tempo de busca: (Sequencial e binaria para Quick-Sort).   |\n");
  printf("\t|  Tempo de busca: (Arvore binaria de busca).                |\n");
  printf("\t|                                                            |\n");
  printf("\t|------------------------------------------------------------|\n");
  printf("\t|                                                            |\n");
  printf("\t ------------------------------------------------------------ \n");
  system("pause");
  system("cls");

  do{   

    qs(vet);
    av(raiz);

    printf("\nDigite 0 para sair ou 1 para continuar: "); 
    scanf("%d", &tmp);
    system("cls");

  }while(tmp == 1);

  return 0;
}



