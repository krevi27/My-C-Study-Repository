/*
Projeto - Memória Virtual
--
Escreva um programa em C que implemente os algoritmos de substituição de páginas FIFO e LRU.
Primeiro gere uma sequência aleatória de referências de páginas em que os números de página variam de
0 a 9. Aplique a sequência a cada algoritmo e registre a quantidade de page fault em cada algoritmo.
Implemente os algoritmos de substituição de modo que a quantidade de frames possa variar de 1 a 7.
Presuma o uso de paginação sob demanda.
*/
#include<stdio.h>

// Projeto feito por Victor Oliveira Kreniski - UC15200469
int n,pg[30],fr[10];
void fifo();
void optimal();
void lru();

void main(){
	int i,opcao;
	printf("Informe a quantidade total de paginas: ");
	scanf("%d",&n);
	printf("\nRegra Numero 1º - Informe uma cadeia de numeros inteiros que totalizem %d valores\n",n);
	printf("Regra Numero 2º - Exemplo da maneira para informar:0 5 7 8 9 7 5 2 3 4 6 e depois aperte Enter\n");
	printf("\nEscreva a sequencia de numeros:");
	for(i=0;i<n;i++){
		scanf("%d",&pg[i]);
	}
	do{
		printf("\n\tmenu\n");
		printf("\n1)Metodo FIFO ( First in, First Out )");
		printf("\n2)Metodo LFU ( Least Frequently Used )");
		printf("\n3)Encerrar\n");
		printf("\nOpcao: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1: fifo();
				break;
			case 2: lru();
				break;
		}
	}while(opcao!=3);
	getchar();
}

void fifo(){
	int i,f,r,s,count,flag,num,psize;
	f=0;
	r=0;
	s=0;
	flag=0;
	count=0;
	printf("\nTamanho do page frame:");
	scanf("%d",&psize);
	for(i=0;i<psize;i++){
		fr[i]=-1;
	}
	while(s<n){
		flag=0;
		num=pg[s];
		for(i=0;i<psize;i++){
			if(num==fr[i]){
				s++;
				flag=1;
				break;
			}
		}
		if(flag==0){
			if(r<psize){	
				fr[r]=pg[s];
				r++;
				s++;
				count++;
			}else{
				if(f<psize){
					fr[f]=pg[s];
					s++;
					f++;
					count++;
				}else 
					f=0;
			}
		}
		printf("\n");			
		for(i=0;i<psize;i++){
			printf("%d\t",fr[i]);
		}
	}
	printf("\nPage Faults=%d",count);
	getchar();
}
void lru(){
	int count[10],i,j,k,fault,f,flag,temp,current,c,dist,max,m,cnt,p,x;
	fault=0;
	dist=0;
	k=0;
	printf("\nTamanho do frame:");
	scanf("%d",&f);	
	for(i=0;i<f;i++){
		count[i]=0;
		fr[i]=-1;
	}
	for(i=0;i<n;i++){
		flag=0;
		temp=pg[i];
		for(j=0;j<f;j++){
			if(temp==fr[j]){
				flag=1;
				break;
			}
		}
		if((flag==0)&&(k<f)){
			fault++;
			fr[k]=temp;
			k++;
		}else if((flag==0)&&(k==f)){
			fault++;			
			for(cnt=0;cnt<f;cnt++){		
				current=fr[cnt];
				for(c=i;c>0;c--){
					if(current!=pg[c])
						count[cnt]++;
					else
						break;
				}
			}
			max=0;
			for(m=0;m<f;m++){
				if(count[m]>max){
					max=count[m];
					p=m;
				}
			}
			fr[p]=temp;
		}
		printf("\n");			
		for(x=0;x<f;x++){
			printf("%d\t",fr[x]);
		}
	}
	printf("\nTotal de page faults = (%d)" ,fault);
	getchar();
}
