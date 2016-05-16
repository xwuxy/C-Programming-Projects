#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"




int size(stack_t *s) {
  return s->size;
}


stack_t *make_stack(void) {
  stack_t *s = malloc(sizeof(stack_t));
  s->size = 0;
  s->list = make_list();
  return s;
}


void push(stack_t *s, int v) {
  list_insert(s->list, 1, v);
  s->size += 1;
}


int pop(stack_t *s) {
  if(is_null(s->list)) {
    return 0;
  }
  int value = s->list->first->v;
  list_remove(s->list, list_get(s->list, 1));
  s->size -= 1;
  return value;
}


void print_stack(stack_t *s) {
  list_print(s->list);
}


void free_stack(stack_t *s) {
  if(s == NULL) {
    return;
  }
  free_list(s->list);
  free(s);
}

 
bool is_null_stack(stack_t *s) {
  if(is_null(s->list)) {
    return true;
  } else {
    return false;
  }
}

// i starts from 0
int stack_get(stack_t *s, int i) {
  return list_get(s->list, i);
}
