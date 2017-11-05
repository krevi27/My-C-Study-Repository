/* 3 - Classificação multithread
Escreva um programa de classificação com múltiplos threads que funciona da seguinte forma: Uma lista de
inteiros é dividida em duas listas menores de tamanho igual. Duas threads separadas (que chamaremos de
threads classificadoras) classificam cada sublista usando um algoritmo de classificação de sua escolha. As
duas sublistas são, então, mescladas por uma terceira thread - uma thread de mesclagem - que as
combina em uma única lista classificada.
Já que dados globais sao compartilhados por todos as threads, talvez a maneira mais fácil de configurar os
dados seja criar um array global. Cada thread classificador trabalhará em uma metade desse array. Um
segundo array global com o mesmo tamanho do array de inteiros desclassificados, também será definido.
A thread de mesclagem combinará as duas sublistas nesse segundo array. Graficamente, esse programa
tem a estrutura mostrada na figura abaixo.
Esse projeto de programação demandará a passagem de
parâmetros para cada uma das threads classificadoras.
Especificamente será necessário identificar o índice inicial
a partir do qual cada thread deve começar a classificar.
A thread-pai exibirá o array classificado, uma vez que todas
as threads classificadoras tenham terminado. */
// Projeto Criado pelo Victor Oliveira Kreniski - Sistemas Operacionais - Opcao 3 do
projeto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
struct Parameters
{
	int *start;
	size_t len;
	int depth;
};
// Criado para sincronizar stdout de overlap
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
// Declara a thread
void *junta_sort_thread(void *pv);
void junta(int *start, int *mid, int *end)
{
	int *res = malloc((end - start) * sizeof(*res));
	int *lhs = start, *rhs = mid, *dst = res;
	while (lhs  = mid && rhs  = end)
		*dst++ = (*lhs < *rhs) ? *lhs++ : *rhs++;
	while (lhs  = mid)
		*dst++ = *lhs++;
	// faz a copia dos resultados
	memcpy(start, res, (rhs - start) * sizeof *res);
	free(res);
}
// Inicio da multi-thread
void junta_sort_mt(int *start, size_t len, int depth)
{
	if (len < 2)
		return;
	if (depth <= 0 || len < 4)
	{
		junta_sort_mt(start, len / 2, 0);

		junta_sort_mt(start + len / 2, len - len / 2, 0);
	}
	else
	{
		struct Parameters parameters = { start, len / 2, depth / 2 };
		pthread_t thrd;
		pthread_mutex_lock(&mtx);
		printf("Comecando subthread...\n");
		pthread_mutex_unlock(&mtx);
		//Criando a thread
		pthread_create(&thrd, NULL, junta_sort_thread, &parameters);
		// Recursividade
		junta_sort_mt(start + len / 2, len - len / 2, depth / 2);
		// Entra na Thread criada
		pthread_join(thrd, NULL);
		pthread_mutex_lock(&mtx);
		printf("Acabou subthread.\n");
		pthread_mutex_unlock(&mtx);
	}
	// merge the partitions.
	junta(start, start + len / 2, start + len);
}
// thread_proc chama merge_sort. Aqui vai ser passado os parametros para a merge_sort
void *junta_sort_thread(void *pv)
{
	struct Parameters *parameters = pv;
	junta_sort_mt(parameters->start, parameters->len, parameters->depth);
	return pv;
}
void junta_sort(int *start, size_t len)
{
	junta_sort_mt(start, len, 4); // 4 é um numero interessante pq vai usar 7 threads
}
// ------------------------- core
---------------------------------------------- -
int main()
{
	static const unsigned int N = 30; // Quantidade de inteiros criados
	int *data = malloc(N * sizeof(*data));
	unsigned int i;

	srand((unsigned)time(0));
	for (i = 0; i<N; ++i)
	{
		data[i] = rand() % 30; // Valor maximo que pode ser gerado
		printf("%4d ", data[i]);
		if ((i + 1) % 8 == 0)
			printf("\n");
	}
	printf("\n");
	// Chama a multi_threaded merge sort para fazer a ordenação
	junta_sort(data, N);
	for (i = 0; i<N; ++i)
	{
		printf("%4d ", data[i]);
		if ((i + 1) % 8 == 0)
			printf("\n");
	}
	printf("\n");
	free(data); // Libera memoria
	return 0;
}