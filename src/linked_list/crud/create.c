#include <stdio.h>
#include <stdlib.h>

#include "../../../include/linked_list/new.h"

#include "../../../include/hash/hash.h"


#define NUM_MAX_JUMPS 100

void create_node(Node *linked_list_first_element, float *value) {

    // creation of the new node
    Node *new_node = malloc(sizeof(Node));

    new_node->node_greater_hash = NULL;
    new_node->node_lesser_hash = NULL;
    new_node->parent_node = NULL;

    new_node->counter_node_passed_throught = 0;

    new_node->value = *value;

    new_node->hash_value = *value;
    //new_node->hash_value = create_hash((char*)value);

//----------------------------------------------------------------------------------------------

    // find the place to put the new node
    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS - 1; ++jump_thought_nodes)
    {

        // the fact the node created passed throught the iterator node is notified :
        ++linked_list_iterator_node->counter_node_passed_throught;

        if (new_node->hash_value > linked_list_iterator_node->hash_value)
        // if the node created has a hash value greater than the iterator node 
        {
            if (linked_list_iterator_node->node_greater_hash == NULL)
            // if there are no node on the greater branch of the iterator node
            {
                // the node created will take the place
                new_node->parent_node = linked_list_iterator_node;
                // connection from the new node to its parent
                linked_list_iterator_node->node_greater_hash = new_node;
                // connection from the parent node to its child 
                // at the greater branche
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
                // the node created will take the place
                new_node->parent_node = linked_list_iterator_node;
                // connection from the new node to its parent
                linked_list_iterator_node->node_lesser_hash = new_node;
                // connection from the parent node to its child 
                // at the lesser branche
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
            fprintf(stderr, "Error : Hash collision");

            // the node must be freed because it is invalid
            free(new_node);
            break;
        }

        if (jump_thought_nodes == NUM_MAX_JUMPS) {
            fprintf(stderr, "Error : The node created was not able to find a place to fit in %d jumps.", NUM_MAX_JUMPS);
            free(new_node);
        }
    }
}


// ----------------- recursion version --------------------

void find_place_node(Node *linked_list_iterator_node, Node *new_node);

void create_node_recursion(Node *linked_list_first_element, float *value) {

    // creation of the new node
    Node *new_node = malloc(sizeof(Node));

    new_node->node_greater_hash = NULL;
    new_node->node_lesser_hash = NULL;
    new_node->parent_node = NULL;

    new_node->counter_node_passed_throught = 0;

    new_node->value = *value;

    new_node->hash_value = *value;

    // find the place to put the new node
    find_place_node(linked_list_first_element, new_node);
}


void find_place_node(Node *linked_list_iterator_node, Node *new_node) {

    if (linked_list_iterator_node == NULL) {
        fprintf(stderr, "Error : The node created was not able to find a place to fit.");
        free(new_node);
    }

    // the fact the node created passed throught the iterator node is notified :
    ++linked_list_iterator_node->counter_node_passed_throught;

    if (new_node->hash_value > linked_list_iterator_node->hash_value)
    // if the node created has a hash value greater than the iterator node 
    {
        if (linked_list_iterator_node->node_greater_hash == NULL)
        // if there are no node on the greater branch of the iterator node
        {
            // the node created will take the place
            new_node->parent_node = linked_list_iterator_node;
            // connection from the new node to its parent
            linked_list_iterator_node->node_greater_hash = new_node;
            // connection from the parent node to its child 
            // at the greater branche
        }
        else if (linked_list_iterator_node->node_greater_hash != NULL)
        // if there is already a node on the greater branch of the iterator node
        {
            find_place_node(linked_list_iterator_node->node_greater_hash, new_node);
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
            // the node created will take the place
            new_node->parent_node = linked_list_iterator_node;
            // connection from the new node to its parent
            linked_list_iterator_node->node_lesser_hash = new_node;
            // connection from the parent node to its child 
            // at the lesser branche
        }
        else if (linked_list_iterator_node->node_lesser_hash != NULL)
        // if there is already a node on the lesser branche of the iterator node
        {
            find_place_node(linked_list_iterator_node->node_lesser_hash, new_node);
            // we will iterate through the node with the lower hash 
            // and continue the loop
        }
    }
    else if (new_node->hash_value == linked_list_iterator_node->hash_value)
    // if there is a hash collision
    {
        fprintf(stderr, "Error : Hash collision");

        // the node must be freed because it is invalid
        free(new_node);
    }
}
