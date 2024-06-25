#ifndef _READ_H_
#define _READ_H_

#define MAX_SIZE 1000

char *parse_filepath(int argc, char *argv[]);

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size);

void phrase_builder(char l[], char s[], unsigned int indexes[], unsigned int length);

#endif
