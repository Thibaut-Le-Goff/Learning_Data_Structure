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
    print_node(first_node, &value);

    int seconde_value = 60;
    create_node(first_node, &seconde_value);

    printf("\nAfter the creation of a second node :\n");
    print_node(first_node, &value);

    printf("\nThe seconde node :\n");
    print_node(first_node, &seconde_value);

    int thrid_value = 55;
    create_node(first_node, &thrid_value);

    printf("\nThe seconde node after the creation of a thrid node :\n");
    print_node(first_node, &seconde_value);

    printf("\nThe thrid node :\n");
    print_node(first_node, &thrid_value);

    int fourth_value = 4;
    create_node(first_node, &fourth_value);

    printf("\nThe first node after the creation of a fourth node :\n");
    print_node(first_node, &value);

    printf("\nThe fourth node :\n");
    print_node(first_node, &fourth_value);

    free(first_node->node_greater_hash->node_lesser_hash);
    free(first_node->node_greater_hash);
    free(first_node->node_lesser_hash);
    free(first_node);
}