#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
      printf("Usage: recover infile\n");
      return 1;
    }

    char *infile = argv[2];

    FILE *inptr = fopen(infile, "r");
    if(inptr == NULL) {
      printf("Could not open %s\n", inptr);
      return 2;
    }

    char *buffer;
    fread(&buffer, 512, 1, inptr);

    if(buffer[0] == 0xff &&
       buffer[1] == 0xd8 &&
       buffer[2] == 0xff &&
       (buffer[3] & 0xf0) == 0xe0) {
         printf("tste");
       }
}