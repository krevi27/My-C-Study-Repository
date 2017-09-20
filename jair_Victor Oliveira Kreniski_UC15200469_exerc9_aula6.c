// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: Auxiliar o IBGE
 
   Entrada : quantidade de cidades pesquisadas, para cada cidade: nome, numero de habitantes e a sua localização.

   Saida   :  

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
#define MAX_CIDADES 10
#define MIN_CIDADES 1
#define TAM_MAX_NOME 100
#define TAM_MIN_NOME 3
#define MAX_NRO_HABITANTES 2000000
#define MIN_NRO_HABITANTES 1
#define MAX_NRO_X 100
#define MIN_NRO_X 0
#define MAX_NRO_Y 100
#define MIN_NRO_Y 0
typedef struct Local{
	int coordenadaX,coordenadaY;
}Local;
typedef struct Dados{
	char nome[TAM_MAX_NOME];
	int nroDeHabitantes;
	struct Local local;
}Dados;
int leInt();
int leValidaInt(char titulo[], int valorMin, int valorMax);
void leValidaString(char titulo[], char texto[], char msgErro[], int tamMax, int tamMin);
struct Dados leDados(void);
float obtemMediaDeHabitantes(struct Dados dados[],int qtdDeCidades);
void apresentaTabela(struct Dados dados[],int qtdDeCidades);
void apresentaQtdAcimaBaixoIgualAMedia(struct Dados dados[],int qtdDeCidades);
int main(void)
{
	setlocale(LC_ALL,"Portuguese");
// Declaracoes
struct Dados dados[MAX_CIDADES];
int qtdDeCidades,contador;
// Instrucoes
qtdDeCidades=leValidaInt("Informe a quantidade de cidades\n",MIN_CIDADES,MAX_CIDADES);
for(contador=0;contador<qtdDeCidades;contador++){
	dados[contador]=leDados();
}
apresentaTabela(dados, qtdDeCidades);
apresentaQtdAcimaBaixoIgualAMedia(dados,qtdDeCidades);
  getch();
  return 0;
}
//Objetivo:
//Parametro:
//Retorno:
void apresentaQtdAcimaBaixoIgualAMedia(struct Dados dados[],int qtdDeCidades){
	system("cls");
	float mediaDeHabitantes;
	int qtdAcimaDaMediaDeHabitantes=0,qtdAbaixoDaMediaDeHabitantes=0,qtdIgualAMediaDeHabitantes=0,contador;
	mediaDeHabitantes=obtemMediaDeHabitantes(dados,qtdDeCidades);
	for(contador=0;contador<qtdDeCidades;contador++){
		if(dados[contador].nroDeHabitantes>mediaDeHabitantes){
			qtdAcimaDaMediaDeHabitantes++;
		}else{
			if(dados[contador].nroDeHabitantes<mediaDeHabitantes){
				qtdAbaixoDaMediaDeHabitantes++;			
			}else{
				qtdIgualAMediaDeHabitantes++;
			}
		}
	}
	printf("A quantidade de cidades acima da média é: %2d\n",qtdAcimaDaMediaDeHabitantes);
	printf("A quantidade de cidades abaixo da média é: %2d\n",qtdAbaixoDaMediaDeHabitantes);
	printf("A quantidade de cidades igual a média é: %2d\n",qtdIgualAMediaDeHabitantes);
}
//Objetivo: Apresentar a tabela
//Parametro: estrutura de dados, qtd de cidades
//Retorno:
void apresentaTabela(struct Dados dados[],int qtdDeCidades){
	float mediaDeHabitantes;
	int contador;
	mediaDeHabitantes=obtemMediaDeHabitantes(dados,qtdDeCidades);
	printf("Nome da cidade - Numero de Habitantes - Coordenada XY - Média/Habitantes\n");
	for(contador=0;contador<qtdDeCidades;contador++){
		printf("%-14.14s %22d %10dX%3dY",dados[contador].nome,dados[contador].nroDeHabitantes, dados[contador].local.coordenadaX,dados[contador].local.coordenadaY);
		if(dados[contador].nroDeHabitantes>mediaDeHabitantes){
			printf(" - Acima\n");
		}else{
			if(dados[contador].nroDeHabitantes<mediaDeHabitantes){
				printf(" - Abaixo\n");
			}else{
				printf(" - Igual\n");
			}
		}
	}
	printf("Para continuar para a segunda parte, pressione qualquer tecla");
	getch();
}
//Objetivo: calcula média de habitantes
//Parametro: dados
//Retorno: media de habitantes
float obtemMediaDeHabitantes(struct Dados dados[],int qtdDeCidades){
	int contador, somaQtdDeHabitantes=0;
	float media;
	for(contador=0;contador<qtdDeCidades;contador++){
		somaQtdDeHabitantes+=dados[contador].nroDeHabitantes;
	}
	media=(float)somaQtdDeHabitantes/qtdDeCidades;
	return media;
}
//Objetivo: ler os valores para o struct
//Parametro:
//Retorno: dados lidos
Dados leDados(void){
	struct Dados dado;
	leValidaString("Informe o nome da cidade\n",dado.nome,"ERRO! Informe corretamente o nome da cidade\n",TAM_MAX_NOME,TAM_MIN_NOME);
	dado.nroDeHabitantes=leValidaInt("Informe a quantidade de habitantes na cidade que o nome foi informado\n",MIN_NRO_HABITANTES,MAX_NRO_HABITANTES);
	dado.local.coordenadaX=leValidaInt("Informe a coordenada X da cidade\n",MIN_NRO_X,MAX_NRO_X);
	dado.local.coordenadaY=leValidaInt("Informe a coordenada Y da cidade\n",MIN_NRO_Y,MAX_NRO_Y);
	return dado;
}
// Objetivo: ler e válidar uma string.
// Parâmetros: referência ao título, texto a ser lido, mensagem de erro, tamanho máximo e mínimo do texto.
// Retorno: nenhum.
void leValidaString(char titulo[], char texto[], char msgErro[], int tamMax, int tamMin){
	int flag, cont, contEspaco;
	do{
		flag=0;
		contEspaco=0;
		printf(titulo);
		fflush(stdin);
		fgets(texto, tamMax, stdin);
		fflush(stdin);
		if(texto[strlen(texto)-1]=='\n'){
			texto[strlen(texto)-1]='\0';
		}
		if(strlen(texto)<tamMin){
			printf("erro no tamanho minimo\n");
			flag=1;
		}else{
			for(cont=0; cont<strlen(texto); cont++){
				if(texto[cont]==' '){
					contEspaco++;
				}
			}
			if(strlen(texto)==contEspaco){
				flag=1;
				printf("erro na qtd espaços\n");
			}
		}
		if(flag==1){
			printf(msgErro);
		}
	}while(flag);
}
// Objetivo: ler um número inteiro.
// Parâmetros: nenhum.
// Retorno: número inteiro.
int leInt(){
	int retScanf, valor;
	do{
		fflush(stdin);
		retScanf=scanf("%d",&valor);
		fflush(stdin);
		if(retScanf==0){
			clrscr();
			printf("Informe um número inteiro\n");
		}
	}while(retScanf==0);
	clrscr();
	return valor;
}
// Objetivo: ler e válidar um número inteiro.
// Parâmetros: referência ao titulo, valor mínimo e máximo.
// Retorno: número inteiro válido.
int leValidaInt(char titulo[], int valorMin, int valorMax){
	int valor;
	do{
		printf(titulo);
		valor=leInt();
		if(valor<valorMin || valor>valorMax){
			clrscr();
			printf("Valor inválido\n");
		}
	}while(valor<valorMin || valor>valorMax);
	clrscr();
	return valor;
}
