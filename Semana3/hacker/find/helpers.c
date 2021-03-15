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
    int result = binarySearch(array, 0, n, value);

    if(result == value) {
        return true;
    } else {
        return false;
    }
}

int binarySearch(int values[], int first, int lastOne, int value) 
{
    int media = (first + lastOne) / 2;
    
    if(values[media] == value) {
        return values[media];
    }

    if(values[first] == values[lastOne]) {
        return values[first];
    } else if(values[media] < value) {
        return binarySearch(values, media +1, lastOne ,value);
    } else {
        return binarySearch(values, first, media -1, value);
    }
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
    for(int count = 1; count < n; count++) 
    {
        //loop para compara o numero de uma posição com todas as outas
        for(int i = 0; i < n - 1; i++) 
        {
            if(values[i] > values[i + 1]) 
            {
                maior = values[i];

                values[i] = values[i +1];

                values[i+1] = maior;
            }
        }
    }
    //compara se está ordenado
    for(int i = 0; i < n -1; i++) 
    {
        if(values[i] > values[i +1]) 
        {
            return false;
        }
    }

    return true;
}
