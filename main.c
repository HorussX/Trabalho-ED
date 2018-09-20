#include "tad.h"

int main(){
	struct REGISTRO tabela, *inicio;
	int dec;

		inicio = (struct REGISTRO*) malloc(sizeof(struct REGISTRO));
		inicio->prox = NULL;
		criar(inicio);
		printf("---------------------------\nLISTA INICIADA\n");
	}while(menu() != 0){
		menu();
		opcao(inicio, dec);
	}
	return 0;
}

