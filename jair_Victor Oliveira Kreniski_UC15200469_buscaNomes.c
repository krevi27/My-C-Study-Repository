// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar uma classe de alunos
 
   Entrada : nomes, se deseja continuar ou não, palavra a ser pesquisada.

   Saida   :mostrar se existe ou não a palavra informada, caso exista, mostrar os nomes que contém.

*/

#include <stdio.h>
#include <conio.c>
#include <string.h>
#define MAXSTRING 31
#define MINSTRING 1
#define MAX 10
#define MIN 1
void leValidaTexto(char titulo[], char nomes[][MAXSTRING],int contador);
char leValidaOpcao();
void pesquisaPalavra(char nomes[][MAXSTRING],int qtd);
int main(void)
{
// Declaracoes
char nomes[MAX][MAXSTRING],opcao, palavraDaPesquisa[MAXSTRING];
int contador,test=0;
// Instrucoes
do{
	system("cls");
	printf("Contagem: %d\n",contador+1);
	leValidaTexto("Informe um texto/nome:\n", nomes,contador);
	contador++;
	opcao=leValidaOpcao();
}while(opcao=='S' && contador<MAX);
do{
	system("cls");
	pesquisaPalavra(nomes,contador);
	opcao=leValidaOpcao();
}while(opcao=='S');
  getch();
  return 0;
}
//Objetivo: Pesquisar no vetor de string se a palavra inserida existe
//Parametro: referencial ao vetor nomes e a qtd
//Retorno:
void pesquisaPalavra(char nomes[][MAXSTRING],int qtd){
	char palavraDaPesquisa[MAXSTRING], stringParaStr[MAXSTRING];
	int contador,contador2, test;
	do{
		printf("Informe uma palavra para ser pesquisada:\n");
		fflush(stdin);
		fgets(palavraDaPesquisa,MAXSTRING,stdin);
		fflush(stdin);
		if(strlen(palavraDaPesquisa)<MINSTRING || strlen(palavraDaPesquisa)>MAXSTRING){
			printf("A palavra para a pesquisa precisa ter entre 1 e 31 caracteres:\n");
		}
	}while(strlen(palavraDaPesquisa)<MINSTRING||strlen(palavraDaPesquisa)>MAXSTRING);
	for(contador=0;contador<strlen(palavraDaPesquisa);contador++){
		palavraDaPesquisa[contador]=tolower(palavraDaPesquisa[contador]);
	}
	for(contador=0;contador<qtd;contador++){
		for(contador2=0;contador2<strlen(nomes[contador]);contador2++){
			nomes[contador][contador2]=tolower(nomes[contador][contador2]);
		}
	for(contador=0;contador<qtd;contador++){
		if(stringParaStr[MAXSTRING]=strstr(palavraDaPesquisa,nomes[contador])!=NULL){
		printf("Palavra %s foi encontrada na %s",palavraDaPesquisa,stringParaStr);
		test=1;
	}
	if(test==0){
		printf("Palavra %s não foi encontrada",palavraDaPesquisa);
	}
}

//Objetivo: ler e validar string de texto
//Parametro: referencial ao titulo, referencial ao vetor descricaoDoProduto;
//Retorno:
void leValidaTexto(char titulo[], char nomes[][MAXSTRING],int contador){
	 do{
		  printf(titulo);
		  fflush(stdin);
		  fgets(nomes[contador], MAXSTRING, stdin);
		  fflush(stdin);
		  if(strlen(nomes[contador])<MINSTRING|| strlen(nomes[contador])>MAXSTRING){
		  	 system("cls");
		   	 printf("O nome/texto deve ter entre 1 e 31 caracteres\n");
		  }
	 }while(strlen(nomes[contador])<MINSTRING|| strlen(nomes[contador])>MAXSTRING);
}
//Objetivo: ler e validar opcao
//Parametro:
//Retorno: S ou N
char leValidaOpcao(){
	char opcao;
	printf("Deseja continuar? S-Sim ; N-Não\n");
	opcao=getche();
	opcao=toupper(opcao);
	while(opcao!='S'&&opcao!='N'){
		printf("Por favor, informe corretamente.\n");
		printf("Deseja continuar? S-Sim ; N-Não\n");
		opcao=getche();
		opcao=toupper(opcao);
	}
	return opcao;
}
