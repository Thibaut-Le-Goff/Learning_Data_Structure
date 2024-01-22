#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <math.h> 

#define MODULO_TREE 1000

/*
This function convert a a string into an int whiwh is the 
concanetation of the ascii code of every charactere of 
the string
*/

int create_hash_tree(char *table) {
    int sum_xor_ascii_characters = 0;
    int array_iterator = 1;

    for (array_iterator = 1; *(table + array_iterator) != '\0'; ++array_iterator) {        
        sum_xor_ascii_characters += *(table + array_iterator - 1) ^ *(table + array_iterator);
    }

    if (array_iterator % 2 == 0) {
        return -((sum_xor_ascii_characters - array_iterator) % MODULO_TREE);
    } 
    else
    {
        return (sum_xor_ascii_characters - array_iterator) % MODULO_TREE;
    }
}


int create_hash_table(char *table, int *length_array) {
    int sum_xor_ascii_characters = 0;
    int array_iterator;

    for (array_iterator = 1; *(table + array_iterator) != '\0'; ++array_iterator) {        
        sum_xor_ascii_characters += *(table + array_iterator - 1) ^ *(table + array_iterator);
    }

    return (sum_xor_ascii_characters - array_iterator) % *length_array;
}
