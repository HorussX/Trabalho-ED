#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct REGISTRO{
	char nome[50];
	int idade;
	struct REGISTRO *prox;
};
