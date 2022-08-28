#include "lista_1_Pilha.h"

int main() // melhorar o principal
{ Pilha *f = (Pilha*) malloc (sizeof(Pilha));;
  TCliente cl ;
	
	int i , c;
	printf("\n capacidade: ");
	scanf("%d", &c);
	criarPilha(f,c);
	
	
	for(i=0;i<3;i++){
	cl = criarCliente(cl);
	inserir(f,cl);}
	imprimeCliente(f);
	//printf("\n busca = %d",busca(f,2));
	//retirarSaldo(f, 1, 50);
	//imprimeCliente(f);
	desempilhar(f);
	imprimeCliente(f);
	desempilhar(f);
	imprimeCliente(f);
	return(1);
}