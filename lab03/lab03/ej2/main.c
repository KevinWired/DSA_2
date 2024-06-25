#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include "weather_utils.h"

void print_help (char *program_name)
{
  printf ("Usage: %s <input file path>\n\n"
		  "Load climate data from a given file in disk.\n"
		  "\n"
		  "The input file must exist in disk and every line in it must have the following format:\n\n"
		  "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
		  "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
		  "The dimensions of the array are given by the macro tclimate.\n"
		  "\n\n", program_name);
}

void max_temp_dump(int a[YEARS])
{
  printf ("\n");
  unsigned int year = FST_YEAR;
  while(year <= LST_YEAR)
	{
	  printf(">> For Year %d; The Maximun Temp. Register Is: %d\n", year,a[year - FST_YEAR]);
	  year = year + 1;
	}
  printf ("\n");
}

void rainy_month_dump(month_t a[YEARS])
{
  char const months[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
  for(unsigned int k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{
	  printf(">> For Year %d; The Most Rainy Month Is: %s\n",k_year, months[a[k_year - FST_YEAR]]);
	}
}

char *parse_filepath(int argc, char *argv[])
{
  /* Parse the filepath given by command line argument. */
  char *result = NULL;

  if (argc < 2)
	{
	  print_help (argv[0]);
	  exit (EXIT_FAILURE);
	}

  result = argv[1];

  return (result);
}

int main (int argc, char *argv[])
{
  char *filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath (argc, argv);

  /* create an array with the type of tclimate */
  WeatherTable array;

  /* parse the file to fill the array and obtain the actual length */
  array_from_file (array, filepath);

  /* show the ordered array in the screen */
  array_dump(array);

  /* shows the minimun temp. of all time */
  printf("\n>> The Historical Minimun Temp. Register Is: %d\n", historycal_min(array));

  /* calculate and shows the max temp. for each year, 1980<=year<=2016 */
  int output_max[YEARS];
  max_temp_array(array, output_max);
  max_temp_dump(output_max);

  /* calculate and shows the rainy month */
  month_t output_rainy[YEARS];
  rainy_month_array(array, output_rainy);
  rainy_month_dump(output_rainy);

  return (EXIT_SUCCESS);
}

