/****************************************************************************
 * dictionary.c
 *
 * CC50
 * Pset 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

typedef struct node 
{
    char word[LENGTH + 1];
    struct node *next;
} node;


/*
 * Returns true if word is in dictionary else false.
 */

bool
check(const char *word)
{
    // TODO
    return false;
}


/*
 * Loads dict into memory.  Returns true if successful else false.
 */

bool
load(const char *dict)
{
    FILE *file = fopen(dict,"r");
    if(!file) 
    {
        unload();
        return 1;
    }

    char word[LENGTH + 1];
    int index;

    while(fscanf(file, "%s", word) != EOF) 
    {
        node *n = malloc(sizeof(node));
        if(n == NULL) {
            unload();
            return 1;
        }

        strcpy(n->word, word);
    }
    fclose(file);


    return true;
}


/*
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int
size(void)
{
    // TODO
    return 0;
}


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool
unload(void)
{
    // TODO
    return false;
}
