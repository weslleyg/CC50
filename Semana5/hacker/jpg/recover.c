#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
      printf("Usage: recover infile\n");
      return 1;
    }

    char *infile = argv[1];

    FILE* inptr = fopen(infile, "r");
    if(inptr == NULL) {
      fclose(inptr);
      printf("Could not open %s\n", inptr);
      return 2;
    }

    int jpgcount = 0;
    int open = 0;

    uint8_t buffer[512];
    uint8_t checkheader1[4] = {0xff, 0xd8, 0xff, 0xe0};
    uint8_t checkheader2[4] = {0xff, 0xd8, 0xff, 0xe1};
    uint8_t check[4];
 
    FILE* outptr;
    fread(buffer, 512, 1, inptr);

    while(fread(buffer, 512, 1, inptr) > 0) {
      for(int i = 0; i < 4; i++) {
        check[i] = buffer[i];
      }

      if(memcmp(checkheader1, check, 4) == 0 || memcmp(checkheader2, check, sizeof(check)) == 0) {
          char filename[8];
          sprintf(filename, "%03i", jpgcount);

          if(open == 0) {
            outptr = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, outptr);
            open = 1;
          }

          if(open == 1) {
            fclose(outptr);
            outptr = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, outptr);
            jpgcount++;
          }
      } else if(open == 1) {
        fwrite(buffer, sizeof(buffer), 1, outptr);
      }
    }

    if(outptr) {
      fclose(outptr);
    }

    fclose(inptr);
    return 0;
}