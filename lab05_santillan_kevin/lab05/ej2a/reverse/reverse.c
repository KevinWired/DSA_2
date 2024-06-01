#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "../stack.h"

static const unsigned int MAX_SIZE = 100u;

void print_help (char *program_name)
{

  printf ("Usage: %s <input file path>\n\n"
	  "Sort an array given in a file in disk.\n"
	  "\n"
	  "The input file must have the following format:\n"
	  " * The first line must contain only a positive integer,"
	  " which is the length of the array.\n"
	  " * The second line must contain the members of the array"
	  " separated by one or more spaces. Each member must be an integer."
	  "\n\n"
	  "In other words, the file format is:\n"
	  "<amount of array elements>\n"
	  "<array elem 1> <array elem 2> ... <array elem N>\n\n",
	  program_name);
}

char *parse_filepath (int argc, char *argv[])
{

  char *result = NULL;

  if (argc < 2)
    {
      print_help (argv[0]);
      exit (EXIT_FAILURE);
    }

  result = argv[1];

  return result;
}

int main (int argc, char *argv[])
{
  char *filepath = NULL;

  filepath = parse_filepath (argc, argv);

  int array[MAX_SIZE];

  unsigned int length = array_from_file (array, MAX_SIZE, filepath);
  printf ("Original: ");
  array_dump (array, length);

  if (length == 0)
    {
      printf ("Empty]\n");
    }
  else
    {
      stack pila = stack_empty();

      for (unsigned int i = 0; i < length; i++)
	{			
	  pila = stack_push (pila, array[i]);
	}

      stack_elem *new_array = calloc(length, sizeof(stack_elem));
      for(unsigned int i=0; i<length; i++)
      {
      	new_array[i] = stack_top(pila);
      	pila = stack_pop(pila);
      }
      assert(new_array != NULL);
      printf ("Reversed: ");
      array_dump (new_array, length);

      free(new_array);
      stack_destroy(pila);
    }

  return EXIT_SUCCESS;
}
