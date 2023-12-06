#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"

void delete_node(Node *linked_list_first_element, int hash_node_to_delete) {

    int num_max_jumps = 10;
    // 
    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= num_max_jumps; ++jump_thought_nodes)
    {
        if (hash_node_to_delete > linked_list_iterator_node->hash_value)
        // if the node wanted has a hash value greater than the iterator node 
        {
            linked_list_iterator_node = linked_list_iterator_node->node_greater_hash;
            // We will iterate through the node with the larger hash. 
            // and continue the loop
        } 
        else if (hash_node_to_delete < linked_list_iterator_node->hash_value)
        // if the node wanted has a hash value less than the 
        // iterator node
        {
            linked_list_iterator_node = linked_list_iterator_node->node_lesser_hash;
            // we will iterate through the node with the lower hash 
            // and continue the loop
        }
        else if (hash_node_to_delete == linked_list_iterator_node->hash_value)
        // if the hash is the one of the one we are looking for
        {
            free(linked_list_iterator_node);
            break;
        }

        if (jump_thought_nodes == num_max_jumps) {
            printf("Error : The node wanted was not found in %d jumps.", num_max_jumps - 1);
        }
    }
}
