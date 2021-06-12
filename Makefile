CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS= -lm
DEPS=filter.h bitarray.h hachage.h
OBJ=filter.o bitarray.o hachage.o

%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

bloom: Main.o $(OBJ)
	@gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) bloom Main.o

execute:
	@./bloom 1000words.txt morewords.txt

valgrind:
	@valgrind ./bloom

time :
	@time ./bloom
