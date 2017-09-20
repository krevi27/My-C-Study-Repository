// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar na pesquisa de nomes em uma lista
 
   Entrada : nome do arquivo de entrada, nome para a pesquisa, se deseja continuar ou nao

   Saida   : Se o nome existe ou nao, caso exista, a linha que se encontra e a string inteira.

*/

#include <stdio.h>
#include <conio.c>
#include <string.h>
#define MAX_NOME_ARQUIVO 20
#define MIN_NOME_ARQUIVO 2
#define MAX_TAM_PALAVRA_PESQUISA 20
#define MIN_TAM_PALAVRA_PESQUISA 2
void pesquisaNoArquivoEApresenta(FILE *arq, char *palavraParaPesquisa,char *nomeDoArquivo);
void leDados(FILE *arq,char *nomeDoArquivo,char *palavraParaPesquisa,int MaxNomeArquivo, int minNomeArquivo, int maxTamPalavraPesquisa,int minTamPalavraPesquisa);
void leValidaString(char msg[],char msgErro[],char textoInformado[],int valorMax,int valorMin);
char leValidaChar(char *opcoes);
int main(void)
{
// Declaracoes
	FILE *arq;
	char nomeDoArquivo[MAX_NOME_ARQUIVO];
	char palavraParaPesquisa[MAX_TAM_PALAVRA_PESQUISA];
// Instrucoes
	leDados(arq,nomeDoArquivo,palavraParaPesquisa,MAX_NOME_ARQUIVO,MIN_NOME_ARQUIVO,MAX_TAM_PALAVRA_PESQUISA,MIN_TAM_PALAVRA_PESQUISA);
	pesquisaNoArquivoEApresenta(arq,palavraParaPesquisa,nomeDoArquivo);
  getch();
  return 0;
}
//Objetivo: pesquisar a palavra informada no arquivo e apresentar, caso exista.
//Parametro: endereco do aqruivo, endereco da string palavra para pesquisa, endereco da string nome do arquivo
//Retorno:
void pesquisaNoArquivoEApresenta(FILE *arq, char *palavraParaPesquisa,char *nomeDoArquivo){
	char textoInPut[100],opcao;
	int contadorDeLinha=0,qtdDePalavrasEncontadas=0;
	do{
		system("cls");
		arq=fopen(nomeDoArquivo,"rt");
		if(arq!=NULL){
			while(!feof(arq)){
				contadorDeLinha++;
				fgets(textoInPut,100,arq);
				if(strstr(textoInPut,palavraParaPesquisa)!=NULL){
					printf("Linha do arquivo: %d conteudo: %s",contadorDeLinha,textoInPut);
					qtdDePalavrasEncontadas++;
				}
				*(textoInPut)='\0';
			}
		}else{
			printf("Arquivo teve problema para ser aberto\n");
			exit(1);
		}
		fclose(arq);
		if(qtdDePalavrasEncontadas==0){
			printf("Nao existem palavras iguais a fornecida: %s\n",palavraParaPesquisa);
		}
		printf("\nDeseja informar outra palavra?\n");
		opcao=leValidaChar("SN");
		if(opcao=='S'){
			leValidaString("Informe a palavra para pesquisa\n","ERRO! Informe corretamente\n",palavraParaPesquisa,20,1);
		}
		getch();
	}while(opcao=='S');
}
//Objetivo: validar a opcao
//Parametro: referencia a string opcoes
//Retorno: S ou N
char leValidaChar(char *opcoes){
	char opcao;
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
//Objetivo: ler todos os dados
//Parametro: endereco do arquivo, endereco do nome do arquivo, endereco da palavra para pesquisa, max nome arquivo, min nome arquivo, max tam palavra pesquisa, min tam palavra pesquisa
//Retorno:
void leDados(FILE *arq,char *nomeDoArquivo,char *palavraParaPesquisa,int MaxNomeArquivo, int minNomeArquivo, int maxTamPalavraPesquisa,int minTamPalavraPesquisa){
	int flag;
	do{
		leValidaString("Informe o nome do arquivo junto a extensão\n","ERRO! Informe corretamente\n",nomeDoArquivo,MaxNomeArquivo,minNomeArquivo);
		arq=fopen(nomeDoArquivo,"rt");
		if(arq!=NULL){
			fclose(arq);
			printf("Arquivo existe\n");
			flag=0;
		}else{
			printf("Arquivo não existe\n");
			flag=1;
		}
	}while(flag==1);
	leValidaString("Informe o nome da palavra que vai ser pesquisada\n","ERRO! Informe corretamente\n",palavraParaPesquisa,maxTamPalavraPesquisa,minTamPalavraPesquisa);
}

//Objetivo: ler e validar uma string 
//Parametro: referencial a msg, referencial a msgerro, referencial a textoinformado, valor max e valor min
//Retorno:
void leValidaString(char msg[],char msgErro[],char textoInformado[],int valorMax,int valorMin){
	int contadorDeBrancos;
	int contador;
	do{
		contadorDeBrancos=0;
		printf(msg);
		fflush(stdin);
		fgets(textoInformado,valorMax,stdin);
		fflush(stdin);
		if(textoInformado[strlen(textoInformado)-1]=='\n'){
			textoInformado[strlen(textoInformado)-1]='\0';
		}
		for(contador=0;contador<strlen(textoInformado);contador++){
			if(textoInformado[contador]==' '){
				contadorDeBrancos++;
			}
		}
		if(contadorDeBrancos==strlen(textoInformado) || strlen(textoInformado)<valorMin){
			printf(msgErro);
		}
	}while(contadorDeBrancos==strlen(textoInformado) || strlen(textoInformado)<valorMin);
}
