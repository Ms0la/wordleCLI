#include <stdio.h>
#include "palabras.h"
#include "tablero.h"
#include "colores.h"
#include "casilla.h"
#include "teclado.h"

int printMenu();

int main(){
    int idiomaElegido = printMenu();
    char palabra[NUM_LETRAS_PALABRA];
    inicializar_azar();
    palabra_al_azar(idiomaElegido, contar_palabras(idiomaElegido), palabra);
    playGame(idiomaElegido, palabra);
}

int printMenu(){
    int choice = 6;
    printf("Seleccione el idioma de las palabras:\n");
    
    printf("0)" );
    imprimir_nombre_idioma(IDIOMA_DEBUG);
    printf("%d palabras)\n", contar_palabras(IDIOMA_DEBUG));
    
    printf("1) ");
    imprimir_nombre_idioma(IDIOMA_CAT);
    printf("%d palabras)\n", contar_palabras(IDIOMA_CAT));
    
    printf("2) ");
    imprimir_nombre_idioma(IDIOMA_EN);
    printf("%d palabras)\n", contar_palabras(IDIOMA_EN));

    printf("3) ");
    imprimir_nombre_idioma(IDIOMA_ES);
    printf("%d palabras)\n", contar_palabras(IDIOMA_ES));

    printf("4) ");
    imprimir_nombre_idioma(IDIOMA_FI);
    printf("%d palabras)\n", contar_palabras(IDIOMA_FI));

    printf("5) ");
    imprimir_nombre_idioma(IDIOMA_MIO);
    printf("%d palabras)\n", contar_palabras(IDIOMA_MIO));

    do {
        scanf("%d%*c", &choice);
        if(choice<0 || choice>5){
            imprimir_nombre_idioma(choice);
            printf("\n");
        }
    } while (choice<0 || choice>5);
}
