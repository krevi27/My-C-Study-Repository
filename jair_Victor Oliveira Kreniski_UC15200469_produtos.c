// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar uma loja de material para construção.
 
   Entrada : código do protudor, preço, descrição.

   Saida   :  todos os dados informados em uma tabela. Maior e menor preço entre todos os produtos

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
#define MAXDESC 21
#define MAXVETOR 15
#define MINPRECO 1
#define MAXPRECO 250
int leInt(char titulo[]);
int leValidaInt(char titulo[],char msgDeErro[],int valorMin, int valorMax);
float leFloat(char titulo[]);
float leValidaFloat(char titulo[],char msgDeErro[],int valorMin,int valorMax);
char leValidaOpcao();
void leValidaTexto(char titulo[], char descricaoDoProduto[][MAXDESC],int contador);
int main(void)
{
// Declaracoes
int codigoDoProduto[MAXVETOR],contador=0,contador2, test;
float precoDoProduto[MAXVETOR], menorPreco=251, maiorPreco=0, mediaDosPrecos=0, somaPrecos=0;
char descricaoDoProduto[MAXVETOR][MAXDESC],opcao;
// Instrucoes
setlocale(LC_ALL,"Portuguese");
do{
system("cls");
printf("Contagem: %dº\n",contador+1);
	do{
		codigoDoProduto[contador]=leValidaInt("Informe o código do produto:\n","Problema com o código informado, informe corretamente:\n",1,MAXVETOR);
		test=testCodigoDoProduto(codigoDoProduto,contador);
	}while(test==1);
	precoDoProduto[contador]=leValidaFloat("Informe o preço do produto:\n","Problema com o preço informado, informe corretamente:\n",1,250);
	if(precoDoProduto[contador]>maiorPreco){
		maiorPreco=precoDoProduto[contador];
	}
	if(precoDoProduto[contador]<menorPreco){
		menorPreco=precoDoProduto[contador];
	}
	somaPrecos=somaPrecos+precoDoProduto[contador];
	leValidaTexto("Informe uma descrição ao produto:\n",descricaoDoProduto,contador);
	contador++;
	opcao=leValidaOpcao();
}while(opcao=='S' && contador<MAXVETOR);
mediaDosPrecos=somaPrecos/contador;
system("cls");
printf("ID do produto | Valor do produto | Descrição do produto\n");
for(contador2=0;contador2<contador;contador2++){
	printf("%-13d | R$:%13.2f | %21s",codigoDoProduto[contador2],precoDoProduto[contador2],descricaoDoProduto[contador2]);
}
printf("=======================================================\n");
printf("Preco Médio: %.2f\n",mediaDosPrecos);
printf("Menor Preço: %.2f\n",menorPreco);
printf("Maior Preço: %.2f\n",maiorPreco);
  getch();
  return 0;
}
//Objetivo: ler e validar string de texto
//Parametro: referencial ao titulo, referencial ao vetor descricaoDoProduto;
//Retorno:
void leValidaTexto(char titulo[], char descricaoDoProduto[][MAXDESC],int contador){
	 do{
		  printf(titulo);
		  fflush(stdin);
		  fgets(descricaoDoProduto[contador], 21, stdin);
		  fflush(stdin);
		  if(strlen(descricaoDoProduto[contador])<2 || strlen(descricaoDoProduto[contador])>21){
		   system("cls");
		   printf("A descrição deve ter entre 1 e 21 letras\n");
		  }
	 }while(strlen(descricaoDoProduto[contador])<2 || strlen(descricaoDoProduto[contador])>21);
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
		ret=scanf("%f",&valorFloat);
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
float leValidaFloat(char titulo[],char msgDeErro[],int valorMin,int valorMax){
	float valorFloat;
	valorFloat=leFloat(titulo);
	while(valorFloat<valorMin||valorFloat>valorMax){
		valorFloat=leFloat(msgDeErro);
	}
	return valorFloat;
}
//Objetivo: ler e validar opcao
//Parametro:
//Retorno: S ou N
char leValidaOpcao(){
	char opcao;
	printf("Deseja informar outro produto? S-Sim ; N-Não\n");
	opcao=getche();
	opcao=toupper(opcao);
	while(opcao!='S'&&opcao!='N'){
		printf("Por favor, informe corretamente.\n");
		printf("Deseja informar outro produto? S-Sim ; N-Não\n");
		opcao=getche();
		opcao=toupper(opcao);
	}
	return opcao;
}
//Objetivo: testar se existe matricula repetida
//Parametro: referencial ao vetor de matriculas dos funcionarios
//Retorno: 1 ou 0
int testCodigoDoProduto(int codigoDoProduto[],int qtd){
	int contador, test=0;
	for(contador=0;contador<qtd;contador++){
		if(codigoDoProduto[contador]==codigoDoProduto[qtd]){
			printf("Código ja foi informado\n");
			test=1;
			break;
		}else{
			test=0;
		}
	}
	return test;
}
