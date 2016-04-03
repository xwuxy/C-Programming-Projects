/* By Convention, I will use c8-5 as the program name instead of */
/* sum */

/* I will also try to give warning if the inputs are not integers */


/***** Mistake Handling: *****/
/* While doing the for loop for string, I always make the same mistake */
/* that I use *str instead of str[i] */
/* I was confused about the use of pointers and subscript syntax */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isDecimalDigit(char ch){
  return isdigit(ch);
}

bool isNotDecimalDigit(char ch) {
  return !(isDecimalDigit(ch));
}

bool isDecimalNumber(char *str) {
  int i = 0;
  for(i = 0; str[i] != '\0'; i++) {
    if(isNotDecimalDigit(str[i])){
      return false;
    }
  }

  return true;
}



int main(int argc, char *argv[]) {
  int i = 0;
  int sum = 0;
  for(i = 1; i < argc; i++) {
    if(isDecimalNumber(argv[i])) {
      sum += atoi(argv[i]);
    } else {
      printf("Please Enter Valid Inputs.\n");
      return 0;
    }
  }
  printf("sum = %d\n", sum);
  
  return 0;
}
