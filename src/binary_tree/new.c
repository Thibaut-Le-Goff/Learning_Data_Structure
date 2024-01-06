#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "../../include/binary_tree/new.h"

#include "../../include/hash/hash.h"


Node *new_binary_tree(float *value) 
{
    Node *first_node = malloc(sizeof(Node));

    // for the tree
    first_node->node_greater_hash = NULL;
    first_node->node_lesser_hash = NULL;
    first_node->parent_node = NULL;

    // for the linked list
    first_node->next_node = NULL;
    first_node->previous_node = NULL;

    first_node->counter_node_passed_through = 0;

    first_node->value = *value;

    first_node->hash_value = *value;
    //first_node->hash_value = create_hash((char*)value);

    return first_node;
}