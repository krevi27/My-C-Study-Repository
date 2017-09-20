// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar a manipulação de dados para uma pesquisa
 
   Entrada : quantidade de mercados e para cada mercado os precos dos produtos
   
   Saida   : se existe ou não a descrição informada e, caso exista, o preço médio do mesmo.
*/
#include <string.h>
#include <stdio.h>
#include <conio.c>
#include <locale.h>
#define MAX_DESC 21
#define MIN_DESC 2
#define QTD_DE_PRODUTO_MAX 5
#define QTD_DE_PRODUTO_MIN 1
#define QTD_MAX_DE_MERCADOS 9
#define QTD_MIN_DE_MERCADOS 4
#define PRECO_MAX 100
void leString(char titulo[],char string[],int max);
void leValidaString(char titulo[],char msgErro[],char string[], int tamanhoMax, int tamanhoMin);
int leInt(char titulo[]);
int leValidaInt(char titulo[],char msgErro[],int valorMax, int valorMin);
float leFloat(char titulo[]);
float leValidaFloat(char titulo[],char msgErro[], int valorMax,int valorMin);
float calculaPrecoMedio(float precosDosProdutos[],int qtdDeMercados);
void pesquisaAlimentacao(char descricaoDosProdutos[QTD_DE_PRODUTO_MAX][MAX_DESC],float medias[],int qtdDeProdutos);
int main(void)
{
	setlocale(LC_ALL,"Portuguese");
// Declaracoes
int qtdDeMercados, qtdDeProdutos,contador,contador2;
char descricaoDosProdutos[QTD_DE_PRODUTO_MAX][MAX_DESC];
float precosDosProdutos[QTD_DE_PRODUTO_MAX][QTD_MAX_DE_MERCADOS],medias[QTD_DE_PRODUTO_MAX];
// Instrucoes
qtdDeMercados=leValidaInt("Informe a quantidade mercados sendo maior que 3 e menor que 10\n","ERRO! maior que 3 e menor que 10\n",QTD_MAX_DE_MERCADOS,QTD_MIN_DE_MERCADOS);
qtdDeProdutos=leValidaInt("Informe a quantidade de produtos\n","ERRO! Maior que 1 e menor que 10\n",QTD_DE_PRODUTO_MAX,QTD_DE_PRODUTO_MIN);
for(contador=0;contador<qtdDeProdutos;contador++){
	leValidaString("Informe a descrição do produto\n","ERRO! Informe corretamente\n",descricaoDosProdutos[contador],MAX_DESC,MIN_DESC);
}
for(contador=0;contador<qtdDeProdutos;contador++){
	for(contador2=0;contador2<qtdDeMercados;contador2++){
		system("cls");
		printf("Para o produto: %s\n",descricaoDosProdutos[contador]);
		printf("Para o mercado: %d\n",contador2+1);
		precosDosProdutos[contador][contador2]=leValidaFloat("Informe o preço do produto:\n","ERRO! Informe um preço válido:\n",PRECO_MAX,1);
	}
}
for(contador=0;contador<qtdDeProdutos;contador++){
		medias[contador]=calculaPrecoMedio(precosDosProdutos[contador], qtdDeMercados);
	}
pesquisaAlimentacao(descricaoDosProdutos, medias, qtdDeProdutos);
  getch();
  return 0;
}
//Objetivo: pesquisar um alimento
//Parametro:referencial a matriz descricaoDosProdutos, referencial a medias, quantidade de produtos;
//Retorno:
void pesquisaAlimentacao(char descricaoDosProdutos[QTD_DE_PRODUTO_MAX][MAX_DESC],float medias[],int qtdDeProdutos){
	char descricaoParaPesquisa[MAX_DESC];
	int contador,test,opcao;
	do{
		opcao=0;
		test=0;
		system("cls");
		leValidaString("Informe uma descrição para ser pesquisada:\n","Erro! Informe corretamente:\n",descricaoParaPesquisa,MAX_DESC,MIN_DESC);
		for(contador=0;contador<qtdDeProdutos;contador++){
			if(stricmp(descricaoParaPesquisa,descricaoDosProdutos[contador])==0){
				test=1;
				break;
			}
		}
		if(test==0){
			printf("Produto %s não cadastrado\n",descricaoParaPesquisa);
		}else{
			printf("%.2f\n",medias[contador]);
		}
		opcao=leValidaInt("Para continuar pressione 1;Para Encerrar pressione 2;\n","ERRO! Informe corretamente:\n",2,1);
	}while(opcao==1);
}
//Objetivo: calcular preço medio
//Parametro:referencial ao vetor precos dos produtos e quantidade de mercados
//Retorno: media
float calculaPrecoMedio(float precosDosProdutos[],int qtdDeMercados){
	float maiorValor=precosDosProdutos[0], media=0, somaValores=0;
	int contador;
	
	for(contador=0;contador<qtdDeMercados;contador++){
		if(maiorValor<precosDosProdutos[contador]){
			maiorValor=precosDosProdutos[contador];
		}
	}
	for(contador=0;contador<qtdDeMercados;contador++){
		somaValores+=precosDosProdutos[contador];
	}
	somaValores-=maiorValor;
	media=somaValores/(qtdDeMercados-1);
	return media;
	
}
//Objetivo: le uma string
//Parametro: referencial ao titulo e a string, tamanho max
//Retorno:
void leString(char titulo[],char string[],int max){
		printf(titulo);
		fflush(stdin);
		fgets(string,max,stdin);
		fflush(stdin);
}
//Objetivo: ler e validar string
//Parametro:referencial ao titulo, mensagem de erro e string
//Retorno:
void leValidaString(char titulo[],char msgErro[],char string[], int tamanhoMax, int tamanhoMin){
	do{
		leString(titulo, string, tamanhoMax);
		if(strlen(string)<tamanhoMin || strlen(string)>tamanhoMax){
			printf("ERRO COM O TAMANHO DA STRING MIN: %d MAX: %d\n",tamanhoMin, tamanhoMax);
		}
	}while(strlen(string)<tamanhoMin || strlen(string)>tamanhoMax);
	if(string[strlen(string)-1]=='\n'){
		string[strlen(string)-1]='\0';
	}
}
//Objetivo: ler um valor inteiro
//Parametro: referencial ao titulo
//Retorno: valor inteiro
int leInt(char titulo[]){
	int ret, valorInteiro;
	do{
		ret=0;
		printf(titulo);
		fflush(stdin);
		ret=scanf("%d",&valorInteiro);
		fflush(stdin);
		if(ret==0){
			printf("ERRO NO VALOR INTEIRO\n");
		}
	}while(ret==0);
	return valorInteiro;
}
//Objetivo: ler e validar um valor inteiro
//Parametro: referencial ao titulo e mensagem de erro, valor max e valor min.
//Retorno: valor inteiro
int leValidaInt(char titulo[],char msgErro[],int valorMax, int valorMin){
	int valorInteiro;
	valorInteiro=leInt(titulo);
	while(valorInteiro<valorMin || valorInteiro>valorMax){
		valorInteiro=leInt(msgErro);
	}
	return valorInteiro;
}
//Objetivo: ler um valor float
//Parametro: referencial ao titulo
//Retorno: valor float
float leFloat(char titulo[]){
	int ret;
	float valorFloat;
	do{
		ret=0;
		printf(titulo);
		fflush(stdin);
		ret=scanf("%f",&valorFloat);
		fflush(stdin);
		if(ret==0){
			printf("ERRO NA LEITURA DO VALOR REAL\n");
		}
	}while(ret==0);
	return valorFloat;
}
//Objetivo: ler e validar um float
//Parametro:referencial ao titulo e a msg de erro, valor max e valor min.
//Retorno: valor float
float leValidaFloat(char titulo[],char msgErro[], int valorMax,int valorMin){
	float valorFloat;
	valorFloat=leFloat(titulo);
	while(valorFloat<valorMin || valorFloat>valorMax){
		valorFloat=leFloat(msgErro);
	}
	return valorFloat;
}
