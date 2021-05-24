#include "filter.h"

int main() {
    srand(time(NULL));

    int m = 8, k = 3, i;
    /*bitarray *a = create_bitarray(m);
    set_bitarray(a, 8);
    set_bitarray(a, 1);
    set_bitarray(a, 3);
    print_bitarray(a);
    clear_bitarray(a);
    printf("\n");
    print_bitarray(a);
    free_bitarray(a);*/

    filter *f = create_filter(m, k);
    print_bitarray(f->bitarray);
    for(i = 0; i < f->weight_height; i++)
        printf("\n%d", f->weight[i]);


    free_filter(f);

    return 0;
}
