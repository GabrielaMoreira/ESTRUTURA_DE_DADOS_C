/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include"stdDados.h"

#define TRUE	1
#define	FALSE	0

/////////////////////////////////////////////////////////////////// INICIALIZA LISTA
void InicializaLista_1(DESC_LISTA_1 *lst){
	lst->inicio = NULL;
	lst->final = NULL;
	lst->quantidade = 0;
}
void InicializaLista_2(DESC_LISTA_2 *lst){
	lst->inicio = NULL;
	lst->final = NULL;
	lst->quantidade = 0;
}
void InicializaLista_3(DESC_LISTA_3 *lst){
	lst->inicio = NULL;
	lst->final = NULL;
	lst->quantidade = 0;
}

///////////////////////////////////////////////////////////////// INCLUI NÓ NA LISTA
int IncluiNoh_1(DESC_LISTA_1 *lst, LISTA_1 dados){
	LISTA_1 *aux;
	
	aux = (LISTA_1 *) malloc(sizeof(LISTA_1));
	
	if(aux == NULL)
		return FALSE;
		
	*aux = dados;
	aux->prox = NULL;
	
	if(lst->inicio == NULL)
		lst->inicio = aux;
	else
		lst->final->prox = aux;
	
	lst->final = aux;
	lst->quantidade++;
	
	return TRUE;
}
int IncluiNoh_2(DESC_LISTA_2 *lst, LISTA_2 dados){
	LISTA_2 *aux;
	
	aux = (LISTA_2 *) malloc(sizeof(LISTA_2));
	
	if(aux == NULL)
		return FALSE;
		
	*aux = dados;
	aux->prox = NULL;
	
	if(lst->inicio == NULL)
		lst->inicio = aux;
	else
		lst->final->prox = aux;
	
	lst->final = aux;
	lst->quantidade++;
	
	return TRUE;
}
int IncluiNoh_3(DESC_LISTA_3 *lst, LISTA_3 dados){
	LISTA_3 *aux;
	
	aux = (LISTA_3 *) malloc(sizeof(LISTA_3));
	
	if(aux == NULL)
		return FALSE;
		
	*aux = dados;	
	aux->prox = NULL;
	
	if(lst->inicio == NULL)
		lst->inicio = aux;
	else
		lst->final->prox = aux;
	
	lst->final = aux;
	lst->quantidade++;
	
	return TRUE;
}

////////////////////////////////////////////////////////// IMPRIME CONTEUDO DA LISTA
void ImprimeLista_1(DESC_LISTA_1 *lst, char *cabec){
	LISTA_1 *aux;
	
	if(lst->inicio == NULL)
		puts("\nLista Vazia");
	else
	{
		printf("%s", cabec);
		
		aux = lst->inicio;
		while(aux != NULL)
		{
			printf("%6.2f ", aux->numero);
			aux = aux->prox;
		}
		puts("");	
	}
}
void ImprimeLista_2(DESC_LISTA_2 *lst, char *cabec){
	LISTA_2 *aux;
	
	if(lst->inicio == NULL)
		puts("\nLista Vazia");
	else
	{
		printf("%s", cabec);			
		
		aux = lst->inicio;
		while(aux != NULL)
		{
			printf("%6.2f ", aux->numero);
			aux = aux->prox;
		}
		puts("");
	}
}
void ImprimeLista_3(DESC_LISTA_3 *lst, char *cabec){
	LISTA_3 *aux;
	
	if(lst->inicio == NULL)
		puts("\nLista Vazia");
	else
	{
		printf("%s", cabec);			
		
		aux = lst->inicio;
		while(aux != NULL)
		{
			printf("%6.2f ", aux->numero);
			aux = aux->prox;
		}
		puts("");
	}
}

///////////////////////////////////////////////////////////////////////// SOMA LISTAS E INCLUI NA LISTA 3
void SomaLista(DESC_LISTA_1 *lst1, DESC_LISTA_2 *lst2, DESC_LISTA_3 *lst3){
	LISTA_1 		*aux1;
	LISTA_2 		*aux2;
	LISTA_3			dados;	
	
	float soma;
	int cont;
	
	cont = 0;
	aux1 = lst1->inicio;
	aux2 = lst2->inicio;
			
	if(lst1->quantidade < lst2->quantidade)					/* Lista 1 MENOR que Lista 2*/
	{
		while(cont < lst1->quantidade){
			soma = aux1->numero + aux2->numero;
			dados.numero = soma;
			
			IncluiNoh_3(lst3, dados);
			
			aux1 = aux1->prox;
			aux2 = aux2->prox;
			cont++;
		}		
		while(cont < lst2->quantidade){
			dados.numero = aux2->numero;
			IncluiNoh_3(lst3, dados);
			
			aux2 = aux2->prox;
			cont++;
		}
	}
	else if(lst2->quantidade < lst1->quantidade)			/* Lista 2 MENOR que Lista 2*/
	{
		while(cont < lst2->quantidade){
			soma = aux1->numero + aux2->numero;
			dados.numero = soma;
			
			IncluiNoh_3(lst3, dados);
			
			aux1 = aux1->prox;
			aux2 = aux2->prox;
			cont++;
		}		
		while(cont < lst1->quantidade){
			dados.numero = aux1->numero;
			IncluiNoh_3(lst3, dados);
			
			aux1 = aux1->prox;
			cont++;
		}
	}
	else if(lst1->quantidade == lst2->quantidade)		  /* Listas com MESMO TAMANHO*/
	{
		while(cont < lst1->quantidade){
			soma = aux1->numero + aux2->numero;
			dados.numero = soma;
			
			IncluiNoh_3(lst3, dados);
			
			aux1 = aux1->prox;
			aux2 = aux2->prox;
			cont++;
		}
	}	
}
