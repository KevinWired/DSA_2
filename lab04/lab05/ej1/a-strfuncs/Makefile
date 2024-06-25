CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
OBJECTS = strfuncs.o main.o
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

list.o: strfuncs.c strfuncs.h
	$(CC) $(CFLAGS) -c strfuncs.c

array_helpers.o: strfuncs.c strfuncs.h
	$(CC) $(CFLAGS) -c array_helpers.c

main.o: main.c strfuncs.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)
# ==13903== All heap blocks were freed -- no leaks are possible
