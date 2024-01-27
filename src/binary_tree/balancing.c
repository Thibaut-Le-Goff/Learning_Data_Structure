#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../include/binary_tree/new.h"
#include "../../include/binary_tree/crud/create.h"
#include "../../include/binary_tree/crud/delete.h"
#include "../../include/binary_tree/crud/read.h"
#include "../../include/binary_tree/crud/get.h"

#define balancing_threshold 1


void show_hash_next_node(Node **linked_list_first_element, Node *node_hash_to_show);
void show_hash_previous_node(Node **linked_list_first_element, Node *node_hash_to_show);
Node *search_lowest_node_hash(Node *starting_node);

void find_middle_node_area(Node *new_root_balanced_tree, Node *first_node_in_area, int *min_area, int *max_area);

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
    int middle_node_index = ceil((float)(((*linked_list_first_element)->counter_node_passed_through) + 1) / 2);
    printf("\nThe index of the middle node is : %d.\n", middle_node_index);

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
    Node *new_root_balanced_tree = lowest_node;
    for (int node_iterator = 2; node_iterator <= middle_node_index; ++node_iterator) {      
        if (new_root_balanced_tree->next_node != NULL) {
            new_root_balanced_tree = new_root_balanced_tree->next_node;
        }
    }

    printf("\nThe middle node is, this node is the new root of the balanced tree :\n");
    print_node(*linked_list_first_element, new_root_balanced_tree->hash_value);

    // create the new tree 

    /*
    We have the new root for the creation of, but, wee still need to 
    find the next nodes to add to the new tree, we can't putt them in
    a random order.

    For this we need to repeat the same algorithme made to fin the
    root on both sides, that mean creating a function that is caling 
    itself two time.*/
    

    int min_lesser_area = 0;
    Node *first_node_lesser_area = lowest_node;
    int max_lesser_area = middle_node_index - 1;

    printf("\nThe first node of the lesser area, between the index %d and %d is :\n", min_lesser_area, max_lesser_area);
    print_node(*linked_list_first_element, first_node_lesser_area->hash_value);

    find_middle_node_area(*linked_list_first_element, first_node_lesser_area, &min_lesser_area, &max_lesser_area);


    int min_greater_area = middle_node_index + 1;
    Node *first_node_greater_area = new_root_balanced_tree->next_node;
    int max_greater_area = (*linked_list_first_element)->counter_node_passed_through + 1;

    printf("\nThe first node of the greater area, between the index %d and %d is :\n",  min_greater_area, max_greater_area);
    print_node(*linked_list_first_element, first_node_greater_area->hash_value);

    find_middle_node_area(*linked_list_first_element, first_node_greater_area, &min_greater_area, &max_greater_area);
}

/**/
void find_middle_node_area(Node *linked_list_first_element, Node *first_node_in_area, int *min_area, int *max_area) {
        
    int middle_node_index = ceil((float)((*max_area - *min_area) / 2));
    printf("\nThe index of the middle node is : %d.\n", middle_node_index);
    
    //if ((middle_node_index >= 1) && (middle_node->next_node != NULL))
    if (middle_node_index >= 1)
    {
        // look up for the middle node :
        Node *middle_node = first_node_in_area;
        for (int node_iterator = 2; node_iterator <= middle_node_index; ++node_iterator) {
            if (middle_node->next_node != NULL) {
                middle_node = middle_node->next_node; 
            }
        }

        printf("\nThe middle node, with the index %d, is between the area %d and %d is :\n", middle_node_index, *min_area, *max_area);
        print_node(linked_list_first_element, middle_node->hash_value);

        int *min_lesser_area = min_area;
        Node *first_node_lesser_area = first_node_in_area;
        int max_lesser_area = middle_node_index - 1;

        find_middle_node_area(linked_list_first_element, first_node_lesser_area, min_lesser_area, &max_lesser_area);

        if (middle_node->next_node != NULL)
        {
            int min_greater_area = middle_node_index + 1;
            Node *first_node_greater_area = middle_node->next_node;
            int *max_greater_area = max_area;

            find_middle_node_area(linked_list_first_element, first_node_greater_area, &min_greater_area, max_greater_area);
        }
    }
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