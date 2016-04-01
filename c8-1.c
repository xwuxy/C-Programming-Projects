/* Charpter 13 Projects 1 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* For each while loop, the problem might be */
/* how to set the first one to small and big */


/* The Biggest Problem might be how to enter the loop !!! ASK QUESTIONS */



// if contain some nonString character,
// return false
// convert the str and check it at the same time



/****************** Error Recording: **********************/
/* Boundary Checking: */
/* Within the width a ... b, should use ( x <= a && x >= b) */
/* should use AND && */


/* When make some modifications, always track the change, and try to find */
/* following changes to it that could produce bugs */


bool upperToSmall(char *str){
  int i = 0;
  for(i = 0; str[i] != '\0'; i++) {
    if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] - 'A' + 'a';
    } else if ( str[i] < 'a' || str[i] > 'z') {
      return false;
    }
  }
  return true;
}


// Could be recursive
bool dictionarySmaller(char *str1, char *str2) {
  int i = 0;
  for(i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
    if(str2[i] < str1[i]) {
      return true;
    }
  }
  return false;
}


// Recursive version of this comparison

bool rDictionarySmaller(char *str1, char *str2) {
  if (*str1 == '\0') {
    return false;
  } else if (*str1 == '\0') {
    return true;
  }

  if(*str2 < *str1) {
    return true;
  } else if (*str2 > *str1) {
    return false;
  } else {
    return rDictionarySmaller(str1+1, str2+1);
  }
}



// I did not choose !Smaller because
// if they are the same 
bool rDictionaryLarger(char *str1, char *str2) {
  if (*str2 == '\0') {
    return false;
  } else if (*str1 == '\0') {
    return true;
  }

  if(*str2 > *str1) {
    return true;
  } else if (*str2 < *str1) {
    return false;
  } else {
    return rDictionaryLarger(str1+1, str2+1);
  }
}


// Set all the elements to 0
// ? Potential Problems?
void clearStr(char *str) {
  int i = 0;
  for(i = 0; str[i] != '\0' && str[i] != 0; i++) {
    str[i] = 0;
  }
  str[i] = 0;
}
  


int main(void){
  char inStr[40] = { 0 };
  char smallStr[40] = "z";
  char bigStr[40] =  "a";

  
  while(true){
    printf("Enter word: ");
    scanf("%s", inStr);
    printf("%s\n", inStr);


    // if inStr has 4 characters, break
    if(inStr[3] != '\0' && inStr[4] == '\0') {
      // First Check the first input
      if(smallStr[0] == 'z' || bigStr[0] == 'a') {
        
        printf("Please Don't Type Four Character Words for the first Input.\n");
        continue;
      } else {
        printf("Smallest word: %s\n", smallStr);
        printf("Largest word: %s\n", bigStr);
        break;
      }
    }

    if(upperToSmall(inStr)) {
      
      if(rDictionarySmaller(smallStr, inStr)) {
        // Clear inStr and move to tempStr
        clearStr(smallStr);
        strcpy(smallStr, inStr);
      }
      
      if(rDictionaryLarger(bigStr, inStr)) {
        clearStr(bigStr);
        strcpy(bigStr, inStr);
      }

      clearStr(inStr);

    } else {

      printf("Please Enter a valid Input.\n");
      continue;
    }
  }
 
  return 0;
}
