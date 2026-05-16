/*
Nome: Isaac Xavier de Araújo RA: 
Nome: Jean Carlos Antunes Rocha RA:
Nome: Matheus Gonçalves dos Santos RA: 10439447
Disciplina: Projeto e Análise de Algoritmos II
*/
#include <stdio.h>
#include <stdlib.h>
#include "itens.h"
#include "guloso.h"
#include "arquivo.h"

int main(int argc, char *argv[]) {
    FILE *input;
    fopen_s(&input, "entrada.txt", "r");
    if (!input)
        return 1;
    
    int num = numFases(input);
    Fase * fase = calloc(num, sizeof(Fase));
    numItem(input, fase);
    lerFases(input, fase);
    /*
    */
    for (int i = 0; i < num; i++) {
        for(int j=0; j < fase[i].numeroItens; j++)
        {
            printf("%f\n", fase[i].itens[j].valor);
        }
    }
    
    FILE *output;
    fopen_s(&output, "saida.txt", "w");
    for (int i = 0; i < num; i++) {
        resolverFase(fase[i], output);
    }
    fclose(input);
    fclose(output);
    free(fase);
    return 0;
}

