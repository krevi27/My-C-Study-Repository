// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar uma empresa
 
   Entrada : nome do departamento, nome do funcionario, salario e o tempo de servico na empresa, se deseja encerrar ou informar outro cadastro.

   Saida   : nome do departamento, nome do funcionario, salario e tempo de servico na empresa, se tem mais de 10 anos de servico, caso tenha, salario com + 10% do valor total.

*/

#include <stdio.h>
#include <conio.c>
#include <string.h>
#define MAX_NOME_DEPARTAMENTO 100
#define MIN_NOME_DEPARTAMENTO 5
#define MAX_NOME_FUNCIONARIO 100
#define MIN_NOME_FUNCIONARIO 5
#define MAX_SALARIO 32000
#define MIN_SALARIO 920
#define MAX_TEMPO_SERVICO 45
#define MIN_TEMPO_SERVICO 1
void apresentaDados(char nomeDoDepartamento[],char nomeDoFuncionario[],float *salarioDoFuncionario,int *tempoDeServicoDoFuncionario);
void lerOsDados(char nomeDoDepartamento[],char nomeDoFuncionario[],float *salarioDoFuncionario,int *tempoDeServicoDoFuncionario);
void leString(char titulo[],char string[],int valorMax);
void leValidaString(char titulo[],char msgErro[],char texto[],int valorMax,int valorMin);
void leValidaFloat(char titulo[],char msgErro[],float *valorFloat,int valorMax,int valorMin);
void leValidaInt(char titulo[],char msgErro[],int *valorInt,int valorMax,int valorMin);
int main(void)
{
// Declaracoes
char nomeDoDepartamento[MAX_NOME_DEPARTAMENTO],nomeDoFuncionario[MAX_NOME_FUNCIONARIO],opcao;
float salarioDoFuncionario;
int tempoDeServicoDoFuncionario, encerrarOuContinuar;
// Instrucoes
do{
	system("cls");
	lerOsDados(nomeDoDepartamento,nomeDoFuncionario,&salarioDoFuncionario,&tempoDeServicoDoFuncionario);
	apresentaDados(nomeDoDepartamento,nomeDoFuncionario,&salarioDoFuncionario,&tempoDeServicoDoFuncionario);
	leValidaInt("Para encerrar aperte 0 ; Para continuar aperte 1 ;\n","Informe 1 ou 0\n",&encerrarOuContinuar,1,0);	
}while(encerrarOuContinuar!=0);
  getch();
  return 0;
}
//Objetivo: apresentar todos os dados lidos
//Parametro: endereco do nome do departamento, endereco do nome do funcionario, endereco do salario do funcionario, endereco do tempo de servico do funcionario
//Retorno:
void apresentaDados(char nomeDoDepartamento[],char nomeDoFuncionario[],float *salarioDoFuncionario,int *tempoDeServicoDoFuncionario){
	system("cls");
	printf("-------------- Ficha Cadastral --------------\n");
	printf("Nome: %s\n",nomeDoFuncionario);
	printf("Departamento: %s\n",nomeDoDepartamento);
	printf("Salario: R$ %.2f\n",*salarioDoFuncionario);
	if(*tempoDeServicoDoFuncionario>=10){
		printf("Mas como o funcionario tem mais de 10 anos de casa\n");
		printf("Seu salario se torna: R$ %.2f\n",(*salarioDoFuncionario)*1.1);
	}
	printf("Tempo de servico: %d Anos\n",*tempoDeServicoDoFuncionario);
	getch();
}
//Objetivo: ler todos os dados de entrada
//Parametro: endereco do nome do departamento, endereco do nome do funcionario, endereco do salario do funcionario, endereco do tempo de servico do funcionario
//Retorno:
void lerOsDados(char nomeDoDepartamento[],char nomeDoFuncionario[],float *salarioDoFuncionario,int *tempoDeServicoDoFuncionario){
	leValidaString("Informe o nome do departamento\n","informe um nome corretamente\n",nomeDoDepartamento,MAX_NOME_DEPARTAMENTO,MIN_NOME_DEPARTAMENTO);
	leValidaString("Informe o nome do funcionario\n","Informe o nome corretamente\n",nomeDoFuncionario,MAX_NOME_FUNCIONARIO,MIN_NOME_FUNCIONARIO);
	leValidaFloat("Informe o seu salario no departamento informado\n","informe corretamente\n",salarioDoFuncionario,MAX_SALARIO,MIN_SALARIO);
	leValidaInt("Informe o seu tempo de servico no departamento\n","Informe corretamente\n",tempoDeServicoDoFuncionario,MAX_TEMPO_SERVICO,MIN_TEMPO_SERVICO);
}
//Objetivo: ler uma string
//Parametro: endereco da string
//Retorno:
void leString(char titulo[],char texto[],int valorMax){
	int contadorDeEspacoEmBranco,contador;
	do{
		contadorDeEspacoEmBranco=0;
		printf(titulo);
		fflush(stdin);
		fgets(texto,valorMax,stdin);
		fflush(stdin);
		if(texto[strlen(texto)-1]=='\n'){
			texto[strlen(texto)-1]='\0';
		}
		for(contador=0;contador<strlen(texto);contador++)
			if(texto[contador]==' '){
				contadorDeEspacoEmBranco++;
			}
		if(strlen(texto)==contadorDeEspacoEmBranco){
			printf("Nao informe um string todo em branco\n");
		}
	}while(strlen(texto)==contadorDeEspacoEmBranco);
}
//Objetivo: ler e validar uma string
//Parametro: endereco do titulo, endereco da msgErro, endereco do texto, valor max e valor min
//Retorno:
void leValidaString(char titulo[],char msgErro[],char texto[],int valorMax,int valorMin){
	leString(titulo,texto,valorMax);
	while(strlen(texto)<valorMin){
		leString(msgErro,texto,valorMax);
	}
}
//Objetivo: ler e validar float
//Parametro: endereco do valor float
//Retorno: 
void leValidaFloat(char titulo[],char msgErro[],float *valorFloat,int valorMax,int valorMin){
	int ret;
	do{
		do{
			ret=0;
			printf(titulo);
			fflush(stdin);
			ret=scanf("%f",valorFloat);
			fflush(stdin);
		}while(ret==0);
	}while(*valorFloat < valorMin || *valorFloat > valorMax);
}
//Objetivo: ler e validar float
//Parametro: endereco do valor float
//Retorno: 
void leValidaInt(char titulo[],char msgErro[],int *valorInt,int valorMax,int valorMin){
	int ret;
	do{
		do{
			ret=0;
			printf(titulo);
			fflush(stdin);
			ret=scanf("%d",valorInt);
			fflush(stdin);
		}while(ret==0);
	}while(*valorInt < valorMin || *valorInt > valorMax);
}
