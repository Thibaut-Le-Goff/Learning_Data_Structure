#include <stdio.h>
#include <stdlib.h>

#include "../../include/binary_tree/new.h"
#include "../../include/binary_tree/crud/read.h"


void show_hash_next_node(Node **linked_list_first_element, Node *node_hash_to_show);
void show_hash_previous_node(Node **linked_list_first_element, Node *node_hash_to_show);


void balance_binary_tree(Node **linked_list_first_element) {

    printf("\nThere are %d nodes on the tree.\n", (*linked_list_first_element)->counter_node_passed_through + 1);

    if ((*linked_list_first_element)->node_lesser_hash != NULL)
    {
        printf("There are %d nodes on the left side of the tree.\n", (*linked_list_first_element)->node_lesser_hash->counter_node_passed_through + 1);
    }

    if ((*linked_list_first_element)->node_greater_hash != NULL)
    {
        printf("There are %d nodes on the right side of the tree.\n", (*linked_list_first_element)->node_greater_hash->counter_node_passed_through + 1);
    }

    printf("\nThe nodes from the root in an ascending order :\n\n");
    show_hash_next_node(linked_list_first_element, *linked_list_first_element);

    printf("The nodes from the root in a descending order :\n\n");
    show_hash_previous_node(linked_list_first_element, *linked_list_first_element);
}


void show_hash_next_node(Node **linked_list_first_element, Node *node_hash_to_show) {
    //printf("Hash : %f.\n", node_hash_to_show->hash_value);
    print_node(*linked_list_first_element, node_hash_to_show->hash_value);

    if (node_hash_to_show->next_node != NULL)
    {
        show_hash_next_node(linked_list_first_element, node_hash_to_show->next_node);
    }
}


void show_hash_previous_node(Node **linked_list_first_element, Node *node_hash_to_show) {
    //printf("Hash : %f.\n", node_hash_to_show->hash_value);
    print_node(*linked_list_first_element, node_hash_to_show->hash_value);

    if (node_hash_to_show->previous_node != NULL)
    {
        show_hash_previous_node(linked_list_first_element, node_hash_to_show->previous_node);
    }
}