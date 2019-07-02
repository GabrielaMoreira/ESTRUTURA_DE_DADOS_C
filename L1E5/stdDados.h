/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

struct registro{
	int constante;
	int expoente;
	struct registro *prox;
}; 
typedef struct registro TAB_POLI;

struct registroD{
	TAB_POLI *inicio;
	TAB_POLI *final;
	int quantidade;
};
typedef struct registroD DESC_POLI;

void InicializaLista(DESC_POLI *);
int IncluiNoh(DESC_POLI *, TAB_POLI);
int ConverteConstante(int *, char *, int);
int ConverteExpoente(int *, char *);
int VerificaExpoenteNegativo(int *, char *);
int ConverteUltimoTermo(int *, char*, int);
int CalculaExpressao(DESC_POLI *, int *, int);
void ImprimeListaResp(DESC_POLI *, int);