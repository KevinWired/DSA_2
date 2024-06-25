#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6;

Weather 
weather_from_file(FILE* file)
{	
    int flag;
    Weather weather;
    
    flag = fscanf(file, EXPECTED_WEATHER_FILE_FORMAT, &weather._average_temp, 
						                              &weather._max_temp,
											  		  &weather._min_temp,
					  	     					      &weather._pressure,
     				  		                          &weather._moisture,
				  		                              &weather._rainfall);
	if(flag != AMOUNT_OF_WEATHER_VARS) // int vs int 
	{
		fprintf(stderr, ">> Error: Invalid Format File, Expected format: <int> <int> <int> <unsigned int> <unsigned int> <unsigned int>");
		exit(EXIT_FAILURE);
	} 
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            					                weather._max_temp,
	    					                    weather._min_temp,
	    					                    weather._pressure,
	    					                    weather._moisture,
	    					                    weather._rainfall);
}
