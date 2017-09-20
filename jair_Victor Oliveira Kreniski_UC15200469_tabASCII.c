// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo:
 	Criar uma tabela ASCII
   Entrada : 
	caracteres e se deseja continuar ou não
   Saida   :  
	o caracter informado, valor decimal correspondente ao caractere, valor octal correspondente ao caractere, valor hexadecimal correspondente ao caractere.
*/

#include <stdio.h>
#include <conio.c>

int main(void)
{
// Declaracoes
char caracteresInformados[15], opcaoContinuar;
int contador;
// Instrucoes
do{
	for(contador=1;contador<=15;contador++)
		{
		system("cls");
		printf("Informe o caracter de numero %d \n", contador);
		scanf("%c",&caracteresInformados[contador]);
		caracteresInformados[contador]=toupper(caracteresInformados[contador]);
			while(caracteresInformados[contador-1]<65 || caracteresInformados[contador-1]>90)
			{
				system("cls");
				printf("ERRO! Informe o caracter de numero %d \n", contador);
				scanf("%c",&caracteresInformados[contador]);
				caracteresInformados[contador]=toupper(caracteresInformados[contador-1]);
			}
		
		}
		system("cls");
		printf("Caractere - valor decimal - valor octal - valor hexadecimal \n");
		printf("%9c - %13d - %10o -%10x \n");
		printf("deseja continuar? Sim ou Nao");
		opcaoContinuar=getche();
		opcaoContinuar=toupper(opcaoContinuar);
		while(opcaoContinuar!='S'||opcaoContinuar!='N'){
			system("cls");
			printf("ERRO Informe corretamente o caracter \n");
			printf("deseja continuar? Sim ou Nao \n");
			opcaoContinuar=getche();
			opcaoContinuar=toupper(opcaoContinuar);
		}
	}while(opcaoContinuar!='N');
		gotoxy(35,1);
		printf("Tabela ASCII encerrada");	
	 getch();
  return 0;
}

