#include <stdio.h>
#include "palabras.h"
#include "casilla.h"
#include "teclado.h"
#include "colores.h"
#include "tablero.h"

static tfield board[NUM_INTENTOS][NUM_LETRAS_PALABRA];

void playGame(int language, char awnser[WORD_LENGTH]){
    initializeGame();
    initializeKeyboard();
    printTablero();
    for(int i=0; i<NUM_INTENTOS && gameStatus; i++){
        inputletter(language, board[i]);
        isWordCorrect(board[i], awnser);
        printTablero();
        if(i==(NUM_INTENTOS-1) && gameStatus){
            printf("\nLa soluci%cn era: ", 162);
            for(int j=0; j<NUM_LETRAS_PALABRA; j++){
                printf("%c", awnser[j]);
            }
            printf("\n");
        }
    }
}

void initializeGame(){
    for(int i=0; i<NUM_INTENTOS; i++){
        for(int j=0; j<NUM_LETRAS_PALABRA; j++){
            board[i][j].color = BLACK;
            board[i][j].letra = 32;
        }
    }
    gameStatus = TRUE;
}

void printTablero(){
    int i, j;
    centerTextLine();
    printLinea();
    for(i=0; i<NUM_INTENTOS; i++){
        centerTextLine();
        for(j=0; j<NUM_LETRAS_PALABRA; j++){
            printf("|");
            printf_bgcolor(board[i][j].color);
            printf("%c", board[i][j].letra);
            printf_reset_color();
        }
        printf("|\n");
        centerTextLine();
        printLinea();
    }
    printKeyboard();
}

void printLinea(){
    for(int j=0; j<11; j++){
        if(j%2==0){
            printf("+");
        } else{
            printf("-");
        }
    }
    printf("\n");
}

void centerTextLine(){
    printf("         ");
}


