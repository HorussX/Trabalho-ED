#include "tad.h"

int main(){
	struct REGISTRO tabela, *inicio;
	int dec = 1;
		inicio = (struct REGISTRO*) malloc(sizeof(struct REGISTRO));
		inicio->prox = NULL;
		criar(inicio);
		printf("---------------------------\nLISTA INICIADA\n");
	while(dec != 0){
		setbuf(stdin,NULL);
		dec = menu();
		opcao(inicio, dec);
	}
	return 0;
}

