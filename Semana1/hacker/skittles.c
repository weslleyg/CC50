#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cc50.h>

int main(void) {

  srand(time(NULL));
  int skittles = rand() % 1024;

  printf("Olá, tente adivinhar quantos skittles tem na maquina: \n");
  int chute = GetInt();

  if(chute < 0) {
    printf("Vamos la! voce consegue fazer melhor.\n");
  }

  if(chute > 1024) {
    printf("Muito alto! tente um numero abaixo de 1023. \n");
  }

  for(int i = 0; chute != skittles; i++) {
    printf("Voce errou! tente novamente: \n");
    chute = GetInt();

    if(chute < 0) {
      printf("Vamos la! voce consegue fazer melhor.\n");
    }

    if(chute > 1024) {
      printf("Muito alto! tente um numero abaixo de 1023. \n");
    }

    if(chute == skittles) {
      printf("Parabens voce acertou!!!!\n");
    }
  }

}