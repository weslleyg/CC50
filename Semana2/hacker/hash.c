#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>
#include <crypt.h>

int main(int argc, char *argv[]) {
  string pass = argv[1];
  string hash = crypt(pass, "50");

  printf("%s", hash);

  return 0;
}