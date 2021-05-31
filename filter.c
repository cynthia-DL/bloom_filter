#include "filter.h"

/**
 * Create a filter and initialize it with m bits and k weights
 * @param int m
 * @param int k
 * @return filter *
 */
filter *create_filter(int m, int k)
{
    int i;
    filter *f = (filter *)malloc(sizeof(filter));
    f->bitarray = create_bitarray(m);
    f->weight = (int *)malloc(sizeof(int) * k);
    f->weight_height = k;

    for (i = 0; i < f->weight_height; i++)
        f->weight[i] = (rand() % 253) + 2;
    return f;
}

/**
 * Free the memory associated with the filter f
 * @param filter *f
 */
void free_filter(filter *f)
{
    free_bitarray(f->bitarray);
    free(f->weight);
    free(f);
}

/**
 * Add the key str to the filter
 * @param f
 * @param str
 * @param hashes
 */
void hash(filter *f, char *str, unsigned hashes[])
{
   int i, j;

    for (i = 0; i < f->weight_height; i++)
    {
        hashes[i] = 0;
        for (j = 0; str[j] != '\0'; j++)
        {
            hashes[i] = (f->weight[i] * hashes[i] + str[j]) % f->bitarray->nb_bit;
        }
    }
}

/**
 * Add the key str to the filter
 * @param f
 * @param str
 */
void add_filter(filter *f, char *str)
{
    int i;
    unsigned *hashes;

    /* initialising hashes */
    hashes = (unsigned int *)malloc(sizeof(unsigned) * f->weight_height);

    /* filling hashes with the hash function */
    hash(f, str, hashes);

    /* changing the bites according to the hashes array */
    for (i = 0; i < f->weight_height; i++)
    {
        set_bitarray(f->bitarray, hashes[i]);
    }

    /* freeing hashes */
    free(hashes);
}

/**
 * Check if the word str is in the filter f
 * @param filter *f
 * @param char *str
 * @return 1 or 0, depends on the result
 */
int is_member_filter(filter *f, char *str)
{
    unsigned int *hashes = (unsigned int *)malloc(sizeof(unsigned int) * f->weight_height);
    int i;

    hash(f, str, hashes);

    for (i = 0; i < f->weight_height; i++)
    {
        if (get_bitarray(f->bitarray, hashes[i]) == 0)
        {
            free(hashes);
            return 0;
        }
    }
    free(hashes);
    return 1;
}