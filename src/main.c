#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list/new.h"
#include "../include/linked_list/crud/read.h"
#include "../include/linked_list/crud/create.h"

#include "../include/binary_tree/search.h"

int main() {
    int value = 50;

    Node *first_node = new_linked_list(&value);

    printf("Before the creation of a second node :\n");
    print_node(first_node);

    //int first_node1[] = {15, 6, 20, 9, 5};
    //int lenght_array = sizeof(first_node1) / sizeof(first_node1[0]);
    //printf("taille : %d\n", lenght_array);

    //search(first_node1, &lenght_array);
    //printf("%d\n", first_node1[5]);
    //printf("%d\n", first_node1[6]);

    int seconde_value = 40;

    create_node(first_node, &seconde_value);

    printf("\nAfter the creation of a second node :\n");
    print_node(first_node);

    printf("\nThe seconde node :\n");
    print_node(first_node->node_lesser_hash);

    free(first_node->node_lesser_hash);
    free(first_node);
}