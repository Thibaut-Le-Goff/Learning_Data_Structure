/**/
#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"

void create_node(Node *linked_list_first_element, int *value) {

    // creation of the new node
    Node *new_node = malloc(sizeof(Node));

    new_node->node_greater_hash = NULL;
    new_node->node_lesser_hash = NULL;

    new_node->value = *value;

    new_node->hash_value = *value;

    // connection between the node created and the 
    // linked list 

    if (new_node->hash_value > linked_list_first_element->hash_value)
    {
        linked_list_first_element->node_greater_hash = new_node;
    }
    else if (new_node->hash_value < linked_list_first_element->hash_value)
    {
        linked_list_first_element->node_lesser_hash = new_node;
    }
}
