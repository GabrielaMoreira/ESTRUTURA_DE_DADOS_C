 /*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

#define MAX_TAM		5000

struct regCid { 
	char nome[21];
	int pop;
	float area;
	float pib;
	float idh;
}TCidade[MAX_TAM];

void InsereEmHeap(int, struct regCid *);
void ImprimeArvore(struct regCid *, char *, int);
void ReorgHeap(int, struct regCid *);

int main(){	
	int i, qtdCidades, cont;
	struct regCid aux;
	
	i = 1;
		
	printf("Informe o numero de cidades beneficiadas: ");
	scanf("%d", &qtdCidades);	
	
	while (TRUE)
	{	
		printf("\nInforme a cidade (FIM p/ encerrar):\n");
		scanf("%s", TCidade[i].nome);
		
		if (strcmp(TCidade[i].nome, "FIM") == 0)
			break;
		
		printf("Populacao: ");
		scanf(" %d", &TCidade[i].pop);
		
		printf("Area: ");
		scanf(" %f", &TCidade[i].area);
		
		printf("PIB: ");
		scanf(" %f", &TCidade[i].pib);
		
		printf("IDH: ");
		scanf(" %f", &TCidade[i].idh);
		
		i++;
		
		if(i == MAX_TAM)
		{
			puts("Lista Lotada!");
			break;
		}
	}
		
	for(cont = 1; cont <= i; cont++)
		InsereEmHeap(cont, TCidade);
	
	i--;
	while (i >= 1)
	{	aux = TCidade[1];		
		TCidade[1] = TCidade[i];	
		TCidade[i] = aux;		
		
		i = i - 1;
		ReorgHeap(i, TCidade);		
	}
	
	ImprimeArvore(TCidade, "\n\n\t\t\t\tCONTEUDO DA LISTA\n___________________________________________________________________________________", qtdCidades);
	
return 0;
}

void InsereEmHeap(int cont, struct regCid *vetor)
{	
	struct regCid aux;
	int posicao = cont + 1;
	
	while (posicao > 1 && vetor[posicao / 2].idh < vetor[posicao].idh)
	{	
		aux = vetor[posicao / 2];
		vetor[posicao / 2] = vetor[posicao];
		vetor[posicao] = aux;
		posicao = posicao / 2;
	}
}

void ReorgHeap(int cont, struct regCid *vetor)
{	
	int posicao = 2;
	struct regCid aux;

	while (posicao <= cont)
	{	
		if(posicao < cont && vetor[posicao].idh < vetor[posicao + 1].idh)
			posicao++;
		
		if (vetor[posicao / 2].idh >= vetor[posicao].idh)
			break;

		aux = vetor[posicao / 2];
		vetor[posicao / 2] = vetor[posicao];
		vetor[posicao] = aux;

		posicao *= 2;
	}
}

void ImprimeArvore(struct regCid *arvore, char *cabec, int qtdCidades)
{	
	int cont, totPop;	
	totPop = 0;
	
	if(arvore[0].nome == '\0')
        puts("Lista vazia");
	else
	{
		printf("%s\n", cabec);
		for (cont = 1; cont <= qtdCidades ; cont++) 
		{	
			printf("CIDADE: %-22s POPULACAO: %7d AREA: %7.2f PIB: %5.2f IDH: %2.2f\n", 
					arvore[cont].nome, 
					arvore[cont].pop, 
					arvore[cont].area, 
					arvore[cont].pib, 
					arvore[cont].idh);
					
			totPop = totPop + arvore[cont].pop;
		}
	}
	printf("\n%d cidades, populacao total %d\n", qtdCidades, totPop);	
}