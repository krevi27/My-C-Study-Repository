// Aluno : Victor Oliveira Krenisii

/*
 Sintese
   Objetivo: implementar uma tabela HASH
 
   Entrada : 

   Saida   :  

*/

#include <stdio.h>
#include <conio.c>
typedef struct Aluno{
	char nome[100];
}Aluno;
typedef struct Hash{
	int qtd,tamanho,colisao,qtdColisoes;
	Aluno itens[44];
	Aluno colisoes[11];
}Hash;
FILE *abreArq(char *nomeDoArquivo,char *modoAbertura);
int chaveDivisao(char *chave,int tamanho);
int main(void)
{
// Declaracoes
Aluno alunos[22];
FILE *pointerToFile;
int contador=0,i;
// Instrucoes
	pointerToFile = abreArq("alunos2016.txt","rt");
	if(pointerToFile!=NULL){
		Hash hash;
		hash.tamanho=43;
		hash.colisao=10;
		hash.qtd=0;
		hash.qtdColisoes=0;
		for(i=0;i<hash.tamanho;i++){
			hash.itens[i].nome[0]="";
		}
		for(i=0;i<hash.qtdColisoes;i++){
			hash.colisoes[i].nome[0]="";
		}
		printf("Arquivo aberto com sucesso. Leitura iniciada\n");
		while(!feof(pointerToFile)){
			fgets((alunos+contador)->nome,100,pointerToFile);
			if((alunos+contador)->nome[strlen((alunos+contador)->nome)-1]=='\n'){
				(alunos+contador)->nome[strlen((alunos+contador)->nome)-1]='\0';
			}
			contador++;
		}
		fclose(pointerToFile);
		printf("Leitura completa  - Nomes lidos: %d\n",contador);
		for(i=0;i<contador;i++){
			if(strlen(hash.itens[chaveDivisao((alunos[i].nome),hash.tamanho)].nome)==0){
				printf("e vazio\n");
				hash.qtd++;
				hash.itens[chaveDivisao((alunos[i].nome),hash.tamanho)] = alunos[i];
			}else{
				printf("Colisao\n");
				hash.qtdColisoes++;
				hash.colisoes[hash.qtdColisoes] = alunos[i];
			}
		}
		printf("%d Repeticoes\n",i);
		printf("\n\nHash - qtd: %d\n",hash.qtd);
		for(i=0;i<hash.tamanho;i++){
			if(strlen(hash.itens[i].nome)>1){
				printf("%s - Conteudo do Hash na posição %d\n",hash.itens[i].nome,i+1);	
			}
		}
		printf("\n\nColisoes - qtd: %d\n",hash.qtdColisoes);
		for(i=0;i<hash.colisao;i++){
			if(strlen(hash.colisoes[i].nome)>1){
				printf("%s - Conteudo do Hash na posição %d\n",hash.colisoes[i].nome,i+1);
			}
		}
	}else{
		printf("Não foi possivel efetuar a leitura do arquivo\n");
	}
  getch();
  return 0;
}
//Objetivo: abrir um arquivo
//Parametro: referencia nome do arquivo, referencia a modo de abertura, referencia a msg
//Retorno: ponteiro do arq
FILE *abreArq(char *nomeDoArquivo,char *modoDeAbertura){
	FILE *arq=NULL;
	if((arq=fopen(nomeDoArquivo,modoDeAbertura))==NULL){
		printf("O Arquivo %s deu erro ao ser aberto\n",nomeDoArquivo);
	}
	return arq;
}
int chaveDivisao(char *chave,int tamanho){
    int hash = 0;
    int i;
    for (i = 0 ; chave[i] != '\0' ; i++)
    {
        hash = hash + chave[i];
    }
    return hash % tamanho;
}

