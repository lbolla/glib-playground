TARGET = main
CC = gcc
# CC = clang
CFLAGS=`pkg-config --cflags glib-2.0` -Wall -Wextra -pedantic -std=c99 -g
LIBS=`pkg-config --libs glib-2.0`

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

valgrind: $(TARGET)
	G_DEBUG=gc-friendly G_SLICE=always-malloc valgrind --leak-check=full ./$(TARGET) testing

clean:
	-rm -f *.o
	-rm -f $(TARGET)
