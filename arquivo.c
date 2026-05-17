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
      sscanf(line, "FASE: %s", fases[numFases].nome);
      itemCount = 0;
    } else if (strncmp(line, "CAPACIDADE:", 11) == 0) {
      sscanf(line, "CAPACIDADE: %lf", &fases[numFases].capacidade);
    } else if (strncmp(line, "REGRA:", 6) == 0) {
      sscanf(line, "REGRA: %s", fases[numFases].regra);
    } else if (strncmp(line, "ITEM:", 5) == 0) {
      Item item;
      memset(&item, 0, sizeof(Item));
 
      // Parse: ITEM: Nome, peso, valor, tipo
      char tempTipo[MAX_TIPO];
      int matched = sscanf(line, "ITEM: %99[^,], %lf, %lf, %s",
                           item.nome, &item.peso, &item.valor, tempTipo);
 
      if (matched == 4) {
          item.valorAjust = item.valor;
          strncpy(item.tipo, tempTipo, MAX_TIPO - 1);
          item.tipo[MAX_TIPO - 1] = '\0';
 
          fases[numFases].itens[itemCount] = item;
          itemCount++;
      }
    }
  }
 
  if (itemCount > 0)
    numFases++;
  rewind(file);
 
  return numFases;
}