// Exercicio do Victor Oliveira Kreniski - UC15200469

// Objetivo: Fazer um sistema usando FILA.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct tNodo{
	int chave;
	struct tNodo *prox;
};
struct tDescritor{
	int qtdNodos;
	struct tNodo *ini;
	struct tNodo *fimTopo;
};
void inicializa(struct tDescritor *desc);
void inclusao(struct tDescritor *tDesc);
void exclusao(struct tDescritor *tDesc);
void listagem(struct tDescritor tDesc);

int main(void)
{
// Declaracoes
int op;
struct tDescritor desc; // inicio = descritor da lista
// Instrucoes
	inicializa(&desc);
	do{
		op = menu();
		switch (op) {
			case 1: inclusao(&desc); break;
			case 2: exclusao(&desc); break;
			case 3: listagem(desc);
		}
	}while (op != 0);
	//FREE APOS ENCERRAMENTO DO PROGRAMA
	return 0;
	getch();
}
//Iniciliaza a lista
void inicializa(struct tDescritor *desc){
	desc->fimTopo = NULL;
	desc->ini = NULL;
	desc->qtdNodos = 0;
}
// Menu
int menu(void) {
  int op;
  do {
    printf("\n\n*** MENU ***\n\n");
    printf("1. Incluir\n");
    printf("2. Excluir\n");
    printf("3. Listar\n");
    printf("0. Sair\n\n");
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    if ((op < 0) || (op > 3))
      printf("Opcao invalida!\n\n"); // Faz a validacao
  } while ((op < 0) || (op > 3));
  return op;
}
// Inclusão
void inclusao(struct tDescritor *tDesc){
	struct tNodo *tNodoAux;
	tNodoAux = malloc(sizeof(struct tNodo));
	do{
		printf("Informe a chave: ");
	}while((scanf("%d",&tNodoAux->chave))!=1);
	if(tDesc->qtdNodos == 0){
		tDesc->ini = tNodoAux;
		tDesc->fimTopo = tNodoAux;
		tDesc->qtdNodos++;
		tNodoAux->prox = NULL;
	}else{
		tDesc->fimTopo->prox = tNodoAux;
		tDesc->fimTopo = tNodoAux;
		tNodoAux->prox = NULL;
	}
}
// Exclusao
void exclusao(struct tDescritor *tDesc){
	struct tNodo *p;
	p =  tDesc->ini;
	tDesc->ini = tDesc->ini->prox;
	tDesc->qtdNodos--;
	printf("\nChave: (%d)\n",p->chave);
	printf("\nSUCESSO\n");
	free(p);
}
//Listagem
void listagem(struct tDescritor tDesc){
	struct tNodo *p;
	if((p = tDesc.ini)!=NULL){
		do{
			printf("-(%d)-",p->chave);
			p = p->prox;
		}while(p!=NULL);
	}else{
		printf("\nImpossivel listar uma lista vazia, burro.\n");
	}
}
