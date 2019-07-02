/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/
struct registro{
	float numero;
	struct registro *prox;
};

typedef struct registro LISTA_1;
typedef struct registro LISTA_2;
typedef struct registro LISTA_3;

typedef struct {
	LISTA_1 *inicio;
	LISTA_1 *final;
	int quantidade;
}DESC_LISTA_1;

typedef struct {
	LISTA_2 *inicio;
	LISTA_2 *final;
	int quantidade;
}DESC_LISTA_2;

typedef struct {
	LISTA_3 *inicio;
	LISTA_3 *final;
	int quantidade;
}DESC_LISTA_3;


/*FUNÇÕES PARA LISTA 1*/
void InicializaLista_1(DESC_LISTA_1 *);
int IncluiNoh_1(DESC_LISTA_1 *, LISTA_1);
int ExcluiNoh_1(DESC_LISTA_1 *, char *);
void ImprimeLista_1(DESC_LISTA_1 *, char *);

/*FUNÇÕES PARA LISTA 2*/
void InicializaLista_2(DESC_LISTA_2 *);
int IncluiNoh_2(DESC_LISTA_2 *, LISTA_2);
int ExcluiNoh_2(DESC_LISTA_2 *, char *);
void ImprimeLista_2(DESC_LISTA_2 *, char *);

/*FUNÇÕES PARA LISTA 3*/
void InicializaLista_3(DESC_LISTA_3 *);
int IncluiNoh_3(DESC_LISTA_3 *, LISTA_3);
void ImprimeLista_3(DESC_LISTA_3 *, char *);
void SomaLista(DESC_LISTA_1 *, DESC_LISTA_2 *, DESC_LISTA_3 *);
