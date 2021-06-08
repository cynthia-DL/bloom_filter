#include "hachage.h"

int main() {
    int m = 32, k = 3;

    srand(time(NULL));

    filter *f = create_filter(m, k);

    free_filter(f);

    return 0;
}
