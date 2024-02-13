#include <stdio.h>
#include <stdlib.h>

#include "../../../include/binary_tree/new.h"
#include "../../../include/binary_tree/crud/create.h"
#include "../../../include/binary_tree/crud/delete.h"
#include "../../../include/binary_tree/crud/read.h"
#include "../../../include/binary_tree/crud/get.h"

#include "../../../include/binary_tree/balanced_tree/operations/put.h"
#include "../../../include/binary_tree/balanced_tree/operations/extract.h"


#define BALANCING_THRESHOLD 1


void show_hash_next_node(Node **linked_list_first_element, Node *node_hash_to_show);
void show_hash_previous_node(Node **linked_list_first_element, Node *node_hash_to_show);

void find_middle_node_area(Node *root_node_balanced_tree, Node *linked_list_first_element, Node *first_node_in_area, int *min_area, int *max_area);

Node *balance_binary_tree(Node **linked_list_first_element) {

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
    show_next_node(*linked_list_first_element, *linked_list_first_element);

    printf("The nodes from the root in a descending order :\n\n");
    show_previous_node(*linked_list_first_element, *linked_list_first_element);
    
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


    ////// determinatioon of the root of the binary tree
    Node *lowest_node = get_lowest_node(*linked_list_first_element);
    if (lowest_node == NULL) {
        fprintf(stderr, "\nThe lowest node was not found.\n");
    }


    float middle_node_index = (float)((*linked_list_first_element)->counter_node_passed_through + 1) / 2;


    // rounding up the number
    int middle_node_index_rounded_up = (int)middle_node_index;

    if (middle_node_index > middle_node_index_rounded_up)
    // if the middle_node_index_rounded_up has numbers after the decimal point
    // it must be rounded up
    {
        middle_node_index_rounded_up++;
    }
    // end 


    // look up for the middle node :
    Node *middle_node = lowest_node;
    for (int node_iterator = 2; node_iterator <= middle_node_index_rounded_up; ++node_iterator) {
        if (middle_node->next_node != NULL) {
            middle_node = middle_node->next_node;
        }
    }

    printf("\nThe root node of the balanced tree, at the index %d, is:\n", middle_node_index_rounded_up);
    print_node(*linked_list_first_element, middle_node->hash_value);
    
    //Node *root_node_balanced_tree = create_balanced_tree(middle_node);
    Node *root_node_balanced_tree = extract_node(linked_list_first_element, middle_node);

    // call of the functions
    int min_area = 0;
    int max_area = middle_node_index_rounded_up - 1;

    Node *first_node_lesser_area = lowest_node;
    find_middle_node_area(root_node_balanced_tree, *linked_list_first_element, first_node_lesser_area, &min_area, &max_area);

    Node *first_node_greater_area = middle_node->next_node;
    find_middle_node_area(root_node_balanced_tree, *linked_list_first_element, first_node_greater_area, &min_area, &max_area);


    /*
    while (linked_list_first_element->counter_node_passed_through != 0) {
        e
    }
    */

    // Les nodes restants
    return root_node_balanced_tree;
}


/**/
void find_middle_node_area(Node *root_node_balanced_tree, Node *linked_list_first_element, Node *first_node_in_area, int *min_area, int *max_area) {
        
    float middle_node_index = (float)(*max_area - *min_area) / 2;



    // rounding up the number
    int middle_node_index_rounded_up = (int)middle_node_index;

    if (middle_node_index > middle_node_index_rounded_up)
    // if the middle_node_index_rounded_up has numbers after the decimal point
    // it must be rounded up
    {
        middle_node_index_rounded_up++;
    }
    // end



    printf("\n\nThe index of the middle node is : %d because (%d - %d) / 2 = %f before being rounded up.\n", middle_node_index_rounded_up, *max_area, *min_area, middle_node_index);
    
    // look up for the middle node :
    Node *middle_node = first_node_in_area;
    for (int node_iterator = 2; node_iterator <= middle_node_index_rounded_up; ++node_iterator) {
        if (middle_node->next_node != NULL) {
            middle_node = middle_node->next_node;
        }
    }

    printf("\nThe middle node of this area is :\n");
    print_node(linked_list_first_element, middle_node->hash_value);


    if (middle_node_index_rounded_up > 1)
    {
        int min_area = 0;
        Node *first_node_lesser_area = first_node_in_area;
        int max_area = middle_node_index_rounded_up - 1;

        //printf("The lesser area, is between %d and %d.\n", min_area, max_area);

        find_middle_node_area(root_node_balanced_tree, linked_list_first_element, first_node_lesser_area, &min_area, &max_area);

        if (middle_node->next_node != NULL)
        {
            Node *first_node_greater_area = middle_node->next_node;

            //printf("The greater area, is between %d and %d.\n", min_area, max_area);

            find_middle_node_area(root_node_balanced_tree, linked_list_first_element, first_node_greater_area, &min_area, &max_area);
        }
    }
}
