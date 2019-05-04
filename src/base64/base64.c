#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Make sure to download these files from libb64 and compile them at the same time as this one! */
#include "b64/cdecode.h"

char* decode(const char* input)
{
	char* output = (char*)malloc(256);
	char* c = output;
	int cnt = 0;
	base64_decodestate s;

	base64_init_decodestate(&s);
	cnt = base64_decode_block(input, strlen(input), c, &s);
	c += cnt;

	/* Null-terminate the string */
	*c = 0;
	return output;
}

int main(int argc, char *argv[])
{
  char b64string[256];
  if(argc == 1) {
    /* No arguments, do interactively instead */
    printf("Enter encoded string: ");
    scanf("%s", b64string);
  }
  else {
    strcpy(b64string, argv[1]);
  }

  char* ptstring;
  ptstring = decode(b64string);

  printf("%s\n", ptstring);

  return 1;
}
