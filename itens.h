#ifndef
#define ITENS_H

typedef struct {
    char   nome[MAX_NOME];
    double peso;
    double valor;
    char   tipo[MAX_TIPO];
    double valorAjust;
    int inteiro;         
} Item;
 
typedef struct {
    char   nome[MAX_NOME];
    double capacidade;
    char   regra[MAX_REGRA];
    Item   itens[MAX_ITENS];
    int    numeroItens;
} Fase;

#endif
