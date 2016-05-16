
/* Please notice this lab comes from my lab for stack */
/* I have make modifications for this project */
/* In this project, I always assume I am a client of the stack library */
/* To complete the hanoi tower implementation. */
  

#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


typedef struct {
  list_t *list;
  int size; // We've defined a variable size to keep track of its size
} stack_t;




// For the following functions, please notice that the stack_t *s parameter
// should not be NULL, it should be created by make_stack function


// size() will return the size of the stack
int size(stack_t *s) ;



// make_stack will create a new stack and returns
// the pointer to it
stack_t *make_stack(void) ;



// push function will add the given value to
// the top of current stack
void push(stack_t *s, int v);



// pop function will retrieve and return one value
// from the top of the stack
int pop(stack_t *s) ;


// print_stack function would print all the values
// in current stack
void print_stack(stack_t *s) ;



// free_stack would free the given stack
void free_stack(stack_t *s);



// is_null_stack would check whether the first element
// in the list of the stack is null
bool is_null_stack(stack_t *s);




// stack_get function would return the value of the ith element
// in the stack, but would not modify the stack
// pre:  i >= 0;

int stack_get(stack_t *s, int i);






#endif
