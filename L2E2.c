/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define TRUE	1
#define FALSE	0

struct regNo{
	int valor;
	struct regNo *esq;
	struct regNo *dir;
};
typedef struct regNo TNO;

TNO *IncluiNo(TNO *, int);
TNO *AchaPai(TNO *, int);
void InicializaControles(TNO *, TNO*, int);
int ComparaArvores(TNO *, TNO *);


int main(){
	TNO *raizA, *raizB;
	int valor, identica;
	char resp;
		
	raizA = NULL;
	raizB = NULL;
	identica = FALSE;
	resp = 'S';
		
	while(resp == 'S')
	{
		printf("\nAtenção: -999 para encerrar");
		
		printf("\nInforme um noh para 1# ARVORE: ");
		while(scanf("%d", &valor), valor != -999)
		{
			printf("Informe um noh para 1# ARVORE: ");
			raizA = IncluiNo(raizA, valor);
		}
		
		printf("\nInforme um noh para 2# ARVORE: ");
		while(scanf("%d", &valor), valor != -999)
		{
			printf("Informe um noh para 2# ARVORE: ");
			raizB = IncluiNo(raizB, valor);
		}
		
		identica = ComparaArvores(raizA, raizB);
		if(identica == TRUE)
			puts("\nAS ARVORES SAO IDENTICAS");
		else
			puts("\nAS ARVORES NAO SAO IDENTICAS");
		
		raizA = NULL;
		raizB = NULL;
		printf("\nDeseja executar outro teste? (S/N): ");
		scanf(" %c", &resp);
		resp = toupper(resp);		
	}

return 0;
}

void InicializaControles(TNO *raizA, TNO *raizB, int identica){
	
	raizA = NULL;
	raizB = NULL;
	identica = FALSE;
}

TNO *IncluiNo(TNO *raiz, int valorNo){
	TNO *aux, *pai;
	
	aux = (TNO *)malloc(sizeof(TNO));
	
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

TNO *AchaPai(TNO *raiz, int valorNo){
	if(raiz == NULL)
		return NULL;
	else
		if(valorNo <= raiz->valor)
			if(raiz->esq == NULL)
				return raiz;
			else
				return AchaPai(raiz->esq, valorNo);
		else
			if(raiz->dir == NULL)
				return raiz;
			else
				return AchaPai(raiz->dir, valorNo);
}

int ComparaArvores(TNO *raizA, TNO *raizB){
	
	// As duas arvores estão vazias - IDENTICAS
    if (raizA == NULL && raizB == NULL) 
        return TRUE; 
  
    // As duas arvores não estão vazias -> COMPARA ARVORES
    if (raizA != NULL && raizB != NULL) 
    { 
        return
        ( 
            raizA->valor == raizB->valor && 
            ComparaArvores(raizA->esq, raizB->esq) && 
            ComparaArvores(raizA->dir, raizB->dir) 
        ); 
    } 
      
    // Uma arvore vazia e outra preenchida - NAO IDENTICAS
    return FALSE; 
}  
	
