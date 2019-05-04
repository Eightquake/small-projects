#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* convertBaseToBase(char* str, int basefrom, int baseto);

int main(int argc, char *argv[])
{
  int bfrom, bto;
  char str[128];

  if(argc == 1) {
    /* No arguments, do interactively instead */
    printf("Enter what base to convert from: ");
    scanf("%d", &bfrom);
    printf("Enter what base to convert into: ");
    scanf("%d", &bto);
    printf("Enter what to convert: ");
    scanf("%s", str);
  }
  else if(argc == 4) {
    /* There are enough arguments to continue */
    bfrom = atoi(argv[1]);
    bto = atoi(argv[2]);
    strcpy(str, argv[3]);
  }
  else {
    /* There are arguments, but not enough to continue */
    fprintf(stderr, "Not enough arguments! Aborting...\n");
    return -1;
  }

  /* Time to do the actual conversion! */
  char* finished = convertBaseToBase(str, bfrom, bto); /* Straight from one base to the other */
  printf("%s\n", finished);
  free(finished); /* As the string has been malloc'd by the conversion function we need to free it */

  return 1;
}

char* convertBaseToBase(char* str, int basefrom, int baseto)
{
  int num = strtol(str, NULL, basefrom);
  int neededDigits = floor((log(num)/log(baseto)));
  int index = neededDigits;

  char* numberString;
  numberString = (char*) malloc(neededDigits); /* Malloc is in bytes, and numberString[index] accesses byte-sized so I will have to store each character in a byte */

  while(num > 0) {
    int d = num/baseto;
    int r = num%baseto;
    char ins;
    itoa(r, &ins, baseto);
    numberString[index] = ins;
    index--;
    num = d;
  }
  numberString[neededDigits+1] = '\0';
  return numberString;
}
