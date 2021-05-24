#include "filter.h"

filter *create_filter(int m, int k){
    int i;
    filter *f = (filter *) malloc(sizeof(filter));
    f->bitarray = create_bitarray(m);
    f->weight = (int *) malloc(sizeof(int) * k);
    f->weight_height = k;

    for(i = 0; i < f->weight_height; i++)
        f->weight[i] = (rand() % 253) + 2;
    return f;
}

void free_filter(filter *f){
    free_bitarray(f->bitarray);
    free(f->weight);
    free(f);
}