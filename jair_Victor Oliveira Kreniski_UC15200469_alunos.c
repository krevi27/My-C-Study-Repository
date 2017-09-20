// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar alunos com as suas notas
 
   Entrada : Notas

   Saida   :notas informadas, média aritmética das notas em forma de tabela

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
float leFloat(char titulo[]);
void calculaMedias(float notas[7][3],float medias[7][1]);
int main(void)
{
// Declaracoes
float notas[7][3],medias[7][1];
int contador,contador2;
// Instrucoes
setlocale(LC_ALL,"Portuguese");
for(contador=0;contador<7;contador++){
	system("cls");
	printf("Para o %dº aluno\n",contador+1);
	for(contador2=0;contador2<3;contador2++){
		notas[contador][contador2]=leFloat("Informe a sua nota:\n");
		while(notas[contador][contador2]<0 || notas[contador][contador2]>10){
			notas[contador][contador2]=leFloat("Informe uma nota correta:\n");
		}
	}
}
calculaMedias(notas, medias);
system("cls");
printf("Aluno - Nota 1 - Nota 2 - Nota 3 - Media \n");
printf("-------------------------------------------\n");
for(contador=0;contador<7;contador++){
	for(contador2=0;contador2<1;contador2++){
		printf("%5.2d   %6.2f   %6.2f   %6.2f   %5.2f \n",contador+1,notas[contador][contador2],notas[contador][contador2+1],notas[contador][contador2+2],medias[contador][contador2]);
	}
}
getch();
return 0;
}


//Objetivo: ler um valor float
//Parametro: referencial ao titulo
//Retorno: valor float
float leFloat(char titulo[]){
	float valorFloat;
	int ret;
		printf(titulo);
		fflush(stdin);
		ret=scanf("%f",& valorFloat);
		fflush(stdin);
		while(ret==0){
			system("cls");
			printf("ERRO!");
			printf(titulo);
			fflush(stdin);
			ret=scanf("%f",&valorFloat);
			fflush(stdin);
		}
		return valorFloat;
}
//Objetivo: calcular medias
//Parametro: referencia a matriz bidemensional notas, referencia a matriz bidemensional medias
//Retorno:
void calculaMedias(float notas[7][3],float medias[7][1]){
	int contador,contador2;
	float somaMedia;
	for(contador=0;contador<7;contador++){
		somaMedia=0;
		for(contador2=0;contador2<3;contador2++){
			somaMedia=notas[contador][contador2]+somaMedia;
		}
		medias[contador][0]=somaMedia/3;
	}
}

