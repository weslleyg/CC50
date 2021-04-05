/****************************************************************************
 * tolower.c
 *
 * CC50
 * Gabriel Lima Guimar�es
 *
 * Converte um char de uppercase para lowercase.
 *
 * Demonstra operadores bitwise.
 ***************************************************************************/
       
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>


int
main(void)
{
    // pega um char mai�sculo do usu�rio
    char c;
    do
    {
        printf("Caracter mai�sculo por favor: ");
        c = GetChar();
    }
    while (c < 'A' || c > 'Z');

    // imprime o char min�sculo
    printf("%c\n", c & 0x20);

    return 0;
}
