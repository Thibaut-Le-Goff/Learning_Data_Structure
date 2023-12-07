#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"
#include "../../../include/linked_list/crud/read.h"

void leaf_node_case(Node *linked_list_iterator_node);

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
        // if the hash is the one of the node we are looking for
        {
            if ((linked_list_iterator_node->node_greater_hash == NULL) && (linked_list_iterator_node->node_lesser_hash == NULL))
            // if the node to delete is a leaf node
            {
                printf("the node %p to delete is a leaf node.\n", (void *)linked_list_iterator_node);
                leaf_node_case(linked_list_iterator_node);
            }
            else if ((linked_list_iterator_node->node_greater_hash != NULL) || (linked_list_iterator_node->node_lesser_hash != NULL))
            // if the node to delete is a parent node
            {
                printf("the node %p to delete is not a leaf node.\n\n", (void *)linked_list_iterator_node);
            }

            free(linked_list_iterator_node);
            break;
        }

        if (jump_thought_nodes == num_max_jumps) 
        {
            printf("Error : The node wanted was not found in %d jumps.", num_max_jumps + 1);
        }
    }
}



void leaf_node_case(Node *linked_list_iterator_node)
{
    if (linked_list_iterator_node->parent_node == NULL)
    {
        printf("this is the root node");
    }            
    else if (linked_list_iterator_node->hash_value > linked_list_iterator_node->parent_node->hash_value)
    // if the node to be deleted is on the larger branch of its parent
    {
        printf("the node %p is the great child of the node %p\n\n", (void *)linked_list_iterator_node->parent_node->node_greater_hash, (void *)linked_list_iterator_node->parent_node);
        linked_list_iterator_node->parent_node->node_greater_hash = NULL;
        // we redirect the pointer to null to avoid referencing an invalid address    
    }
    else if (linked_list_iterator_node->hash_value < linked_list_iterator_node->parent_node->hash_value)
    // if the node to be deleted is on the lower branch of its parent
    {
        printf("the node %p is the lesser child of the node %p\n\n", (void *)linked_list_iterator_node->parent_node->node_lesser_hash, (void *)linked_list_iterator_node->parent_node);
        linked_list_iterator_node->parent_node->node_lesser_hash = NULL;
        // we redirect the pointer to null to avoid referencing an invalid address    
    } 
}
