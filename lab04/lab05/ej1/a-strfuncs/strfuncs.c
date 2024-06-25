#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

#include "strfuncs.h"

static bool string_inv(const char *str)
{
	bool flag = (str != NULL) && (*str != '\0');
	return flag;
} 

size_t string_length(const char *str) 
{
	assert(string_inv(str));
    size_t size = 0;
    while (str[size] != '\0') 
    {
        size = size + 1;
    }
    assert(string_inv(str));
    
    return size;
}

char *string_filter(const char *str, char c)
{
	assert(string_inv(str));
    size_t size = string_length(str);
    char *not_c = calloc(size + 1, sizeof(char));
    char *not_c_ptr = not_c;

    while (*str != '\0')
    {
        if (*str != c)
        {
            *not_c_ptr = *str;
            not_c_ptr++;
        }

        str++;
    }
	assert(string_inv(not_c));
    return not_c; 
}

static void string_swap(char *str, unsigned int i, unsigned int j)
{
    char tmp;
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

static void string_reverse(char *str)
{
    size_t length = string_length(str);
    for (unsigned int i = 0; i < length / 2; i++)
    {
        string_swap(str, i, length - i - 1);
    }
}

bool string_is_symmetric(const char *str)
{   
	assert(string_inv(str));
	size_t size = string_length(str);
	char *copy = calloc(size + 1, sizeof(char));
	assert(copy != NULL);
    for(size_t i = 0; i < size; i++)
    {
    	copy[i] = str[i];
    }
    copy[size] = '\0';
    string_reverse(copy);
    bool symmetric = true;
    for(size_t i = 0; i<size && symmetric; i++)
    {
    	symmetric = symmetric && (copy[i]==str[i]);
    }
    free(copy);
	return symmetric;
}
