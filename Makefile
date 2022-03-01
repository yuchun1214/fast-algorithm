CC := gcc
CFLAGS := -std=c99 -g -fsanitize=address

all : hw2 polynomial gcd flops

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

hw2: hw2.o
	$(CC) $(CFLAGS) -o $@ $^

polynomial: polynomial.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

gcd: binary_gcd.o
	$(CC) $(CFLAGS) -o $@ $^

flops: flops.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-rm *.o

.PHONY:
	clean
