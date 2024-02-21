#include <stdio.h>
#include <stdlib.h>

#include "../../../include/binary_tree/new.h"
#include "../../../include/binary_tree/crud/read.h"

#include "../../../include/binary_tree/crud/operations/put.h"
#include "../../../include/binary_tree/crud/operations/extract.h"

#include "../../../include/list/sort.h"

#include "../../../include/hash/create_hash.h"

#include "../../../include/stdr_outputs/binary_tree/collision.h"

#define NUM_MAX_JUMPS 100

//void collision_case(Node *linked_list_iterator_node);

void create_node(Node *linked_list_first_element, float *value) {

    // creation of the new node
    Node *new_node = malloc(sizeof(Node));

    // for the tree
    new_node->node_greater_hash = NULL;
    new_node->node_lesser_hash = NULL;
    new_node->parent_node = NULL;

    // for the linked list
    new_node->next_node = NULL;
    new_node->previous_node = NULL;

    new_node->counter_node_passed_through = 0;

    new_node->value = *value;

    new_node->hash_value = *value;
    //new_node->hash_value = create_hash((char*)value);

    put_node(linked_list_first_element, new_node);
}


// ----------------- recursion version --------------------

//void find_place_node(Node *linked_list_iterator_node, Node *new_node);

void create_node_recursion(Node *linked_list_first_element, float *value) {

    // creation of the new node
    Node *new_node = malloc(sizeof(Node));

    // for the tree
    new_node->node_greater_hash = NULL;
    new_node->node_lesser_hash = NULL;
    new_node->parent_node = NULL;

    // for the linked list
    new_node->next_node = NULL;
    new_node->previous_node = NULL;

    new_node->counter_node_passed_through = 0;

    new_node->value = *value;

    new_node->hash_value = *value;

    // find the place to put the new node
    put_node_recursion(linked_list_first_element, new_node);
}
