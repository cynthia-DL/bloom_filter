#include "bitarray.h"

bitarray *create_bitarray(int m){
    int i;
    int taille = 1 + (m / 8) / (int) sizeof(int);

    bitarray *bit_array = (bitarray *) malloc(sizeof(bitarray));
    bit_array->tab_bit = (int *) malloc(sizeof(int) * taille);

    for(i = 0; i < taille; i++)
        bit_array->tab_bit[i] = 0;

    bit_array->nb_bit = m;
    bit_array->taille_tab = taille;

    return bit_array;
}

void free_bitarray(bitarray *a){
    free(a->tab_bit);
    free(a);
}

void set_bitarray(bitarray *a, int pos) {
    int one = 1;
    int tab = pos / 32;
    int bit = pos % 32;

    a->tab_bit[a->taille_tab - 1 - tab] = a->tab_bit[a->taille_tab - 1 - tab] | (one << (bit - 1));
}

void print_bitarray(bitarray *a) {
    int taille = a->taille_tab;
    int i, j;
    int octet;

    for (i = 0; i < taille; i++) {
        octet = a->tab_bit[i];
        printf(" ");
        for (j = 32; j >= 0; j--) {
            if ((octet / (int) pow(2, j)) == 1) {
                octet = octet - pow(2, j);
                printf("1");
            }
            else{
                printf("0");
            }
        }
    }
}