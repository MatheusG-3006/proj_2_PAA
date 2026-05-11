#include <stdlib.h>
#include "merge.h"

void merge(Item itens[], int esq, int meio, int dir) {

    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    Item *L = malloc(n1 * sizeof(Item));
    Item *R = malloc(n2 * sizeof(Item));

    int i, j, k;

    for(i = 0; i < n1; i++)
        L[i] = itens[esq + i];

    for(j = 0; j < n2; j++)
        R[j] = itens[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;

    while(i < n1 && j < n2){

        double r1 = L[i].valorAjust / L[i].peso;
        double r2 = R[j].valorAjust / R[j].peso;

        if(r1 >= r2)
            itens[k++] = L[i++];
        else
            itens[k++] = R[j++];
    }

    while(i < n1)
        itens[k++] = L[i++];

    while(j < n2)
        itens[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Item itens[], int esq, int dir){

    if(esq < dir){

        int meio = (esq + dir) / 2;

        mergeSort(itens, esq, meio);

        mergeSort(itens, meio + 1, dir);

        merge(itens, esq, meio, dir);
    }
}