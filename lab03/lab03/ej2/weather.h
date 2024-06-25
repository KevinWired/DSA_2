#ifndef _WEATHER_H
#define _WEATHER_H
#define EXPECTED_WEATHER_FILE_FORMAT "%d %d %d %u %u %u"
#include <stdio.h>

typedef struct _weather
{
    int _average_temp;
    int _max_temp;
    int _min_temp;
    unsigned int _pressure;
    unsigned int _moisture;
    unsigned int _rainfall;
} Weather;

Weather weather_from_file(FILE* file);

void weather_to_file(FILE* file, Weather weather);

#endif //_WEATHER_H
