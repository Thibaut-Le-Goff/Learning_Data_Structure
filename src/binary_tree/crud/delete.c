#include <stdio.h>
#include <stdlib.h>

#include "../../../include/binary_tree/new.h"
#include "../../../include/binary_tree/crud/read.h"

#include "../../../include/binary_tree/crud/operations/put.h"
#include "../../../include/binary_tree/crud/operations/extract.h"

#define NUM_MAX_JUMPS 100

/*

void leaf_node_case(Node *node_to_delete);
void parent_node_case(Node **linked_list_first_element, Node *node_to_delete);


void fill_gap_list(Node *node_to_delete);

void set_node_pointers_to_null(Node *node_to_delete);
*/

void delete_node(Node **linked_list_first_element, float hash_node_to_delete) {

    Node *linked_list_iterator_node = *linked_list_first_element;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS; ++jump_thought_nodes)
    {
        // we have to mdecrease the number of nodes who passed 
        // through the node in order to keep this number acurate
        // after the deletion of the node :
        --linked_list_iterator_node->counter_node_passed_through;

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
            // we disconect the node from the tree before freeing the node
            Node *node_to_delete = extract_node(linked_list_first_element, linked_list_iterator_node);            
            free(node_to_delete);
            break;
        }

        if (jump_thought_nodes == NUM_MAX_JUMPS)
        {
            fprintf(stderr, "Error : The node to delete was not found in %d jumps.", jump_thought_nodes);
        }
    }
}