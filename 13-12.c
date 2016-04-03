/* C Programming Language Chapter 8 Project 14 */
/* print the reversal of a sentence without using data structure */


/* Error Handling: */
/* getchar() is very easy to confuse within the for loop, */
/*   especially for the 2D for loop, since the first one */
/*   for loop might be lost and not initiated; */

/* Be especially careful when handling the junction of 2D loop */

/* Now I am going to propagate the |0| and |1| notation for index values */
/* since |0| could represent the machine index version */
/* |1| means size */
/* notice that for the end of the loop, it is still |1| notation */
/* for the last i++ side effects */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_LENGTH 20
#define ARR_LENGTH 30

bool isNotWhiteSpace(char ch) {
  bool value = isspace(ch);
  return !value;
}

bool isNotBlank(char ch) {
  bool value = isblank(ch);
  return !value;
}

// To be simple, I will only swap the string arr
// Size refers to the size(1) in the 2D array
void swapArr(char arr1[], char arr2[], int size) {
  char temp = 0;
  int i = 0;
  for(i = 0; i < size; i++) {
    temp = arr1[i];
    arr1[i] = arr2[i];
    arr2[i] = temp;
  }
}
  
  

  


int main(void) {
  printf("Enter a sentense: ");
  char str[ARR_LENGTH][STR_LENGTH] = { 0 };
  int i = 0;
  int j = 0;
  char ch = -1;
  char mark = 0;

  
  for(i = 0; ch != '\n' &&  i < ARR_LENGTH; i++) {
    //printf("\n%d*", i);
    for(j = 0, ch = getchar(); isNotWhiteSpace(ch) && j < STR_LENGTH; j++) {
      //printf("%d:%c ", j, ch);
      str[i][j] = ch;
      ch = getchar();
    }
    str[i][j] = '\0';
    // so will not include white space characters
  }
  int iMax = i;  // iMac |1| since i++ at the end
  printf("iMax = %d\n", iMax);

  /*****************************
   To this part it stores the input in 2D array
   *****************************/ 

  // Now let's reverse the order in 2D array
  // I did so intentionally to increase the difficulty
  // Since I could just reverse print it

  for(i = 0; i < iMax / 2; i++) {
    // swap(i, iMac - i);
    char temp = 0;
    for(j = 0; j < STR_LENGTH; j++) {
      temp = str[i][j];
      str[i][j] = str[iMax - i - 1][j];
      str[iMax - i - 1][j] = temp;
    }
  }
  
  for(i = 0; i < iMax; i++) { 
    for(j = 0; str[i][j] != '\0'; j++) { 
      printf("%c", str[i][j]); 
    }
    printf("\n"); 
  } 

  return 0;

}




// Alternative Solution:

/* First get all of the inputs into an array */
/* And then use divide mechanism to divide them into 2D arrays */
/* It is better to handle than using getchar() to handle the stream */
