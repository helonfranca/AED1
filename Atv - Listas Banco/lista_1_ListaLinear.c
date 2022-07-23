#include "lista_1_ListaLinear.h"

int main(){  // melhorar o principal
  Lista *f = (Lista*) malloc (sizeof(Lista));;
  TCliente cl ;
	
	int i , c;
	printf("\n capacidade: ");
	scanf("%d", &c);
	criarLista(f,c);
	
	
	for(i=0;i<3;i++){
	cl = criarCliente(cl);
	inserir(f,cl);}
	imprimeCliente(f);
	printf("\n busca = %d",busca(f,3));
	retirarSaldo(f, 1, 50);
	//imprimeCliente(f);
	//retirarCliente(f,2);
	imprimeCliente(f);
	return(1);
}

