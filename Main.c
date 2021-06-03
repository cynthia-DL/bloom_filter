#include "filter.h"

int main() {
    int m = 32, i, k = 3;
    /*bitarray *a = create_bitarray(m);*/

    srand(time(NULL));

    /*set_bitarray(a, 31);
    if(get_bitarray(a, 31))
        printf("Youpi\n");
    else
        printf("FUCK\n");
    set_bitarray(a, 12);
    set_bitarray(a, 20);
    free_bitarray(a);*/

    filter *f = create_filter(m, k);
    add_filter(f, "tomate");
    print_bitarray(f->bitarray);
    printf("\n");
    if(is_member_filter(f, "prog"))
        printf("\nOK\n");
    else
        printf("\nNOP\n");


    free_filter(f);

    return 0;
}
