#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../../include/binary_tree/new.h"
#include "../../../include/binary_tree/crud/read.h"


void examine_node(Node *node_to_examine);


void collision_warning(Node *node_responsible_for_collision, Node *node_victim_of_collision, char *function_name) {

    time_t current_time;
    time(&current_time);

    fprintf(stderr, "\nA collision has occurred at %s, at the function %s.\n\n", ctime(&current_time), function_name);

    fprintf(stderr, "The node responsible for the collision and its neighbours are :\n");
    examine_node(node_responsible_for_collision);

    fprintf(stderr, "\nThe node victim of the collision and its neighbours are :\n");
    examine_node(node_victim_of_collision);
}


void examine_node(Node *node_to_examine) {

    fprintf(stderr, "The node to examine is :\n");
    show_node_stdr(node_to_examine);

    fprintf(stderr, "Its parent is :\n");
    if (node_to_examine->parent_node != NULL)
    {
        show_node_stdr(node_to_examine->parent_node);
    }
    else
    {
        fprintf(stderr, "The node doesn't have parent.\n");
    }

    fprintf(stderr, "Its greater node is :\n");
    if (node_to_examine->node_greater_hash != NULL) 
    {
        show_node_stdr(node_to_examine->node_greater_hash);
    }
    else
    {
        fprintf(stderr, "The node doesn't have a node at its greater branche.\n");
    }

    fprintf(stderr, "Its lesser node is :\n");
    if (node_to_examine->node_lesser_hash != NULL)
    {
        show_node_stdr(node_to_examine->node_lesser_hash);
    }
    else
    {
        fprintf(stderr, "The node doesn't have a node at its lesser branche.\n");
    }

    fprintf(stderr, "Its previous node is :\n");
    if (node_to_examine->previous_node != NULL) 
    {
        show_node_stdr(node_to_examine->previous_node);
    }
    else
    {
        fprintf(stderr, "The node doesn't have a previous node.\n");
    }

    fprintf(stderr, "Its next node is :\n");
    if (node_to_examine->next_node != NULL)
    {
        show_node_stdr(node_to_examine->next_node);
    }
    else
    {
        fprintf(stderr, "The node doesn't have a next node.\n");
    }
}