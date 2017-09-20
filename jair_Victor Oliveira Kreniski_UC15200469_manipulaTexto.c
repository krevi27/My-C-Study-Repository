// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: manipular um texto
 
   Entrada : um texto

   Saida   :  quantidade de caracteres, quantidade de caracteres numéricos, quantidade de caracteres alfábeticos (a-z,A-Z)
   			texto todo em caracteres minusculos, o texto com os caracteres na ordem inversa

	ler e validar a string texto (void leValidaString)
	obter a quantidade de caracteres alfabéticos(int obtemQtddeAplha)
	passar caracteres para minusculo e apresentar(void passaCaractersParaMinusculo)
	apresentar o texto invertido(void mostraTextoInverso)
	
*/

#include <stdio.h>
#include <conio.c>
#define TAMNOME 500
void leValidaString(char titulo[],char msgDeErro[],int tamanhoMinimo, int tamanhoMaximo, char texto[]);
int obtemQtdeAlpha(char texto[]);
void passaCaractersParaMinusculo(char texto[]);
void mostraTextoInverso(char texto[]);
int main(void)
{
// Declaracoes
char texto[TAMNOME];
int contador, qtdNumericaNoTexto=0, qtdAlfabeticaNoTexto;
// Instrucoes
leValidaString("Informe o texto, min 10 - max 500 caracteres\n","ERRO! Informe o texto corretamente\n", 10, TAMNOME, texto);
system("cls");
printf("a quantidade de caracteres existente no texto e: %u \n", (unsigned)strlen(texto));
for(contador=0;contador<=TAMNOME-1;contador++){
	if(texto[contador]>=48 && texto[contador]<=57){
		qtdNumericaNoTexto++;
	}
}
qtdAlfabeticaNoTexto=obtemQtdeAlpha(texto);
printf("a quantidade de caracteres alfabeticos e de: %d \n",qtdAlfabeticaNoTexto);
passaCaractersParaMinusculo(texto);
mostraTextoInverso(texto);
  getch();
  return 0;
}
//Objetivo ler e validar string
//Parametro referencia ao titulo, referencia a mensagem de erro, tamanho minimo, tamanho maximo, referencia ao texto
//Retorno 
void leValidaString(char titulo[],char msgDeErro[],int tamanhoMinimo, int tamanhoMaximo, char texto[]){
	do{
		printf("%s \n",titulo);
		fflush(stdin);
		fgets(texto,tamanhoMaximo,stdin);
		fflush(stdin);
		if(texto[strlen(texto)-1]=='\n'){
			texto[strlen(texto)-1]='\0';
		}
		if(strlen(texto)<tamanhoMinimo){
			printf("%s \n",msgDeErro);
		}
	}while(strlen(texto)<tamanhoMinimo);
}
//Objetivo obter quantidade de caracteres alfabeticos
//Parametro referencial ao texto
//Retorno quantidade de caracteres alfabeticos
int obtemQtdeAlpha(char texto[]){
	int contador, quantidadeDeLetras=0;
	for(contador=0;contador<=strlen(texto);contador++){
		if(texto[contador]>=65 && texto[contador]<=90){
			quantidadeDeLetras++;
		}
		if(texto[contador]>=97 && texto[contador]<=122){
			quantidadeDeLetras++;
		}
	}
	return quantidadeDeLetras;
}
//Objetivo passar caracteres para minusculo
//Parametro referencia ao vetor de texto
//Retorno
void passaCaractersParaMinusculo(char texto[]){
	int contador;
	for(contador=0;contador<=strlen(texto);contador++){
		if(texto[contador]>=65 && texto[contador]<=90 || texto[contador]>=97 && texto[contador]<=122){
			texto[contador]=tolower(texto[contador]);
		}
	}
	printf("texto todo minusculo e: %s \n", texto);
}
//Objetivo apresentar texto inverso
//Parametro referencial ao vetor de texto
//Retorno
void mostraTextoInverso(char texto[]){
	int contador;
	printf("texto de tras para frente e: ");
	for(contador=strlen(texto)-1; contador>=0; contador--){
		printf("%c", texto[contador]);
	}
}
