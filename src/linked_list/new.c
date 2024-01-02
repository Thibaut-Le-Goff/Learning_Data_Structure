#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "../../include/linked_list/new.h"

#include "../../include/hash/hash.h"


Node *new_linked_list(float *value) 
{
    Node *first_node = malloc(sizeof(Node));

    first_node->node_greater_hash = NULL;
    first_node->node_lesser_hash = NULL;
    first_node->parent_node = NULL;

    first_node->counter_node_passed_throught = 0;

    first_node->value = *value;

    first_node->hash_value = *value;
    //first_node->hash_value = create_hash((char*)value);

    return first_node;
}