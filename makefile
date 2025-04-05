CC = gcc
CFLAGS = -Wall -Wextra

all: app1

app1: main.o metrics.o utils.o
	$(CC) $(CFLAGS) -o app1 main.o metrics.o utils.o

main.o: main.c metrics.h utils.h
	$(CC) $(CFLAGS) -c main.c

metrics.o: metrics.c metrics.h
	$(CC) $(CFLAGS) -c metrics.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o app1

