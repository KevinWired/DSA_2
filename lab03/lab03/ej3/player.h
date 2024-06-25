#ifndef _PLAYER_H
#define _PLAYER_H
#define MAX_NAME_LENGTH 100u
#define MAX_COUNTRY_LENGTH 3u

typedef struct _player_t {
    char name[MAX_NAME_LENGTH + 1u]; //adding 1u to reserve space for \0 ending char
    char country[MAX_COUNTRY_LENGTH + 1u]; //adding 1u to reserve space for \0 ending char
    unsigned int rank;
    unsigned int age;
    unsigned int points;
    unsigned int tournaments;
} player_t;

#endif //_PLAYER_H
