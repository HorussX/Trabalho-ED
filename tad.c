#include "tad.h"

int tam = 0;

void criar(struct REGISTRO *dado){/*função usada para preencher os dados do primeiro registro*/
	printf("Insira os dados..\n");
	printf("NOME: ");
	setbuf(stdin,NULL);
	scanf("%[^\n]s",dado->nome);
	setbuf(stdin,NULL);
	printf("IDADE: ");
	setbuf(stdin,NULL);
	scanf("%d",&dado->idade);
	setbuf(stdin,NULL);
}

int menu(){
	int dec;
	printf("---------------------------\n");
	printf("Escolha uma opção\n");
	printf("[0] Sair\n");
	printf("[1] Inserir no inicio\n");
	printf("[2] Escolher onde inserir\n");
	printf("[3] Inserir no final\n");
	printf("[4] Esvaziar lista\n");
	printf("[5] Exibir lista\n");
	setbuf(stdin,NULL);
	scanf("%d",&dec);
	return dec;
}

void opcao(struct REGISTRO *dado, int x){
	struct REGISTRO reg;
	reg.prox = NULL;
	switch(x){
		case 1:
			criar(&reg);
			inserirInicio(dado,reg);
			break;
		/*case 2:
			criar(&reg);
			inserirPos(dado,reg);
			break;*/
		case 3:
			criar(&reg);
			inserirFim(dado,reg);
			break;
		case 4:
			esvaziar(dado);
			break;
		case 5:
			exibir(dado);
			break;
	}
}

int vazia(struct REGISTRO *inicio){ //verifica se a lista está vazia
	if(inicio->prox == NULL){
		return 1;
	}else{
		return 0;
	}
}
int inserirInicio(struct REGISTRO *inicio, struct REGISTRO aux){//Inserir no inicio da lista
	aux.prox = inicio;
	inicio->prox = &aux;
	tam++;
	return 0;
}

/*int inserirPos(struct REGISTRO *inicio, struct REGISTRO dados){
	
}*/

int inserirFim(struct REGISTRO *inicio, struct REGISTRO dados){//insere um elemento no fim da lista
	struct REGISTRO *aux = malloc(sizeof(struct REGISTRO));
	dados.prox = NULL;
	if(vazia(inicio)){
		inicio->prox = &dados;
	}else{
		aux->prox = inicio;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = &dados;
	}
	tam++;
}

void esvaziar(struct REGISTRO *inicio){//esvazia a lista
	inicio->prox = NULL;
	tam = 0;
}

void exibir(struct REGISTRO *dados){ //exibe todos os registros da lista
	int i = 0;
	struct REGISTRO *aux = (struct REGISTRO*)malloc(sizeof(struct REGISTRO));
	aux = dados;
	while(1){
		printf("---------------------------\n");
		printf("Nome[%d]: %s\n",i+1,aux->nome);
		printf("Idade[%d]: %d\n",i+1,aux->idade);
		if(aux->prox == NULL){
			break;
		}
		aux = aux->prox;
		i++;
	}
	printf("---------------------------\n");
}

