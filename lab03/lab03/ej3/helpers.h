#ifndef _HELPERS_H
#define _HELPERS_H
#include <stdbool.h>
#include "player.h"

bool array_is_permutation_of(player_t a[], player_t other[], unsigned int length);

void array_copy(player_t dst[], player_t src[], unsigned int length);

unsigned int process_file(const char *filepath, player_t atp[]);

void atp_dump(player_t atp[], unsigned int length);

#endif
