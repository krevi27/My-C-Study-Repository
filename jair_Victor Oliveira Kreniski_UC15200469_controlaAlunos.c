// Aluno : Victor Oliveira Kreniski

/*
 Sintese
   Objetivo: auxiliar uma turma
 		
   Entrada : quantidade de alunos, nota e sexo;

   Saida   :  quantidade de alunos e alunas aprovados e reprovados e a média dos alunos e das alunas

*/

#include <stdio.h>
#include <conio.c>
int leValidaInt();
float leValidaFloat();
char leValidaSexo();
void apresentaResultados(int qtdDeAlunos,float notasDosAlunos[],char sexos[]);
int main(void)
{
// Declaracoes
	int contador, qtdDeAlunos;
	float notasDosAlunos[35];
	char sexos[35];
// Instrucoes
	qtdDeAlunos=leValidaInt();
	for(contador=0;contador<=qtdDeAlunos-1;contador++){
		system("cls");
		notasDosAlunos[contador]=leValidaFloat();
		sexos[contador]=leValidaSexo();
	}
	apresentaResultados(qtdDeAlunos,notasDosAlunos,sexos);
  getch();
  return 0;
}
//Objetivo: ler quantidade de alunos;
//Parametro: nenhum
//Retorno: quantidade de Alunos.
int leValidaInt(){
int quantidadeDeAlunos;
	printf("Informe a quantidade de alunos: (1 a 35)\n");
	scanf("%d",&quantidadeDeAlunos);
	while(quantidadeDeAlunos<=0 || quantidadeDeAlunos>35){
			system("cls");
			printf("ERRO! Informe a quantidade de alunos: (1 a 35)\n");
			scanf("%d",&quantidadeDeAlunos);
	}	
	return quantidadeDeAlunos;
}
//Objetivo: ler e validar notas
//Parametro: nenhum
//Retorno: nota do aluno
float leValidaFloat(){
	float notaDoAluno;
	printf("Informe a sua nota:\n");
	scanf("%f",& notaDoAluno);
	while(notaDoAluno<0 || notaDoAluno>10){
			system("cls");
			printf("ERRO! Informe a sua nota:\n");
			scanf("%f",& notaDoAluno);
	}
	return notaDoAluno;
}
//Objetivo: ler e validar sexo
//Parametro: nenhum
//Retorno: sexo do aluno
char leValidaSexo(){
	char sexo;
	printf("informe o seu sexo: \n");
	sexo=getche();
	sexo=toupper(sexo);
	while(sexo!='M' && sexo!='F'){
		system("cls");
		printf("informe o seu sexo: \n");
		sexo=getche();
		sexo=toupper(sexo);
	}
	return sexo;
}
//Objetivo: apresentar dados
//Paraemtro: qtd de alunos, notas de alunos e sexo
//Retorno: nenhum
void apresentaResultados(int qtdDeAlunos,float notasDosAlunos[],char sexos[]){
	int contador, qtdFemininoAprovado, qtdFemininoReprovado, qtdMasculinoAprovado, qtdMasculinoReprovado;
	float mediaMasculina, mediaFeminina;
	mediaMasculina=0;
	mediaFeminina=0;
	qtdFemininoAprovado=0;
	qtdMasculinoAprovado=0;
	qtdFemininoReprovado=0;
	qtdMasculinoReprovado=0;
	for(contador=0;contador<=qtdDeAlunos-1;contador++){
		if(sexos[contador]=='M'&&notasDosAlunos[contador]>=7 ){
			mediaMasculina=notasDosAlunos[contador]+mediaMasculina;
			qtdMasculinoAprovado++;
		}
		if(sexos[contador]=='M'&&notasDosAlunos[contador]<7){
				mediaMasculina=notasDosAlunos[contador]+mediaMasculina;
				qtdMasculinoReprovado++;
		}
		if(sexos[contador]=='F'&&notasDosAlunos[contador]>=7 ){
			mediaFeminina=notasDosAlunos[contador]+mediaFeminina;
			qtdFemininoAprovado++;
		}
		if(sexos[contador]=='F'&&notasDosAlunos[contador]<7){
			mediaFeminina=notasDosAlunos[contador]+mediaFeminina;
			qtdFemininoReprovado++;
		}
	}
	mediaMasculina=mediaMasculina/(qtdMasculinoReprovado+qtdMasculinoAprovado);
	mediaFeminina=mediaFeminina/(qtdFemininoAprovado+qtdFemininoReprovado);
	system("cls");
	printf("Aprovados:  \n");
	printf("Alunos: %d Alunas: %d\n", qtdMasculinoAprovado, qtdFemininoAprovado);
	printf("Reprovados: \n");
	printf("Alunos: %d Alunas: %d\n",qtdMasculinoReprovado,qtdFemininoReprovado);
	if(qtdMasculinoReprovado+qtdMasculinoAprovado==0){
		printf("Não tem homens para fazer media \n");
	}else{
		printf("Média Masculina %.2f\n",mediaMasculina);
	}
	if(qtdFemininoAprovado+qtdFemininoReprovado==0){
		printf("Não tem mulheres para fazer media \n");
	}else{
		printf("Média feminina %.2f\n",mediaFeminina);
	}
}

