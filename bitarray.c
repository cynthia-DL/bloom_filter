#include "bitarray.h"

bitarray *create_bitarray(int m){
    int i;
    int taille = 1 + (m / 8) / (int) sizeof(int);

    bitarray *bit_array = (bitarray *) malloc(sizeof(bitarray));
    bit_array->tab_bit = (int *) malloc(sizeof(int) * taille);

    for(i = 0; i < m; i++)
        bit_array->tab_bit[i] = 0;
    bit_array->taille = m;
    
    return bit_array;
}

void free_bitarray(bitarray *a){
    free(a->tab_bit);
    free(a);

}

/*void set_bitarray(bitarray *a, int pos) {
    ? one = ?
    one = 1;
    a->tab_bit = a->tab_bit | (one << (pos - 1));
    free(one);
}*/