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

/////////////////////////////////////////////////////////////////// INICIALIZA LISTA
void InicializaLista(DESC_POLI *descritor){
	descritor->inicio = NULL;
	descritor->final = NULL;
	descritor->quantidade = 0;
}

///////////////////////////////////////////////////////////////// INCLUI NÓ NA LISTA
int IncluiNoh(DESC_POLI *lista, TAB_POLI dado){
	
	TAB_POLI *aux;
	
	aux = (TAB_POLI *)malloc(sizeof(TAB_POLI));
	
	if(aux == NULL)
		return FALSE;
	
	*aux = dado;
	aux->prox = NULL;
	
	if(lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->final->prox = aux;
	
	lista->final = aux;
	lista->quantidade++;
	
	return TRUE;	
}

///////////////////////////////////////////////////////////////// CONVERTE A CONSTANTE
int ConverteConstante(int *constante, char *polinomio, int flagNegativo){
	int j, numero, inicio, posicao;
		
	numero = 0;	
	inicio = constante[0];
	posicao = constante[0];	
	
	while(polinomio[posicao] != 'x' && polinomio[posicao] != 'X' && polinomio[posicao] != '\0'){
		posicao++;
	}			
	
	/*Valor é sinal seguido ou sucedido de incognita em qualquer outra posição OU Primeiro valor é sinal negativo seguido de incognita*/
	if((inicio == posicao) || (inicio == 0 && posicao == 1 && polinomio[0] == '-')) 
	{
		numero = 1;
	}
	else
	{
		for(j = inicio; j < posicao; j++)
		{
			if(polinomio[j] != '+' && polinomio[j] != '-' && polinomio[j] != '\0')
				numero = (numero + (polinomio[j] - '0')) * 10;	
			}
			numero = numero/10;				
	}
			
	if(flagNegativo == TRUE)
		numero = numero * -1;
		
	constante[0] = posicao;
	constante[1] = numero;
				
	return *constante;
}

///////////////////////////////////////////////////////////////// CONVERTE  O EXPOENTE
int ConverteExpoente(int *expoente, char *polinomio){
	int j, numero, inicio, posicao, flagExpoNegativo;
	int expoNegativo[2];	
	
	numero = 0;
	inicio = expoente[0];
	posicao = expoente[0] + 1; /*avança caracter x*/
	
	inicio = posicao;			
	while(polinomio[posicao] != '+' && polinomio[posicao] != '-' && polinomio[posicao] != '\0'){
		posicao++;
	}
	
	expoNegativo[0] = posicao;
	*expoNegativo = VerificaExpoenteNegativo(expoNegativo, polinomio);
	flagExpoNegativo = expoNegativo[1];
	
	if(flagExpoNegativo == TRUE)
	{
		
		posicao = expoNegativo[0];
		for(j = inicio; j < posicao; j++)
		{
			if(polinomio[j] != '+' && polinomio[j] != '-' && polinomio[j] != '\0')
				numero = (numero + (polinomio[j] - '0')) * 10;	
		}
		numero = numero/10;					
		numero = numero * -1;				
	}
	else
	{
		if(inicio == posicao)
			numero = 1;					
		else
		{
			for(j = inicio; j < posicao; j++)
			{
				if(polinomio[j] != '+' && polinomio[j] != '-')
					numero = (numero + (polinomio[j] - '0')) * 10;	
			}
			numero = numero/10;				
		}
	}
	
	expoente[0] = posicao;
	expoente[1] = numero;
	
	return *expoente;	
}

///////////////////////////////////////////////////////////////// VERIFICA SE É EXPOENTE NEGATIVO
int VerificaExpoenteNegativo(int *expoenteNegativo, char *polinomio){
	int posicaoNegativo, flagExpoNegativo;
	
	posicaoNegativo = expoenteNegativo[0] + 1;
	while(polinomio[posicaoNegativo] != '+' && polinomio[posicaoNegativo] != '-' && polinomio[posicaoNegativo] != 'x' && polinomio[posicaoNegativo] != 'X' && polinomio[posicaoNegativo] != '\0'){
		posicaoNegativo++;
	}
						
	if(polinomio[posicaoNegativo] == '-' || polinomio[posicaoNegativo] == '+')
		flagExpoNegativo = TRUE;
	else
		flagExpoNegativo = FALSE;
	
	
	expoenteNegativo[0] = posicaoNegativo;
	expoenteNegativo[1] = flagExpoNegativo;
	
	return *expoenteNegativo;
}

///////////////////////////////////////////////////////////////// CONVERTE TERMO IDEPENDENTE
int ConverteUltimoTermo(int *ultimoTermo, char *polinomio, int flagNegativo){
	int numero, posicao, inicio;
	
	posicao = ultimoTermo[0];
	inicio = ultimoTermo[0];
	numero = 0;
	
	while(polinomio[posicao] != '\0' && polinomio[posicao] != 'x' && polinomio[posicao] != 'X' && polinomio[posicao] != '\0'){
			numero = (numero + (polinomio[posicao] - '0')) * 10;
			posicao++;
	}
		
	if(polinomio[posicao] == 'x' || polinomio[posicao] == 'X')
	{
		ultimoTermo[0] = inicio;
		*ultimoTermo = ConverteConstante(ultimoTermo, polinomio, flagNegativo);
		numero = ultimoTermo[1];
		*ultimoTermo = ConverteExpoente(ultimoTermo, polinomio);
		ultimoTermo[0]= numero;
		
	}
	else
	{
		numero = numero/10;
		
		if(flagNegativo == TRUE)
			numero = numero * -1;
		
		ultimoTermo[0] = numero;
		ultimoTermo[1] = 0;
	}
	
	return *ultimoTermo;
}

////////////////////////////////////////////////////////// IMPRIME CONTEUDO DA LISTA
void ImprimeLista(DESC_POLI *lista, int cont){
	TAB_POLI *aux;
	
	if(lista->inicio == NULL)
		puts("\nLista Vazia");
	else
	{
		printf("Caso %d: ", cont);
		
		aux = lista->inicio;
		while(aux != NULL)
		{
			printf("%d %d\n", aux->constante, aux->expoente);
			aux = aux->prox;
		}
		puts("");	
	}
}

////////////////////////////////////////////////// CALCULA RESULTADO DA EXPRESSAO COM VALOR DE X INFORMADO
int CalculaExpressao(DESC_POLI *lista, int *valorX, int posicao){
	TAB_POLI *aux;
	int x;
	float resp;
	
	resp = 0;
	x = valorX[posicao];
	
	aux = lista->inicio;
	while(aux != NULL)
	{
		resp = resp + (pow(x,aux->expoente) * aux->constante);
		aux = aux->prox;
	}
	
	return resp;
}