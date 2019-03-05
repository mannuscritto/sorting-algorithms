typedef struct __result {
    unsigned long long comparacoes;
    unsigned long long trocas;
    char nome[30];
} RESULTADOS;

void copiar(unsigned long long * , unsigned long long * , unsigned long long);
void mostrar(unsigned long long * , unsigned long long);
void mostrar_resultados(RESULTADOS);

void bubble(unsigned long long * , unsigned long long, RESULTADOS * );
void bubble_otimizado(unsigned long long * , unsigned long long, RESULTADOS * );
void select_sort(unsigned long long *, unsigned long long, RESULTADOS *);
void insert_sort(unsigned long long *, unsigned long long, RESULTADOS *);
void quick_sort(unsigned long long *, unsigned long long, RESULTADOS *);
void __quick_sort(unsigned long long *, unsigned long long, unsigned long long, RESULTADOS *);
