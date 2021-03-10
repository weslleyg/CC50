#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
  int k = atoi(argv[1]);
  FILE *f;
  char linha[1000];
  char c = [1000];

  printf("%i\n", k);
  printf("Insira o nome do arquivo para criptografar: \n");
  string texto = GetString();

  f = fopen(texto, "r");
  if(!f) {
    return 2;
  }

  fgets(linha, 1000, f);

  printf("%s", linha);
}