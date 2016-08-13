CC = cc

CFLAGS = -g -Wall -Werror

OBJECTS = eds.c \
		heap.c \
		khelper.c \
		linearsorts.c \
		main.c \
		matrix.c \
		ordstats.c \
		rand.c \
		re.c \
		sorts.c \
		subarray.c \
		quicksort.c \

all: main

main: $(OBJECTS)
		$(CC) $(OBJECTS) -o main $(CFLAGS)
