#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"

void print_node(Node *linked_list_first_element, int hash_node_to_print) {

    int num_max_jumps = 10;
    // 
    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= num_max_jumps; ++jump_thought_nodes)
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
            printf("Addr of the node : %p\n", (void *)linked_list_iterator_node);

            printf("Addr of the parent node : %p\n", (void *)linked_list_iterator_node->parent_node);

            if (linked_list_iterator_node->node_greater_hash != NULL) {
                printf("addr of node with a greater hash : %p\n", (void *)linked_list_iterator_node->node_greater_hash);       
            }

            if (linked_list_iterator_node->node_lesser_hash != NULL) {
                printf("addr of node with a lesser hash : %p\n", (void *)linked_list_iterator_node->node_lesser_hash);
            }

            printf("Value stored : %d\n", linked_list_iterator_node->value);
            printf("Hash : %d\n", linked_list_iterator_node->hash_value);

            break;
        }

        if (jump_thought_nodes == num_max_jumps) {
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.\n", num_max_jumps + 1);
        }
    }
}

// ----------------------- Recursion version ------------------------

void print_node_recursion(Node* linked_list_iterator_node, int hash_node_to_print) {

    if (linked_list_iterator_node == NULL) {
        fprintf(stderr, "Error : The node wanted was not found.\n");
    }

    if (hash_node_to_print > linked_list_iterator_node->hash_value)
    // if the node wanted has a hash value greater than the iterator node 
    {
        print_node_recursion(linked_list_iterator_node->node_greater_hash, hash_node_to_print);
        // We will iterate through the node with the larger hash. 
        // and continue the loop
    } 
    else if (hash_node_to_print < linked_list_iterator_node->hash_value)
    // if the node wanted has a hash value less than the 
    // iterator node
    {
        print_node_recursion(linked_list_iterator_node->node_lesser_hash, hash_node_to_print);
        // we will iterate through the node with the lower hash 
        // and continue the loop
    }
    else if (hash_node_to_print == linked_list_iterator_node->hash_value)
    // if the hash is the one of the one we are looking for
    {
        printf("Addr of the node : %p\n", (void *)linked_list_iterator_node);
        printf("Addr of the parent node : %p\n", (void *)linked_list_iterator_node->parent_node);

        if (linked_list_iterator_node->node_greater_hash != NULL) {
            printf("addr of node with a greater hash : %p\n", (void *)linked_list_iterator_node->node_greater_hash);       
        }

        if (linked_list_iterator_node->node_lesser_hash != NULL) {
            printf("addr of node with a lesser hash : %p\n", (void *)linked_list_iterator_node->node_lesser_hash);
        }

        printf("Value stored : %d\n", linked_list_iterator_node->value);
        printf("Hash : %d\n", linked_list_iterator_node->hash_value);
    }
}