#include <stdio.h>
#include <stdlib.h>

#include "../../include/linked_list/new.h"

void balance_binary_tree(Node **linked_list_first_element) {


    printf("\nThere are %d nodes on the tree.\n", (*linked_list_first_element)->counter_node_passed_throught + 1);
    printf("There are %d nodes on the left side of the tree.\n", (*linked_list_first_element)->node_lesser_hash->counter_node_passed_throught + 1);
    printf("There are %d nodes on the right side of the tree.\n", (*linked_list_first_element)->node_greater_hash->counter_node_passed_throught + 1);

}