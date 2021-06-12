#include "hachage.h"

#include <stdio.h>

int main(int argc, char* argv[]) {

    filter *f;
    table *tab;
    char * file;
    char * file2;

    double maybe = 0;
    double find = 0;
    double nbWordTested = 0;
    int taille = 0;
    int nb_hach = 0;
    int taille_hach = 0;
    char word[1000];
    double nbWord = 0;

    FILE* infile2;
    FILE* infile;

    if(argc > 1){
        file = argv[1];
        if(argc > 2)
            file2 = argv[2];
        else
            file2 = "morewords.txt";
    }
    else
        file = "1000words.txt";

    while(taille < 1) {
        printf("Choisissez le nombre de bit dans le bitarray : ");
        scanf(" %d", &taille);
    }

    while(nb_hach < 1) {
        printf("Choisissez le nombre de fonctions de hachage : ");
        scanf(" %d", &nb_hach);
    }

    while(taille_hach < 1){
        printf("Choisissez la taille de la table de hachage : ");
        scanf(" %d", &taille_hach);
    }

    f = create_filter(taille, nb_hach);
    tab = create_table(taille_hach);

    infile2 = fopen(file2,"r");
    infile = fopen(file,"r");

    if(infile == NULL) {
        fprintf(stderr, "File doesn't exist.\n");
        exit(1);
    }

    if(infile2 == NULL) {
        fprintf(stderr, "File2 doesn't exist.\n");
        exit(1);
    }

    srand(time(NULL));

    while( fscanf(infile,"%s",word)== 1) {
        nbWord++;
        add_filter(f, word);
        add_table(tab, word);
    }
    fclose(infile);

    while( fscanf(infile2,"%s",word)== 1) {
        nbWordTested++;
        if(is_member_filter(f, word)) {
            maybe++;
            if(find_list(tab->bucket[hache(word) % taille_hach], word) != NULL) {
                find++;
            }
        }
    }

    printf("%f -> %f\n",nbWordTested,nbWord);
    printf("Peut-être : %f ->  Oui : %f\n",maybe, find);
    printf("Taux de faux positifs : %f", find / maybe);

    fclose(infile2);
    free_filter(f);
    free_table(tab);

    return 0;
}
