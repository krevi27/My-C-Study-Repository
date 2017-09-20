// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: ordenar valores
 
   Entrada : três valores de salarios para tres variaves respectivamente

   Saida   :  os valores informados de forma ordenada

*/

#include <stdio.h>
#include <conio.c>
#define MAX_SALARIO 50000000
#define MIN_SALARIO 880
void troca(float *salario1,float *salario2,float *salario3);
void leValidaFloat(char titulo[],char msgErro[],float *valorFloat,int valorMax,int valorMin);
int main(void)
{
// Declaracoes
float salarioFunc1,salarioFunc2,salarioFunc3;
// Instrucoes
leValidaFloat("Informe o valor do salario 1\n","Informe o valor corretamente\n",&salarioFunc1,MAX_SALARIO,MIN_SALARIO);
leValidaFloat("Informe o valor do salario 2\n","Informe o valor corretamente\n",&salarioFunc2,MAX_SALARIO,MIN_SALARIO);
leValidaFloat("Informe o valor do salario 3\n","Informe o valor corretamente\n",&salarioFunc3,MAX_SALARIO,MIN_SALARIO);
troca(&salarioFunc1,&salarioFunc2,&salarioFunc3);
system("cls");
printf("%.2f\n",salarioFunc1);
printf("%.2f\n",salarioFunc2);
printf("%.2f\n",salarioFunc3);
  getch();
  return 0;
}
//Objetivo:
//Parametro:
//Retorno:
void troca(float *salario1,float *salario2,float *salario3){
	float salarios[3], aux;
	int contador, contador2;
	salarios[0]=*salario1;
	salarios[1]=*salario2;
	salarios[2]=*salario3;
	for(contador=0;contador<3;contador++){
		for(contador2=contador+1;contador2<3;contador2++){
			if(salarios[contador]<salarios[contador2]){
				aux=salarios[contador];
				salarios[contador]=salarios[contador2];
				salarios[contador2]=aux;
			}
		}
	}
	*salario1=salarios[0];
	*salario2=salarios[1];
	*salario3=salarios[2];
	

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
		}while(ret==0);
	}while(*valorFloat < valorMin || *valorFloat > valorMax);
}
