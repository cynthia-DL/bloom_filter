#include "bitarray.h"

/**
 * Create a bitarray and initialize it with w bits
 * @param int m
 * @return bitarray *
 */
bitarray *create_bitarray(int m){
    int i;
    int taille = 1 + (m / 32);

    bitarray *bit_array = (bitarray *) malloc(sizeof(bitarray));
    bit_array->tab_bit = (int *) malloc(sizeof(int) * taille);

    for(i = 0; i < taille; i++)
        bit_array->tab_bit[i] = 0;

    bit_array->nb_bit = m;
    bit_array->taille_tab = taille;

    return bit_array;
}

/**
 * Free the memory associated with the bitarray a
 * @param bitarray *a
 */
void free_bitarray(bitarray *a){
    free(a->tab_bit);
    free(a);
}

/** Set position pos in the bitarray to 1
 * @param bitarray a
 * @param int pos
 */
void set_bitarray(bitarray *a, int pos) {
    if(pos > a->nb_bit)
        exit(EXIT_FAILURE);

    int one = 1;
    int tab = pos / 32;
    int bit = (pos % 32) + 1;

    a->tab_bit[a->taille_tab - 1 - tab] = a->tab_bit[a->taille_tab - 1 - tab] | (one << (bit - 1));
    
}

/**
 * Print the bitarray bit by bit
 * @param bitarray *a
 */
void print_bitarray(bitarray *a) {
    int taille = a->taille_tab;
    int i, j;
    int octet;
    int reste = a->nb_bit % 32;

    for (i = 0; i < taille; i++) {
        octet = a->tab_bit[i];
        for (j = 32; j > 0; j--) {
            if ((octet / (int) pow(2, j)) == 1) {
                octet = octet - pow(2, j);
                if( (i != 0) || (j <= reste))
                    printf("1");
            }
            else {
                if( (i != 0) || (j <= reste))
                    printf("0");
            }
        }
    }
}

/** 
 * Get the value at position pos in the bitarray
 * @param bitarray *a
 * @param int pos
 * @return 0 or 1 depending of the value of the bit pos
 */
int get_bitarray(bitarray* a, int pos){
    int tab;
    int bit;
    int res;

    /* tab represent which array of a->tab_bit contains pos*/
    tab = a->taille_tab - pos/32 - 1;

    /* bit represent where is pos in a->tab_bit[which_array] */
    bit = pos - 32 * ( a->taille_tab - tab - 1);

    /* res is the value at position pos in the bitarray*/
    res =  (a->tab_bit[tab] & (1 << bit)) ? 1 : 0;

    return res;
}

/** Set position pos in the bitarray to 0 
 * @param bitarray a
 * @param int pos
 */
void reset_bitarray(bitarray *a, int pos){
    int tab;
    int bit;

    /* tab represent which array of a->tab_bit contains pos*/
    tab = a->taille_tab - pos/32 - 1;

    /* bit represent where is pos in a->tab_bit[which_array] */
    bit = pos - 32 * ( a->taille_tab - tab - 1);

    a->tab_bit[tab] = (int) a->tab_bit[tab] & ~(1 << bit);
}
/**
 * Put all bits to 0 int the bitarray a
 * @param bitarray *a
 */
void clear_bitarray(bitarray *a){
    int i;

    for(i = 0; i < a->taille_tab; i++)
        a->tab_bit[i] = 0;
}