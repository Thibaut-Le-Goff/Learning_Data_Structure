#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"
#include "../../../include/linked_list/crud/read.h"


void leaf_node_case(Node *linked_list_iterator_node);
void parent_node_case(Node *linked_list_iterator_node);


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
            if ( (linked_list_iterator_node->node_greater_hash == NULL) && 
                 (linked_list_iterator_node->node_lesser_hash == NULL) &&
                 (linked_list_iterator_node->parent_node != NULL) )
            // if the node to delete is a leaf node :
            // it has no child but has a parent
            {
                leaf_node_case(linked_list_iterator_node);
            }
            else if ( (linked_list_iterator_node->node_greater_hash != NULL) || 
                      (linked_list_iterator_node->node_lesser_hash != NULL) )
            // if the node to delete is a parent node :
            // it has at least one child
            {
                parent_node_case(linked_list_iterator_node);
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



void leaf_node_case(Node *node_to_delete)
{
    if (node_to_delete->hash_value > node_to_delete->parent_node->hash_value)
    // if the node to be deleted is on the larger branch of its parent
    {
        node_to_delete->parent_node->node_greater_hash = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the parent
        
        node_to_delete->parent_node = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the children
    }
    else if (node_to_delete->hash_value < node_to_delete->parent_node->hash_value)
    // if the node to be deleted is on the lower branch of its parent
    {
        node_to_delete->parent_node->node_lesser_hash = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the parent

        node_to_delete->parent_node = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the children
    } 
}


/**/
void parent_node_case(Node *node_to_delete)
{
    printf("Node parent à suprimer %p", (void *)node_to_delete);

    /**/
    // The node to replace the node to delete must be the next higher one
    if (node_to_delete->node_greater_hash->node_lesser_hash == NULL)
    // if the node on the greater branch does not have a lesser child
    // that mean the next higher hash is this one
    {
        // the node who will replace the node to delete will inherit his pointer
        node_to_delete->node_greater_hash->node_lesser_hash = node_to_delete->node_lesser_hash;
        node_to_delete->node_greater_hash->parent_node = node_to_delete->parent_node;
        // except the one who point to his greater branch because it would mean
        // to create a pointer who point to its value

        // the pointer coming from the node to delete have been inherit to
        // to the replacement node.

        // but there still the node who point to the node to delete

        node_to_delete->node_lesser_hash->parent_node = node_to_delete->node_greater_hash;
        // The greater child become the parent of its previous siter

        node_to_delete->parent_node->node_greater_hash = node_to_delete->node_greater_hash;
        // the parent of the node to delete adopt its greater child

        // finaly, we set all pointer of the node to delete to null :
        node_to_delete->parent_node = NULL;
        node_to_delete->node_lesser_hash = NULL;
        node_to_delete->node_greater_hash = NULL;
    }
    /*
    int num_max_jumps = 10;
    Node *iterator_node_next_sup = node_to_delete;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= num_max_jumps; ++jump_thought_nodes)
    {
        iterator_node_next_sup
    }*/
}
