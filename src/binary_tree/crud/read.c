#include <stdio.h>
#include <stdlib.h>
#include "../../../include/binary_tree/new.h"

#define NUM_MAX_JUMPS 100

void show_node(Node *node_to_show);


void print_node(Node *linked_list_first_element, float hash_node_to_print) {

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
            show_node(linked_list_iterator_node);
            break;
        }
        else
        {
            fprintf(stderr, "Error : The node wanted does not have a hash value.\n");
        }

        if (jump_thought_nodes == NUM_MAX_JUMPS) {
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.\n", NUM_MAX_JUMPS);
        }
    }
}

// ----------------------- Recursion version ------------------------

void print_node_recursion(Node* linked_list_iterator_node, float hash_node_to_print) {

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
        show_node(linked_list_iterator_node);
    }
}



void show_node(Node *node_to_show) {

    printf("Addr of the node : %p\n", (void *)node_to_show);

    if (node_to_show->parent_node != NULL) {
        printf("Addr of the parent node on the tree : %p\n", (void *)node_to_show->parent_node);
    }

    if (node_to_show->node_greater_hash != NULL) {
        printf("addr of node with a greater hash on the tree : %p\n", (void *)node_to_show->node_greater_hash);       
    }

    if (node_to_show->node_lesser_hash != NULL) {
        printf("addr of node with a lesser hash on the tree : %p\n", (void *)node_to_show->node_lesser_hash);
    }

    if (node_to_show->next_node != NULL) {
        printf("addr of the next node on the list : %p\n", (void *)node_to_show->next_node);       
    }

    if (node_to_show->previous_node != NULL) {
        printf("addr of the previous node on the list : %p\n", (void *)node_to_show->previous_node);
    }

    printf("The number of nodes who passed through this one is : %d\n", node_to_show->counter_node_passed_through);

    printf("Value stored : %f\n", node_to_show->value);
    printf("Hash : %f\n\n", node_to_show->hash_value);
}



void show_node_stdr(Node *node_to_show) {

    fprintf(stderr, "Addr of the node : %p\n", (void *)node_to_show);

    if (node_to_show->parent_node != NULL) {
        fprintf(stderr, "Addr of the parent node on the tree : %p\n", (void *)node_to_show->parent_node);
    }

    if (node_to_show->node_greater_hash != NULL) {
        fprintf(stderr, "addr of node with a greater hash on the tree : %p\n", (void *)node_to_show->node_greater_hash);       
    }

    if (node_to_show->node_lesser_hash != NULL) {
        fprintf(stderr, "addr of node with a lesser hash on the tree : %p\n", (void *)node_to_show->node_lesser_hash);
    }

    if (node_to_show->next_node != NULL) {
        fprintf(stderr, "addr of the next node on the list : %p\n", (void *)node_to_show->next_node);       
    }

    if (node_to_show->previous_node != NULL) {
        fprintf(stderr, "addr of the previous node on the list : %p\n", (void *)node_to_show->previous_node);
    }

    fprintf(stderr, "The number of nodes who passed through this one is : %d\n", node_to_show->counter_node_passed_through);

    fprintf(stderr, "Value stored : %f\n", node_to_show->value);
    fprintf(stderr, "Hash : %f\n\n", node_to_show->hash_value);
}
