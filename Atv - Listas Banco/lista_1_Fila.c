#include "Lista_1_Fila.h"

int main() // melhorar o principal
{ Fila*f = (Fila*) malloc (sizeof(Fila));;
  TCliente cl ;
	
	int i , c;
	printf("\n capacidade: ");
	scanf("%d", &c);
	criarLista(f,c);
	
	
	for(i=0;i<3;i++){
	cl = criarCliente(cl);
	inserir(f,cl);}
	imprimeCliente(f);
	//printf("\n busca = %d",busca(f,2));
	//retirarSaldo(f, 1, 50);
	//imprimeCliente(f);
	retirarCliente(f);
	imprimeCliente(f);
	return(1);
}