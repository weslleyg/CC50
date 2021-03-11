#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  string pass = argv[1];

  if(argc == 1 || argc == 3) {
    return 1;
  }

  printf("%s %i", pass, argc);

} 