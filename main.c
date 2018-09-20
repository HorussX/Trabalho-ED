#include "tad.h"

int main(){
	struct REGISTRO tabela, *inicio;
	int dec;
	printf("Deseja iniciar a lista?[1][0]\n");
	setbuf(stdin,NULL);
	scanf("%d",&dec); //decisão
	setbuf(stdin,NULL);
	if(dec > 0){
		inicio = (struct REGISTRO*) malloc(sizeof(struct REGISTRO));
		inicio->prox = NULL;
		criar(inicio);
		printf("---------------------------\nLISTA INICIADA\n");
	}else{
		printf("LISTA NÃO INICIADA\n");
		return 0;
	}while(menu() != 0){
		menu();
		opcao(inicio, dec);
	}
	return 0;
}
//Melhorar função Inserir Meio e criar função de visualização
