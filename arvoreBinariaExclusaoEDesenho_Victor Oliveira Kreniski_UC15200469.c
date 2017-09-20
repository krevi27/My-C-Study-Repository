#include <stdio.h>
#include <stdlib.h>
// Made in China - All copyRights reserved - Victor ( kkk )
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
int remocaoArvBin(struct tNodo *raiz,int valor);
struct tNodo* removeNodo(struct tNodo *currentNodo);
void imprime(tNodo *p, int nivel);

int main(void) {
  struct tNodo *raiz=NULL, *novo;
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
   	    	if((remocaoArvBin(raiz,valor))==0){
   	    		printf("Erro ao excluir - nodo não encontrado\n");
			   }else{
			   	printf("Nodo excluido com sucesso\n");
			   }
   	    	break;
   	    case 8:
   	    	imprime(raiz,0);
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
  printf("8. Arvore\n");
  printf("0. Sair\n\n");
  printf("Digite sua opcao: ");
  scanf("%d", &op);
  return op;
}
void imprime(tNodo *p, int nivel){
     int i;
     if(p == NULL)
        return;
     imprime(p->dir, nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%6d\n\n",p->valor);
     imprime(p->esq,nivel+1);
}
// Auxilia nos três tipos de exclusões
int remocaoArvBin(struct tNodo *raiz,int valor){
	if( raiz == NULL ){
		return 0;
	}else{
		struct tNodo *ant = NULL;
		struct tNodo *atual = NULL;
		atual = raiz;
		while(atual != NULL){
			if(valor == atual->valor){ // Nesse if eu vou tratar o lado da remoção
				if(atual == raiz){
					raiz = removeNodo(atual); // Caso o valor a ser removido seja a raiz
				}else{ // Se não for a raiz, é a direita ou esquerda.
					if(ant->dir == atual){
						ant->dir = removeNodo(atual); 
					}else{
						ant->esq = removeNodo(atual);
					}		
				}
				return 1;
			}
			ant = atual; // Continuo andando na arvore a procura do Nó a ser removido.
			if( valor > atual->valor){
				atual = atual->dir;
			}else{
				atual = atual->esq;
			}
		}
	}
	
}
struct tNodo* removeNodo(struct tNodo *currentNodo){
	struct tNodo *no1,*no2;
	if(currentNodo->esq == NULL){ // Sem filho da esquerda. Aponta para o filho da direita.
		no2 = currentNodo->dir;		// Trata tanto o nó folha como o nó com 1 filho só.
		free(currentNodo);
		return no2;
	}
	no1 = currentNodo; // Procura filho mais a direita na sub-arvore da esquqerda
	no2 = currentNodo->esq;
	while(no2->dir != NULL){
		no1 = no2;
		no2 = no2->dir;
	}
	if(no1 != currentNodo){	// Copia o filho mais a direita na sub-arvore esquerda para o lugar do nó removido
		no1->dir = no2->esq;
		no2->esq = currentNodo->esq;
	}
	no2->dir = currentNodo->dir;
	free(currentNodo);
	return no2;	
}

void destruir(struct tNodo *raiz) {
	if(raiz == NULL){
		return;
	}else{
		destruir(raiz->dir);
		destruir(raiz->esq);
		free(raiz);
		raiz = NULL;
	}
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
