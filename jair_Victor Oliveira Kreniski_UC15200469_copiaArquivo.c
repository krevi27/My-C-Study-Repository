// Aluno : Victor oliveira Kreniski

/*
 Sintese
   Objetivo: fazer uma copia do arquivo fornecido
 
   Entrada : nome do arquivo

   Saida   : copia do conteudo do arquivo fornecido para outro arquivo

*/

#include <stdio.h>
#include <conio.c>
#define MAX_NOME_ARQUIVO 20
#define MIN_NOME_ARQUIVO 2
void leValidaString(char msg[],char msgErro[],char textoInformado[],int valorMax,int valorMin);
int leDados(FILE *arquivoDeEntrada,FILE *arquivoDeSaida,char *nomeDoArquivoDeEntrada,char *nomeDoArquivoDeSaida,int MaxNomeArquivo, int minNomeArquivo);
void copiaArquivo(FILE *arquivoDeEntrada, FILE *arquivoDeSaida,char *nomeDoArquivoDeEntrada,char *nomeDoArquivoDeSaida,int flagDeSaida);
char leValidaOpcao(char *opcoes);
int main(void)
{
// Declaracoes
FILE *arquivoDeEntrada;
FILE *arquivoDeSaida;
char nomeDoArquivoDeEntrada[MAX_NOME_ARQUIVO];
char nomeDoArquivoDeSaida[MAX_NOME_ARQUIVO];
int flagDeSaida;
// Instrucoes
flagDeSaida=leDados(arquivoDeEntrada,arquivoDeSaida,nomeDoArquivoDeEntrada,nomeDoArquivoDeSaida,MAX_NOME_ARQUIVO,MIN_NOME_ARQUIVO);
copiaArquivo(arquivoDeEntrada,arquivoDeSaida,nomeDoArquivoDeEntrada,nomeDoArquivoDeSaida,flagDeSaida);
  getch();
  return 0;
}
//Objetivo: copiar os dados do arquivo de entrada para o arquivo de saida
//Parametro: endereco do arquivo de entrada, endereco do arquivo de saida, endereco da string nome do arquivo de entrada, endereco da string nome do arquivo de saida, flag de saida
//Retorno:
void copiaArquivo(FILE *arquivoDeEntrada, FILE *arquivoDeSaida,char *nomeDoArquivoDeEntrada,char *nomeDoArquivoDeSaida,int flagDeSaida){
	char caractere;
	char opcao;
	arquivoDeEntrada=fopen(nomeDoArquivoDeEntrada,"rt");
	if(arquivoDeEntrada==NULL){
		printf("Não foi possivel abrir o arquivo de entrada\n");
		getch();
		(exit(1));
	}else{
		fclose(arquivoDeEntrada);
	}
	if(flagDeSaida==0){
		printf("O arquivo existe, deseja dar overwrite?\n");
		opcao=leValidaOpcao("SN");
		if(opcao=='S'){
			arquivoDeEntrada=fopen(nomeDoArquivoDeEntrada,"rt");
			arquivoDeSaida=fopen(nomeDoArquivoDeSaida,"wt");
			while((caractere = fgetc(arquivoDeEntrada))!=EOF){
				fputc(caractere,arquivoDeSaida);
			}
			fclose(arquivoDeEntrada);
			fclose(arquivoDeSaida);
			printf("Copia feita com sucesso!\n");
		}else{
			printf("Encerrando...");
			getch();
			(exit(1));
		}
	}else{
			printf("O arquivo %s vai ser gerado\n",nomeDoArquivoDeSaida);
			printf("Efetuando a cópia do arquivo %s para o %s\n",nomeDoArquivoDeEntrada,nomeDoArquivoDeSaida);
			arquivoDeEntrada=fopen(nomeDoArquivoDeEntrada,"rt");
			arquivoDeSaida=fopen(nomeDoArquivoDeSaida,"wt");
			while((caractere = fgetc(arquivoDeEntrada))!=EOF){
				fputc(caractere,arquivoDeSaida);
			}
			fclose(arquivoDeEntrada);
			fclose(arquivoDeSaida);
			printf("Copia feita com sucesso!\n");
			getch();
	}
}
//Objetivo: ler todos os dados
//Parametro: endereco do arquivo, endereco do nome do arquivo, endereco da palavra para pesquisa, max nome arquivo, min nome arquivo, max tam palavra pesquisa, min tam palavra pesquisa
//Retorno: 0 ou 1
int leDados(FILE *arquivoDeEntrada,FILE *arquivoDeSaida,char *nomeDoArquivoDeEntrada,char *nomeDoArquivoDeSaida,int MaxNomeArquivo, int minNomeArquivo){
	int flagDeEntrada;
	int flagDeSaida;
	do{
		leValidaString("Informe o nome do arquivo de entrada junto a extensão\n","ERRO! Informe corretamente\n",nomeDoArquivoDeEntrada,MaxNomeArquivo,minNomeArquivo);
		arquivoDeEntrada=fopen(nomeDoArquivoDeEntrada,"rt");
		if(arquivoDeEntrada!=NULL){
			fclose(arquivoDeEntrada);
			printf("Arquivo existe\n");
			flagDeEntrada=0;
		}else{
			printf("Arquivo não existe\n");
			flagDeEntrada=1;
		}
	}while(flagDeEntrada==1);
		leValidaString("Informe o nome do arquivo de saida junto a extensão\n","ERRO! Informe corretamente\n",nomeDoArquivoDeSaida,MaxNomeArquivo,minNomeArquivo);
		arquivoDeSaida=fopen(nomeDoArquivoDeSaida,"rt");
		if(arquivoDeSaida!=NULL){
			fclose(arquivoDeSaida);
			flagDeSaida=0;
		}else{
			printf("Arquivo não existe\n");
			flagDeSaida=1;
		}
	return flagDeSaida;
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
