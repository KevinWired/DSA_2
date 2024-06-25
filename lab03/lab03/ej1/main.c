#include <stdlib.h>
#include <stdio.h>
#include "read.h"

static void dump(char a[], unsigned int length) 
{
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc,char *argv[]) {
  
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    char *path = NULL;
    
    path = parse_filepath(argc, argv);
    
    length = data_from_file(path, indexes, letters, MAX_SIZE);

    phrase_builder(letters, sorted, indexes, length);
    
    dump(sorted, length);

    return EXIT_SUCCESS;
}
