// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar a CBF
 
   Entrada : nome do presidente da cbf,opcao a ser exucatada,identificacao do Jogo: Numero unico, valor arrecadado, cidade onde foi realizado jogo;

   Saida   : se foi encontrado o arquivo com o nome do presidente ou nao, tabela com todos os dados informados, informacoes das cidades com o mesmo nome da pesquisa.

*/

#include <stdio.h>
#include <conio.c>
#define TAM_CIDADE 120
#define MAX_PRE 120
#define MAX_JOGOS 450
#define MIN_CODIGO_JOGO 300
#define MAX_ARRECADACAO 1000000
#define MIN_ARRECADACAO 1000
typedef struct Jogos{
	int idDoJogo;
	float valorArrecadado;
	char cidade[TAM_CIDADE];
}Jogos;
void pesquisador(int contadorDeJogos,Jogos *jogos,int tamCidade);
void apresentacaoDosDados(char *presidenteDaCbf,int contadorDeJogos,Jogos *jogos);
void leDados(Jogos *jogos,int contador,int minCodigoJogo,int maxArrecadacao,int minArrecadacao, int tamCidade);
int verificaIdRepetida(Jogos *jogos,int valorMax);
void buscaNomePresidente(char *presidenteDaCbf, int tamNomePresidente);
void leFloat(char *msg,float *valorFloat);
void leInt(char *msg,int *valorInteiro);
void leValidaOpcao(char *msg,char *opcao,char *opcoes);
void leValidaString(char *msg, char *texto, int tamanhoMax);
int main(void)
{
// Declaracoes
Jogos jogos[MAX_JOGOS];
char presidenteDaCbf[MAX_PRE],opcao;
int contadorDeJogos=0,contador=-1;
// Instrucoes
buscaNomePresidente(presidenteDaCbf,MAX_PRE);
getch();
system("cls");
do{	
	system("cls");
	leValidaOpcao("Informe qual opcao deseja fazer;\nC-Cadastramento de jogos\nA-Apresentacao dos dados\nP-Pesquisar por cidade\nE-Encerrar\n",&opcao,"CAPE");
	switch (opcao){
		system("cls");
		case 'C':
			system("cls");
			if(contadorDeJogos<MAX_JOGOS){
				contadorDeJogos++;
				contador++;
				leDados(jogos,contador,MIN_CODIGO_JOGO,MAX_ARRECADACAO,MIN_ARRECADACAO,TAM_CIDADE);
			}else{
				printf("Nao é capaz de informar mais jogos, limite atingido\n");
				getch();
				break;
			}
			getch();
			break;
		case 'A':
			system("cls");
			apresentacaoDosDados(presidenteDaCbf,contadorDeJogos,jogos);
			getch();
			break;
		case 'P':
			system("cls");
			pesquisador(contadorDeJogos,jogos,TAM_CIDADE);
			break;
		case 'E':
			system("cls");
			printf("Programa vai ser encerrado\n");
			getch();
			return 0;
	}
}while(opcao!='E');
  getch();
  return 0;
}
//Objetivo: pesquisar o nome informado
//Parametro: contador de jogos, endereco da estrutura de jogos, tam cidade
//Retorno:
void pesquisador(int contadorDeJogos,Jogos *jogos,int tamCidade){
	int contador, flag=0;
	char cidadeParaPesquisa[tamCidade];
	leValidaString("Informe o nome da cidade a ser pesquisada\n",cidadeParaPesquisa,tamCidade);
	for(contador=0;contador<contadorDeJogos;contador++){
		if(stricmp(cidadeParaPesquisa,(jogos+contador)->cidade)==0){
			printf("%20.20s %10d %9.2f\n",(jogos+contador)->cidade,(jogos+contador)->idDoJogo,(jogos+contador)->valorArrecadado);
			flag=1;
		}
	}
	if(flag==0){
		printf("Nao foi encontrado nenhuma cidade com esse nome\n");
	}
	getch();
}
//Objetivo: apresntar os dados em formato de tabela
//Parametro: endereco da string presidente da cbf, contador de jogos e endereco da estrutura jogos
//Retorno:
void apresentacaoDosDados(char *presidenteDaCbf,int contadorDeJogos,Jogos *jogos){
	int contador;
	printf("Nome do presidente da CBF: %s\n",presidenteDaCbf);
	printf("%20.20s %25.25s %20.20s\n","Cidade","Identificacao do jogo","Valor arrecadado");
	for(contador=0;contador<contadorDeJogos;contador++){
		printf("%20.20s %25d %20.2f\n",(jogos+contador)->cidade,(jogos+contador)->idDoJogo,(jogos+contador)->valorArrecadado);
	}
}
//Objetivo: le os dados do jogo
//Parametro: endereco da estrutura jogos, contador, min codigo jogo, max arrecadacao, min arrecadacao, tam cidade
//Retorno:
void leDados(Jogos *jogos,int contador,int minCodigoJogo,int maxArrecadacao,int minArrecadacao, int tamCidade){
	int flag;
	do{
		do{
			flag=0;
			leInt("Informe a identificacao do jogo\n",&(jogos+contador)->idDoJogo);
			if((jogos+contador)->idDoJogo<=minCodigoJogo){
				flag=1;
				printf("Informe um codigo maior que %d\n",minCodigoJogo);
			}
		}while(flag==1);
		flag=verificaIdRepetida(jogos,contador);
	}while(flag==1);
	do{
		flag=0;
		leFloat("Informe o valor arrecadado no jogo\n",&(jogos+contador)->valorArrecadado);
		if((jogos+contador)->valorArrecadado<minArrecadacao || (jogos+contador)->valorArrecadado>maxArrecadacao){
			printf("Informe um valor entre %d e %d\n",minArrecadacao,maxArrecadacao);
			flag=1;
		}
	}while(flag==1);
		flag=0;
		leValidaString("Informe o nome da cidade\n",(jogos+contador)->cidade,tamCidade);
}
//Objetivo: verificar se o codigo informado é repetido
//Parametro: endereco da estrutura jogos e valor max
//Retorno: 0 ou 1
int verificaIdRepetida(Jogos *jogos,int valorMax){
	int contador,flag=0;
	for(contador=0;contador<valorMax;contador++){
		if((jogos+contador)->idDoJogo==(jogos+valorMax)->idDoJogo){
			printf("ID informada e repetida\n");
			flag=1;
			break;
		}
	}
	return flag;
}
//Objetivo: buscar o nome do presidente, se nao achar, vai gerar um.
//Parametro: endereco da string presidente da cbf, tam nome presidente
//Retorno:
void buscaNomePresidente(char *presidenteDaCbf, int tamNomePresidente){
	FILE *arquivoPresidenteDaCbf;
	if((arquivoPresidenteDaCbf=fopen("presidenteDaCbf.txt","r"))!=NULL){
		printf("Foi encontrado o arquivo que e usado para salvar o nome do presidente da cbf\n");
		fgets(presidenteDaCbf,tamNomePresidente,arquivoPresidenteDaCbf);
		fclose(arquivoPresidenteDaCbf);
	}else{
		printf("Não foi encontrado o arquivo que e usado para salvar o nome do presidente da cbf\n");
		leValidaString("Informe o nome do presidente da cbf\n",presidenteDaCbf,tamNomePresidente);
		if((arquivoPresidenteDaCbf=fopen("presidenteDaCbf.txt","w"))!=NULL){
			printf("Nome do presidente %s foi salvo com sucesso no programa presidenteDaCbf.txt\n",presidenteDaCbf);
			fputs(presidenteDaCbf,arquivoPresidenteDaCbf);
			fclose(arquivoPresidenteDaCbf);
		}
		
	}
}
//Objetivo: ler um valor float
//Parametro: endereco da mensagem, endereco do valor float
//Retorno:
void leFloat(char *msg,float *valorFloat){
	int ret;
	do{
		ret=0;
		printf("%s",msg);
		fflush(stdin);
		ret=scanf("%f",valorFloat);
		fflush(stdin);
		if(ret==0){
			printf("Valor float esta com erro\n");
		}
	}while(ret==0);
}
//Objetivo: ler um valor inteiro
//Parametro: endereco da mensagem e endereco do valor inteiro
//Retorno:
void leInt(char *msg,int *valorInteiro){
	int ret;
	do{
		ret=0;
		printf("%s",msg);
		fflush(stdin);
		ret=scanf("%d",valorInteiro);
		fflush(stdin);
		if(ret==0){
			printf("Valor inteiro esta com erro\n");
		}
	}while(ret==0);
}
//Objetivo: ler e validar opcao
//Parametro: endereco da mensagem, endereco da opcao, endereco da string opcoes
//Retorno:
void leValidaOpcao(char *msg,char *opcao,char *opcoes){
	do{
		printf("%s",msg);
		fflush(stdin);
		*opcao=getch();
		fflush(stdin);
		*opcao=toupper(*opcao);
	}while(strchr(opcoes,*opcao)==NULL);
}
//Objetivo: ler e validar uma string
//Parametro: endereco da mensangem, endereco do texto, tamanho maximo
//Retorno:
void leValidaString(char *msg, char *texto, int tamanhoMax){
	int contador, contadorDeBrancos=0,flag;
	do{
		flag=0;
		printf("%s",msg);
		fflush(stdin);
		fgets(texto,tamanhoMax,stdin);
		if(texto[strlen(texto)-1]=='\n'){
			texto[strlen(texto)-1]='\0';
		}
		for(contador=0;contador<strlen(texto);contador++){
			texto[contador]=tolower(texto[contador]);
		}
		for(contador=0;contador<strlen(texto);contador++){
			if(texto[contador]==' '){
				contadorDeBrancos++;
			}
		}
		if(strlen(texto)==contadorDeBrancos){
			printf("Nao informe um texto em branco\n");
			flag=1;
		}
	}while(flag==1);
}
