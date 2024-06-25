#include "weather_utils.h"
#include <stdlib.h>
#include "weather.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

int historycal_min(WeatherTable a)
{// calculates minimum temp of all time	
	int min = a[0][0][0]._min_temp;
	for(unsigned int k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{
		for(unsigned int k_month = january; k_month <= december; k_month = k_month + 1)
		{
			for(unsigned int k_day = FST_DAY; k_day <= DAYS; k_day = k_day + 1)
			{
				if(min > a[k_year-FST_YEAR][k_month][k_day-FST_DAY]._min_temp)
				{
					min = a[k_year-FST_YEAR][k_month][k_day-FST_DAY]._min_temp;
				}
			}
		}
	}
	return min;
}

void max_temp_array(WeatherTable array, int output[YEARS]) 
{// for each year, 1980<=year<=2016 register the max. temp
	for(unsigned int k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{	
		int max = array[k_year - FST_YEAR][january][0]._max_temp;
		for(unsigned int k_month = january; k_month <= december; k_month = k_month + 1)
		{
			for(unsigned int k_day = FST_DAY; k_day <= LST_DAY; k_day = k_day + 1)
			{
				int item = array[k_year - FST_YEAR][k_month][k_day-1]._max_temp; 
				if(max < item)
				{
					max = item; 
					output[k_year - FST_YEAR] = max; // stores max temp in the index=(k_year - FST_YEAR)  
				} 
			}//end of k_day		
		}//end of k_month	
	}//end of k_year
}

void rainy_month_array(WeatherTable array, month_t output[YEARS])
{
	for(unsigned int k_year = FST_YEAR; k_year <= LST_YEAR; k_year = k_year + 1)
	{	
		unsigned int rainy_month_aux = 0; // for each year reset the rainy_month
		for(unsigned int k_month = january; k_month <= december; k_month = k_month + 1)
		{	
			unsigned int rainy_month = 0; // for each month reset the rainy month
			for(unsigned int k_day = FST_DAY; k_day <= LST_DAY; k_day = k_day + 1)
			{
				rainy_month = rainy_month + array[k_year-FST_YEAR][k_month][k_day-FST_DAY]._rainfall; // cumulative monthly rainfall
			}
			if(rainy_month > rainy_month_aux) // guarda
			{
				rainy_month_aux = rainy_month;
				output[k_year-FST_YEAR] = k_month; // stores the most rainy month in the index=(k_year - FST_YEAR)
			}// end of k_day
		}// end of k_month
	}// end of k_year
}
