#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  
  printf("Insira o numero do cartao para validar: \n");
  unsigned long long numero = GetLongLong();

  unsigned int contagem;
  unsigned int n1, n2;
  unsigned int mult = 0, soma = 0;

  while(numero > 0) {
    const unsigned int digito = numero %10;
    
    ++contagem;
    
    n2 = n1;
    n1 = digito;
    
    soma = soma + (digito << mult) % 10 + (digito << mult) /10;
    
    mult = 1 - mult;

    numero = numero / 10;
  }

  soma = soma %10;

  if((0 == soma) && (15 == contagem) &&
    ((n1 == 3) && (n2 == 4) || (n2 == 7))) {
      printf("AMEX\n");
    } else if((0 == soma) && (16 == contagem) &&
                (n1 == 5) && (n2 >0) && (n2 <6)) {
                  printf("MASTERCARD\n");
    } else if ((0 == soma) && (16 == contagem) || (13 == contagem) &&
                (n1 == 4)) {
                  printf("VISA\n");
    } else {
      printf("INVALID\n");
    }
}