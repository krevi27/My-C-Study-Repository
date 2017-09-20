// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: Auxiliar uma Empresa
 
   Entrada : Quantidade de funcionarios, quantidade de meses que cada funcionario trabalhou, e para cada mes, a quantidade de dias que faltou.

   Saida   :  tabela com os valores organizados.

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
#define MAX 10
#define MIN 1
int leInt(char titulo[]);
int leValidaInt(char titulo[],char msgDeErro[],int valorMin, int valorMax);
void apresentaTabela(int qtdDeFuncionarios, int qtdDeFaltasNoTrabalho[][4]);
int main(void)
{
// Declaracoes
int qtdDeFuncionarios, contador, contador2, qtdDeFaltasNoTrabalho[10][4], valorTotalDeFaltas[10];
// Instrucoes
setlocale(LC_ALL, "Portuguese");
qtdDeFuncionarios=leValidaInt("Informe a quantidade de funcionários:\n","Informe uma quantidade válida de funcionários:\n",1,10);
for(contador=0;contador<qtdDeFuncionarios;contador++){
	valorTotalDeFaltas[contador]=0;
	for(contador2=0;contador2<4;contador2++){
		system("cls");
		printf("Para o trabalhador %dº no mês %d\n",contador+1,contador2+1);
		qtdDeFaltasNoTrabalho[contador][contador2]=leValidaInt("Informe quantos dias você faltou:\n","Informe um valor válido de faltas:\n",0,30);
	}
	
}
apresentaTabela(qtdDeFuncionarios, qtdDeFaltasNoTrabalho);
  getch();
  return 0;
}
//Objetivo:
//Parametro:
//Retorno:
int leInt(char titulo[]){
	int valorInt, ret;
	do{
		printf(titulo);
		fflush(stdin);
		ret=scanf("%d",&valorInt);
		fflush(stdin);
		if(ret==0){
			printf("ERRO NA LEITURA DO VALOR INTEIRO! ");
		}
	}while(ret==0);
	return valorInt;
}
//Objetivo:
//Parametro:
//Retorno:
int leValidaInt(char titulo[],char msgDeErro[],int valorMin, int valorMax){
	int valorInt;
	valorInt=leInt(titulo);
	while(valorInt<valorMin || valorInt>valorMax){
		valorInt=leInt(msgDeErro);
	}
	return valorInt;
}
//Objetivo:
//Parametro:
//Retorno:
void apresentaTabela(int qtdDeFuncionarios, int qtdDeFaltasNoTrabalho[][4]){
	int contador,contador2,faltasTotais;
	system("cls");
	printf("Funcionário   mes1 mes2 mes3 mes4 total\n");
	for(contador=0;contador<qtdDeFuncionarios;contador++){
		printf("%11.d   ",contador+1);
		faltasTotais=0;
		for(contador2=0;contador2<4;contador2++){
			faltasTotais=faltasTotais+qtdDeFaltasNoTrabalho[contador][contador2];
		}
		for(contador2=0;contador2<4;contador2++){
			printf("%4.d" ,qtdDeFaltasNoTrabalho[contador][contador2]);
		}
			printf("%9.d",faltasTotais);
		printf("\n");
	}
}

