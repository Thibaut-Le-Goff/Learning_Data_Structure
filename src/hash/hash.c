#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <math.h> 

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
    int sum_ascii_characters = 0;


    int array_iterator;
    for (array_iterator = 1; *(table + array_iterator) != '\0'; ++array_iterator) {        
        char characte[100];

        // pb : the int may be too long, a solution 
        //      is to substracte the numbers by pair
        sprintf(characte, "%d", abs(*(table + array_iterator - 1) - *(table + array_iterator)));

        // concatenation
        strcat(result, characte);

        // test and uftu have the same hash without it
        sum_ascii_characters += *(table + array_iterator - 1);
    }
    
    
    // conversion to a long double
    long double result_as_int = atof(result);


    // if the string is really long
    int diminish_result_iterator;
    for (diminish_result_iterator = 0; diminish_result_iterator <= 1000; ++diminish_result_iterator) {
        if (result_as_int > 500)
        {
            // test and uftu have the same hash without it
            result_as_int += (sin(sum_ascii_characters) * 100);

            result_as_int /= array_iterator;
        }
        else if (result_as_int <= 1000)
        {
            break;
        }
    }

    // test and uftu have the same hash without it
    if (sum_ascii_characters % 2 == 0) {
        return (float)-result_as_int;
    } 
    else
    {
        return (float)result_as_int;
    }
}