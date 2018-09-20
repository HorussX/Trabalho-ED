#include "tad.h"

void criar(struct REGISTRO *dado){/*função usada para preencher os dados do primeiro registro*/
	printf("Insira os dados..\n");
	printf("NOME: ");
	setbuf(stdin,NULL);
	scanf("%[^\n]s",dado->nome);
	setbuf(stdin,NULL);
	printf("IDADE: ");
	scanf("%d",&dado->idade);
	setbuf(stdin,NULL);

}

int inserirIn(struct REGISTRO *inicio, struct REGISTRO aux){//Inserir no inicio
	aux.prox = inicio;
	inicio = &aux;
	return 0;
}

int inserirMeio(struct REGISTRO *inicio, struct REGISTRO dados){//inserir ordenado por idade
	struct REGISTRO *aux = (struct REGISTRO*) malloc(sizeof(struct REGISTRO));
	int i = 0, j;
	aux = inicio;
	while(dados.idade > aux->idade  && aux->prox != NULL){
		aux = aux->prox;
		i++;
	}
	if(dados.idade < aux->idade){
		dados.prox = aux;
		aux = inicio;
		for(j=0;j<i;j++){
			aux = aux->prox;
		}
		aux->prox = &dados;
	}else{
		aux->prox = &dados;
	}
}

void print(struct REGISTRO *dados){
	int i = 0;
	while(dados->prox != NULL){
		printf("---------------------------\nNome[%d]: %s\n",i+1,dados->nome);
		printf("Idade[%d]: %d",i+1,dados->idade);
	}
	printf("---------------------------\n");
}

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
		printf("---------------------------\nLISTA INICIADA\n---------------------------\n");
	}else{
		printf("LISTA NÃO INICIADA\n");
		return 0;
	}while(dec != 3){
		printf("---------------------------\n");
		printf("ESCOLHA UMA FUNÇÃO:\n---------------------------\n");
		printf("[1]INSERIR INICIO;\n[2]INSERIR;\n[3]PRINTAR\n[4]SAIR\n---------------------------\n");
		setbuf(stdin,NULL);
		scanf("%d",&dec);
		if(dec == 1){
			criar(&tabela);
			inserirIn(inicio,tabela);
		}else{
			if(dec == 2){
				criar(&tabela);
				inserirMeio(inicio,tabela);
			}
		}
	}
	return 0;
}
//Melhorar função Inserir Meio e criar função de visualização
