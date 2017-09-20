// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: separar par e impar
 
   Entrada : valores inteiros e se deseja continuar

   Saida   : todos os numeros inteiros informados, numeros pares em ordem crescente, numeros impares em ordem crescente, quantidade de numeros pares e impares.

*/

#include <stdio.h>
#include <conio.c>
//Prototipos
int leValidaInt(char titulo[],int cont);
int leInt();
char validaOpcao();
void ordenaCrescentePar(int vetPar[], int contPar);
void ordenaCrescenteImpar(int vetImpar[], int contImpar);
void apresentaParImpar(int numeros[],int vetPar[],int vetImpar[],int cont,int contPar,int contImpar,int qntPar,int qntImpar);
//
int main(void)
{
// Declaracoes
 int numeros[100],vetPar[100],vetImpar[100],cont=0,contImpar=0,contPar=0,qntPar=0,qntImpar=0;
 char opcao;
// Instrucoes
	do{
     numeros[cont]=leValidaInt("\nInforme o numero: ",cont);
     opcao=validaOpcao();
     if(numeros[cont]%2==0){
     	vetPar[contPar]=numeros[cont];
     	contPar++;
     	qntPar++;
	 }else{
     	vetImpar[contImpar]=numeros[cont];
     	contImpar++;
     	qntImpar++;
	 }
     cont++;
     system("cls");
	}while(opcao=='S');
	 	ordenaCrescentePar(vetPar,contPar);
	 	ordenaCrescenteImpar(vetImpar,contImpar);
	    apresentaParImpar(numeros,vetPar,vetImpar,cont,contPar,contImpar,qntPar,qntImpar);
   getch();
  return 0;
}
// Objetivo: apresentar a tabela final
// Prâmetros: referencia aos vetores,e os contadores,quantidade impar e par
// Retorna:
void apresentaParImpar(int numeros[],int vetPar[],int vetImpar[],int cont,int contPar,int contImpar,int qntPar,int qntImpar){
		int cont2;
		printf("Numeros  ");	
	   for(cont2=0;cont2<cont;cont2++){
   	 	printf("\n%d ",numeros[cont2]);

   	   }
   	    printf("\nPares em crescente:");
        for(cont2=0;cont2<contPar;cont2++){
   			printf("\n%d",vetPar[cont2]);
	    }
	    printf("\nA quantidade de numeros pares e %d",qntPar);
	    printf("\nImpares em crescente:");
	    for(cont2=0;cont2<contImpar;cont2++){
   		printf("\n%d",vetImpar[cont2]);
	    }
	    printf("\nA quantidade de numeros impar e %d",qntImpar);
}
// Objetivo: ordena os numeros do vetor impar
// Prâmetros: referencia ao vetor impar e contador impar
// Retorna:
void ordenaCrescenteImpar(int vetImpar[], int contImpar){
 int menorValor, aux, contador, i;
 for(contador=0;contador<contImpar;contador++){
  menorValor=contador;
  for(i=contador+1; i<contImpar; i++){
   if(vetImpar[menorValor]>vetImpar[i]){
    menorValor=i;
   }
  }
  if(contador!=menorValor){
   aux=vetImpar[contador];
   vetImpar[contador]=vetImpar[menorValor];
   vetImpar[menorValor]=aux;
  }
 }
}
// Objetivo: ordena os numeros do vetor par
// Prâmetros: referencia ao vetor par e contador par
// Retorna:
void ordenaCrescentePar(int vetPar[], int contPar){
 int menorValor, aux, contador, p;
 for(contador=0;contador<contPar;contador++){
  menorValor=contador;
  for(p=contador+1; p<contPar; p++){
   if(vetPar[menorValor]>vetPar[p]){
    menorValor=p;
   }
  }
  if(contador!=menorValor){
   aux=vetPar[contador];
   vetPar[contador]=vetPar[menorValor];
   vetPar[menorValor]=aux;
  }
 }
}
//Objetivo:Validar a opcao do usuario
//Parametros:
//Retorno:opcao
char validaOpcao(){
   char opcao;
   printf("\nDeseja continuar S/N: ");
   opcao=getch();
   opcao=toupper(opcao);
   	while(opcao!='N'&& opcao!='S'){
   		printf("\nOpcao invalida, informe  S/N: ");
    	opcao=getch();
    	opcao=toupper(opcao);
   	   }  
   	 return opcao;  
}  
//Objetivo:ler e valida um numero inteiro
//Parametros:titulo e contador
//Retorno:numero
int leValidaInt(char titulo[],int cont){
    int nmr;
    do{
	printf(titulo,cont+1);
	nmr=leInt();
		if(nmr<0){
			printf("\nNumero invalido,informe um valido");
		}	
	}while(nmr<0);
	return nmr;
}
//Objetivo:ler o numero inteiro
//Parametros:nenhum
//Retorno:numero
int leInt(){
	int nmr,retInt;
	do{
	fflush(stdin);
	retInt=scanf("%d",&nmr);
	fflush(stdin);
		if(retInt==0){
			printf("\nnumero invalido,informe um valido");
		}
	}while(retInt==0);
	return nmr;
}
