#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct REGISTRO{
	char nome[50];
	int idade;
	struct REGISTRO *prox;
};

void criar(struct REGISTRO *dado);

int menu(void);

void esvaziar(struct REGISTRO *inicio);

void opcao(struct REGISTRO *dado, int x);

int inserirInicio(struct REGISTRO *inicio, struct REGISTRO aux);

int inserirPos(struct REGISTRO *inicio, struct REGISTRO dados);

int inserirFim(struct REGISTRO *inicio, struct REGISTRO dados);

void esvaziar(struct REGISTRO *inicio);

void exibir(struct REGISTRO *dados);

