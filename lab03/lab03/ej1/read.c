#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "read.h"

char *parse_filepath(int argc, char *argv[])
{
    char *res = NULL;
    if (argc < 2) {
        printf("Escriba correctamente el path.");
        exit(EXIT_FAILURE);
    }
    res = argv[1];
    return res;
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
{ 
	FILE *file;
        
	file = fopen(path, "r");
		
	if(file == NULL)
	{
		printf(">> Error: Can't Read File\n"); 
		exit(EXIT_FAILURE);
		
	}
	
	unsigned int length=0;

	while(fscanf(file,"%u -> *%c*\n", &indexes[length], &letters[length]) != EOF) 
	{
		
		if(length>max_size)
		{
			printf(">> Error: Invalid Length %u\n", length);
		    exit(EXIT_FAILURE);
		}
		
		if(indexes[length]>MAX_SIZE-1)
		{
			printf(">> Error: %u Letter Can't Be Stored (Index=%d Is Not In Range)\n", indexes[length], MAX_SIZE-1);
						
			exit(EXIT_FAILURE);
		}
		
		length = length+1;
	} 
		
	fclose(file);
	
	return length; 

}

void phrase_builder(char l[], char s[], unsigned int indexes[], unsigned int length)
{

    for(unsigned int i=0; i<length; ++i)
    {
     		s[indexes[i]] = l[i];
         
    }
}

