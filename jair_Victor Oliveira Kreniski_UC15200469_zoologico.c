// Aluno : Victor Oliveira Kreniski	

/*
 Sintese
   Objetivo: auxiliar um zoológico
 
   Entrada : quantidade de animais que vão ser informados, ID numérica do animal, peso em gramas do animal.

   Saida   : uma tabela com os pesos informados, respectivas id, assinalando os maiores e menores pesos e as IDs com o peso menor que a media.

*/

#include <stdio.h>
#include <conio.c>
#define MAX 10
#define MIN 1
int leInt(char titulo[]);
int leValidaInt(int valorMinimo,int valorMaximo, char titulo[], char msgDeErro[]);
int testDeIDRepetida(int qtd,int identificacaoDosAnimais[]);
float leFloat(char titulo[]);
float leValidaFloat(int valorMinimo, int valorMaximo, char titulo[],char msgDeErro[]);
int main(void)
{
// Declaracoes
int identificacaoDosAnimais[MAX], qtdDeAnimais,contador,test, qtdAbaixoDaMedia=0;
float pesoDosAnimais[MAX], somaPeso=0,menorPeso,maiorPeso, mediaDoPeso=0;
char observacoes[MAX][20];
// Instrucoes
qtdDeAnimais=leValidaInt(MIN,MAX,"Informe a quantidade de animais a serem informados -MIN:1 -MAX:10\n","Informe uma quantidade respeitando os valores minimo e maximo:\n");
for(contador=0;contador<qtdDeAnimais;contador++){
	do{
	identificacaoDosAnimais[contador]=leValidaInt(MIN,MAX,"Informe a ID:\n","ERRO! Informe uma ID valida \n");
	test=testDeIDRepetida(contador,identificacaoDosAnimais);
	}while(test==1);
	pesoDosAnimais[contador]=leValidaFloat(0,50000,"Informe o peso do animal:\n","ERRO! Informe um peso do animal:\n");
	somaPeso=pesoDosAnimais[contador]+somaPeso;
}	
menorPeso=pesoDosAnimais[0];
maiorPeso=pesoDosAnimais[0];
mediaDoPeso=somaPeso/qtdDeAnimais;
for(contador=0;contador<qtdDeAnimais;contador++){
	if(pesoDosAnimais[contador]>maiorPeso){
		maiorPeso=pesoDosAnimais[contador];
	}
	if(pesoDosAnimais[contador]<menorPeso){
		menorPeso=pesoDosAnimais[contador];
	}
}
for(contador=0;contador<qtdDeAnimais;contador++){
	if(pesoDosAnimais[contador]==maiorPeso){
		strcpy(observacoes[contador],"Maior Peso\0");
	}
}
for(contador=0;contador<qtdDeAnimais;contador++){
	if(pesoDosAnimais[contador]==menorPeso){
		strcpy(observacoes[contador],"Menor peso\0");
	}
}
system("cls");
printf("ID do animal\t Peso do animal\t Observacao\n");
for(contador=0;contador<qtdDeAnimais;contador++){
	printf("%12.d %18.2f  %s \n",identificacaoDosAnimais[contador],pesoDosAnimais[contador],observacoes[contador]);
}
printf("quantidade de animais com o peso menor do que a media:");
for(contador=0;contador<qtdDeAnimais;contador++){
	if(pesoDosAnimais[contador]<mediaDoPeso){
		qtdAbaixoDaMedia++;
	}
}
printf(" e de %d",qtdAbaixoDaMedia);
getch();
return 0;
}


//objetivo: ler inteiro
//parametro: referencial ao titulo
//retorno: valor inteiro
int leInt(char titulo[]){
	int ret, valorInteiro;
	printf(titulo);
	fflush(stdin);
	ret=scanf("%d",& valorInteiro);
	fflush(stdin);
	while(ret==0){
		printf("ERRO! informe um valor valido \n");
		fflush(stdin);
		ret=scanf("%d",& valorInteiro);
		fflush(stdin);
	}
	return valorInteiro;
}
//objetivo: ler e validar inteiro
//parametro: valor min, valor max, referencial ao titutlo, referencial a msg de erro;
//retorno: valor inteiro
int leValidaInt(int valorMinimo, int valorMaximo, char titulo[],char msgDeErro[]){
	int valorInteiro;
	valorInteiro=leInt(titulo);
	while(valorInteiro<valorMinimo || valorInteiro>valorMaximo){
		valorInteiro=leInt(msgDeErro);
	}
	return valorInteiro;
}
//objetivo: impedir de repetir a matricula
//parametro: qtd, referencial ao identificador dos animais
//retorno: 0 ou 1
int testDeIDRepetida(int qtd,int identificacaoDosAnimais[]){
	int contador, test=0;
	for(contador=0;contador<qtd;contador++){
		test=0;
		if(identificacaoDosAnimais[contador]==identificacaoDosAnimais[qtd]){
			test=1;
			printf("ID repetida\n");
			break;
		}else{
			test=0;
		}
	}
	return test;
}
//objetivo: ler float
//parametro: referencial ao titulo
//retorno: valor float
float leFloat(char titulo[]){
	int ret;
	float valorFloat;
	printf(titulo);
	fflush(stdin);
	ret=scanf("%f",& valorFloat);
	fflush(stdin);
	while(ret==0){
		printf("ERRO! informe um valor valido \n");
		fflush(stdin);
		ret=scanf("%f",& valorFloat);
		fflush(stdin);
	}
	return valorFloat;
}
//objetivo: ler e validar float
//parametro: valor min, valor max, referencial ao titulo, referencial a msg de erro
//retorno: valor floar
float leValidaFloat(int valorMinimo, int valorMaximo, char titulo[],char msgDeErro[]){
	float valorFloat;
	valorFloat=leFloat(titulo);
	while(valorFloat<valorMinimo || valorFloat>valorMaximo){
		valorFloat=leFloat(msgDeErro);
	}
	return valorFloat;
}
//objetivo:
//parametro:
//retorno:


