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
    // int menor = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
    
        count = values[i + 1];

        if(values[i] > count) {
            if(count == 0) {
                count = values[i];
            }

            values[i + 1] = values[i];
            values[i] = count;
        } else {
            count = values[i];
        }
        printf("%i", values[i]);

        printf("count: %i ", count);
    }

    return false;
}


// enquanto i não comparar com todas posições faça