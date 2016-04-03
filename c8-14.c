/* C Programming Language Chapter 8 Project 14 */
/* print the reversal of a sentence without using data structure */

#include <stdio.h>
#include <stdbool.h>

#define STRLENGTH 100


/* Mistake Handling: */
/* Don't use "string" for 'char' */
/* Always check the boundary conditions */
/**** The following mistake program is for reverse all the characters ***/

/*
int main(void){
  printf("Enter a sentense: ");
  char str[STRLENGTH] = { 0 };
  int i = 0;
  char ch = 0;
  while(true) {
    ch = getchar();
    str[i] = ch;
    i++;
    if(i >= STRLENGTH - 1) {
      break;
    }
    if(ch == '?' || ch == '!') {
      str[i] = ch;
      break;
    } else if(ch == '\n') {
      break;
    }
  }
  for(i = i -1; i >= 0; i--) {
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}

*/


int main(void) {
  printf("Enter a sentense: ");
  char str[STRLENGTH] = { 0 };
  int i = 0;
  char ch = 0;
  char mark = 0;
  while(true) {
    ch = getchar();
    if(ch == '?' || ch == '!') {
      mark = ch;
      break;
    }
    if(ch == '\n') {
      break;
    }
    str[i] = ch;
    i++;

  }
  // j is a index that points to the end of the last space
  // k is the index that iterates through the small str
  // now, i is the index that iterates through the whole str

  /* Now the array would not contain \n or mark \n */
  int j = i;
  int k = 0;

  for(; i>= 0; i--) {
    if(str[i] == ' ' || i == 0) {
      // In case when it reaches 0, k should start from 0
      if(i == 0){
        k = 0;
      } else {
        k = i + 1;
      }
      for(; k < j; k++) {
        printf("%c", str[k]);
      }
      if(i == 0) { break; };
      printf(" ");
      j = i;
    }

  }
  if( mark != 0) {
    printf("%c", mark);
  }
  printf("\n");

  return 0;

}



// How to deal with the ? Question mark?
