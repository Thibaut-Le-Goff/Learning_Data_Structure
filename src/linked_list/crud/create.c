/**/
#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"

void create_node(Node *linked_list_first_element, int *value) {

    // creation of the new node
    Node *new_node = malloc(sizeof(Node));

    new_node->node_greater_hash = NULL;
    new_node->node_lesser_hash = NULL;

    new_node->value = *value;

    new_node->hash_value = *value;

    int num_max_jumps = 10;

    // 
    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_trhought_nodes = 0; jump_trhought_nodes <= num_max_jumps; ++jump_trhought_nodes)
    {
        if (new_node->hash_value > linked_list_iterator_node->hash_value)
        // if the node created has a hash value greater than the iterator node 
        {
            if (linked_list_iterator_node->node_greater_hash == NULL)
            // if there are no node on the greater branch of the iterator node
            {
                linked_list_iterator_node->node_greater_hash = new_node;
                // the node created will take the place
                break;
                // and stop the loop 
            }
            else if (linked_list_iterator_node->node_greater_hash != NULL)
            // if there is already a node on the greater branch of the iterator node
            {
                linked_list_iterator_node = linked_list_iterator_node->node_greater_hash;
                // We will iterate through the node with the larger hash. 
                // and continue the loop
            }
        } 
        else if (new_node->hash_value < linked_list_iterator_node->hash_value)
        // if the node created has a hash value less than the 
        // iterator node
        {
            if (linked_list_iterator_node->node_lesser_hash == NULL)
            // if there are no node at the lesser branche of the iterator node
            {
                linked_list_iterator_node->node_lesser_hash = new_node;
                // the node created will take the place
                break;
                // and stop the loop 
            }
            else if (linked_list_iterator_node->node_lesser_hash != NULL)
            // if there is already a node on the lesser branche of the iterator node
            {
                linked_list_iterator_node = linked_list_iterator_node->node_lesser_hash;
                // we will iterate through the node with the lower hash 
                // and continue the loop
            }
        }
        else if (new_node->hash_value == linked_list_iterator_node->hash_value)
        // if there is a hash collision
        {
            printf("Error : Hash collision");

            // the node must be freed because it is invalid
            free(new_node);
            break;
        }

        if (jump_trhought_nodes == (num_max_jumps - 1)) {
            printf("Error : The node created was not able to find a place to fit in %d jumps.", num_max_jumps);
            free(new_node);
        }
    }
}
