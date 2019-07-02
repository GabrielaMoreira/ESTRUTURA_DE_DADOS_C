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

int main (){
	TDescr lista;
	TCidade dadosInf;
	
	InicializaLista(&lista);

	while(TRUE)
	{
		printf("\nInforme a cidade (FIM p/ encerrar): ");
		scanf("%s", dadosInf.nome);
		
		if(strcmp(dadosInf.nome, "FIM") == 0)
			break;
		
		printf("\nPopulacao: ");
		scanf("%d", &dadosInf.pop);
		printf("\nArea: ");
		scanf("%f", &dadosInf.area);
		
		if(!IncluiNoh(&lista, dadosInf))
		{
			puts("\nMemoria insufiente para esta operacao\n");
			return 2;
		}	
	}
	
	ImprimeLista(&lista, "CONTEUDO DA LISTA");
	
	while(TRUE)
	{
		printf("\nInforme a cidade a excluir: ");
		scanf("%s", dadosInf.nome);
		puts("");
		
		if(strcmp(dadosInf.nome, "FIM") == 0)
			break;
		
		if(ExcluiNoh(&lista, dadosInf.nome))
			ImprimeLista(&lista, "NOVO CONTEUDO DA LISTA");
		else
			puts("\nCidade nao existe na lista\n");
	}

return 0;
}