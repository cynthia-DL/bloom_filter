#include "hachage.h"

link *create_link(char word[]) {
    link *lnk = malloc(sizeof(link));
    lnk->word = malloc(strlen(word)+1);
    strcpy(lnk->word, word);
    lnk->next = NULL;
    return lnk;
}

table *create_table(int M){
    table *tab_hach = (table*)malloc(sizeof(table));
    int i;

    tab_hach->bucket = (link**)malloc(sizeof(link*)*M);
    tab_hach->size = 0;
    tab_hach->M = M;

    for(i = 0; i < M; i++)
        tab_hach->bucket[i] = NULL;

    return tab_hach;
}

link *find_list(link* lst, char word[]) {
    link *ptr = lst;
    while (ptr != NULL && !equal(ptr->word, word))
        ptr = ptr->next;
    return ptr;
}

link *insert_first_list(link *lst, char word[]) {
    link *tmp = create_link(word);
    tmp->next = lst;
    return tmp;
}

int equal(char* w1, char* w2) {
    return strcmp(w1, w2) == 0;
}

unsigned int hache(char *p){
    unsigned int h=0,g;
    for(;*p;p++){
        h=(h<<4)+*p;
        if((g = h&0xf0000000)) /*il y a des valeurs dans les 4 bits de poids fort*/
        {
            h=h^(g>>24);/*elles vont influencer l'octet de poids faible*/
            h=h^g;/*on les supprime du haut de h*/
        }
    }
    return h;
}

void add_table(table *tab, char word[]){
    int index = hache(word);

    if(!(find_list(tab->bucket[index % tab->M], word)))
        tab->bucket[index % tab->M] = insert_first_list(tab->bucket[index % tab->M], word);
}

void free_link(link *lnk) {
    free(lnk->word);
    free(lnk);
}

void free_list(link *lst) {
    while (lst) {
        link *tmp = lst;
        lst = lst->next;
        free_link(tmp);
    }
}

void free_table(table *tab) {
    int i;
    for(i = 0; i < tab->M; i++){
        free_list(tab->bucket[i]);
    }
    free(tab->bucket);
    free(tab);
}