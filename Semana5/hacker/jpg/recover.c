#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

    uint8_t buffer[512];
    uint8_t checkheader1[4] = {0xff, 0xd8, 0xff, 0xe0};
    uint8_t checkheader2[4] = {0xff, 0xd8, 0xff, 0xe1};
 
    if(buffer[0] == 0xff &&
       buffer[1] == 0xd8 &&
       buffer[2] == 0xff &&
       (buffer[3] & 0xf0) == 0xe0);
    
    char *filename;

    sprintf(filename, "#03i.jpg", 2);

    FILE *img = fopen(filename, "w");
    
}