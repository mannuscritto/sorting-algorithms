#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

//#define TAM 1000
unsigned long TAM;

int main(int argc, char *argv[]) {
	int i, j, opt, qtd, ord;
	RESULTADOS result;

	srand (time(NULL));

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &TAM);
	if (!TAM) exit(1);
	
	unsigned long arquivo_original[TAM];
	unsigned long arquivo_para_ordenar[TAM];
	
	printf("\t\tMenu\n\n");
	printf("\tAleatorio          [1]\n");
	printf("\tOrdenado           [2]\n");
	printf("\tOrdenado Invertido [3]\n");
	do {
		printf("Escolha a ordenacao: ");
		scanf("%d", &ord);
	} while (ord < 0);
	switch (ord) {
		case 2:
			for (i = 1; i <= TAM; i++) {
				arquivo_original[i] = i;
			}
			break;
		case 3:
			for (i = 0; i < TAM; i++) {
				arquivo_original[i] = TAM - i;
			}
			break;
		default:
			ord = 1;
	}
	

	while (1) {
		system("cls");
		//system("clear");
		printf("\t\tMENU\n\n");
		printf("\tBubble           [1]\n");
		printf("\tBubble Otimizado [2]\n");
		printf("\tSelect Sort      [3]\n");
		printf("\tInsert Sort      [4]\n");
		printf("\tQuick Sort       [5]\n");
		printf("\tSair             [0]\n");
		do {
			printf("Escolha o algoritmo: ");
			scanf("%d", &opt);
		} while(opt < 0);
		do {
			printf("Escolha a quantidade: ");
			scanf("%d", &qtd);
		} while (qtd < 0);
		for (j = 0; j < qtd; j++) {
			if (ord == 1) {
				for (i = 0; i < TAM; i++) {
					arquivo_original[i] = rand() % 1000;
				}
			}
			copiar(arquivo_original, arquivo_para_ordenar, TAM);
			switch (opt) {
				case 1:
					bubble(arquivo_para_ordenar, TAM, &result);
					mostrar_resultados(result);
					break;
				case 2:
					bubble_otimizado(arquivo_para_ordenar, TAM, &result);
					mostrar_resultados(result);
					break;
				case 3:
	                 select_sort(arquivo_para_ordenar, TAM, &result);
	                 mostrar_resultados(result);
	                 break;
	            case 4:
	                 insert_sort(arquivo_para_ordenar, TAM, &result);
	                 mostrar_resultados(result);
	                 break;
	            case 5:
	                 quick_sort(arquivo_para_ordenar, TAM, &result);
	                 mostrar_resultados(result);
	                 break;
				case 0:
					exit(0);
					break;
				default:
					printf("Opcao Invalida\n");
			}
		}
		system("PAUSE");	
		//system("read line");
	}
	return 0;
}
