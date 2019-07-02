/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include <stdio.h>
#include<stdlib.h>

#define TRUE	1
#define FALSE	0

struct regNo{ 
	struct regNo *esq;
	int valor;
	struct regNo *dir;
};typedef struct regNo TNo;

TNo *IncluiNo(TNo *, int);
TNo *AchaPai(TNo *, int);
void imprime_infixa(TNo *);

int main(){ 
	TNo *raiz = NULL;
	int numero;
		
	while (1){ 
		printf("\nInforme o valor:\n"); 
		scanf("%d", &numero);

		if (numero == -999) 
			break;
		
		raiz = IncluiNo(raiz, numero);
	}
	imprime_infixa(raiz);
	
	return 0;
}
TNo *IncluiNo(TNo *raiz, int valorNo){
	TNo *aux, *pai;
	
	aux = (TNo *) malloc (sizeof(TNo));
	
	aux->valor = valorNo;
	aux->dir = NULL;
	aux->esq = NULL;
	
	pai = AchaPai(raiz, valorNo);
	if(pai == NULL)
		raiz = aux;
	else
		if(valorNo <= pai->valor)
			pai->esq = aux;
		else
			pai->dir = aux;
	
	return raiz;	
}
TNo *AchaPai(TNo *raiz, int valorNo){ 
	if (raiz == NULL)
		return NULL;
	else
		if (valorNo <= raiz->valor)
			if (raiz->esq == NULL)
				return raiz;
			else
				return AchaPai(raiz->esq, valorNo);
		else
			if (raiz->dir == NULL)
				return raiz;
			else
				return AchaPai(raiz->dir, valorNo);
}

void imprime_infixa(TNo *raiz){
      
	if(raiz != NULL)
	{	
		printf("<");
		
		imprime_infixa(raiz->esq);
		printf("%d", raiz->valor);
		imprime_infixa(raiz->dir);

		printf(">");
	}
	else
		printf("<>");
}