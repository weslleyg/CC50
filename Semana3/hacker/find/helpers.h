/****************************************************************************
 * helpers.h
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
 
#include <cc50.h>


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int values[], int n);

int
binarySearch(int values[], int first, int lastOne, int value);


/*
 * Sorts array of n values.  Returns true if
 * successful, else false.
 */

bool
sort(int values[], int n);
