#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansicolors.h"

#define MAX_LENGTH 1820

char *string_clone(const char *str, size_t length) {
    char *str_clone = calloc(length + 1, sizeof(char));
    for (size_t i=0; i<length;i++) {
        str_clone[i] = str[i];
    }
    str_clone[length] = '\0';
    return str_clone;
}

void str_destroy(char *char_sequence) {
	free(char_sequence);	
}

int main(void) {
    char original[]=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         ANSI_BRGOLD
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                           Episode II \n\n"
         "                      ATTACK OF THE CLONES\n\n"
         "                There is  unrest in the Galactic\n"
         "                Senate. Several  thousand  solar\n"
         "                systems  have   declared   their\n"
         "                intentions to leave the Republic.\n\n"
         "                This      separatist     movement,\n"
         "                under  the   leadership   of  the\n"
         "                mysterious   Count   Dooku,   has\n"
         "                made it difficult for the limited\n"
         "                number   of   Jedi   Knights   to\n"
         "                maintain   peace   and  order  in\n"
         "                the galaxy.\n\n"
         "                Senator   Amidala,   the   former\n"
         "                Queen   of  Naboo,  is  returning\n"
         "                to  the  Galactic  Senate to vote\n"
         "                on the critical issue of creating\n"
         "                an    ARMY    OF   THE   REPUBLIC\n"
         "                to    assist    the   overwhelmed\n"
         "                Jedi....\n" ANSI_WHITE;
    char *copy=NULL;

    copy = string_clone(original, sizeof(original)/sizeof(*original));
    printf("Original:\n" ANSI_CYAN
            " %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   :\n" ANSI_CYAN
           " %s\n", copy);
	str_destroy(copy);
    return EXIT_SUCCESS;
}
/*	--- Error (str_clone) ---
*	El error str_clone es que trabajaba con una variable local (stack), osea una vez que la funcion retorne la variable (local) muere/se pierde.
*
*	--- Solucion (memoria dinamica) ---
*	Trabajamos con memoria dinamica (heap), de esta manera podemos retornar un puntero a este bloque de memoria reservado.
*	Y como trabajamos con memoria dinamica es importante liberarla en un momento oportuno.

*   --- Valgrind (test resumen) ---
*	All heap blocks were freed -- no leaks are possible.

*	--- Problema Usando char *original="" ---
*	No se puede cambiar el contenido de lo que apunta original.
*	
*	--- GDB: Lista de comandos principales usados [b:7, info locas, print length, n] ---
*	length+1 (line 6): '<error reading variable clone(no se puede acceder a la memoria en la direccion 0x0)>'. 
*
*/
