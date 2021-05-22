#include "filter.h"

int main() {
    int m = 45;
    bitarray *a = create_bitarray(m);
    set_bitarray(a, 34);
    print_bitarray(a);
    free_bitarray(a);


    return 0;
}
