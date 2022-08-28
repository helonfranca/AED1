#include "tabelaHashexercicios.h"

int main(void)
{
	Hash tab;
	int opt;
	inicializaHash(tab);

	do
	{
		opt = menu();
		opcao(tab, opt);
	} while (opt != 6);

	return 0;
}
