/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"L1E2.h"

void InicializaLista(TDescritor *lista){
	lista->inicio = NULL;
	lista->fim = NULL;
}
int IncluiNo(TDescritor *lista, TAluno dados){
	TAluno *aux;
	
	aux = (TAluno *) malloc(sizeof(TAluno));
		
	if (aux == NULL)
		return 0;
	
	*aux = dados;
	aux->prox = NULL;
	
	if (lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->fim->prox = aux;
		
	lista->fim = aux;
	
	return 1;
}
void ImprimeLista(TDescritor *lista, char *cabecalho){
	TAluno *aux;

	if (lista->inicio == NULL)
		printf("Lista vazia\n");
	else{	
	printf("%s\n", cabecalho);

		aux = lista->inicio;
		while (aux != NULL){	
			printf("%-18s %-8s %5.2f %5d\n",aux->ra, aux->sigla, aux->nota , aux->faltas);
			aux = aux->prox;
		}
	}
}
int ExcluiNo(TDescritor *lista, char *aluno){
	TAluno *aux, *ant;
		
	aux = lista->inicio;
	ant = NULL;	

 	while(aux != NULL && strcmp(aux->sigla, aluno) == 0){
		lista->inicio = aux->prox;
		aux = lista->inicio;
	}
	if(aux == NULL && lista->inicio != NULL)
		return 0;
		
	while(1){
		while(aux != NULL && strcmp(aux->sigla, aluno) != 0) {
			ant = aux;
			aux = aux->prox;
		}
		if(aux == NULL)
			return 1;
		else{
			if(ant == NULL) 
				lista->inicio = aux->prox;
			else
				ant->prox = aux->prox;
			free(aux); 
			aux = ant->prox;
		}		
	}
	return 1;
}