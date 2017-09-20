// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: calcula a área de uma esfera
 
   Entrada : Informe o raio da esfera

   Saida   : área de uma esfera

*/

#include <stdio.h>
#include <conio.c>
#define CALCULA_AREA_DA_ESFERA(raio) ((4)*(3.14)*((raio)*(raio)))
float leFloat(char titulo[]);
float leValidaFloat(char titulo[],char msgErro[],int max, int min);
int main(void)
{
// Declaracoes
float raioDaEsfera;
// Instrucoes
raioDaEsfera=leValidaFloat("Informe o raio:\n","ERRO! Informe o raio corretamente:\n",20,1);
printf("A area da esfera, de acordo com o raio informado é: %.2f cm2",CALCULA_AREA_DA_ESFERA(raioDaEsfera));
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
