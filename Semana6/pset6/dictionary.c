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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define N 100

typedef struct node 
{
    char word[LENGTH + 1];
    struct node *next;
} 
node;

node *table[N];

int strcasecmp(const char *s1, const char *s2)
{
    int offset,ch;
    unsigned char a,b;

    offset = 0;
    ch = 0;
    while( *(s1+offset) != '\0' )
    {
        /* check for end of s2 */
        if( *(s2+offset)=='\0')
            return( *(s1+offset) );

        a = (unsigned)*(s1+offset);
        b = (unsigned)*(s2+offset);
        ch = toupper(a) - toupper(b);
        if( ch<0 || ch>0 )
            return(ch);
        offset++;
    }

    return(ch);
}


/*
 * Returns true if word is in dictionary else false.
 */

bool
check(const char *word)
{
    int value = 0;
    int hash;

    for(int i = 0; word[i] != '\0'; i++)
    {
        value = value + tolower(word[i]);
    }

    hash = value%N;

    node *cursor = table[hash];

    while(cursor != NULL)
    {
        int x = strcasecmp(cursor->word, word);

        if(x == 0) 
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

/*
 *  Function hash
 */

int count = 0;

unsigned int hashFunc(const char *word)
{
    int value = 0;
    count++;

    for(int i = 0; word[i] != '\0'; i++)
    {
        value = value + tolower(word[i]);
    }

    return value%N;
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
    int index = 0;

    while(fscanf(file, "%s", word) != EOF) 
    {
        node *n = malloc(sizeof(node));
        if(n == NULL) {
            unload();
            return 1;
        }

        strcpy(n->word, word);
        index = hashFunc(word);

        n->next = table[index];
        table[index] = n;
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
    return count;
}


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool
unload(void)
{
    int buckets = 0;
    while(buckets < N)
    {
        while(table[buckets] != NULL) 
        {
            node *temp = table[buckets];
            table[buckets] = table[buckets]->next;
            free(temp);
        }
        buckets = buckets + 1;
    }

    return true;
}
