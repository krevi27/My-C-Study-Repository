// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar uma empresa
 
   Entrada : quantidade de funcionarios e para cada funcionario o seu salário e sexo;

   Saida   :  média dos salários dos funcionarios e a média dos salarios das funcionárias

*/

#include <stdio.h>
#include <conio.c>

float leValidaSalario();
char leValidaSexo();
float calculaMedia(int qtdDoSexo, float valorDoSalario);
int main(void)
{
// Declaracoes
int qtdDeFuncionarios, contador,contador1, qtdHomens, qtdMulheres, qtdDoSexo;
float salarios[100], mediaDosSalariosMasculinos, mediaDosSalariosFemininos, somaMediaMasculina, somaMediaFeminina, valorDoSalarioTotal;
char sexos[100];
// Instrucoes
	somaMediaMasculina=0;
	somaMediaFeminina=0;
	mediaDosSalariosMasculinos=0;
	mediaDosSalariosFemininos=0;
	qtdHomens=0;
	qtdMulheres=0;
	printf("Informe a quantidade de funcionarios: \n");
	scanf("%d",& qtdDeFuncionarios);
	while(qtdDeFuncionarios<=0 || qtdDeFuncionarios>100){
		system("cls");
		printf("ERRO! Informe a quantidade de funcionarios: \n");
		scanf("%d",& qtdDeFuncionarios);
	}
	for(contador=0;contador<=qtdDeFuncionarios-1;contador++){
		salarios[contador]=leValidaSalario();
		sexos[contador]=leValidaSexo();
		if(sexos[contador]=='M'){
			qtdHomens++;
			somaMediaMasculina=salarios[contador]+somaMediaMasculina;
		}else{
			qtdMulheres++;
			somaMediaFeminina=salarios[contador]+somaMediaFeminina;
		}
	}
	qtdDoSexo=qtdMulheres;
	valorDoSalarioTotal=somaMediaFeminina;
	mediaDosSalariosFemininos=calculaMedia(qtdDoSexo,valorDoSalarioTotal);
	qtdDoSexo=qtdHomens;
	valorDoSalarioTotal=somaMediaMasculina;
	mediaDosSalariosMasculinos=calculaMedia(qtdDoSexo,valorDoSalarioTotal);
	system("cls");
	if(mediaDosSalariosMasculinos>0){
	printf("O salario medio Masculino : %.2f\n",mediaDosSalariosMasculinos);
	}else{
		printf("Nao existem homens\n");
	}
	if(mediaDosSalariosFemininos>0){
	printf("O salario medio Feminino: %.2f\n",mediaDosSalariosFemininos);
	}else{
		printf("Nao existem mulheres\n");
	}
  getch();
  return 0;
}
//Objetivo: ler e validar salario
//Parametro:
//Retorno: salario
float leValidaSalario(){
	float salario;
	system("cls");
	printf("Informe o seu salario: \n");
	scanf("%f",& salario);
	while(salario<=0){
		system("cls");
		printf("ERRO! Informe o seu salario: \n");
		scanf("%f",& salario);
	}
	return salario;
	
}
//Objetivo: ler e validar sexo
//Parametro:
//Retorno: sexo
char leValidaSexo(){
	char sexo;
	system("cls");
	printf("Informe o seu sexo: \n");
	sexo=getche();
	sexo=toupper(sexo);
	while(sexo!='M' && sexo!='F'){
		system("cls");
		printf("ERRO! Informe o seu sexo: \n");
		sexo=getche();
		sexo=toupper(sexo);
	}
	return sexo;
}
//Objetivo: calcular a média
//Parametro: qtd do sexo e valorDoSalarioTotal
//Retorno: media  masculina/feminina
float calculaMedia(int qtdDoSexo, float valorDoSalarioTotal){
	float media;
	media=valorDoSalarioTotal/qtdDoSexo;
	return media;
}





