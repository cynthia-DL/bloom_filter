#include "filter.h"

int main() {
    int m = 8;
    bitarray *a = create_bitarray(m);
    set_bitarray(a, 8);
    set_bitarray(a, 1);
    set_bitarray(a, 3);
    print_bitarray(a);
    clear_bitarray(a);
    printf("\n");
    print_bitarray(a);
    free_bitarray(a);


    return 0;
}
