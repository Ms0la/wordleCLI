#ifndef CASILLA_H
#define CASILLA_H

#include "tablero.h"

#define LENGTH_PALABRA 5

void inputletter(int idioma, tfield wordSlots[NUM_LETRAS_PALABRA]);
void isWordCorrect(tfield myWord[NUM_LETRAS_PALABRA], char awnser[NUM_LETRAS_PALABRA]);

#endif