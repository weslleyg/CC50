#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>

void main() {
  printf("M procurando F:\n");
  int M1 = GetInt();
  printf("F procurando M:\n");
  int F1 = GetInt();
  printf("F procurando F:\n");
  int F2 = GetInt();
  printf("M procurando M:\n");
  int M2 = GetInt();

  int soma = M1 + F1 + M2 + F2;
  float max = 20;

  float div = ((float)soma / (float)100);

  int calcM1 =  (float)M1 / div;
  int calcM2 =  (float)M2 / div;
  int calcF1 =  (float)F1 / div;
  int calcF2 =  (float)F2 / div;

  int maxM1 = ((float)calcM1 / (float)100) * max;
  int maxM2 = ((float)calcM2 / (float)100) * max;
  int maxF1 = ((float)calcF1 / (float)100) * max;
  int maxF2 = ((float)calcF2 / (float)100) * max;

  //printf("%i %i %i %i\n", maxM1, maxF1, maxM2, maxF2);

  for(unsigned i = 0; i < maxM1; i++) {
    printf("%c%c%c\n", 35,35,35);
  }

  printf("M-F\n\n");

  for(unsigned i = 0; i < maxF1; i++) {
    printf("%c%c%c\n", 35,35,35);
  }

  printf("F-M\n\n");

  for(unsigned i = 0; i < maxM2; i++) {
    printf("%c%c%c\n", 35,35,35);
  }

  printf("M-M\n\n");

  for(unsigned i = 0; i < maxF2; i++) {
    printf("%c%c%c\n", 35,35,35);
  }

  printf("F-F\n\n");

  // int calcM1 = 100 - ((((float)soma / (float)M1) -1) * 100);
  // int calcF1 = 100 - ((((float)soma / (float)F1) -1) * 100);
  // int calcF2 = (((float)soma / (float)F2) -1) * 100;
  // int calcM2 = (((float)soma / (float)M2) -1) * 100;
}