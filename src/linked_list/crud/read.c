#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"

void print_node(Node *linked_list_first_element, int *hash_node_to_print) {

    int num_max_jumps = 10;
    // 
    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_trhought_nodes = 0; jump_trhought_nodes <= num_max_jumps; ++jump_trhought_nodes)
    {
        if (*hash_node_to_print > linked_list_iterator_node->hash_value)
        // if the node wanted has a hash value greater than the iterator node 
        {
            linked_list_iterator_node = linked_list_iterator_node->node_greater_hash;
            // We will iterate through the node with the larger hash. 
            // and continue the loop
        } 
        else if (*hash_node_to_print < linked_list_iterator_node->hash_value)
        // if the node wanted has a hash value less than the 
        // iterator node
        {
            linked_list_iterator_node = linked_list_iterator_node->node_lesser_hash;
            // we will iterate through the node with the lower hash 
            // and continue the loop
        }
        else if (*hash_node_to_print == linked_list_iterator_node->hash_value)
        // if there is a hash collision
        {
            printf("Addr of the node : %p\n", linked_list_iterator_node);

            if (linked_list_iterator_node->node_greater_hash != NULL) {
                printf("addr of node with a greater hash : %p\n", linked_list_iterator_node->node_greater_hash);       
            }

            if (linked_list_iterator_node->node_lesser_hash != NULL) {
                printf("addr of node with a lesser hash : %p\n", linked_list_iterator_node->node_lesser_hash);
            }

            printf("Value stored : %d\n", linked_list_iterator_node->value);
            printf("Hash : %d\n", linked_list_iterator_node->hash_value);

            break;
        }

        if (jump_trhought_nodes == (num_max_jumps - 1)) {
            printf("Error : The node wanted was not found in %d jumps.", num_max_jumps);
        }
    }
}


/*
void print_node(Node *node_to_print) {
    printf("Addr of the node : %p\n", node_to_print);

    if (node_to_print->node_greater_hash != NULL) {
        printf("addr of node with a greater hash : %p\n", node_to_print->node_greater_hash);       
    }

    if (node_to_print->node_lesser_hash != NULL) {
        printf("addr of node with a lesser hash : %p\n", node_to_print->node_lesser_hash);
    }

    printf("Value stored : %d\n", node_to_print->value);
    printf("Hash : %d\n", node_to_print->hash_value);
}
*/