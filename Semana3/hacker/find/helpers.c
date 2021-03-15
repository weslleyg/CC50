/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cc50.h>
#include <stdio.h>

#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int array[], int n)
{
    // TODO: re-implement as binary search
    for (int i = 0; i < n; i++)
        if (array[i] == value)
            return true;
    return false;
}


/*
 * Sorts array of n values.  Returns true if
 * successful, else false.
 */

bool
sort(int values[], int n)
{   
    int maior = 0;
    //loop para comparar cada posição
    for(int count = 1; count < n; count++) {
        //loop para compara o numero de uma posição com todas as outas
        for(int i = 0; i < n - 1; i++) {
            if(values[i] > values[i + 1]) {
                maior = values[i];

                values[i] = values[i +1];

                values[i+1] = maior;
            }
        }
    }
    //imprimi cada posição do array ordenado
    for(int i = 0; i < n; i++) {
        printf(" %i ", values[i]);
    }

    return false;
}
