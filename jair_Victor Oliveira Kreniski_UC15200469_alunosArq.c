// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: fazer uma tabela e salva-la
 
   Entrada : nome do arquivo de entrada, nome do arquivo de saida.

   Saida   :  tabela com as matriculas, notas e nome de cada aluno

*/

#include <stdio.h>
#include <conio.c>
#define MAX_ALUNO 25
#define MAX_NOME_ARQUIVO 101
#define MAX_NOME_ALUNO 101
typedef struct Aluno{
	int matricula;
	float nota;
	char nome[MAX_NOME_ALUNO];
}Aluno;
void leValidaTexto(char *msg,char *texto,int valorMax);
void ordenaDecrescente(Aluno *alunos,int contadorDeLinhas);
char classificaNota(float nota);
void apresentaTabela(Aluno *alunos,int contadorDeLinhas);
void escreveDadosOutPut(Aluno *alunos,int contadorDeLinhas);
int main(void)
{
// Declaracoes
Aluno alunos[MAX_ALUNO];
char enderecoArquivoDeEntrada[MAX_NOME_ARQUIVO];
FILE *arquivoDeEntrada;
int contadorDeLinhas=0,contador=0, flag;
// Instrucoes
do{
	flag=0;
	leValidaTexto("Informe o nome do arquivo de entrada junto a extensao\n",enderecoArquivoDeEntrada,MAX_NOME_ARQUIVO);
	arquivoDeEntrada=fopen(enderecoArquivoDeEntrada,"rt");
	if(arquivoDeEntrada==NULL){
		flag=1;
		printf("O arquivo informado %s esta com erros\n",enderecoArquivoDeEntrada);
	}else{
		printf("Arquivo encontrado\n");
		fclose(arquivoDeEntrada);
	}
}while(flag==1);
arquivoDeEntrada=fopen(enderecoArquivoDeEntrada,"r");
if(arquivoDeEntrada!=NULL){
	printf("Comecando a leitura\n");
	while(!feof(arquivoDeEntrada)){
		contadorDeLinhas++;
		fscanf(arquivoDeEntrada,"%d %f",&(alunos+contador)->matricula,&(alunos+contador)->nota);
		fgets((alunos+contador)->nome,MAX_NOME_ALUNO,arquivoDeEntrada);
		if((alunos+contador)->nome[strlen((alunos+contador)->nome)-1]=='\n'){
			(alunos+contador)->nome[strlen((alunos+contador)->nome)-1]='\0';
		}
		contador++;
	}
	fclose(arquivoDeEntrada);
}else{
	printf("Não foi possivel abrir o arquivo de entrada\n");
	return 1;
}
ordenaDecrescente(alunos,contadorDeLinhas);
apresentaTabela(alunos,contadorDeLinhas);
getch();
system("cls");
escreveDadosOutPut(alunos,contadorDeLinhas);
  getch();
  return 0;
}
//Objetivo: escrever os dados iguais a tabela informada em um arquivo
//Parametro:
//Retorno:
void escreveDadosOutPut(Aluno *alunos,int contadorDeLinhas){
	FILE *arquivoOutPut;
	char enderecoArquivoDeSaida[MAX_NOME_ARQUIVO];
	int contador;
	char situacao;
	leValidaTexto("Informe o nome do arquivo de saida junto a extensao\n",enderecoArquivoDeSaida,MAX_NOME_ARQUIVO);
	arquivoOutPut=fopen(enderecoArquivoDeSaida,"w");
	if(arquivoOutPut!=NULL){
		fprintf(arquivoOutPut,"%14.14s %10.10s %5.5s %10.10s\n","Nome do Aluno","Matricula","Nota","Situacao");
		for(contador=0;contador<contadorDeLinhas;contador++){
			fprintf(arquivoOutPut,"%14.14s %10d %5.2f %10.10c\n",(alunos+contador)->nome,(alunos+contador)->matricula,(alunos+contador)->nota,situacao=classificaNota((alunos+contador)->nota));
		}
		printf("Dados foram printados com sucesso\n");
		fclose(arquivoOutPut);
	}else{
		printf("Nao foi possivel imprimir os dados no arquivo informado\n");
	}
}
//Objetivo: apresentar a tabela com todos os dados lidos do arquivo junto a situacao de acordo com a nota
//Parametro: endereco da estrutura alunos, contador de linhas
//Retorno: 
void apresentaTabela(Aluno *alunos,int contadorDeLinhas){
	int contador;
	char situacao;
	printf("A tabela vai ser apresentada, aperte qualquer coisa para continuar\n");
	getch();
	system("cls");
	printf("%14.14s %10.10s %5.5s %10.10s\n","Nome do Aluno","Matricula","Nota","Situacao");
	for(contador=0;contador<contadorDeLinhas;contador++){
		printf("%14.14s %10d %5.2f %10.10c\n",(alunos+contador)->nome,(alunos+contador)->matricula,(alunos+contador)->nota,situacao=classificaNota((alunos+contador)->nota));
	}
}
//Objetivo: classificar se a nota é Aprovada ou reprovada
//Parametro: nota
//Retorno: A ou R;
char classificaNota(float nota){
	if(nota>=7){
		return 'A';
	}else{
		return 'R';
	}
}
//Objetivo: ordena a estrutura de forma descrescente de acordo com o salario
//Parametro: endereco do vetor de estrutura alunos, contador de linhas
//Retorno:
void ordenaDecrescente(Aluno *alunos,int contadorDeLinhas){
		int contador,contador2;
		Aluno aux;
		for(contador=0;contador<contadorDeLinhas-1;contador++){
			for(contador2=contador+1;contador2<contadorDeLinhas;contador2++){
				if(((alunos+contador)->nota)<((alunos+contador2)->nota)){
					aux=(*(alunos+contador));
					(*(alunos+contador))=(*(alunos+contador2));
					(*(alunos+contador2))=aux;
				}
			}
		}
}
//Objetivo: ler e validar a string informada
//Parametro: endereco da msg,endereco do texto,valor max
//Retorno:
void leValidaTexto(char *msg,char *texto,int valorMax){
	int contador,contadorDeCaracteresBrancos=0,flag;
	do{
		flag=0;
		printf("%s",msg);
		fflush(stdin);
		fgets(texto,valorMax,stdin);
		fflush(stdin);
		if(texto[strlen(texto)-1]=='\n'){
			texto[strlen(texto)-1]='\0';
		}
		for(contador=0;contador<strlen(texto);contador++){
			texto[contador]=tolower(texto[contador]);
		}
		for(contador=0;contador<strlen(texto);contador++){
			if(texto[contador]==' '){
				contadorDeCaracteresBrancos++;
			}
		}
		if(contadorDeCaracteresBrancos==strlen(texto)){
			printf("Nome invalido! Digite novamente:\n");
			flag=1;
		}
	}while(flag==1);
}
