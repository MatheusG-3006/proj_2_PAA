#include <stdio.h>
#include <string.h>

#include "guloso.h"
#include "merge.h"

void aplicarRegra(Fase *fase){

    for(int i = 0; i < fase->numeroItens; i++){
        fase->itens[i].inteiro = 0;
        if(strcmp(fase->regra,
                  "MAGICOS_VALOR_DOBRADO") == 0){

            if(strcmp(fase->itens[i].tipo,
                      "magico") == 0){

                fase->itens[i].valorAjust *= 2;
            }
        }

        else if(strcmp(fase->regra,
                       "SOBREVIVENCIA_DESVALORIZADA") == 0){

            if(strcmp(fase->itens[i].tipo,
                      "sobrevivencia") == 0){

                fase->itens[i].valorAjust *= 0.8;
            }
        }

        else if(strcmp(fase->regra,
                       "TECNOLOGICOS_INTEIROS") == 0){

            if(strcmp(fase->itens[i].tipo,
                      "tecnologico") == 0){

                fase->itens[i].inteiro = 1;
            }
        }
    }
}

double resolverFase(Fase fase, FILE *saida){

    aplicarRegra(&fase);

    mergeSort(fase.itens, 0, fase.numeroItens - 1);

    fprintf(saida,
            "--- FASE: %s ---\n",
            fase.nome);

    fprintf(saida,
            "Capacidade da mochila: %.2lf kg\n",
            fase.capacidade);

    double capacidade = fase.capacidade;
    double lucro = 0;

    int limite = fase.numeroItens;

    if(strcmp(fase.regra,
              "TRES_MELHORES_VALOR_PESO") == 0){

        limite = 3;
    }

    for(int i = 0;
        i < limite && capacidade > 0;
        i++){

        Item item = fase.itens[i];

        if(item.peso <= capacidade){

            fprintf(saida,
                    "Pegou (inteiro) %s (%.2lfkg, R$ %.2lf)\n",
                    item.nome,
                    item.peso,
                    item.valorAjust);

            capacidade -= item.peso;

            lucro += item.valorAjust;
        }

        else{

            if(item.inteiro == 1)
                continue;

            double fracao =
                capacidade / item.peso;

            double valorFrac =
                item.valorAjust * fracao;

            fprintf(saida,
                    "Pegou (fracionado) %s (%.2lfkg, R$ %.2lf)\n",
                    item.nome,
                    capacidade,
                    valorFrac);

            lucro += valorFrac;

            capacidade = 0;
        }
    }

    fprintf(saida,
            "Lucro da fase: R$ %.2lf\n\n",
            lucro);

    return lucro;
}