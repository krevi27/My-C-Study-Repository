#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Sintese
//   objetivo "Lista circular duplamente encadeada nao descrescente"

// Tipo para Dados
typedef struct tDado {
  float peso; // chave
  int numero;
} tDado;

// Tipo para Nodo
typedef struct tNodo {
  struct tDado dado;
  struct tNodo *ant;	
  struct tNodo *prox;	
} tNodo;

// Tipo para Descritor
typedef struct tDescritor {
  struct tNodo *ini;	
  int qtd;
  float pesos;
} tDescritor;

// Prototipo de funcoes
int menu(void);
struct tNodo* buscaNodo(struct tDescritor desc);
void inicializar(struct tDescritor*);
void destruir(struct tDescritor);
void incluir(struct tDescritor*, struct tNodo*);
void listar(struct tDescritor);
void consultar(struct tDescritor desc);
void alterar(struct tDescritor desc);
void exclusao(struct tDescritor *desc);
int main(void) {
  struct tDescritor descritor;
  struct tNodo *novo;
  int op;
  
  inicializar(&descritor);
  do {
    op = menu();
    switch (op) {
      case 1:
        printf("\n\n* Incluir *\n\n");
      	novo = (struct tNodo*) malloc(sizeof(struct tNodo));
      	printf("Digite o peso.: ");
		scanf("%f", &(novo->dado.peso));
      	printf("Digite o valor: ");
		scanf("%d", &(novo->dado.numero));
		incluir(&descritor, novo);
   	    break;
      case 2: 
        printf("\n\n* Listar *\n\n");
        listar(descritor);
        break;
    	case 3:
    		exclusao(&descritor);
    		break;
    	case 4:
    		consultar(descritor);
    		break;
    	case 5:
    		alterar(descritor);
    		break;
	}
  } while (op != 0);
  destruir(descritor);
  return 0;
}

int menu(void) {
  int op;
  printf("\n\n*** Menu ***\n\n");
  printf("1. Incluir\n");
  printf("2. Listar\n");
  printf("3. Excluir\n");
  printf("4. Consultar\n");
  printf("5. Alterar\n");
  printf("0. Sair\n\n");
  printf("Digite sua opcao: ");
  scanf("%d", &op);
  return op;
}
//Busca o endereco de um nodo com a chave informada
struct tNodo* buscaNodo(struct tDescritor desc){
	float peso;
	int i;
	struct tNodo *n;
	n = desc.ini;
	printf("\nInforme o peso a ser consultado: ");
	scanf("%f",&peso);
	for (i=0; i<desc.qtd; i++) {
		if(n->dado.peso == peso){
			return n;
		}else{
			n = n->prox;
		}
	}
	return NULL;
}
//Inicializa o descritor
void inicializar(struct tDescritor *desc) {
  (*desc).pesos = 0; // desc->pesos = 0;
  (*desc).qtd = 0;
  (*desc).ini = NULL;
}
//Efetua a destruição de uma lista
void destruir(struct tDescritor desc) {
  struct tNodo *p;
  int i;
  for (i=0; i<desc.qtd; i++) {
    p = desc.ini;
    desc.ini = desc.ini->prox;
    free(p);
  }
}
//Efetua uma inclusão de um novo Nodo
void incluir(struct tDescritor *desc, struct tNodo *n) {
  struct tNodo *p = (*desc).ini;
  
  if ((*desc).ini == NULL) { // Lista vazia
    n->ant = n;
    n->prox = n;
    (*desc).ini = n;
  }
  else {
  	do {
  	  p = p->prox;
    } while ((p->dado.peso < n->dado.peso) && (p != (*desc).ini));
  	n->ant = p->ant;
  	n->prox = p;
  	p->ant->prox = n;
  	p->ant = n;

  	if (n->dado.peso < (*desc).ini->dado.peso) // Atualizar o ponteiro ini
  	  (*desc).ini = n;
  }
  (*desc).qtd++;
  (*desc).pesos += n->dado.peso;
}
//Efetua uma listagem 
void listar(struct tDescritor desc) {
  struct tNodo *p = desc.ini;
  int i;
  printf("\n---------------------------------\n");
  printf("Peso total: %7.3f kg\n",desc.pesos);
  printf("Quantidade de gordos: %d\n",desc.qtd);
  printf("---------------------------------\n");
  printf("Peso      Num\n");
  printf("=======   =====\n");
  for (i=0; i<desc.qtd; i++) {
    printf("%7.3f - %5d\n", p->dado.peso, p->dado.numero);
    p = p->prox;
  }
}
//Efetua uma consulta de todos os pesos equivalentes ao informado
void consultar(struct tDescritor desc){
	int flag=0;
	struct tNodo *n;
	n = buscaNodo(desc);
	if(n!=NULL){
		printf("Peso: %7.3f - Numero: %5d\n", n->dado.peso, n->dado.numero);
		flag=1;
	};
	if(flag==0){
		printf("\nNao foi possivel encontrar nada\n");
	}
}
//Efetua a alteracao de um nodo existente na lista
void alterar(struct tDescritor desc){
	struct tNodo *n;
	if((n = buscaNodo(desc))!=NULL){
		printf("\nInforme o novo numero: ");
		scanf("%d",&(n->dado.numero));
	}else{
		printf("Peso informado nao existe na lista\n");
	}
	
}
//Efetua uma exclusão de um nodo existente da lista
void exclusao(struct tDescritor *desc){
	struct tNodo *n;
	if((n = buscaNodo(*desc))!=NULL){
		n->ant->prox = n->prox;
		n->prox->ant = n->ant;
		desc->pesos -=  n->dado.peso;
		desc->qtd -= 1;
		free(n);
		n = NULL;
		printf("\n Exclusao com sucesso\n");
	}else{
		printf("\nNao foi encontrado nada\n");
	}
}
