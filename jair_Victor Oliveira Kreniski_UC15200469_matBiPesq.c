// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: gerar uma matriz
 
   Entrada : quantidade de linhas e quantidade de colunas na matriz. Valores para preencher a matriz. Um numero a ser pesquisado na tabela e se deseja continuar

   Saida   :  Uma tabela com os valores informados, se existe ou não o valor informado na tabela.

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
#define MAXLINHAS 20
#define MAXCOLUNAS 6
int leInt(char titulo[]);
int main(void)
{
// Declaracoes
int contador,contador2, qtdDeLinhas, qtdDeColunas, valoresInteiros[MAXLINHAS][MAXCOLUNAS],opcao, valorParaPesquisa, ret;
// Instrucoes
setlocale(LC_ALL,"Portuguese");
qtdDeLinhas=leInt("Informe a quantidade de linhas da matriz:\n");
while(qtdDeLinhas<1 || qtdDeLinhas >MAXLINHAS){
	qtdDeLinhas=leInt("ERRO! Informe a quantidade de linhas da Matriz corretamente (1-20):\n");
}
qtdDeColunas=leInt("Informe a quantidade de colunas da matriz:\n");
while(qtdDeColunas<1 || qtdDeColunas>MAXCOLUNAS){
	qtdDeColunas=leInt("ERRO! Informe a quantidade de colunas da matriz correamente (1-6):\n");
}
for(contador=0;contador<qtdDeLinhas;contador++){
	for(contador2=0;contador2<qtdDeColunas;contador2++){
		system("cls");
		printf("Sendo a linha numero %d e coluna %d \n",contador+1,contador2+1);
		valoresInteiros[contador][contador2]=leInt("Informe o valor que vai preencher o respectivo espaço:\n");
	}
}
system("cls");
for(contador=0;contador<qtdDeLinhas;contador++){
	for(contador2=0;contador2<qtdDeColunas;contador2++){
		printf("%3.d",valoresInteiros[contador][contador2]);
	}
	printf("\n");
}
printf("Para continuar pressione qualquer tecla\n");
getche();
do{
	system("cls");
	ret=0;
	valorParaPesquisa=leInt("Informe o valor para a pesquisa na matriz:\n");
	for(contador=0;contador<qtdDeLinhas;contador++){
		for(contador2=0;contador2<qtdDeColunas;contador2++){
		if(valorParaPesquisa==valoresInteiros[contador][contador2]){
			printf("Valor %d encontrado na coluna: %d  linha: %d\n", valorParaPesquisa, contador+1,contador2+1);
			ret=1;
			}
	}
	}
	if(ret==0){
			printf("\nO valor %d não existe na matriz\n", valorParaPesquisa);
		}
	printf("Deseja continuar?\n");
	opcao=leInt("1 continua - outro numero encerra \n");
}while(opcao==1);
  getch();
  return 0;
}
//Objetivo: ler um valor inteiro
//Parametro: referencial ao titulo
//Retorno: valor inteiro
int leInt(char titulo[]){
	int valorInt, ret;
	do{
		printf(titulo);
		fflush(stdin);
		ret=scanf("%d",&valorInt);
		fflush(stdin);
		if(ret==0){
			printf("ERRO NA LEITURA DO VALOR INTEIRO! ");
		}
	}while(ret==0);
	return valorInt;
}
