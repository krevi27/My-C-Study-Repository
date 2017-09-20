// Aluno : Augusto Henrique de Almeida Silva

#include <stdio.h>
#include <stdlib.h>
// Sintese
//   objetivo "Arvore Binaria de Busca"

// Tipo para Nodo
typedef struct tNodo {
  struct tNodo *esq;	
  int valor;
  struct tNodo *dir;	
} tNodo;

// Prototipo de funcoes
int menu(void);
void incluir(struct tNodo**, struct tNodo*);
struct tNodo* pesquisar(struct tNodo*, int v);
void destruir(struct tNodo*);
void caminharEm(struct tNodo*);
void caminharPre(struct tNodo*);
void caminharPos(struct tNodo*);
int altura(struct tNodo*, struct tNodo*);

struct tNodo* nodoDaTroca(struct tNodo **raiz);
struct tNodo* exclui(struct tNodo **raiz, struct tNodo *no);
void Desenha(struct tNodo *raiz);

int main(void) {
  struct tNodo *raiz = NULL, *novo = NULL;
  int op, valor;
  
  // Criar uma arvore de teste  
  novo = (struct tNodo*) malloc(sizeof(struct tNodo));
  novo->valor = 50;
  incluir(&raiz, novo);
  novo = (struct tNodo*) malloc(sizeof(struct tNodo));
  novo->valor = 20;
  incluir(&raiz, novo);
  novo = (struct tNodo*) malloc(sizeof(struct tNodo));
  novo->valor = 75;
  incluir(&raiz, novo);
  novo = (struct tNodo*) malloc(sizeof(struct tNodo));
  novo->valor = 10;
  incluir(&raiz, novo);
  novo = (struct tNodo*) malloc(sizeof(struct tNodo));
  novo->valor = 30;
  incluir(&raiz, novo);
  
  do {
    op = menu();
    switch (op) {
      case 1:
        printf("\n\n* Incluir *\n\n");
      	novo = (struct tNodo*) malloc(sizeof(struct tNodo));
      	printf("Digite o valor: ");
		scanf("%d", &(novo->valor));
		incluir(&raiz, novo);
   	    break;
      case 2: 
        printf("\n\n* Pesquisar *\n\n");
      	printf("Digite o valor: ");
		scanf("%d", &valor);
		if (pesquisar(raiz, valor) == NULL)
      	  printf("Nao achei!");
      	else
      	  printf("Achei!");
   	    break;
      case 3: 
        printf("\n\n* Caminhamento - Em *\n\n");
		caminharEm(raiz);
   	    break;
      case 4: 
        printf("\n\n* Caminhamento - Pre *\n\n");
		caminharPre(raiz);
   	    break;
      case 5: 
        printf("\n\n* Caminhamento - Pos *\n\n");
		caminharPos(raiz);
   	    break;
      case 6: 
        printf("\n\n* Altura *\n\n");
      	printf("Digite o valor: ");
		scanf("%d", &valor);
		novo = pesquisar(raiz, valor);
		if (!novo)
      	  printf("Nao achei!");
      	else
      	  printf("Altura = %d", altura(raiz, novo));
   	    break;
   	  case 7:
   	    printf("\n\n* Excluir *\n\n");
      	printf("Digite o valor: ");
		scanf("%d", &valor);
		novo = pesquisar(raiz, valor);
		if (!novo)
      	  printf("Nao achei!");
      	else
      	  exclui(&raiz, novo);
   	    break;
   	  case 8:
   	  	
   	  	break;
	}
  } while (op != 0);
  destruir(raiz);
	
  return 0;
}

int menu(void) {
  int op;
  printf("\n\n*** Menu ***\n\n");
  printf("1. Incluir\n");
  printf("2. Pesquisar\n");
  printf("3. Caminhamento - em\n");
  printf("4. Caminhamento - pre\n");
  printf("5. Caminhamento - pos\n");
  printf("6. Altura\n");
  printf("7. Excluir\n");
  printf("8. Desenha Arvore\n");
  printf("0. Sair\n\n");
  printf("Digite sua opcao: ");
  scanf("%d", &op);
  return op;
}

void destruir(struct tNodo *raiz) {
	// se virem!!!
}

void incluir(struct tNodo **raiz, struct tNodo *n) {
	n->esq = n->dir = NULL;
	if ((*raiz) == NULL)
	  (*raiz) = n;
	else
	  if (n->valor < (*raiz)->valor)
	    incluir(&((*raiz)->esq), n);
	  else
	    incluir(&((*raiz)->dir), n);
}

struct tNodo* pesquisar(struct tNodo *raiz, int v) {
	if ((raiz == NULL) || (raiz->valor == v))
    	return raiz;
    if (v < raiz->valor)
      	return pesquisar(raiz->esq, v);
    return pesquisar(raiz->dir, v);
}

void caminharEm(struct tNodo *raiz) {
	if (raiz == NULL)
		return;
	caminharEm(raiz->esq);
	printf("%d, ", raiz->valor);
	caminharEm(raiz->dir);
}

void caminharPre(struct tNodo *raiz) {
	if (raiz == NULL)
		return;
	printf("%d, ", raiz->valor);
	caminharPre(raiz->esq);
	caminharPre(raiz->dir);
}

void caminharPos(struct tNodo *raiz) {
	if (raiz == NULL)
		return;
	caminharPos(raiz->esq);
	caminharPos(raiz->dir);
	printf("%d, ", raiz->valor);
}

int altura(struct tNodo *raiz, struct tNodo *no) {
	int maior, ad;
	if (raiz == NULL)
		return -1;
	if (raiz == no)
		return 0;
	maior = altura(raiz->esq, no);
	ad = altura(raiz->dir, no);
	if ((maior == -1) && (ad == -1))
		return -1;
	if (ad > maior)
	  maior = ad;
  	return maior+1;
}

struct tNodo* exclui(struct tNodo **raiz, struct tNodo *no){
	struct tNodo *p;
	
	// encontrar quem vai ser excluido
	if(no->valor < (*raiz)->valor){
		(*raiz)->esq = exclui(&((*raiz)->esq), no);
		return (*raiz);
	}else{
		if(no->valor > (*raiz)->valor){
			(*raiz)->dir = exclui(&((*raiz)->dir), no);
			return (*raiz);
		}else{
			if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
				free((*raiz));
				return NULL;
			}else{
				if((*raiz)->esq != NULL && (*raiz)->dir == NULL){
					p = (*raiz)->esq;
					free((*raiz));
					return p;
				}else{
					if((*raiz)->esq == NULL && (*raiz)->dir != NULL){
						p = (*raiz)->dir;
						free((*raiz));
						return p;
					}else{
						p = (*raiz);
						(*raiz) = nodoDaTroca(&((*raiz)->esq));
						(*raiz)->esq = p->esq;
						(*raiz)->dir = p->dir;
						free(p);
					}
				}
			}
		}
	}
	
}

struct tNodo* nodoDaTroca(struct tNodo **raiz){
	struct tNodo *p;
	if((*raiz)->dir != NULL){
		p = nodoDaTroca(&((*raiz)->dir));
		if(p == NULL){
			p = (*raiz)->dir;
			(*raiz)->dir = NULL;
		}
		return p;
	}
	return NULL;
}

void Desenha(struct tNodo *raiz) {
	if (raiz == NULL)
		return;
	caminharEm(raiz->esq);
	printf("%d, ", raiz->valor);
	caminharEm(raiz->dir);
}
