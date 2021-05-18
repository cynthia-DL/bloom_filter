#ifndef PROJET_BLOOM_BITARRAY_H
#define PROJET_BLOOM_BITARRAY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct _bitarray {
/* TODO */
} bitarray;

/* Return a pointer to an empty bitarray that can store m bits */
bitarray *create_bitarray(int m);

/* Free the memory associated with the bitarray */
void free_bitarray(bitarray *a);

/* Set position pos in the bitarray to 1 */
void set_bitarray(bitarray *a, int pos);

/* Set position pos in the bitarray to 0 */
void reset_bitarray(bitarray *a, int pos);

/* Get the value at position pos in the bitarray */
int get_bitarray(bitarray* a, int pos);

/* Set all positions in the bitarray to 0 */
void clear_bitarray(bitarray *a);
#endif