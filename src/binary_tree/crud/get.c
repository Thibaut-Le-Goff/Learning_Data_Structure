#include <stdio.h>
#include <stdlib.h>
#include "../../../include/binary_tree/new.h"

#define NUM_MAX_JUMPS 100


Node *get_node(Node *linked_list_first_element, float hash_node_to_print) {

    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_thought_nodes = 1; jump_thought_nodes <= NUM_MAX_JUMPS; ++jump_thought_nodes)
    {
        if (hash_node_to_print > linked_list_iterator_node->hash_value)
        // if the node wanted has a hash value greater than the iterator node 
        {
            linked_list_iterator_node = linked_list_iterator_node->node_greater_hash;
            // We will iterate through the node with the larger hash. 
            // and continue the loop
        } 
        else if (hash_node_to_print < linked_list_iterator_node->hash_value)
        // if the node wanted has a hash value less than the 
        // iterator node
        {
            linked_list_iterator_node = linked_list_iterator_node->node_lesser_hash;
            // we will iterate through the node with the lower hash 
            // and continue the loop
        }
        else if (hash_node_to_print == linked_list_iterator_node->hash_value)
        // if the hash is the one of the one we are looking for
        {
            return linked_list_iterator_node;
        }
        else
        {
            fprintf(stderr, "Error : The node wanted does not have a hash value.\n");
        }

        if (jump_thought_nodes == NUM_MAX_JUMPS) {
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.\n", NUM_MAX_JUMPS);
        }
    }

    return NULL;
}

// ----------------------- Recursion version ------------------------

Node *get_node_recursion(Node* linked_list_iterator_node, float hash_node_to_print) {

    if (linked_list_iterator_node == NULL) {
        return NULL;
    }

    if (hash_node_to_print > linked_list_iterator_node->hash_value)
    // if the node wanted has a hash value greater than the iterator node 
    {
        return get_node_recursion(linked_list_iterator_node->node_greater_hash, hash_node_to_print);
        // We will iterate through the node with the larger hash. 
        // and continue the loop
    } 
    else if (hash_node_to_print < linked_list_iterator_node->hash_value)
    // if the node wanted has a hash value less than the 
    // iterator node
    {
        return get_node_recursion(linked_list_iterator_node->node_lesser_hash, hash_node_to_print);
        // we will iterate through the node with the lower hash 
        // and continue the loop
    }
    else if (hash_node_to_print == linked_list_iterator_node->hash_value)
    // if the hash is the one of the one we are looking for
    {
        return linked_list_iterator_node;
    }

    return NULL;
}