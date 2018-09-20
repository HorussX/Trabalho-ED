#include "tad.h"

int main(){
	struct REGISTRO tabela, *inicio;
	int dec = 1;
		inicio = (struct REGISTRO*) malloc(sizeof(struct REGISTRO));
		inicio->prox = NULL;
		criar(inicio);
		printf("---------------------------\nLISTA INICIADA\n");
	while(dec != 0){
		dec = menu();
		opcao(inicio, dec);
		printf("%d",dec);
		criar(inicio);
	}
	return 0;
}

