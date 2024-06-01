CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
SOURCES = main.c queue.c queue_helpers.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = readqueue

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)
	
# ./readqueue ../input/example-easy.in 

