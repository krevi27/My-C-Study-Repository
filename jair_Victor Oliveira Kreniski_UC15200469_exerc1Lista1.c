// Aluno : Victor Oliveira Kreniski	

/*
 Sintese
   Objetivo: auxiliar uma empresa
 
   Entrada : matricula, se deseja continuar.

   Saida   :   tabela com os valores em ordem decrescente de salario

*/

#include <stdio.h>
#include <conio.c>
#define MAX 50
#define MIN 1
#include <locale.h>
int leInt(char titulo[]);
int leValidaInt(char titulo[],char msgDeErro[],int valorMin, int valorMax);
int testMatriculasFuncionarios(int matriculasFuncionarios[],int qtd);
float leFloat(char titulo[]);
float leValidaFloat(char titulo[],char msgDeErro[],int valorMin, int valorMax);
void bubbleSort(float salariosFuncionarios[],int matriculasFuncionarios[],int qtd);
char leValidaOpcao();
int main(void)
{
// Declaracoes
	int matriculasFuncionarios[MAX],contador=0,contador2, test;
	float salariosFuncionarios[MAX];
	char opcao;
// Instrucoes
setlocale(LC_ALL,"Portuguese");
do{
	matriculasFuncionarios[contador]=leValidaInt("Informe a sua matricula:\n","\n Por favor, informe uma matricula válida:\n",0,MAX);
	test=testMatriculasFuncionarios(matriculasFuncionarios,contador);
	while(test==1){
		matriculasFuncionarios[contador]=leValidaInt("Matricula repetida, informe outra:\n","\n Por favor, informe uma matricula válida:\n",0,MAX);
		test=testMatriculasFuncionarios(matriculasFuncionarios,contador);
	}
	salariosFuncionarios[contador]=leValidaFloat("Informe o seu salario:\n","Por favor, informe um salario válido:\n",0,50000);
	bubbleSort(salariosFuncionarios,matriculasFuncionarios,contador);
	for(contador2=0;contador2<contador+1;contador2++){
		printf("%d  %2.2f \n",matriculasFuncionarios[contador2],salariosFuncionarios[contador2]);
	}
	opcao=leValidaOpcao();
	contador++;
	system("cls");
}while(opcao=='S');

  getch();
  return 0;
}
//Objetivo: ler um valor inteiro
//Parametro: referencial ao titulo
//Retorno: valor inteiro
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
//Objetivo: ler e validar um valor inteiro
//Parametro: referencial ao titulo, referencial a msg de erro, valor min e valor max.
//Retorno: valor Inteiro
int leValidaInt(char titulo[],char msgDeErro[],int valorMin, int valorMax){
	int valorInt;
	valorInt=leInt(titulo);
	while(valorInt<valorMin || valorInt>valorMax){
		valorInt=leInt(msgDeErro);
	}
	return valorInt;
}
//Objetivo: ler valor float
//Parametro:referencial ao titulo
//Retorno: valor float
float leFloat(char titulo[]){
	int ret;
	float valorFloat;
	do{
		printf(titulo);
		fflush(stdin);
		ret=scanf("%d",&valorFloat);
		fflush(stdin);
		if(ret==0){
			printf("ERRO NA LEITURA DO VALOR REAL! ");
		}
	}while(ret==0);
	return valorFloat;
}
//Objetivo: ler e validar valor float
//Parametro: referencial ao titulo, referencial a mensagem de erro, valor min, valor max
//Retorno: valor float
float leValidaFloat(char titulo[],char msgDeErro[],int valorMin, int valorMax){
	float valorFloat;
	valorFloat=leFloat(titulo);
	while(valorFloat<valorMin ||valorFloat>valorMax){
		valorFloat=leFloat(msgDeErro);
	}
	return valorFloat;
}
//Objetivo: ler e validar opcao
//Parametro:
//Retorno: S ou N
char leValidaOpcao(){
	char opcao;
	printf("Deseja continuar? S-Sim ; N-Não");
	opcao=getche();
	opcao=toupper(opcao);
	while(opcao!='S'&&opcao!='N'){
		printf("Por favor, informe corretamente.");
		printf("Deseja continuar? S-Sim ; N-Não");
		opcao=getche();
		opcao=toupper(opcao);
	}
	return opcao;
}
//Objetivo: testar se existe matricula repetida
//Parametro: referencial ao vetor de matriculas dos funcionarios
//Retorno: 1 ou 0
int testMatriculasFuncionarios(int matriculasFuncionarios[],int qtd){
	int contador, test=0;
	for(contador=0;contador<qtd;contador++){
		if(matriculasFuncionarios[contador]==matriculasFuncionarios[qtd]){
			test=1;
			break;
		}else{
			test=0;
		}
	}
	return test;
}
//Objetivo: ordenar os vetores pelo bubbleSort em ordem decrescente
//Paramtero: referencia ao vetor salarios funcionarios, referenciao ao vetor matriculas funcionarios e a qtd
//retorno:
void bubbleSort(float salariosFuncionarios[],int matriculasFuncionarios[],int qtd){
	int aux,auxParaMatriculas,i,j;
	for(j=qtd-1;j<=1;j--){
		for(i=0;i>j;i++){
			if(salariosFuncionarios[i]>salariosFuncionarios[i+1]){
				aux=salariosFuncionarios[i];
				salariosFuncionarios[i]=salariosFuncionarios[i+1];
				salariosFuncionarios[i+1]=aux;
				auxParaMatriculas=matriculasFuncionarios[i];
				matriculasFuncionarios[i]=matriculasFuncionarios[i+1];
				matriculasFuncionarios[i+1]=auxParaMatriculas;
			}
		}
	}
}
