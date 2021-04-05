/****************************************************************************
 * toupper.c
 *
 * CC50
 * Gabriel Lima Guimar�es
 *
 * Converte um char lowercase para uppercase.
 *
 * Demonstra operadores bitwise.
 ***************************************************************************/
       
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>


int
main(void)
{
    // pega um char min�sculo do usu�rio
    char c;
    do
    {
        printf("Caracter min�sculo por favor: ");
        c = GetChar();
    }
    while (c < 'a' || c > 'z');

    // imprime o char mai�sculo
    printf("%c\n", c & 0xdf);

    return 0;
}
