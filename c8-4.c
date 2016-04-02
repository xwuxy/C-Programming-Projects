#include <stdio.h>

/* Please notice that for this program, */
/* since the file name is under convention */
/* c8-3 will replace reverse as the program */
/* name */
  
int main(int argc ,char *argv[]) {
  int i = 0;
  for(i = argc - 1; i > 0; i--) {
    printf("%s ", argv[i]);
  }
  printf("\n");
  return 0;
}
