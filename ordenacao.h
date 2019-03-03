typedef struct __result {
    unsigned long comparacoes;
    unsigned long trocas;
    char nome[30];
} RESULTADOS;

void copiar(unsigned long * , unsigned long * , unsigned long);
void mostrar(unsigned long * , unsigned long);
void mostrar_resultados(RESULTADOS);

void bubble(unsigned long * , unsigned long, RESULTADOS * );
void bubble_otimizado(unsigned long * , unsigned long, RESULTADOS * );
void select_sort(unsigned long *, unsigned long, RESULTADOS *);
void insert_sort(unsigned long *, unsigned long, RESULTADOS *);
void quick_sort(unsigned long *, unsigned long, RESULTADOS *);
void __quick_sort(unsigned long *, unsigned long, unsigned long, RESULTADOS *);
