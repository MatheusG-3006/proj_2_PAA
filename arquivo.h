#pragma once

#include <stdio.h>
#include "itens.h"

int lerFases(FILE * file, Fase fases[]);
void numItem(FILE * file, Fase *fases);
int numFases(FILE * file);