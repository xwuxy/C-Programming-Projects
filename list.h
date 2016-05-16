/* This file comes from my lab for stack  */
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
 
 
typedef struct node {
  int v;
  struct node *next;
} node_t;

typedef struct node_list {
  node_t *first;
} list_t;



list_t *make_list(void);

// list_insert will insert one value to given index
// Please notice the first element in the list
// has index 1 (NOT 0)
void list_insert(list_t *l, int i, int v);

bool list_remove(list_t *l, int v);

// list_set function will set the node in the list
// at given index to value v
void list_set(list_t *l, int i, int v);


// list_get function will return the value of the
// node at given index, but not delete it
int list_get(list_t *l, int i);


void free_list(list_t *list);

void list_print(list_t *list);


// is_null function will check whether the first
// element of the list is NULL
bool is_null(list_t *list);
                            

#endif
