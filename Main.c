#include "hachage.h"

int main() {
    int m = 32, k = 3, M = 50;
    filter *f = create_filter(m, k);
    table *tab = create_table(M);
    char * file = "1000words.txt";
    char * file2 = "morewords.txt";

    double maybe = 0;
    double isin = 0;
    double nbWordTested = 0;

    char word[50];
    double nbWord = 0;

    FILE* infile2 = fopen(file2,"r");
    FILE* infile = fopen(file,"r");

    if(file == NULL) {
        fprintf(stderr, "File doesn't exist.\n");
        exit(1);
    }

    if(file2 == NULL) {
        fprintf(stderr, "File doesn't exist.\n");
        exit(1);
    }

    srand(time(NULL));

    while( fscanf(infile,"%s",word)==1 ) {
        nbWord++;
        add_filter(f, word);
        add_table(tab, word);
    }
    fclose(infile);

    while( fscanf(infile2,"%s",word)==1 ) {
        nbWordTested++;
        if(is_member_filter(f, word)) {
            maybe++;
            if(find_list(tab->bucket[hache(word) % M], word) != NULL) {
                isin++;
            }
        }
    }

    printf("%f -> %f\n",nbWordTested,nbWord);
    printf("%f -> %f\n",maybe, isin);

    fclose(infile2);
    free_filter(f);
    free_table(tab);

    return 0;
}
