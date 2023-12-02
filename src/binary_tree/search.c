#include <stdlib.h>
#include <stdio.h>

/*
Node search(Node first_node) {
    
}
*/

void search(int table[], int *lenght_array)
{
    for (int i = 0; i <= *lenght_array - 1; ++i) {
        printf("iterator = %d\n", i);
        printf("%d\n", table[i]);
    }
}