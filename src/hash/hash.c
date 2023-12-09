#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

/*
This function convert a a string into an int whiwh is the 
concanetation of the ascii code of every charactere of 
the string
*/

void create_hash(char table[], int *lenght_array)
{ 
    char result[20] = {'\0'};
    
    for (int i = 0; i <= *lenght_array - 3; ++i) {
        printf("iterator = %d\n", i);
        printf("%d\n", table[i]);
        
        char characte[20];

        sprintf(characte, "%d", table[i]);

        // pb : the int may be too long, a solution 
        //      is to substracte the numbers by pair
        //sprintf(characte, "%d", abs(table[i] - table[i + 1]));

        strcat(result, characte);
    }

    printf("Result: %s\n", result);
    
    long int cresult_as_int = atol(result); 
    printf("Result as an int : %ld\n", cresult_as_int);
}