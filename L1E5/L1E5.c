/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include"stdDados.h"

#define TRUE	1
#define FALSE	0

int main(){
	int ocorrencia, cont, j, final, tamanho, flagNegativo, qtdValores;
	int numeroConvertido[2];
	int valoresX[11]; 
	char polinomio[31];
	float raiz;
	TAB_POLI dados;
	DESC_POLI lista;
		
	InicializaLista(&lista);	
	scanf("%d", &ocorrencia);
	
	for(cont = 1; cont <= ocorrencia; cont++)
	{
		scanf("%s", polinomio);
		scanf("%d", &qtdValores);
		
		for(j = 0; j < qtdValores; j++)
			scanf("%d", &valoresX[j]);
		
		tamanho = strlen(polinomio);
		polinomio[tamanho] = '\0';
		tamanho = tamanho - 1;
		
		final = tamanho;
		while(polinomio[final] != '+' && polinomio[final] != '-') /*Exclui ultimo valor (com ou sem incognita) do loop de conversao*/
			final--;		
		
		if(polinomio[0] == '-')
			flagNegativo = TRUE;
		else
		{
			flagNegativo = FALSE;
			final--;
		}
			
		
		for(numeroConvertido[0] = 0; numeroConvertido[0] < final; numeroConvertido[0] = numeroConvertido[0] + 1)
		{				
			//CALCULO PARA CONSTANTE	
			*numeroConvertido = ConverteConstante(numeroConvertido, polinomio, flagNegativo);
			dados.constante = numeroConvertido[1];			
			
			//CALCULO PARA EXPOENTE
			*numeroConvertido = ConverteExpoente(numeroConvertido, polinomio);
			dados.expoente = numeroConvertido[1];
			
			if(IncluiNoh(&lista, dados) == FALSE)
			{
				puts("\n\nMemoria insuficiente para esta operação\n\n");
				return 2;
			}
			
			/*verifica sinal de constante pois valor de posicao é incrementado ao retornar no loop*/
			if(polinomio[numeroConvertido[0]] == '-')
				flagNegativo = TRUE;				
			else
				flagNegativo = FALSE;	
		}
		
		//CALCULO PARA TERMO IDEPENDENTE
		*numeroConvertido = ConverteUltimoTermo(numeroConvertido, polinomio, flagNegativo);
		dados.constante = numeroConvertido[0];
		dados.expoente = numeroConvertido[1];
		
		if(IncluiNoh(&lista, dados) == FALSE)
		{
			puts("\n\nMemoria insuficiente para esta operação\n\n");
			return 2;
		}
		
		printf("Caso %d: ", cont);
		for(j = 0; j < qtdValores; j++)
		{
			raiz = CalculaExpressao(&lista, valoresX, j);
			printf("%8.2f ", raiz);
		}
		puts("");
		InicializaLista(&lista);
	}	
return 0;
}