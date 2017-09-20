// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: concatenar
 
   Entrada : três nomes.

   Saida   : conteudo da string com todos os 3 nomes juntos, quantidade de letras a ou A existentes, se a string contem se,Se,sE,SE.
			
			será requisitado ao usuario 3 nomes a serem informados, após os 3 nomes serem lidos e validados será feito a concatenação(void concatencao)e vai ser apresentado o nome completo. vai ser contado a quantidade de
			letras a ou A na string(int contadorDeLetrasA) e sera apresentado a quantidade de letras a ou A. Verificar a quantidade de se,Se,sE,SE na string(verificadorDeSe) e apresentar se existem na string
*/

#include <stdio.h>
#include <conio.c>
void leValidaTexto(char titulo[], char nome[]);
void concatenacao(char nome1[],char nome2[],char nome3[],char nomeCompleto[]);
int contadorDeLetrasA(char nomeCompleto[]);
int verificadorDeSe(char nomeCompleto[]);

int main(void)
{
// Declaracoes
char nome1[101],nome2[101],nome3[101],nomeCompleto[301];
int contadorDeAs, quantidadeDeSe;

// Instrucoes
leValidaTexto("Informe o primeiro nome\n", nome1);
leValidaTexto("Informe o segundo nome\n",nome2);
leValidaTexto("Informe o terceiro nome\n",nome3);
concatenacao(nome1,nome2,nome3,nomeCompleto);
puts(nomeCompleto);
contadorDeAs=contadorDeLetrasA(nomeCompleto);
printf("Quantidade de A ou a:%d \n",contadorDeAs);
quantidadeDeSe=verificadorDeSe(nomeCompleto);
if(quantidadeDeSe>0){
	printf("Contem se, Se, sE, SE na string \n");
}else{
	printf("Não contem se, Se, sE, SE na string \n");
}

  getch();
  return 0;
}
//Objetivo: ler e validar string de texto
//Parametro: referencial ao titulo, referencial ao vetor nome;
//Retorno:
void leValidaTexto(char titulo[], char nome[]){
 system("cls");
 do{
  printf(titulo);
  fflush(stdin);
  fgets(nome, 101, stdin);
  fflush(stdin);
  if(strlen(nome)<2 || strlen(nome)>101){
   system("cls");
   printf("O nome deve ter entre 1 e 100 letras\n");
  }
 }while(strlen(nome)<2 || strlen(nome)>101);
 system("cls");
}
//Objetivo: concatenar os nomes
//Parametro: referencial ao vetor nome1, referencial ao vetor nome2, referencial ao nome3, referencal ao nomeCompleto
//Retorno:
void concatenacao(char nome1[],char nome2[],char nome3[],char nomeCompleto[]){
int cont;
 strcpy(nomeCompleto, nome3);
 for(cont=0; cont<=strlen(nomeCompleto)-1; cont++){
 	 if(nomeCompleto[cont]=='\n'){
   		nomeCompleto[cont]=',';
  	 }
 }
 strcat(nomeCompleto, nome1);
 for(cont=0; cont<=strlen(nomeCompleto)-1; cont++){
 	 if(nomeCompleto[cont]=='\n'){
   		nomeCompleto[cont]=' ';
  	 }
 }
 strcat(nomeCompleto, nome2);
}
//Objetivo: contador de letras A ou a
//Parametro: referencial ao vetor nomeCompleto
//Retorno: quantidade de letras A ou a
int contadorDeLetrasA(char nomeCompleto[]){
int contador, contadorDeAs=0;
for(contador=0;contador<strlen(nomeCompleto)-1;contador++){
	if(nomeCompleto[contador]=='a'||nomeCompleto[contador]=='A'){
		contadorDeAs++;
	}
}
return contadorDeAs;
}
//Objetivo: verificar se existe se, Se, sE, SE na string.
//Parametro: referencia ao vetor nomeCompleto
//Retorno: quantidadeDeSe;
int verificadorDeSe(char nomeCompleto[]){
int contador, quantidadeDeSe=0;
for(contador=0;contador<strlen(nomeCompleto)-1;contador++){
	if(nomeCompleto[contador]=='s'&& nomeCompleto[contador+1]=='e'){
		quantidadeDeSe++;
	}
	if(nomeCompleto[contador]=='S'&& nomeCompleto[contador+1]=='e'){
		quantidadeDeSe++;
	}
	if(nomeCompleto[contador]=='s'&& nomeCompleto[contador+1]=='E'){
		quantidadeDeSe++;
	}
	if(nomeCompleto[contador]=='S'&& nomeCompleto[contador+1]=='E'){
		quantidadeDeSe++;
	}
}
return quantidadeDeSe;
}
