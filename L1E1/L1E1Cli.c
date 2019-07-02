/*
	AMANDA CARVALHEIRO DOS SANTOS		RA: 0030481721003
	GABRIELA CRISTINA MOREIRA FRANCO	RA: 0030481721009
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"L1E1.h"

int main(){
	TDescritor lista;
	TAluno dados;

	InicializaLista(&lista);
	while(1){
		printf("Informe o RA: (XXX para encerrar): \n");
		scanf("%s", dados.ra);
		
		if(strcmp(dados.ra, "XXX") == 0)
			break;
			
		printf("Informe a sigla da disciplina: \n");
		scanf("%s", dados.sigla);
		
		printf("Informe a nota do aluno: \n");
		scanf("%f", &dados.nota);
		
		printf("Informe a quantidade de faltas: \n");
		scanf("%d", &dados.faltas);
		
		if(IncluiNo(&lista, dados) == 0){
			printf("Memoria insuficiente\n");
			return 2;
		}
	}
	ImprimeLista(&lista, "\nDados do aluno:");
	
	while(1){
		printf("Informe a sigla que deseja excluir (XXX para encerrar): \n");
		scanf("%s", dados.sigla);
		
		if(strcmp(dados.sigla, "XXX") == 0)
			break;
		
		if(ExcluiNo(&lista, dados.sigla) != 0)
			ImprimeLista(&lista, "\nNovos dados:");
		else
			printf("Sigla nao existe\n");
	}
	return 0;
}