/****************************************************************************
 * binary.c
 *
 * CC50
 * Gabriel Lima Guimar�es
 *
 * Mostra um n�mero em bin�rio.
 *
 * Demonstra operadores bitwise.
 ***************************************************************************/
       
#include <cs50.h>
#include <stdio.h>


int
main(void)
{
    // pega um n�mero do usu�rio
    int n;
    do
    {
        printf("Inteiro n�o negativo por favor: ");
        n = GetInt();
    }
    while (n < 0);

    // imprime o n�mero em bin�rio
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        int mask = 1 << i;
        if (n & mask)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
