#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdbool.h>
#include "weather.h"

#define FST_YEAR 1980
#define LST_YEAR 2016
#define YEARS 37

typedef enum {january, february, march, april, may, june, july, august, september, october, november, december} month_t;

#define MONTHS 12

#define FST_DAY 1
#define LST_DAY 28
#define DAYS 28

typedef Weather WeatherTable [YEARS][MONTHS][DAYS];

void array_dump(WeatherTable a);

void array_from_file(WeatherTable a, const char *filepath);

#endif
