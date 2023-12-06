#include <stdio.h>
#include <stdlib.h>
#include "../../include/linked_list/new.h"

Node *new_linked_list(int *value) 
{
    Node *first_node = malloc(sizeof(Node));

    first_node->node_greater_hash = NULL;
    first_node->node_lesser_hash = NULL;
    first_node->parent_node = NULL;

    first_node->value = *value;

    first_node->hash_value = *value;

    return first_node;
}