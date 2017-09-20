// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: Auxiliar um calculo matematico
 
   Entrada : os termos da equação de segundo grau

   Saida   :  se possui raizes reais iguais ou diferentes.

*/
#include <locale.h>
#include <stdio.h>
#include <conio.c>
#define MAX 100
#define MIN -100
#define calculaDeltaDaEquacaoDeSegundoGrau(a,b,c) (((b)*(b))-(((4)*(a))*(c)))
float leValidaFloat(char titulo[],char msgErro[],int max, int min);
float leFloat(char titulo[]);
int main(void)
{
	setlocale(LC_ALL,"Portuguese");
// Declaracoes
float termoA,termoB,termoC, valorDelta;
// Instrucoes
termoA=leValidaFloat("Informe o valor do termo A da equação de segundo grau\n","ERRO! Informe corretamente:\n",MAX,MIN);
termoB=leValidaFloat("Informe o valor do termo B da equação de segundo grau\n","ERRO! Informe corretamente:\n",MAX,MIN);
termoC=leValidaFloat("Informe o valor do termo C da equação de segundo grau\n","ERRO! Informe corretamente:\n",MAX,MIN);
valorDelta=calculaDeltaDaEquacaoDeSegundoGrau(termoA,termoB,termoC);
if(valorDelta>0){
	printf("A equação possui duas raízes distintas\n");
}else{
	if(valorDelta==0){
		printf("A equacão possui raízes iguais\n");
	}else{
		printf("A equação não possui nenhuma raíz\n");
	}
}
  getch();
  return 0;
}
//Objetivo: ler um valor float
//Parametro: referencial oo vetor titulo
//Retorno: valor real
float leFloat(char titulo[]){
	float valorFloat;
	int ret;
	do{
		ret=0;
		printf(titulo);
		fflush(stdin);
		ret=scanf("%f",&valorFloat);
		fflush(stdin);
		if(ret==0){
			printf("Erro na leitura do valor real\n");
		}
	}while(ret==0);
	return valorFloat;
}
//Objetivo: ler e validar valor real
//Parametro: referencial a titulo, msg de erro. max e min.
//Retorno: valor real
float leValidaFloat(char titulo[],char msgErro[],int max, int min){
	float valorFloat;
	valorFloat=leFloat(titulo);
	while(valorFloat<min || valorFloat>max){
		valorFloat=leFloat(msgErro);
	}
	return valorFloat;
}
