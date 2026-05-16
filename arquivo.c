#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numFases(FILE *file) {
  char line[256];
  int num = 0;
  while (fgets(line, sizeof(line), file)) {
    if (strncmp(line, "FASE:", 5) == 0) {
      num++;
    }
  }
  rewind(file);
  return num;
}

void numItem(FILE *file, Fase *fases) {

  char line[256];
  int index = -1;
  int itemCount = 0;

  while (fgets(line, sizeof(line), file)) {
    if (strncmp(line, "FASE:", 5) == 0) {
      index++;
      fases[index].numeroItens = 0;
    }
    else if (strncmp(line, "ITEM:", 5) == 0) {
      fases[index].numeroItens++;
    }
  }
  rewind(file);
}

int lerFases(FILE *file, Fase *fases) {

  if (!file)
    return -1;

  char line[256];
  int numFases = -1;
  int itemCount = 0;

  while (fgets(line, sizeof(line), file)) {
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
      line[len - 1] = '\0';

    if (strlen(line) == 0)
      continue;

    // Queria que switch case funcionasse para string em c
    if (strncmp(line, "FASE:", 5) == 0) {
     
    numFases++;
      sscanf_s(line, "FASE: %s", fases[numFases].nome);
      itemCount = 0;
      //fases[numFases].numeroItens = 0;
    } else if (strncmp(line, "CAPACIDADE:", 11) == 0) {
      sscanf_s(line, "CAPACIDADE: %lf", &fases[numFases].capacidade);
    } else if (strncmp(line, "REGRA:", 6) == 0) {
      sscanf_s(line, "REGRA: %s", fases[numFases].regra);
    } else if (strncmp(line, "ITEM:", 5) == 0) {
      Item item;
      
      char *start = strchr(line, ':') + 2;
      char *comma1 = strchr(start, ',');
      char *comma2 = strchr(comma1 + 1, ',');
      char *comma3 = strchr(comma2 + 1, ',');

      int size_last = sizeof(comma3);
      
      if (comma1 && comma2 && comma3) {
          strncpy(item.nome, start, comma1 - start);
          item.nome[comma1 - start] = '\0';
          int size = comma3 - comma2;
          char valor[300];
          strncpy(valor, comma2 + 2, size - 2);
          sscanf_s(comma1 + 1, "%lf", &item.peso);
          //sscanf_s(comma2 + 1, "%lf", &item.valor);
          item.valor = atof(valor);
          item.valorAjust = atof(valor);
          sscanf_s(comma3, "%s", item.tipo);
          strncpy(item.tipo, comma3 + 2, size_last + 8);
          //printf("%s\n", item.tipo);
          fases[numFases].itens[itemCount] = item;
          
        itemCount++;
        //fases[numFases].numeroItens = itemCount;
      }
    }
  }

  if (itemCount > 0)
    numFases++;
  rewind(file);

  return numFases;
}

/*
int main()
{
    int num = numFases("entrada.txt");
    Fase * fase = calloc(num, sizeof(Fase));
    lerFases("entrada.txt", fase);
    free(fase);
    return 0;
}
*/