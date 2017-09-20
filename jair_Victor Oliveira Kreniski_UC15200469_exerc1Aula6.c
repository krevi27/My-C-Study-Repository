// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: gerenciar um arquivo
 
   Entrada :  nome do arquivo

   Saida   :  

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
#include <string.h>
#define MAX_NOME_ARQUIVO 20
#define MIN_NOME_ARQUIVO 1
void leValidaString(char msg[],char msgErro[],char textoInformado[],int valorMax,int valorMin);
int verificaArquivo(FILE *arq, char *nomeDoArquivo);
char leValidaOpcao(char *opcoes);
int main(void)
{
	setlocale(LC_ALL,"Portuguese");
// Declaracoes
FILE *arq;
char nomeDoArquivo[MAX_NOME_ARQUIVO];
int flag;
char opcao;
// Instrucoes
leValidaString("Informe o nome do arquivo junto a extensão .txt\n","ERRO! Informe corretamente\n",nomeDoArquivo,MAX_NOME_ARQUIVO,MIN_NOME_ARQUIVO);
flag=verificaArquivo(arq,nomeDoArquivo);
if(flag==0){
	printf("O arquivo foi encontrado, deseja escrever sobre o arquivo\n overwrite o %s?\n",nomeDoArquivo);
	opcao=leValidaOpcao("SN");
	if(opcao=='S'){
		printf("Overwriting...\n");
		arq=fopen(nomeDoArquivo,"w");
		fclose(arq);
	}else{
		printf("Programa vai encerrar\n");
	}
}else{
	printf("Arquivo não existe, será criado um arquivo com o nome %s",nomeDoArquivo);
	arq=fopen(nomeDoArquivo,"w");
	fclose(arq);
}
  getch();
  return 0;
}
//Objetivo: validar a opcao
//Parametro: referencia a string opcoes
//Retorno: S ou N
char leValidaOpcao(char *opcoes){
	char opcao;
	printf("S-N\n");
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
//Objetivo: verificar se o arquivo já existe
//Parametro: endereco de arquivo e endereco do nome do arquivo.
//Retorno: 0 ou 1
int verificaArquivo(FILE *arq, char *nomeDoArquivo){
	int flag;
	arq=fopen(nomeDoArquivo,"r");
	if(arq==NULL){
		printf("Arquivo não encontrado\n");
		flag = 1;
	}else{
		printf("Arquivo encontrado\n");
		fclose(arq);
		flag = 0;
	}
	return flag;
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
