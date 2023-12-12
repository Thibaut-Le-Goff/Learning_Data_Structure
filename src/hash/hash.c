#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

/*
This function convert a a string into an int whiwh is the 
concanetation of the ascii code of every charactere of 
the string
*/

float create_hash(char *table)
{

    if (table == NULL) {
        fprintf(stderr, "Error: Null pointer passed to create_hash.\n");
        return 0.0;
    }

    char result[100] = {'\0'};

    char *ptr_table = table;

    int array_iterator;
    for (array_iterator = 1; *(ptr_table + array_iterator) != '\0'; ++array_iterator) {        
        char characte[100];

        // pb : the int may be too long, a solution 
        //      is to substracte the numbers by pair
        sprintf(characte, "%d", abs(*(ptr_table + array_iterator - 1) - *(ptr_table + array_iterator)));

        // concatenation
        strcat(result, characte);
    }
    
    // conversion to a long double
    long double result_as_int = atof(result);

    // if the string is really long 
    int diminish_result_iterator;
    for (diminish_result_iterator = 1; diminish_result_iterator <= 1000; ++diminish_result_iterator) {
        if (result_as_int > 1000) 
        {
            result_as_int /= array_iterator;
        }
        else if (result_as_int <= 1000)
        {
            break;
        }
    }

    return (float)result_as_int;
}