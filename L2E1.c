/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
#include<stdio.h>
#include<stdlib.h>

struct regNo{
	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo *IncluiNo(TNo *raiz, int numero);
TNo *AchaPai(TNo *r, int n);
int ImprimeArvore(TNo *r, int n);
int MaiorNo(TNo *r);
int MenorNo(TNo *r);
int ContaFolhas(TNo *r);
int ContaNos (TNo *r);
int ProcuraNo(TNo *r, int numero);
int AlturaArvore(TNo *r);


int main(){
	TNo *raiz = NULL;
	int numero, resposta;
	
	while(1){
		printf("\nInforme o valor:\n");
		scanf("%d", &numero);
		
		if(numero < 0)
			break;
			
		raiz = IncluiNo(raiz, numero);
	}
	ImprimeArvore(raiz, 0);
	
	/*Imprimindo a função MaiorNo*/
	printf("\nO maior valor da arvore eh: %d.\n", MaiorNo(raiz));
	
	/*Imprimindo a função MenorNo*/
	printf("\nO menor valor da arvore eh: %d.\n", MenorNo(raiz));
	
	/*Quantidade folhas e nós*/
	printf("\nA arvore possui %d folhas.\n", ContaFolhas(raiz) );
	printf("\nA arvore possui %d elementos.\n", ContaNos(raiz));
	
	/*Altura da árvore*/
	printf("\nA altura da arvore eh: %d.\n", AlturaArvore(raiz));
	
	/*Procurando o No*/
	printf("\nInforme um valor para pesquisa:\n");
			scanf("%d", &numero);
			
			resposta = ProcuraNo(raiz, numero);
			
			if(resposta == 1)
				printf("%d existe na arvore\n", numero);
			else
				printf("%d nao existe na arvore\n", numero);
	
	return 0;
}
TNo *IncluiNo(TNo *raiz, int numero){
	TNo *pai, *aux;
	
	aux = (TNo *) malloc(sizeof(TNo));
		
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;
		
		/*Fazendo o encadeamento do novo noh*/
		pai = AchaPai(raiz, numero);
		
		if(pai == NULL)
			raiz = aux;
		else
			if(numero <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
			
		return raiz;
}
TNo *AchaPai(TNo *r, int n){
	if(r == NULL)
		return NULL;
	else
		if(n <= r->valor)
			/*n é descendente do lado esquerdo de r*/
			if(r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, n);
		else
			/*n é descendente do lado direito de r*/
			if(r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, n);
}
int ImprimeArvore(TNo *r, int n){
	int c;
	
	if(r != NULL){
		for(c = 0;c < n;c++)
			printf("\t");
		printf("%d\n", r->valor);
		
		ImprimeArvore(r->esq, n + 1);
		ImprimeArvore(r->dir, n + 1);
	}
	return 0;
}
int ProcuraNo(TNo *r, int numero){
		
	if(r == NULL)
		return 0;
	
	if(r->valor == numero)
		return 1;
	
	if(r->valor > numero)
		return ProcuraNo(r->esq, numero);
	else
		return ProcuraNo(r->dir, numero);
}
int MaiorNo(TNo *r){
	while(r->dir != NULL){
		r = r->dir;
	}
	return r->valor;
}
int MenorNo(TNo *r){
	while(r->esq != NULL){
		r = r->esq;
	}
	return r->valor;
}
int ContaFolhas(TNo *r){
   if(r == NULL)
        return 0;
   if(r->esq == NULL && r->dir == NULL)
        return 1;
   return ContaFolhas(r->esq) + ContaFolhas(r->dir);
}
int ContaNos(TNo *r){
	if(r == NULL)
		return 0;
	else
		return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}
int AlturaArvore(TNo *r) {
	int altEsquerda, altDireita;
   if (r == NULL) 
      return -1; // altura da árvore vazia
   else {
    altEsquerda = AlturaArvore (r->esq);
    altDireita = AlturaArvore (r->dir);
      if (altEsquerda < altDireita) 
		return altDireita + 1;
      else 
		return altEsquerda + 1;
   }
}