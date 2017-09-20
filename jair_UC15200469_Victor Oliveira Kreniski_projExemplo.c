// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar os funcionarios de uma empresa
 
   Entrada : matricula, nome, salario atual e nome do departamento

   Saida   : Menu de opções,

*/

#include <stdio.h>
#include <conio.c>
#define MAX_NOME 30
#define MAX_DEPARTAMENTO 30
//Declaração de estruturas ======
typedef struct Funcionario{
	int matricula;
	char nome[MAX_NOME];
	float salarioAtual;
	char nomeDoDepartamento[MAX_DEPARTAMENTO];
}Funcionario;
//Funcoes que constinuem o Menu principal =======
void apresentaTabelaFuncionarios();
void apresentaTabelaDepartamento(const int maxDepartamento);
void apresentaTabelaMatricula();
void leDadosESalvaDados(int maxNome,int maxDepartamento);
//Funcoes auxiliares da salvaDadosArquivo =====
void salvaDadosArquivo(Funcionario *funcionario);
void leDados(int maxNome,int maxDepartamento,Funcionario *funcionario);
//Funcao auxiliar a leDados ======
int verificaMatricula(int matricula);
//Funcoes auxiliares de leitura de dados ====
void leFloat(char *msg,float *valorFloat);
void leInt(char *msg,int *valorInteiro);
void leValidaOpcao(char *msg,char *opcao,char *opcoes);
void leValidaString(char *msg, char *texto, int tamanhoMax);

int main(void)
{
// Declaracoes
char opcao;
// Instrucoes
do{
	system("cls");
	leValidaOpcao("Informe qual opcao voce deseja executar:\nC-Cadastrar\nA-Apresentar tabela dos funcionarios cadastrados\nD-Pesquisar por departamento\nM-Pesquisar os dados de um funcionario pela matricula\nE-Encerrar",&opcao,"CADME");
	switch(opcao){
		case 'C':
			system("cls");
			leDadosESalvaDados(MAX_NOME,MAX_DEPARTAMENTO);
			printf("Pressione para continuar\n");
			getch();
			break;
		case 'A':
			system("cls");
			apresentaTabelaFuncionarios();
			printf("Pressione para continuar\n");
			getch();
			break;
		case 'D':
			system("cls");
			apresentaTabelaDepartamento(MAX_DEPARTAMENTO );
			printf("Pressione para continuar\n");
			getch();
			break;
		case 'M':
			system("cls");
			apresentaTabelaMatricula();
			printf("Pressione para continuar\n");
			getch();
			break;
		case 'E':
			system("cls");
			break;
	}
}while(opcao!='E');
  return 0;
}
//Objetivo: apresentar a tabela de acordo com a funcao selecionada
//Parametro: opcao
//Retorno:
void apresentaTabelaFuncionarios(){
	FILE *arq;
	int contador=0;
	Funcionario funcionario;
	if((arq=fopen("dadosFunc.txt","rb"))!=NULL){
				while(!feof(arq)){
					if(fread(&funcionario,sizeof(Funcionario),1,arq)==1){
						if(contador==0){
							system("cls");
							printf("%10.10s %10.10s %10.10s %13.13s\n","Matricula","Nome","Salario","Departamento");
						}
						printf("%10d %10.10s %10.2f %13.13s\n",funcionario.matricula,funcionario.nome,funcionario.salarioAtual,funcionario.nomeDoDepartamento);
						contador++;
					}else{
						if(feof(arq)){
							break;
						}else{
							printf("Arquivo corrompido\n");
						}
					}
				}
		fclose(arq);
	}else{
		printf("Nao foi possivel abrir o arquivo para apresentar os dados cadastrados\nVerifique o diretório\n");
	}
}
//Objetivo: apresentar uma tabela com base na palavra fornecida
//Parametro: max departamento
//Retorno:
void apresentaTabelaDepartamento(const int maxDepartamento){
	FILE *arq;
	int contador=0;
	Funcionario funcionario;
	char departamentoPesquisa[maxDepartamento];
	leValidaString("Informe o nome do departamento para fazer a pesquisa\n",departamentoPesquisa,maxDepartamento);
	if((arq=fopen("dadosFunc.txt","rb"))!=NULL){
		while(!feof(arq)){
			if(fread(&funcionario,sizeof(Funcionario),1,arq)==1){
				if(stricmp((funcionario.nomeDoDepartamento),departamentoPesquisa)==0){
					if(contador==0){
						system("cls");
						printf("%10.10s %10.10s %10.10s %13.13s\n","Matricula","Nome","Salario","Departamento");
					}
						printf("%10d %10.10s %10.2f %13.13s\n",funcionario.matricula,funcionario.nome,funcionario.salarioAtual,funcionario.nomeDoDepartamento);
						contador++;
					}
				}else{
					if(feof(arq)){
					break;
					}else{
						printf("Arquivo corrompido\n");
					}
				}
			}
		fclose(arq);
		if(contador==0){
			printf("Nao foi encontrado nada com esse nome de departamento\n");
		}
	}else{
		printf("Nao foi possivel abrir o arquivo para pesquisar por departamento\nOlhe o diretório do programa\n");
	}
}
//Objetivo: apresenta os dados do funcionario com base na matricula informada
//Parametro:
//Retorno:
void apresentaTabelaMatricula(){
	int matricula,contador=0;
	FILE *arq;
	Funcionario funcionario;
	do{
		leInt("Informe uma matricula para ser pesquisada\n",&matricula);
		if(matricula<=0){
			printf("Erro! Matricula nao e valida\n");
			getch();
		}
	}while(matricula<=0);
	if((arq=fopen("dadosFunc.txt","rb"))!=NULL){
		while(!feof(arq)){
			if(fread(&funcionario,sizeof(Funcionario),1,arq)==1){
				if(funcionario.matricula==matricula){
					system("cls");
					printf("Funcionario encontrado --- Dados abaixo\n");
					printf("%10.10s %10.10s %10.10s %13.13s\n","Matricula","Nome","Salario","Departamento");
					printf("%10d %10.10s %10.2f %13.13s\n",funcionario.matricula,funcionario.nome,funcionario.salarioAtual,funcionario.nomeDoDepartamento);
					contador++;
					break;
				}
			}
		}
		if(contador=0){
			printf("Nao foi encontrado nenhum funcionario com a matricula: %d",matricula);
		}
		fclose(arq);
	}else{
		printf("Nao foi possivel abrir o arquivo para buscar o funcionario pela matricula\n");
	}
}
//Objetivo: ler os dados e salvar no arquivo
//Parametro: max nome e max departamento
//Retorno:
void leDadosESalvaDados(int maxNome,int maxDepartamento){
	Funcionario funcionario;
	leDados(maxNome,maxDepartamento,&funcionario);
	salvaDadosArquivo(&funcionario);
}
//Objetivo: responsavel em ler os dados
//Parametro: maxNome, maxDepartamento, endereco da estrutura de funcionario
//Retorno:
void leDados(int maxNome,int maxDepartamento,Funcionario *funcionario){
	int flag;
	do{
		do{
			leInt("Informe a matricula do funcionario\n",&funcionario->matricula);
			if(funcionario->matricula<=0){
				flag=1;
				printf("Qualquer matricula que seja maior do que 0\n");
			}else{
				flag=0;
			}
		}while(flag==1);
		flag=verificaMatricula(funcionario->matricula);
		if(flag==1){
			printf("Matricula repetida!\n");
		}
	}while(flag==1);
		leValidaString("Informe o seu nome:\n",funcionario->nome,maxNome);
		do{
			leFloat("Informe o seu salario atual\n",&funcionario->salarioAtual);
			if(funcionario->salarioAtual<=0){
				printf("Informe um salario valido\n");
			}
		}while(funcionario->salarioAtual<=0);
		leValidaString("Informe o nome do departamento que voce trabalha\n",funcionario->nomeDoDepartamento,maxDepartamento);
}
//Objetivo: salvar os dados no arquivo dadosFunc.txt no diretório do programa
//Parametro: referencia a estrutura funcionario
//Retorno:
void salvaDadosArquivo(Funcionario *funcionario){
	FILE *arq;
	if((arq=fopen("dadosFunc.txt","ab"))!=NULL){
		if((fwrite(funcionario,sizeof(Funcionario),1,arq))==1){
			printf("Gravado com sucesso\n");
		}else{
			printf("Erro ao gravar no arquivo dadosFunc.txt\n");
		}
		fclose(arq);
	}else{
		printf("Nao foi possivel abrir o arquivo para gravar os dados\n");
	}
}

//Objetivo: verificar se a matricula informada e repetida
//Parametro: matricula
//Retorno: 0 ou 1
int verificaMatricula(int matricula){
	FILE *arq;
	Funcionario funcionario;
	if((arq=fopen("dadosFunc.txt","rb"))!=NULL){
		while(!feof(arq)){
			if((fread(&funcionario,sizeof(Funcionario),1,arq))==1){
				if(funcionario.matricula==matricula){
					fclose(arq);
					return 1;
				}
			}else{
				if(feof(arq)){
					break;
				}else{
					printf("Dado corrompido\n");
				}
			}
		}
		return 0;
		fclose(arq);
	}else{
		printf("Nao foi encontrado o arquivo para o teste de matricula\nQualquer duvida va ate o diretorio do programa\n");
		return 0;
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
