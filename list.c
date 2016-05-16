// Please notice that This file tries to dynamically allocate a linked list
// I will update a POD version (allocate NOT on heap BUT on stack version) later.

#include "list.h"


bool is_null(list_t *list) {
  if(list->first == NULL) {
    return true;
  } else {
    return false;
  }
}

node_t *make_node(int v, node_t *next) {
  node_t *node = malloc(sizeof(node_t));
  node->v = v;
  node->next = next;
  return node;
}

void free_node(node_t *node) {
  free(node);
}

list_t *make_list(void) {
  list_t *list = malloc(sizeof(list_t));
  list->first = NULL;
  return list;
}

void list_t_insert_front(int v, list_t *list) {
  list->first = make_node(v, list->first);
} 

void list_t_insert_back(int v, list_t *list) {
  if(list->first == NULL) {
    list->first = make_node(v, NULL);
    return;
  }
  node_t *cur = list->first;
  while(cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = make_node(v, NULL);
}
 
void list_insert(list_t *l, int i, int v) {
  // MY SELF REMINDER: ALWAYS set index = 2 when you consider
  // the first case

  // We use index = 1 + 1 because we start from 1, but
  // we are dealing with cur->next (this is the index!);
  int index = 2;
  if(l->first == NULL) {
    if(i == 1) {
      list_t_insert_front(v, l);
      return;
    } else {
      printf("Empty List!\n");
      return;
    }
  }
  if( i == 1) {
    list_t_insert_front(v,l);
    return;
  }
  node_t *cur = l->first;
  while(index < i && cur->next != NULL) {
    cur = cur->next;
    index++;
  }
  if(i == index) {
  cur->next = make_node(v, cur->next);
  } else {
    printf("Wrong Index!\n");
  }
  return;
}
 
void list_remove_index(list_t *l, int i) {
  int index = 2;
  if(l->first == NULL) {
    if(i == 1) {
      free_node(l->first);
      l->first = NULL;
      return;
    } else {
      printf("Empty List:\n");
      return;
    }
  }

  // Incrementing the pointer throughout the list
  node_t *cur = l->first;
  while(index < i && cur->next != NULL) {
    cur = cur->next;
    index++;
  }

  // Two Cases When quit the loop:
  // First, i == index
  // Second, it reaches the end
  if(i == index) {
    free_node(cur->next);
    cur->next = NULL;
    return;
  } else {
    printf("Wrong Index!");
    return;
  }
}






bool list_remove(list_t *l, int v) {
  if(l->first == NULL) {
    printf("The List Is Empty!\n");
    return false;
  }

  if(l->first->v == v) {
    node_t *to_del = l->first;
    l->first = l->first->next;
    free(to_del);
    return true;
  }
  node_t *cur = l->first;
  while(cur->next != NULL) {
    if(cur->next->v == v) {
      node_t *to_del = cur->next;
      cur->next = cur->next->next;
      free(to_del);
      return true;
    }
    cur = cur->next;
  }
  printf("Can't find node B: V:%d in the note_list!\n", cur->v);
  return false;
}


void list_set(list_t *l, int i, int v) {
  node_t *cur = l->first;
  int index = 0;
  while(cur != NULL && index < i) {
    cur = cur->next;
    index++;
  }
  if(index == i) {
    cur-> v = v;
  } else {
    printf("Wrong Index: Too large for this linked List\n");
  }
  return;
}


int list_get(list_t *l, int i) {
  int index = 1;
  node_t *cur = l->first;
  while(cur != NULL && index < i) {
    cur = cur->next;
    index++;
  }
  if(index == i) {
    return cur->v;
  } else {
    printf("Wrong Index: Too Large for this linked List\n");
  }

  return 0;

}



void free_list(list_t *list) {
  node_t *cur = list->first;
  while(cur != NULL) {
    node_t *to_del = cur;
    cur = cur->next;
    free(to_del);
  }
  free(list);
}



void list_print(list_t *list) {
  node_t *cur = list->first;
  while(cur != NULL) {
    printf("v:%d\n", cur->v);
    cur = cur->next;
  }
}


