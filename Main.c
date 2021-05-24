#include "filter.h"

int main() {
    int m = 72;
    bitarray *a = create_bitarray(m);
    set_bitarray(a, 67);
    set_bitarray(a, 34);
    print_bitarray(a);
    free_bitarray(a);


    return 0;
}
