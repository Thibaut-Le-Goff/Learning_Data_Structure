#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../../include/binary_tree/new.h"
#include "../../../include/binary_tree/crud/read.h"

void examine_tree_stdr(Node *first_node_binary_tree) {

    fprintf(stderr, "\nThere has been a problem during the creation of the tree:\n");

    fprintf(stderr, "\nThere are %d nodes on the tree.\n", first_node_binary_tree->counter_node_passed_through + 1);

    if (first_node_binary_tree->node_lesser_hash != NULL)
    {
        fprintf(stderr, "There are %d nodes on the left side of the tree.\n", first_node_binary_tree->node_lesser_hash->counter_node_passed_through + 1);
    }

    if (first_node_binary_tree->node_greater_hash != NULL)
    {
        fprintf(stderr, "There are %d nodes on the right side of the tree.\n", first_node_binary_tree->node_greater_hash->counter_node_passed_through + 1);
    }

    fprintf(stderr, "\nThe nodes from the root in an ascending order :\n\n");
    show_next_node_stdr(first_node_binary_tree, first_node_binary_tree);

    fprintf(stderr, "The nodes from the root in a descending order :\n\n");
    show_previous_node_stdr(first_node_binary_tree, first_node_binary_tree);
}