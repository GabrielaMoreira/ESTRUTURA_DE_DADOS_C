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
#define FALSE	0

int main(){
	LISTA_1 		dados1;
	LISTA_2			dados2;	
	DESC_LISTA_1 	lista1;
	DESC_LISTA_2	lista2;
	DESC_LISTA_3	lista3;
		
	InicializaLista_1(&lista1);
	InicializaLista_2(&lista2);
	InicializaLista_3(&lista3);
	
	printf("\nInforme um numero (LISTA 1): ");
	while(scanf("%f", &dados1.numero), dados1.numero >= 0)
	{
		if(IncluiNoh_1(&lista1, dados1) == FALSE)
		{
			puts("\n\nMemoria insuficiente para esta operação\n\n");
			return 2;
		}
		printf("\nInforme um numero (LISTA 1): ");
	}
	
	printf("\nInforme um numero (LISTA 2): ");
	while(scanf("%f", &dados2.numero), dados2.numero >= 0)
	{
		if(IncluiNoh_2(&lista2, dados2) == FALSE)
		{
			puts("\n\nMemoria insuficiente para esta operação\n\n");
			return 2;
		}	
		printf("\nInforme um numero (LISTA 2): ");
	}
	puts("");
	
	ImprimeLista_1(&lista1, "\nLista 1: ");
	ImprimeLista_2(&lista2, "Lista 2: ");
	
	SomaLista(&lista1, &lista2, &lista3);
	
	ImprimeLista_1(&lista1, "\nLista 1: ");
	ImprimeLista_2(&lista2, "Lista 2: ");
	ImprimeLista_3(&lista3, "Lista 3: ");

return 0;
}