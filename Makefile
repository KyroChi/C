CC = cc

CFLAGS = -g

OBJECTS = heap.c \
		khelper.c \
		linked.c \
		main.c \
		matrix.c \
		rand.c \
		re.c \
		sorts.c \
		subarray.c \

all: main

main: $(OBJECTS)
		$(CC) $(OBJECTS) -o main $(CFLAGS)
