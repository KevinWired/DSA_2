#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdio.h>

#include "array_helpers.h"
#include "weather.h"

int historycal_min(WeatherTable array);

void max_temp_array(WeatherTable array, int output[YEARS]);

void rainy_month_array(WeatherTable array, month_t out[YEARS]);

#endif

