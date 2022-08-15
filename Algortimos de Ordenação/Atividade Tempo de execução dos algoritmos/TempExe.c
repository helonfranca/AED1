#include "TempExe.h"
#define MAX 50000

int main(){
    int vet[MAX];
    int n;
    int opt;
	
	do{
		opt=menu();
		option(opt,vet,n);
	}while(opt!=6);

    return 0;
}

