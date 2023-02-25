#ifndef TABLERO_H
#define TABLERO_H

#define NUM_INTENTOS 6
#define WORD_LENGTH 5

typedef struct{
    char letra;
    int color;
}tfield;

int gameStatus;

void initializeGame();
void printTablero();
void printLinea();
void centerTextLine();
void playGame(int language, char awnser[WORD_LENGTH]);

#endif