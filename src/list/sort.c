#include <stdlib.h>
#include <stdio.h>

#include "../../include/binary_tree/new.h"

/*
We need to sort the node in as ascending order
in order to balance the tree, here we take advantage
of the binary tree algorithm :

- Before the new node goes to the greater path we see if
the new node is smaller than the node considered to 
be the next node of the iterator node, to see if the new
one is closer to the iterator than the actual next node 
of the iterator node.

- Before the new node goes to the lesser path we see if
the new node is greater than the node considered to 
be the previous node of the iterator node, to see if the new
one is closer to the iterator nodes than the actual previous 
node of the iterator node.
*/

void determination_previous_node_of_new_node(Node *linked_list_iterator_node, Node *new_node) {

    // we know the hash of the new node is greater than the hash
    // of the iterator, but we must know if its closer to it
    // than the actual next_node (lower in that case)

    if ( (linked_list_iterator_node->next_node != NULL) &&
         (new_node->hash_value < linked_list_iterator_node->next_node->hash_value) )
    // if there is already a node considered as the next node
    // and if the hash of the new node is lesser than the one
    // of the next node.
    {
        // the node must fit between two node :

        ///// from the side of the iterator next node :
        // the iterator next node recognize the new node 
        // as its previous node
        linked_list_iterator_node->next_node->previous_node = new_node;
        // the new node recognize the iterator next node as
        // its next
        new_node->next_node = linked_list_iterator_node->next_node;


        ///// from the side of the iterator node :
        // the iterator node recognize the new node 
        // as its next node
        linked_list_iterator_node->next_node = new_node;
        // the new node recognize the iterator node as
        // its previous
        new_node->previous_node = linked_list_iterator_node;
    }
    else if (linked_list_iterator_node->next_node == NULL)
    // if there is no node as the next node
    {
        // the iterator node recognize the new node 
        // as its next node
        linked_list_iterator_node->next_node = new_node;

        // the new node recognize the iterator node as
        // its previous
        new_node->previous_node = linked_list_iterator_node;
    }
}


void determination_next_node_of_new_node(Node *linked_list_iterator_node, Node *new_node) {

    // we know the hash of the new node is lesser than the hash
    // of the iterator, but we must know if its closer to it
    // than the actual previous_node (greater in that case)

    if ( (linked_list_iterator_node->previous_node != NULL) &&
         (new_node->hash_value > linked_list_iterator_node->previous_node->hash_value) )
    // if there is already a node considered as the previous node
    // and if the hash of the new node is greater than the one
    // of the previous node.
    {
        // the node must fit between two node :

        ///// from the side of the iterator previous node :
        // the iterator next node recognize the new node 
        // as its previous node
        linked_list_iterator_node->previous_node->next_node = new_node;
        // the new node recognize the iterator previous node as
        // its previous
        new_node->previous_node = linked_list_iterator_node->previous_node;


        ///// from the side of the iterator node :
        // the iterator node recognize the new node 
        // as its previous node
        linked_list_iterator_node->previous_node = new_node;
        // the new node recognize the iterator node as
        // its next
        new_node->next_node = linked_list_iterator_node;
    }
    else if (linked_list_iterator_node->previous_node == NULL)
    // if there is no node as the previous node
    {
        // the iterator node recognize the new node 
        // as its previous node
        linked_list_iterator_node->previous_node = new_node;

        // the new node recognize the iterator node as
        // its next
        new_node->next_node = linked_list_iterator_node;
    }
}
