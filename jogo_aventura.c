/*
Nome: Isaac Xavier de Araújo RA: 
Nome: Jean Carlos Antunes Rocha RA:
Nome: Matheus Gonçalves dos Santos RA: 10439447
Disciplina: Projeto e Análise de Algoritmos II
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_NOME 100; 
#define MAX_FASES 10; 
#define MAX_ITENS 50; 
#define MAX_TIPO 50; 
#define MAX_REGRA 100; 


typedef struct{
    char nome[MAX_NOME];
    double peso; 
    double valor; 
    char tipo[MAX_TIPO];
    double valorAjust; 
    int inteiro; 
} Item; 

typedef struct{ 
    char nome[MAX_NOME];
    double capacidadeMochila;
    char regra[MAX_REGRA]; 
    Item itens[MAX_ITENS];
    int numeroItens;   
} Fase;

// Ordenação

void merge(Item itens[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int i, j, k;

    Item *L = malloc(n1 * sizeof(Item));
    Item *R = malloc(n2 * sizeof(Item));

    for (i = 0; i < n1; i++) L[i] = itens[esq + i];
    for (j = 0; j < n2; j++) R[j] = itens[meio + 1 + j];

    i = 0; j = 0; k = esq;
    while (i < n1 && j < n2) {
        double r1 = L[i].valorAjustado / L[i].peso;
        double r2 = R[j].valorAjustado / R[j].peso;
        if (r1 >= r2) itens[k++] = L[i++];
        else          itens[k++] = R[j++];
    }
    while (i < n1) itens[k++] = L[i++];
    while (j < n2) itens[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Item itens[], int esq, int dir){
    if(esq < dir){
        int meio = (esq + dir)/2; 
        mergeSort(itens,esq,meio); 
        mergeSort(itens,meio + 1,dir); 
        merge(itens,esq,meio,dir); 
    }
}

// Entrada de Arquivo 

int leFase(const char *nomeArquivo, Fase fases[], int maxFases){
    FILE *f = fopen(nomeArquivo *r); 

    if(!f){
        fprintf(stderr, "Não foi possível abrir o arquivo '%s'.\n",nomeArquivo);
        return -1
    }

    char linha[512]; 
    int numeroFases = -1; 

} //Continua a partir daqui