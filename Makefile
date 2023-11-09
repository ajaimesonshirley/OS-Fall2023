# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Author>
#list: list.c main.c
#	gcc list.c main.c -o list

CC = gcc
CFLAGS = -Wall -Wextra
SRCS = main.c list.c
OBJS = $(SRCS:.c=.o)
TARGET = list

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c list.h
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -f $(OBJS) $(TARGET)
