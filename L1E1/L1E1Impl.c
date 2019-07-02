/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"L1E1.h"

void InicializaLista(TDescritor *lista){
	lista->fim = -1;
}
int IncluiNo(TDescritor *lista, TAluno dados){
	lista->fim = lista->fim + 1;
	
	lista->aluno[lista->fim] = dados;
	
	return 1;
}
void ImprimeLista(TDescritor *lista, char *cabecalho){
	int cont;
	
	if(lista->fim == -1)
		printf("Lista vazia\n");
	else{
		printf("%s\n", cabecalho);
		
		cont = 0;
		
		while(cont <= lista->fim){
			printf("%-18s %-8s %5.2f %5d\n", lista->aluno[cont].ra, lista->aluno[cont].sigla,
		   		   lista->aluno[cont].nota, lista->aluno[cont].faltas);
			cont = cont + 1;
		}	
	}
}
int ExcluiNo(TDescritor *lista, char *alunos){
	int cont, cont2;
	
	/*Procurando o no*/
	for(cont = 0;cont <= lista->fim && strcmp(lista->aluno[cont].sigla, alunos) != 0; cont++);
		
	if(cont > lista->fim)
		return 0;
	
	while(1){
		/*Localizando a sigla a excluir*/
		for(cont = 0;cont <= lista->fim && strcmp(lista->aluno[cont].sigla, alunos) != 0; cont++);
		
		if(cont > lista->fim)
			return 1;
		else{
			/*Removendo*/
			for(cont2 = cont + 1;cont2 <= lista->fim;cont2++)
				lista->aluno[cont2 - 1] = lista->aluno[cont2];
			
			lista->fim = lista->fim - 1;
		}
	}
	return 1;
}