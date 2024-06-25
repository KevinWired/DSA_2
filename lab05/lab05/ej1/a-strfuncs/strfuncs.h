#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

#ifndef _STRFUNC_
#define _STRFUNC_

size_t string_length(const char *str);
/*
*	DESC: Calcula la longitud de la cadena apuntada por str
*/

char *string_filter(const char *str, char c);
/*
*	DESC: devuelve una nueva cadena en memoria dinamica que se obtiene tomando los caracteres de str
*	que son distintos del caracter c.
*/

bool string_is_symmetric(const char *str);
/*
*	DESC: indica si la cadena apuntada por str es simetrica
*/

#endif
