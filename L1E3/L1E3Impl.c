/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "stdDados.h"

#define TRUE	1
#define FALSE	0

/////////////////////////////////////////////////////////////////// INICIALIZA LISTA
void InicializaLista(TDescr *lst){
	lst->inicio = NULL;
	lst->final = NULL;
	lst->qtde = 0;
	lst->totPop = 0;
}

///////////////////////////////////////////////////////////////// INCLUI NÓ NA LISTA
int IncluiNoh(TDescr *lst, TCidade dados)
{
	TCidade *aux;
	
	aux = (TCidade *) malloc(sizeof(TCidade)); 		
	
	if(aux == NULL)
		return FALSE;
	
	*aux = dados; 									
	aux->prox = NULL;	
	
	if(lst->inicio == NULL)							
	{
		lst->inicio = aux;
		aux->prev = NULL;
	}		
	else
	{
		aux->prev = lst->final;
		lst->final->prox = aux;		
	}
					
	lst->final = aux;
	lst->qtde++;
	lst->totPop = lst->totPop + aux->pop;
		
	return TRUE;	
}

/////////////////////////////////////////////////////////////////// EXCLUI NÓ DA LISTA
int ExcluiNoh(TDescr *lst, char *cidade){
	TCidade *aux, *ant;
	
	aux = lst->inicio;
	ant = NULL;
	
	
	
		while(aux!= NULL && strcmp(aux->nome, cidade) != 0)	
		{
			ant = aux;
			aux = aux->prox;
		}
	
		if(aux == NULL)
			return FALSE;
		else
		{
			if(lst->qtde == 1)						/*Só há UM nó na lista e esse deve ser excluido*/
			{
				InicializaLista(lst);	
			}	
			else if(ant == NULL) 					/*O PRIMEIRO nó dexe ser excluido*/
			{	
				lst->inicio = aux->prox;
				lst->inicio->prev = NULL;
			}
			else if(aux->prox == NULL) 				/*O ULTIMO nó deve ser excluido*/
			{
				lst->final = aux->prev;
				lst->final->prox = NULL;
			}		
			else									/*Um nó do CENTRO deve ser excluido*/
			{
				ant->prox = aux->prox;
				aux->prox->prev = aux->prev;		
			}
			
		
			lst->totPop = lst->totPop - aux->pop;
			free(aux);											
			lst->qtde = lst->qtde - 1;					
		}	
	
	return TRUE;
}

//////////////////////////////////////////////////////////////// IMPRIME CONTEUDO DA LISTA
void ImprimeLista(TDescr *lst, char *cabec){
	TCidade *aux;
	
	if(lst->inicio == NULL)
		puts("\nLISTA VAZIA\n");
	else
	{
		printf("\n    %s INICIO / FIM\n", cabec);
		puts("______________________________________________");
		
		aux = lst->inicio;
		while(aux != NULL){
			printf("%-22s %7d %7.2f %7.2f\n", aux->nome, aux->pop, aux->area, aux->pop / aux->area);
			aux = aux->prox;
		}		
		printf("\n%d cidades, %d habitantes\n", lst->qtde, lst->totPop);
		
		printf("\n    %s FIM / INICIO\n", cabec);
		puts("______________________________________________");
		
		aux = lst->final;
		while(aux != NULL){
			printf("%-22s %7d %7.2f %7.2f\n", aux->nome, aux->pop, aux->area, aux->pop / aux->area);
			aux = aux->prev;
		}
		printf("\n%d cidades, %d habitantes\n", lst->qtde, lst->totPop);
	}	
}