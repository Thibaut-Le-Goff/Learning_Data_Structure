#include <stdio.h>
#include "../../../include/linked_list/new.h"

//print_node(int *hash_node_to_print, Node *) {
void print_node(Node *node_to_print) {

    if (node_to_print->node_greater_hash != NULL) {
        printf("addr of node with a greater hash : %p\n", node_to_print->node_greater_hash);       
    }

    if (node_to_print->node_lesser_hash != NULL) {
        printf("addr of node with a lesser hash : %p\n", node_to_print->node_lesser_hash);
    }

    printf("Value stored : %d\n", node_to_print->value);
    printf("Hash : %d\n", node_to_print->hash_value);
}

/*
struct Node {
        
    Node *node_greater_hash;
    Node *node_lesser_hash;

    int value;

    int hash_value;
};
*/