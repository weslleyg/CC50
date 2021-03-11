#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void crypto(char*, int);

int main(int argc, char *argv[]) {
  int k = atoi(argv[1]);
  FILE *f;
  char linha[1000];

  printf("Insira o nome do arquivo para criptografar: \n");
  string texto = GetString();

  f = fopen(texto, "r");
  if(!f) {
    return 2;
  }

  fgets(linha, 1000, f);

  crypto(linha, k);
}

void crypto(char *linha, int k) {
  int c = 0;

  for(int i = 0; i < strlen(linha); i++) {
    if(linha[i] == 32) {
      printf(" ");
    }

    if(linha[i] <= 90) {
      if((linha[i] + k) > 90) {
        c = linha[i] - 26;
        c = c + k;
        printf("%c", c);
      } else {
        c = linha[i] + k;

        printf("%c", c);
      }
    } else if((linha[i] + k) > 122) {
      c = linha[i] - 26;
      c = c + k;
      printf("%c", c);
    } else {
      c = linha[i] + k;

    printf("%c", c);
    }
  }
}