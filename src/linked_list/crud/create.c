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

    // 
    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_trhought_nodes = 0; jump_trhought_nodes <= 1000; ++jump_trhought_nodes)
    {
        //printf("%d", jump_trhought_nodes);
        if (new_node->hash_value > linked_list_iterator_node->hash_value)
        // if the node created has a hash value higher than the 
        // iterator node 
        {
            if (linked_list_iterator_node->node_greater_hash == NULL)
            // if there are no node at the greater branche of the iterator node
            {
                linked_list_iterator_node->node_greater_hash = new_node;
                // the node created will take the place
                break;
                // and stop the loop 
            }
            else if (linked_list_iterator_node->node_greater_hash != NULL)
            // if there is already a node at the greater branche of the iterator node
            {
                linked_list_iterator_node = linked_list_iterator_node->node_greater_hash;
                // we will iterate through the node with a greater hash 
                // and continue the loop
            }
        } 
        else if (new_node->hash_value < linked_list_iterator_node->hash_value)
        // if the node created has a hash value lower than the 
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
            // if there is already a node at the lesser branche of the iterator node
            {
                linked_list_iterator_node = linked_list_iterator_node->node_lesser_hash;
                // we will iterate through the node with a lower hash 
                // and continue the loop
            }
        }
        else if (new_node->hash_value == linked_list_iterator_node->hash_value)
        // if there is a hash collision
        {
            printf("Error : Hash collision");

            // the node must be freed because its invalide
            free(new_node);
            break;
        }
    }
}
