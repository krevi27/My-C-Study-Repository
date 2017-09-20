// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: Auxiliar uma loja de megazine.
 
   Entrada : nome Completo, numero do cpf, numero do rg, o sexo, a renda mensal e a data de nascimento.

   Saida   : nome Completo, numero do cpf, numero do rg, o sexo, a renda mensal e a data de nascimento.

*/

#define TAM_NOME 251
#define MIN_NOME 5
#define MAX_RG  8
#define MIN_RG 7
#define MAX_CPF 12
#define MIN_CPF 11
#define MAX_ESPACO_NASCIMENTO 9
#define MIN_ESPACO_NASCIMENTO 8
#define MAX_RENDA 50000
#define MIN_RENDA 0
#include <locale.h>
#include <string.h>
#include <stdio.h>
#include <conio.c>
struct Cadastro{
	float rendaMensal;
	char nomeCompleto[TAM_NOME],numeroDoCpf[MAX_CPF],numeroDoRg[MAX_RG],dataDeNascimento[MAX_ESPACO_NASCIMENTO];
};
void leString(char titulo[],char textoString[],int max);
void leValidaString(char titulo[],char msgErro[],char textoString[],int max,int min);
float leFloat(char titulo[]);
float leValidaFloat(char titulo[], char msgErro[],int valorMax, int valorMin);
int analisaString(char textoString[]);
int main(void)
{
// Declaracoes
struct Cadastro cadastro;
int erro;
// Instrucoes
leValidaString("Informe o seu nome completo\n","Por favor, informe corretamente\n",cadastro.nomeCompleto,TAM_NOME,MIN_NOME);
do{
	erro=0;
	leValidaString("Informe o seu CPF\n","Informe o CPF corretamente\n11 Digitos.\n",cadastro.numeroDoCpf,MAX_CPF,MIN_CPF);
	erro=analisaString(cadastro.numeroDoCpf);
}while(erro==1);
do{
	erro=0;
	leValidaString("Informe o seu RG\n","Informe o RG corretamente\n8 Digitos.\n",cadastro.numeroDoRg,MAX_RG,MIN_RG);
	erro=analisaString(cadastro.numeroDoRg);
}while(erro==1);
do{
	erro=0;
	leValidaString("Informe a sua data de nascimento, EX: 09021990\n","ERRO! Informe a Data de nascimento corretamente\n",cadastro.dataDeNascimento,MAX_ESPACO_NASCIMENTO,MIN_ESPACO_NASCIMENTO);
	erro=analisaString(cadastro.dataDeNascimento);
}while(erro==1);
cadastro.rendaMensal=leValidaFloat("Informe a sua renda mensal\n","ERRO! Informe a renda mensal corretamente\n",MAX_RENDA,MIN_RENDA);
system("cls");
printf("Nome Completo: %s\nData de nascimento: %s\nCPF: %11.11s RG: %10.10s\nRenda Mensal:%.2f Reais\n",cadastro.nomeCompleto,cadastro.dataDeNascimento,cadastro.numeroDoCpf,cadastro.numeroDoRg,cadastro.rendaMensal);
  getch();
  return 0;
}
//Objetivo: validar se a informação entregue pelo usuario está correta
//Parametro: referencial a string
//Retorno: 0 ou 1
int analisaString(char textoString[]){
	int erro,cont;
	for(cont=0;cont<strlen(textoString);cont++){
		if(isdigit(textoString[cont])){
			erro=0;
		}else{
			printf("Somente os valores numericos");
			erro=1;
			break;
		}
	}
	return erro;
}
//Objetivo: ler uma string
//Parametro: referencial ao titulo, referencial a textoString, max
//Retorno:
void leString(char titulo[],char textoString[],int max){
	printf(titulo);
	fflush(stdin);
	fgets(textoString,max,stdin);
	fflush(stdin);
	if(textoString[strlen(textoString)-1]=='\n'){
		textoString[strlen(textoString)-1]='\0';
	}
}
//Objetivo: ler e validar a string
//Parametro: referencial ao titulo, referencial a msg erro, referencial ao vetor texto string, max e min
//Retorno:
void leValidaString(char titulo[],char msgErro[],char textoString[],int max,int min){
	leString(titulo,textoString,max);
	while(strlen(textoString)<min){
		leString(msgErro,textoString,max);
	}
}
//Objetivo: ler float
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
			printf("Valor real está com erro, informe corretamente:\n");
		}
	}while(ret==0);
	return valorFloat;
}
//Objetivo: ler e validar valor Inteiro
//Parametro: referencial ao titulo, mensagem de erro, valor maximo e valor min
//Retorno: valor inteiro
float leValidaFloat(char titulo[], char msgErro[],int valorMax, int valorMin){
	float valorFloat;
	valorFloat=leFloat(titulo);
	while(valorFloat<valorMin || valorFloat>valorMax){
		valorFloat=leFloat(msgErro);
	}
	return valorFloat;
}
