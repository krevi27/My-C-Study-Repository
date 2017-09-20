// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar um banco
 
   Entrada : numero de clientes, para cada cliente: numero da conta, que não pode ser repetido e o saldo atual.

   Saida   :  dados de todos os clientes cadastrados indicando os clientes que possuem o maior e menor saldo e a quantidade de clientes com saldo menor que o saldo médio
   
	ler(leInt) e validar a quantidade de clientes no banco
	ler(leInt) e validar o numero da conta
	ler(leFloat) e validar o saldo
	calcular qual cliente possue o maior saldo
	calcular qual cliente possue o menor saldo
	calcular a media do saldo
	comparar todos os saldos e mostrar qual deles tem menos que a média.
*/

#include <stdio.h>
#include <conio.c>
#define MAXFUNC 999
int leInt(char titulo[]);
float leFloat(char titulo[]);
int main(void)
{
// Declaracoes
int qtdDeClientes, contador, contador2, numerosDasContas[MAXFUNC], ret=0, numeroDoMaiorSaldo, numeroDoMenorSaldo;
float saldosAtuais[MAXFUNC], saldoMaior, saldoMenor, mediaDoSaldo;
// Instrucoes
	saldoMenor=10000001;
	saldoMaior=0;
	mediaDoSaldo=0;
	 qtdDeClientes=leInt("Informe a quantidade de clientes existentes no banco:");
	 while(qtdDeClientes<=0 || qtdDeClientes>MAXFUNC){
	 	system("cls");
	 	qtdDeClientes=leInt("ERRO Informe a quantidade de clientes existentes no banco:");
	 }
	 for(contador=0;contador<=qtdDeClientes-1;contador++){
	 	system("cls");
		do{
			numerosDasContas[contador]=leInt("Informe o numero da sua conta:");
				for(contador2=0;contador2<=contador-1;contador2++){
					if(numerosDasContas[contador2]==numerosDasContas[contador]){
						ret=1;
						printf("Já existe!");
						break;
					}else{
						ret=0;
					}
				
				}
		}while(ret==1);
		saldosAtuais[contador]=leFloat("Informe o seu saldo:");
		while(saldosAtuais[contador]>10000000){
			saldosAtuais[contador]=leFloat("ERRO! Informe o seu saldo:");
		}
	}
	 system("cls");
	 	printf("Cadastro Cliente \t Saldo \n");
	 for(contador=0;contador<=qtdDeClientes-1;contador++){
	 	printf("%16.d\t %5.f \n",numerosDasContas[contador],saldosAtuais[contador]);
		if(saldoMaior<=saldosAtuais[contador]){
			saldoMaior=saldosAtuais[contador];
			numeroDoMaiorSaldo=numerosDasContas[contador];
		}
		if(saldoMenor>=saldosAtuais[contador]){
			saldoMenor=saldosAtuais[contador];
			numeroDoMenorSaldo=numerosDasContas[contador];
		}
	 }
	 printf("Maior saldo pertence a matricula: %d sendo o saldo com o valor: R$%2.f \n",numeroDoMaiorSaldo,saldoMaior);
	 printf("Menor saldo pertence a matricula: %d sendo o saldo com o valor: R$%2.f \n",numeroDoMenorSaldo,saldoMenor);
	 printf("Deseja continuar?");
	 getche();
	 system("cls");
	 for(contador=0;contador<=qtdDeClientes-1;contador++){
	 	mediaDoSaldo=saldosAtuais[contador]+mediaDoSaldo;
	 }
	 printf("Cadastros com o saldo menor que a media: \n");
	mediaDoSaldo=mediaDoSaldo/qtdDeClientes;
	 for(contador=0;contador<=qtdDeClientes-1;contador++){
	 	if(saldosAtuais[contador]<mediaDoSaldo){
			printf("%d \n",numerosDasContas[contador]);
		 }
	 }
  getch();
  return 0;
}
//Objetivo: ler um inteiro
//Parametro: referencial ao titulo
//Retorno: inteiro
int leInt(char titulo[]){
	int retScanf, inteiro;
	do{
		printf("%s\n",titulo);
		fflush(stdin);
		retScanf=scanf("%d",&inteiro);
		fflush(stdin);
	}while(retScanf==0);
	return inteiro;
}
//Objetivo: ler um valor float
//Parametro: referencial ao titulo
//Retorno: valor float
float leFloat(char titulo[]){
	int retScanf;
	float valorReal;
	do{
		printf("%s\n",titulo);
		fflush(stdin);
		retScanf=scanf("%f",&valorReal);
		fflush(stdin);
	}while(retScanf==0);
	return valorReal;
}
