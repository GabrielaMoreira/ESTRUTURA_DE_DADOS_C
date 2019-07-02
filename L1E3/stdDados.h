/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
struct regCid{
	char nome[21];
	int pop;
	float area;
	struct regCid *prox;
	struct regCid *prev;
}; typedef struct regCid TCidade;

typedef struct {
	TCidade *inicio, *final;
	int qtde, totPop;
}TDescr;

void InicializaLista(TDescr *);
int IncluiNoh(TDescr *, TCidade);
int ExcluiNoh(TDescr *, char *);
void ImprimeLista(TDescr *, char *);