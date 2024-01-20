#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../include/binary_tree/new.h"
#include "../../include/binary_tree/crud/create.h"
#include "../../include/binary_tree/crud/delete.h"
#include "../../include/binary_tree/crud/read.h"

#define balancing_threshold


void show_hash_next_node(Node **linked_list_first_element, Node *node_hash_to_show);
void show_hash_previous_node(Node **linked_list_first_element, Node *node_hash_to_show);
Node *search_lowest_node_hash(Node *starting_node);


void balance_binary_tree(Node **linked_list_first_element) {

    printf("\nThere are %d nodes on the tree.\n", (*linked_list_first_element)->counter_node_passed_through + 1);

    if ((*linked_list_first_element)->node_lesser_hash != NULL)
    {
        printf("There are %d nodes on the left side of the tree.\n", (*linked_list_first_element)->node_lesser_hash->counter_node_passed_through + 1);
    }

    if ((*linked_list_first_element)->node_greater_hash != NULL)
    {
        printf("There are %d nodes on the right side of the tree.\n", (*linked_list_first_element)->node_greater_hash->counter_node_passed_through + 1);
    }
    
    
    printf("\nThe nodes from the root in an ascending order :\n\n");
    show_hash_next_node(linked_list_first_element, *linked_list_first_element);

    printf("The nodes from the root in a descending order :\n\n");
    show_hash_previous_node(linked_list_first_element, *linked_list_first_element);
    
    /*
    In order to balance the tree, we need to make sure that there are approximately, 
    if not exactly, the same number of nodes on both sides.
    To do this, we need to know the localisation of the middle node in the unbalanced region.

    We can estimate the position of the node in the list, who is in an ascending order
    by dividing the total number of nodes in the unbalanced 
    (cf: The number of nodes who passed through )area by 2 and rounding up to avoid
    a float.
    Here we have the index, on the list, of the central node of the unbalanced range 
    We can get to the middle node by starting a for loop through the list,
    starting at the node with the lowest hash.
    */

    // POC from the root node
    int middle_node_index_0 = (*linked_list_first_element)->counter_node_passed_through;
    printf("\nThe index of the middle node is : %d.\n", middle_node_index_0);

    int middle_node_index_1 = ((*linked_list_first_element)->counter_node_passed_through) + 1;
    printf("\nThe index of the middle node is : %d.\n", middle_node_index_1);

    int middle_node_index_2 = (((*linked_list_first_element)->counter_node_passed_through) + 1) / 2;
    printf("\nThe index of the middle node is : %d.\n", middle_node_index_2);

    int middle_node_index_3 = ceil((float)(((*linked_list_first_element)->counter_node_passed_through) + 1) / 2);
    printf("\nThe index of the middle node is : %d.\n", middle_node_index_3);

    //look up for the lowest hash :
    Node *lowest_node = search_lowest_node_hash(*linked_list_first_element);

    if (lowest_node == NULL) {
        printf("\nThe lowest node was not found.\n");
    } 
    else
    {
        printf("\nThe lowest node is :\n");
        print_node(*linked_list_first_element, lowest_node->hash_value);    
    }

    // look up for the middle node :
    Node *middle_node = lowest_node;
    for (int node_iterator = 0; node_iterator <= middle_node_index_3 - 2; ++node_iterator) {      
        if (middle_node->next_node != NULL) {
            middle_node = middle_node->next_node; 
        }
    }

    printf("\nThe middle node is, this node is the new root of the balanced tree :\n");
    print_node(*linked_list_first_element, middle_node->hash_value);
}


void show_hash_next_node(Node **linked_list_first_element, Node *node_hash_to_show) {
    //printf("Hash : %f.\n", node_hash_to_show->hash_value);
    print_node(*linked_list_first_element, node_hash_to_show->hash_value);

    if (node_hash_to_show->next_node != NULL)
    {
        show_hash_next_node(linked_list_first_element, node_hash_to_show->next_node);
    }
}


void show_hash_previous_node(Node **linked_list_first_element, Node *node_hash_to_show) {
    //printf("Hash : %f.\n", node_hash_to_show->hash_value);
    print_node(*linked_list_first_element, node_hash_to_show->hash_value);

    if (node_hash_to_show->previous_node != NULL)
    {
        show_hash_previous_node(linked_list_first_element, node_hash_to_show->previous_node);
    }
}

/**/
Node *search_lowest_node_hash(Node *starting_node) {
    if (starting_node->node_lesser_hash != NULL) 
    {
        return search_lowest_node_hash(starting_node->node_lesser_hash);
    }
    else if (starting_node->node_lesser_hash == NULL)
    {
        return starting_node;
    }

    return NULL;
}