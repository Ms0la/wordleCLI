#include <stdio.h>
#include "palabras.h"
#include "colores.h"
#include "teclado.h"
#include "casilla.h"

/*Declaramos este tipo local aqui, dado que solo lo vamos a usar para evitar colorear
una letra mas de dos veces*/
typedef struct 
{
    char awnser[WORD_LENGTH];
    int isPositionFound[WORD_LENGTH];
}tawnser;

void inputletter(int idioma, tfield wordSlots[NUM_LETRAS_PALABRA])
{
    int isValid = FALSE;
    char word[NUM_LETRAS_PALABRA];
    do{
        printf("\n Introduce palabra: ");
        for(int i=0; i<NUM_LETRAS_PALABRA; i++){
            scanf("%c", &word[i]);
            if(word[i]>=97 && word[i]<=122){
                word[i] -= 97;
                word[i] += 65;
            }
        }
        scanf("%*c"); //Limpiamos el buffer para evitar que el scanf rompa la siguiente iteracion
        isValid = es_palabra_correcta(idioma, word);
        if(isValid==FALSE){
            printf("\nEsta palabra no existe\n");
        }
    } while(isValid==FALSE);
    
    for(int i=0; i<NUM_LETRAS_PALABRA; i++){
        wordSlots[i].letra = word[i];
        wordSlots[i].color = WHITE;
    }
}

void isWordCorrect(tfield myWord[NUM_LETRAS_PALABRA], char awnser[NUM_LETRAS_PALABRA])
{
    int equalCount = 0, i;
    tawnser awnserData;

    for(i=0; i<NUM_LETRAS_PALABRA; i++){
        awnserData.awnser[i] = awnser[i];
        awnserData.isPositionFound[i] = FALSE;
    }

    //Evaluamos primero a ver si hay letras en la posición correcta
    for(i=0; i<NUM_LETRAS_PALABRA; i++){
        if(myWord[i].letra == awnser[i]){
            myWord[i].color = GREEN;
            awnserData.isPositionFound[i] = TRUE;
            equalCount++;
            changeKeyboardLetterColour(myWord[i].letra, myWord[i].color);
        } 
    }
    
    //Evaluamos después si hay letras correctas pero en posiciones erróneas
    for(i=0; i<NUM_LETRAS_PALABRA; i++){
        for(int j=0; j<NUM_LETRAS_PALABRA; j++){
            if(myWord[i].letra == awnser[j] && !awnserData.isPositionFound[j]){
                myWord[i].color = YELLOW;
                awnserData.isPositionFound[j] = TRUE;
                changeKeyboardLetterColour(myWord[i].letra, myWord[i].color);
            }
        }
    }

    if(equalCount == NUM_LETRAS_PALABRA){
        gameStatus = FALSE;
    }
}
