CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
DEPS=filter.h bitarray.h
OBJ=filter.o bitarray.o

%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

bloom: Main.o $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) bloom Main.o

execute:
	@./bloom

valgrind:
	@valgrind ./bloom

time :
	@time ./bloom
