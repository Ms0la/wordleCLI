#include <stdio.h>
#include "colores.h"
#include "teclado.h"
#include "tablero.h"

#define NUMLETRAS 26

static tfield letras[NUMLETRAS];

void initializeKeyboard(){
	char qwerty[NUMLETRAS] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
	for (int i=0; i<NUMLETRAS; i++){
		letras[i].letra = qwerty[i];
		letras[i].color =  BLACK;
	}
}

void printKeyboard(){
    for(int i = 0; i < NUMLETRAS; i++)
	{
		printf("[");
		printf_bgcolor(letras[i].color);
		printf("%c", letras[i].letra);
		printf_reset_color();
		printf("]");	
		if(i == 9) printf("\n ");
		if(i == 18) printf("\n  ");
		if(i == NUMLETRAS-1) printf("\n ");
	}
}

void changeKeyboardLetterColour(char letter, int colour){
	for(int i=0; i++; i++){
		if(letras[i].letra == letter){
			letras[i].color = colour;
		}
	}	
}
