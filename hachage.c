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

link *insert_first_list(link *lst, char word[], int pos) {
    link *tmp = create_link(word);
    tmp->next = lst;
    return tmp;
}

int equal(char* w1, char* w2) {
    return strcmp(w1, w2) == 0;
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