// Aluno : Victor Oliveira Kreniski	

/*
 Sintese
   Objetivo: Auxiliar uma empresa
 
   Entrada : matricula do funcionario, salario, se deseja continuar ou não.

   Saida   :  As matriculas com os respectivos salarios, maior e menor salario.

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
#define MAX_FUNCIONARIO 500
#define MIN_FUNCIONARIO 2
#define MAX_SALARIO 31000
#define MIN_SALARIO 880
#define MAX_MATRICULA 500
#define MIN_MATRICULA 0
typedef struct Funcionario{
	int matriculaDoFuncionario;
	float salarioDoFuncionario;
}Funcionario;
void leValidaFloat(char titulo[],char msgErro[],float *valorFloat,int valorMax,int valorMin);
void leValidaInt(char titulo[],char msgErro[],int *valorInt,int valorMax,int valorMin);
void obtemMaiorEmMenorSalario(Funcionario *funcionarios,int contadorFuncionario,float *maiorSalario,float *menorSalario);
char leValidaOpcao(char *opcoes);
int main(void)
{
// Declaracoes
Funcionario funcionarios[MAX_FUNCIONARIO];
int contadorFuncionario=0;
char opcao;
float maiorSalario,menorSalario;
int contador;
// Instrucoes
	do{
		system("cls");
		leValidaInt("Informe a matricula do funcionário\n","ERRO! Informe uma matricula corretamente\n",&funcionarios[contadorFuncionario].matriculaDoFuncionario,MAX_MATRICULA,MIN_MATRICULA);
		leValidaFloat("Informe o salário do funcionário\n","ERRO! Respeite os valores min e max\n",&funcionarios[contadorFuncionario].salarioDoFuncionario,MAX_SALARIO,MIN_SALARIO);
		contadorFuncionario++;
		printf("Deseja continuar?\n");
		opcao=leValidaOpcao("SN");
		if(opcao=='N'){
			printf("Uma tabela vai ser apresentada\n");
			getch();
		}
	}while(opcao=='S' || contadorFuncionario>=MAX_MATRICULA);
	system("cls");
	obtemMaiorEmMenorSalario(funcionarios,contadorFuncionario,&maiorSalario,&menorSalario);
	for(contador=0;contador<contadorFuncionario;contador++){
		printf("Matricula: %3d e Salario: %5.2f\n",(funcionarios+contador)->matriculaDoFuncionario,(funcionarios+contador)->salarioDoFuncionario);
	}
		printf("Maior Salario: %.2f\n",maiorSalario);
		printf("Menor Salario: %.2f\n",menorSalario);
  getch();
  return 0;
}
//Objetivo: validar a opcao
//Parametro: referencia a string opcoes
//Retorno: S ou N
char leValidaOpcao(char *opcoes){
	char opcao;
	printf("S-N\n");
	opcao=getch();
	opcao=toupper(opcao);
	while(strchr(opcoes,opcao)==NULL){
		printf("Informe corretamente\n");
		printf("S-N\n");
		opcao=getch();
		opcao=toupper(opcao);
	}
	return opcao;
}
//Objetivo: obter maior salario e menor salario
//Parametro: endereco de funcionarios, contador de funcionario, endereco de maior salario, endereco de menor salario
//Retorno:
void obtemMaiorEmMenorSalario(Funcionario *funcionarios,int contadorFuncionario,float *maiorSalario,float *menorSalario){
	int contador;
	*maiorSalario=funcionarios->salarioDoFuncionario,*menorSalario=funcionarios->salarioDoFuncionario;
	for(contador=0;contador<contadorFuncionario;contador++){
		if(*maiorSalario<(funcionarios[contador]).salarioDoFuncionario){
			*maiorSalario=(funcionarios[contador]).salarioDoFuncionario;
		}else{
			if(*menorSalario>(funcionarios[contador]).salarioDoFuncionario){
				*menorSalario=(funcionarios[contador]).salarioDoFuncionario;
			}
		}
	}
}
//Objetivo: ler e validar float
//Parametro: endereco do valor float
//Retorno: 
void leValidaFloat(char titulo[],char msgErro[],float *valorFloat,int valorMax,int valorMin){
	int ret;
	do{
		do{
			ret=0;
			printf(titulo);
			fflush(stdin);
			ret=scanf("%f",valorFloat);
			fflush(stdin);
			if(ret==0){
				printf("ERRO NO VALOR REAL\n");
			}
		}while(ret==0);
		if(*valorFloat < valorMin || *valorFloat > valorMax){
			printf(msgErro);
		}
	}while(*valorFloat < valorMin || *valorFloat > valorMax);
}
//Objetivo: ler e validar float
//Parametro: endereco do valor float
//Retorno: 
void leValidaInt(char titulo[],char msgErro[],int *valorInt,int valorMax,int valorMin){
	int ret;
	do{
		do{
			ret=0;
			printf(titulo);
			fflush(stdin);
			ret=scanf("%d",valorInt);
			fflush(stdin);
			if(ret==0){
				printf("ERRO NO VALOR INTEIRO\n");
			}
		}while(ret==0);
		if(*valorInt < valorMin || *valorInt > valorMax){
			printf(msgErro);
		}
	}while(*valorInt < valorMin || *valorInt > valorMax);
}
