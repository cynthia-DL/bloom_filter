#ifndef BLOOM_FILTER_HACHAGE_H
#define BLOOM_FILTER_HACHAGE_H

#include "filter.h"

typedef struct _link {
    char *word;
    struct _link *next;
} link;

typedef struct _table {
    link **bucket;
    int M; /* nombre de seaux */
    int size; /* nombre de mots dans la table */
} table;

link *create_link(char word[]);
table *create_table(int M);
link *find_list(link* lst, char word[]);
link *insert_first_list(link *lst, char word[]);
int equal(char* w1, char* w2);
unsigned int hache(char *p);
void add_table(table *tab, char word[]);
void free_link(link *lnk);
void free_list(link *lst);
void free_table(table *tab);

#endif
