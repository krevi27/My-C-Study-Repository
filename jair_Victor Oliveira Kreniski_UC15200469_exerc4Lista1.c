// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: Auxiliar o ministério da Agricultura.
 
   Entrada : Nome de quem forneceu as respostas da pesquisa, quantidade de alimentos, o preço, se deseja continuar ou não.

   Saida   :  Nome do responsavel pela pesquisa, uma tabela com todas informações informadas, local e precos acima do informados.

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
#include <string.h>
#define MAX_ALIMENTOS 500
#define TAM_NOME 29
int leInt(char titulo[]);
int leValidaInt(char titulo[],char msgErro[],int valorMax, int valorMin);
float leFloat(char titulo[]);
float leValidaFloat(char titulo[],char msgErro[], int valorMax,int valorMin);
void leString(char titulo[],char string[]);
void leValidaString(char titulo[],char msgErro[],char string[], int tamanhoMax, int tamanhoMin);
void stringToLower(char string[]);
void AtoUpper(char string[]);
void apresentaAlimentos(float precosDosAlimentos[][5], int contadorDeAlimentos, char nomeDoUsuario[]);
void pesquisaAlimentos(float precosDosAlimentos[][5],int contadorDeAlimentos);
int main(void)
{
	setlocale(LC_ALL,"Portuguese");
// Declaracoes
int qtdDeAlimentos,contadorDeAlimentos,contadorDeMercados,opcao;
float precosDosAlimentos[MAX_ALIMENTOS][5];
char nomeDoUsuario[TAM_NOME];
// Instrucoes
leValidaString("Informe o nome do usuário da pesquisa:\n","INFORME O NOME CORRETAMENTE", nomeDoUsuario, TAM_NOME, 2);
system("cls");
qtdDeAlimentos=leValidaInt("Informe a quantidade de alimentos:\n","ERRO! INFORME A QUANTIDADE DE ALIMENTOS:\n",MAX_ALIMENTOS,2);
for(contadorDeAlimentos=0;contadorDeAlimentos<qtdDeAlimentos;contadorDeAlimentos++){
	for(contadorDeMercados=0;contadorDeMercados<5;contadorDeMercados++){
		system("cls");
		printf("Para o mercado %d informe o preço do produto %d\n",contadorDeMercados+1,contadorDeAlimentos+1);
		precosDosAlimentos[contadorDeAlimentos][contadorDeMercados]=leValidaFloat("Informe o preço do produto:\n","ERRO! Informe o preço do produto corretamente:\n",10,1);
	}
}
do{
	opcao=0;
	system("cls");
	apresentaAlimentos(precosDosAlimentos,contadorDeAlimentos,nomeDoUsuario);
	pesquisaAlimentos(precosDosAlimentos,contadorDeAlimentos);
	opcao=leValidaInt("Informe 1 para continuar; Informe 2 para encerrar;","1 ou 2; Informe corretamente.",2,1);
}while(opcao==1);
  getch();
  return 0;
}
//Objetivo: Apresentar uma tabela com os ALimentos
//Parametro: referencial a matriz precos dos alimentos, referenciala o vetor nome do usuario, contador de alimentos
//Retorno:
void apresentaAlimentos(float precosDosAlimentos[][5], int contadorDeAlimentos, char nomeDoUsuario[]){
	int contador,contador2,contador3;
	stringToLower(nomeDoUsuario);
	AtoUpper(nomeDoUsuario);
	printf("Responsável: %s\n",nomeDoUsuario);
	printf("%-15.15s %20.20s","Alimento","Precos(R$)\n");
	printf("           ");
	for(contador=0;contador<5;contador++){
		printf("%3.3s%d  ","Sup",contador+1);
	}
	printf("\n");
	for(contador=0;contador<contadorDeAlimentos;contador++){
		printf("%d         ",contador+1);
		for(contador2=0;contador2<5;contador2++){
			printf(" %.2f ",precosDosAlimentos[contador][contador2]);
		}
		printf("\n");
	}
}
//Objetivo: pesquisar um alimento
//Parametro:referencial a matriz precos dos alimentos, contador de alimentos, soma valor total
//Retorno:
void pesquisaAlimentos(float precosDosAlimentos[][5],int contadorDeAlimentos){
	int contador,contador2, test=0;
	float valorParaPesquisa;
		valorParaPesquisa=leValidaFloat("Informe um valor para efetuar a pesquisa\n","Informe um valor entre 1 e 10 para pesquisa\n",10,1);
		printf("Alimentos com preços acima de R$ %.2f\n",valorParaPesquisa);
		printf("%-10.10s  %12.12s\n","Alimento","Supermercado");
		for(contador=0;contador<contadorDeAlimentos;contador++){
			for(contador2=0;contador2<5;contador2++){
				if(precosDosAlimentos[contador][contador2]>valorParaPesquisa){
					printf("%-d %16d\n",contador+1,contador2+1);
					test=1;
				}
			}
		}
		if(test==0){
			printf("Não existe nenhum valor acima do informado\n");
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
//Objetivo: le uma string
//Parametro: referencial ao titulo e a string
//Retorno:
void leString(char titulo[],char string[]){
		printf(titulo);
		fflush(stdin);
		fgets(string,TAM_NOME,stdin);
		fflush(stdin);
}
//Objetivo: ler e validar string
//Parametro:referencial ao titulo, mensagem de erro e string
//Retorno:
void leValidaString(char titulo[],char msgErro[],char string[], int tamanhoMax, int tamanhoMin){
	int contador;
	do{
		leString(titulo, string);
		if(strlen(string)<tamanhoMin || strlen(string)>tamanhoMax){
			printf("ERRO COM O TAMANHO DA STRING MIN: %d MAX: %d\n",tamanhoMin, tamanhoMax);
		}
	}while(strlen(string)<tamanhoMin || strlen(string)>tamanhoMax);
	if(string[strlen(string-1)]=='\n'){
		string[strlen(string-1)]='\0';
	}
}

//Objetivo: passar uma string inteira para minusculo
//Parametro: referencial a uma string
//Retorno:
void stringToLower(char string[]){
	int contador;
	for(contador=0;contador<strlen(string);contador++){
		string[contador]=tolower(string[contador]);
	}
}
//Objetivo: passar todas caracteres: a para A
//Parametro: referencial a string
//Retorno:
void AtoUpper(char string[]){
	int contador;
	for(contador=0;contador<strlen(string);contador++){
		if(string[contador]=='a'){
			string[contador]=toupper(string[contador]);
		}
	}
}
