// Aluno : Victor Oliveira Kreniski

/*
algoritmo controleAlturas;
// Síntese
//  Objetivo:  auxiliar uma pesquisa
//  Entrada : quantidade de pessoas, altura, se deseja continuar.
//  Saída   : Maior Altura, menor Altura, média das alturas de um conjunto de pessoas.

// Valores de Entrada
// 3 pessoas
// 1
// 1,85
// 1,53
// Valores de Saida
//Maior Altura: 1,85
//Menor Altura: 1,00
//Média de altura: 1,46
principal
	// Declarações
	real alturas[100], mediaDasAlturas, maiorAltura, menorAltura;
	inteiro qtdDePessoas,contador;
	// Instruções
	mediaDasAlturas=0;
	maiorAltura=0;
	menorAltura=3.1;
	escreval("Informe a quantidade de pessoas que vão fornecer a altura. ( Até 100 Pessoas)");
	leia(qtdDePessoas);
	enquanto(qtdDePessoas<=0 ou qtdDePessoas>100)faca
		limpaTela();
		escreval("ERRO! Informe a quantidade de pessoas que vão fornecer a altura. ( Até 100 Pessoas)");
		leia(qtdDePessoas);
	fimEnquanto
	para(contador de 0 ate qtdDePessoas-1 passo 1)faca
		limpaTela();
		escreval("Informe a sua altura, usuario ",contador+1,"º");
		leia(alturas[contador]);
		enquanto(alturas[contador]<=0 ou alturas[contador]>3)faca
			limpaTela();
			escreval("ERRO! Informe a sua altura, usuario ",contador+1,"º");
			leia(alturas[contador]);
		fimEnquanto
	fimPara
	para(contador de 0 ate qtdDePessoas-1 passo 1)faca
		se(alturas[contador]<menorAltura)entao
			menorAltura=alturas[contador];
		fimSe
	fimPara
	para(contador de 0 ate qtdDePessoas-1 passo 1)faca
		se(alturas[contador]>maiorAltura)entao
			maiorAltura=alturas[contador];
		fimSe
	fimPara
	para(contador de 0 ate qtdDePessoas-1 passo 1)faca
		mediaDasAlturas=mediaDasAlturas+alturas[contador];
	fimPara
	mediaDasAlturas=mediaDasAlturas/qtdDePessoas;
	limpaTela();
	escreval("Maior Altura: ",maiorAltura);
	escreval("Menor Altura: ",menorAltura);
	escreval("Media das Alturas: ",mediaDasAlturas);
fimPrincipal
*/

#include <stdio.h>
#include <conio.c>

int main(void)
{
// Declaracoes
	float alturas[100], mediaDasAlturas, maiorAltura, menorAltura;
	int qtdDePessoas,contador;
// Instrucoes
	mediaDasAlturas=0;
	maiorAltura=0;
	menorAltura=3.1;
	printf("Informe a quantidade de pessoas que vão fornecer a altura. ( Até 100 Pessoas)\n");
	scanf("%d",& qtdDePessoas);
	while(qtdDePessoas<=0 || qtdDePessoas>100){
		system("cls");
		printf("ERRO! Informe a quantidade de pessoas que vão fornecer a altura. ( Até 100 Pessoas)\n");
		scanf("%d",&qtdDePessoas);
	}
	for(contador=0;contador<=qtdDePessoas-1;contador++){
		system("cls");
		printf("Informe a sua altura, usuario %dº",contador+1);
		scanf("%f",& alturas[contador]);
		while(alturas[contador]<=0 || alturas[contador]>3){
			system("cls");
			printf("ERRO! Informe a sua altura, usuario %dº",contador+1);
			scanf("%f",&alturas[contador]);
		}
	}
	for(contador=0;contador<=qtdDePessoas-1;contador++){
		if(alturas[contador]<menorAltura){
			menorAltura=alturas[contador];
		}
	}
	for(contador=0;contador<=qtdDePessoas-1;contador++){
		if(alturas[contador]>maiorAltura){
			maiorAltura=alturas[contador];
		}
	}
	for(contador==0;contador<=qtdDePessoas-1;contador++){
		mediaDasAlturas=mediaDasAlturas+alturas[contador];
	}
	mediaDasAlturas=mediaDasAlturas/qtdDePessoas;
	system("cls");
	printf("Maior Altura: %.2f ",maiorAltura);
	printf("Menor Altura: %.2f ",menorAltura);
	printf("Media das Alturas: %.2f ",mediaDasAlturas);
  getch();
  return 0;
}
