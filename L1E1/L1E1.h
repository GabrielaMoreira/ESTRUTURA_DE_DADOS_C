/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/

struct sAluno{
	char ra[14];
	char sigla[6];
	float nota;
	int faltas;
};
typedef struct sAluno TAluno;

typedef struct{
	int fim;
	TAluno aluno[200];
} TDescritor;

void InicializaLista(TDescritor *);
int IncluiNo(TDescritor *, TAluno);
void ImprimeLista(TDescritor *, char *);
int ExcluiNo(TDescritor *, char *);