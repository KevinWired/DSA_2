#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 100

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered=NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);

    char *str = fgets(user_input, MAX_LENGTH, stdin);
    if(str == NULL)
    {
    	printf("Error al leer el texto\n");
    	return EXIT_FAILURE;
    }
 
    bool condition = (user_input[string_length(user_input) - 1] == '\n');
    if(condition)
    {
    	user_input[string_length(user_input) - 1] = '\0';
    	assert(user_input != NULL);
    }
    
    filtered = string_filter(user_input, ignore_chars[0]);
    for (unsigned int i=0; i < SIZEOF_ARRAY(ignore_chars); i++) {
    char *ptr_to_filtered = filtered;
        filtered = string_filter(filtered, ignore_chars[i]);
        free(ptr_to_filtered);
    }

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");
    free(filtered);
    return EXIT_SUCCESS;
}

