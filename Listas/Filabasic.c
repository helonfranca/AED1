#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 

}Fila;

void criarFila( Fila *f, int c ) { 

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void inserir(Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover(Fila *f ) { // pega o item do comeÃ§o da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia(Fila *f ) { // retorna verdadeiro se a fila estÃ¡ vazia

	return (f->nItens==0);

}

int estaCheia(Fila *f ) { // retorna verdadeiro se a fila estÃ¡ cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.1f\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

void main () {

	int opcao, capa;
	float valor;
	Fila f;

	// cria a fila
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&f, capa);

	// apresenta menu
	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&f)){

					printf("\nFila Cheia!!!\n\n");

				}
				else {

					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&f,valor);

				}

				break;

			case 2: // remove elemento
				if (estaVazia(&f)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					valor = remover(&f);
					printf("\n%1f removido com sucesso\n\n", valor) ; 

				}
				break;

				case 3: // mostrar fila
					if (estaVazia(&f)){

						printf("\nFila vazia!!!\n\n");

					}
					else {

						printf("\nConteudo da fila => ");
						mostrarFila(&f);

					}
					break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
}