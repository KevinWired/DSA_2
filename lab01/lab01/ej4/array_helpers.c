
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array_helpers.h"
#include <stdbool.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {

    FILE *archivo;
    
    archivo = fopen(filepath, "r");

    if (archivo == NULL) 
    {
        printf(">> Error: Can't read file\n");
        exit(EXIT_FAILURE);
    }

    unsigned int length;
    
    fscanf(archivo, "%u", &length);

    if (length <= 0 || length > max_size) 
    {
        printf(">> Error: Invalid Length!\n");
                
        exit(EXIT_FAILURE);
    }
    
    int item = 0;
    
    unsigned int i = 0;
    
    while(fscanf(archivo, "%d", &item) == true)
    {
    	array[i] = item;
    	
    	i = i+1;
    }
            
    if(i != length)
    {
    	printf(">> Error: Invalid File (Length != Count Elements)\n");
    	    	
    	exit(EXIT_FAILURE);
    	
    }

    fclose(archivo);
    
    return length;
}

void array_dump(int a[], unsigned int length) 
{
	
    printf("[");
    
    for(unsigned int i=0; i<length; i++)
    {
    	if(i<length-1)
    	{
    		printf("%d, ",a[i]);
    	}
    	else
    	{
    		printf("%d]\n", a[i]);
    	}
    }
}

bool array_is_sorted(int a[], unsigned int length)
{
	
	if(length==1 || length==0)
	{
		return true;
	}
	else 
	{
		return (a[length-2]<=a[length-1]) && array_is_sorted(a,length-1);
	}

}

