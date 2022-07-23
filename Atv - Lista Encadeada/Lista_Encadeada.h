#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
}; 
typedef struct Node node;

int menu(void)
{
	int opt;
	
	printf("Escolha a opcao\n");
	
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
    printf("4. Zerar Lista\n");
	printf("5. Exibir lista Inversa\n");
	printf("6. Exibir Numero de Elementos\n");
    printf("7. Encontra: Maior valor, Menor Valor e Media\n");
	printf("99. Sair \n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
} 

void opcao(node *LISTA, int op)
{   int x ;
	switch(op){	
			
		case 1:
			exibe(LISTA);
            printf("\n");
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereInicio(LISTA,x);
            printf("\n");
			break;
		
		case 3:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereFim(LISTA,x);
            printf("\n");
			break;
        case 4:
			libera(LISTA);
            printf("\n");
			break;		
			
		case 5:
            exibeinverso(LISTA);
            printf("\n");
			break;
			
		case 6:
			printf("Numero de elementos : %d\n",contador(LISTA));
            printf("\n");
			break;
		
		case 7:
			valores(LISTA);
            printf("\n");
			break;
		
		case 99:
			
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}


void inicia(node *LISTA){ //Inicializado lista 
	LISTA->prox = NULL;
    LISTA->num = NULL;
}


int vazia(node *LISTA){ //Verificação se Lista depois de alocada estar vazia
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}


void insereFim(node *LISTA,int x){ // Inserindo no FIM, entrando com o valor x e o ponteiro para lista

	node *novo=(node *) malloc(sizeof(node)); // Criando ponteiro novo e alocando memoria 

	if(!novo){                                // Em caso de não ter espaço na memoria 
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	novo->prox = NULL;                  // atribuindo novo ao ponteiro prox
	novo->num = x ;    

	if(vazia(LISTA)){
		LISTA->prox=novo;
    }
	else{
		node *tmp = LISTA->prox;  // para inserir no final devemos criar um ponteiro temporario 
		
		while(tmp->prox != NULL){  // andando pela lista com o ponteiro tmp, e quando tmp for igual a prox, prox vai ser igual novo
			tmp = tmp->prox;
        }

        tmp->prox = novo;
	}
}

void insereInicio(node *LISTA, int x){          //Inserindo no Inicio, entrando com o valor x e o ponteiro para lista

	node *novo=(node *) malloc(sizeof(node));   // Criando ponteiro novo e alocando memoria 
	
    if(!novo){
		printf("Sem memoria disponivel!\n");    // Em caso de não ter espaço na memoria 
		exit(1);
	}
	
	
	node *oldHead = LISTA->prox;        //ponteiro onldHead vai ser igual a lista, inicio
	
	LISTA->prox = novo;                 //Lista no campo prox vai ser igual ao ponteiro novo
	novo->num = x ;                     // novo vai ser igual ao num
	novo->prox = oldHead;               //novo no campo prox vai ser o inicio da lista 
}

int exibe(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return 0;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
	return 1;
}

node * busca(node *LISTA, int x, node ** ant)
{ node *ptr ;
  *ant = LISTA ;
  ptr = NULL ;	
  if(vazia(LISTA)) return NULL ;
               else 
               { ptr = LISTA->prox;
				 while (ptr != NULL) 
				     if (ptr->num == x)  break ;
				                         else 
				                           { *ant = ptr ;
					                        ptr = ptr->prox ;}
					                
					                
				return ptr ;     
               }	
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

int contador(node *LISTA)
{  int cont = 0;
    node *ptr;
    ptr = LISTA->prox;

	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

    while(ptr != NULL){			//Segue a mesma logica da funcao busca, porem percorre toda lista ate achar NULL no apontador
       cont++;
       ptr = ptr->prox;  
    }
    if( cont == 0){
        printf("Nao ha elementos na lista\n");
    }
   
	
	return cont;	
}

void exibeinverso(node *LISTA){	
    if(LISTA == NULL){
		return;
	}
	
	exibeinverso(LISTA->prox);		
	if(LISTA->num != NULL){		
		printf("  %d", LISTA->num);
	}  
}
 
int removeLista(node *LISTA, int x){
    node *aux , *ant ;
    aux = busca(LISTA, x, &ant);
  
    if(aux){ 
        ant->prox = aux->prox ;
	    free(aux);
	    return(1);
	} 
    
    else return 0 ;
}   
 
int valores(node *LISTA){ 
    
    if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	int soma = tmp->num;	//SEM ESSA DECLARACAO O SOMADOR NAO FUNCIONA
	int maior = tmp->num;
	int menor = tmp->num;
	float media;
	

	
	while( tmp->prox != NULL){
		tmp = tmp->prox;
		if(tmp->num > maior){	//Acha o maior numero da lista
			maior = tmp->num;
		}
		if(tmp->num < menor){	//Acha o menor numero da lista
			menor = tmp->num;
		}

		soma = soma + tmp->num;	//Soma dos elementos da lista
	}

	media = (float)soma/contador(LISTA); //Acessa a funcao contador para encontrar o numero de elementos

	printf("Maior: %d \n", maior);
	printf("Menor: %d \n", menor);
	printf("Media: %.1f \n", media);
}

