#ifndef ITENS_H
#define ITENS_H

#define MAX_NOME  100
#define MAX_FASES 10
#define MAX_ITENS 50
#define MAX_TIPO  50
#define MAX_REGRA 100

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
