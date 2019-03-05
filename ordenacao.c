#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include <string.h>

void mostrar(unsigned long long * a, unsigned long long n) {
    unsigned long i;
    for (i = 0; i < n; i++)
        printf("%4d ", a[i]);
    printf("\n");
    return;
}

void mostrar_resultados(RESULTADOS r) {
	FILE *out_file_comp = fopen("result_comp.txt", "a");
	FILE *out_file_troc = fopen("result_troc.txt", "a");
	if (out_file_comp == NULL || out_file_troc == NULL) {
		printf("Erro! Nao pode abrir arquivo\n");
		exit(-1);
	}
    printf("Resultado do algoritmo %s\n", r.nome);
    
    printf(" %llu comparacoes\n", r.comparacoes);
    fseek(out_file_comp, 0, SEEK_END);
    fprintf(out_file_comp, "%llu\n", r.comparacoes);
    
    printf(" %llu trocas\n", r.trocas);
    fseek(out_file_troc, 0, SEEK_END);
    fprintf(out_file_troc, "%llu\n", r.trocas);
    
    printf("\n");
    fclose(out_file_comp);
    fclose(out_file_troc);
    return;
}

void copiar(unsigned long long * a, unsigned long long * b, unsigned long long n) {
    unsigned long i;
    for (i = 0; i < n; i++)
        b[i] = a[i];
    return;
}


/* 
 * Algoritmo Bubble
 * Instrumentado
 */
void bubble(unsigned long long * a, unsigned long long n, RESULTADOS * r) {
    unsigned long long limite, i, j, t;
    r->comparacoes = 0;
    r->trocas = 0;
    strcpy(r->nome, "Bubble Normal");
    for (i = 0; i < n; i++) {
        limite = (n - 1) - i;
        for (j = 0; j < limite; j++) {
            r-> comparacoes = r-> comparacoes + 1;
            if (a[j] > a[j + 1]) {
                r-> trocas = r-> trocas + 1;
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    return;
}

/*
 * Algoritmo Bubble Otimizado
 * Instrumentado
 */
void bubble_otimizado(unsigned long long * a, unsigned long long n, RESULTADOS * r) {
    unsigned long long limite, i, j, t;
    unsigned long long troca = 1;
    r-> comparacoes = 0;
    r-> trocas = 0;
    strcpy(r->nome, "Bubble Otimizado");
    for (i = 0; i < n && troca; i++) {
        troca = 0;
        limite = (n - 1) - i;
        for (j = 0; j < limite; j++) {
            r-> comparacoes = r-> comparacoes + 1;
            if (a[j] > a[j + 1]) {
                r-> trocas = r-> trocas + 1;
                troca = 1;
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    return;
}

/*
 * Algoritmo de ordenacao por selecao
 * A instrumentar
 */
void select_sort(unsigned long long *a, unsigned long long n, RESULTADOS *r) {
     unsigned long long limite, i, idx, j, t;
     r->comparacoes = 0;
     r->trocas = 0;
     strcpy(r->nome, "Select Sort");
     limite = n - 1;
     i = 0;
     while (i < limite) {
           idx = i;
           for (j = i+1; j < n; j++) {
               r->comparacoes++;
               if (a[j] < a[idx]) {
                  idx = j;         
               }    
           }
           if (i != idx) {
              r->trocas++;
              t = a[i];
              a[i] = a[idx];
              a[idx] = t;
           }
           i++;
     }
     return;
}

/*
 * Algoritmo de ordenacao por insercao
 * A instrumentar
 */ 
void insert_sort(unsigned long long *a, unsigned long long n, RESULTADOS *r) {
     unsigned long long i, x, j;
     r->comparacoes = 0;
     r->trocas = 0;
     strcpy(r->nome, "Insert Sort");
     for (i = 1; i < n; i++) {
         x = a[i];
         for (j = i; (j > 0) && (x < a[j-1]); j--) {
         	r->comparacoes++;
         	r->trocas++;
         	a[j] = a[j-1];
		 }
         a[j] = x;
     }
     return;
} 

/* 
 * Funcao de chamada para algoritmo Quick Sort
 */
void quick_sort(unsigned long long *a, unsigned long long n, RESULTADOS *r) {
	r->comparacoes = 0;
	r->trocas = 0;
	strcpy(r->nome, "Quick Sort");
     __quick_sort(&*a, 0, n-1, r);
     return;    
}

/*
 * Algoritmo Quick Sort
 * A instrumentar
 */
void __quick_sort(unsigned long long *a, unsigned long long int Esq, unsigned long long int Dir, RESULTADOS *r) {
      unsigned long long x, i, j, t;
     
     x = a[Esq + (Dir - Esq)/2];
     
     i = Esq;
     j = Dir;
     do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        r->comparacoes++;
        if (i <= j) {
        	r->trocas++;
           	t = a[i];
           	a[i] = a[j];
           	a[j] = t;
           	i++; j--;
        }
     } while(i <= j);
     
     if (j > Esq) __quick_sort(a, Esq, j, r);
     if (i < Dir) __quick_sort(a, i, Dir, r);
}

/*void __quick_sort(unsigned long long *a, unsigned long long Esq, unsigned long long Dir, RESULTADOS *r) {
    unsigned long long i, j, x, t;
     
    i = Esq;
    j = Dir;
    x = a[(Esq + (Dir - Esq)) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < Dir) {
            i++;
        }
        while(a[j] > x && j > Esq) {
            j--;
        }
        r->comparacoes++;
        if(i <= j) {
        	r->trocas++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
     
    if(j > Esq) {
        __quick_sort(a, Esq, j, r);
    }
    if(i < Dir) {
        __quick_sort(a, i, Dir, r);
    }
}*/
