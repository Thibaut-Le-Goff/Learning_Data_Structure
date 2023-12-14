#include <stdio.h>
#include <stdlib.h>
#include "../../../include/linked_list/new.h"
#include "../../../include/linked_list/crud/read.h"

#define NUM_MAX_JUMPS 10

void leaf_node_case(Node *linked_list_iterator_node);
void parent_node_case(Node *linked_list_iterator_node);


void delete_node(Node *linked_list_first_element, int hash_node_to_delete) {

    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS; ++jump_thought_nodes)
    {
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
            if ( (linked_list_iterator_node->node_greater_hash == NULL) && 
                 (linked_list_iterator_node->node_lesser_hash == NULL) &&
                 (linked_list_iterator_node->parent_node != NULL) )
            // if the node to delete is a leaf node :
            // it has no child but has a parent
            {
                leaf_node_case(linked_list_iterator_node);
            }
            else if ( (linked_list_iterator_node->node_greater_hash != NULL) || 
                      (linked_list_iterator_node->node_lesser_hash != NULL) )
            // if the node to delete is a parent node :
            // it has at least one child
            {
                parent_node_case(linked_list_iterator_node);
            }

            free(linked_list_iterator_node);
            break;
        }

        if (jump_thought_nodes == NUM_MAX_JUMPS) 
        {
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.", jump_thought_nodes + 1);
        }
    }
}


// ---------------------------------------- leaf_node_case -------------------------------------------------------------------


void leaf_node_case(Node *node_to_delete)
{
    if (node_to_delete->hash_value > node_to_delete->parent_node->hash_value)
    // if the node to be deleted is on the larger branch of its parent
    {
        node_to_delete->parent_node->node_greater_hash = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the parent
        
        node_to_delete->parent_node = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the children
    }
    else if (node_to_delete->hash_value < node_to_delete->parent_node->hash_value)
    // if the node to be deleted is on the lower branch of its parent
    {
        node_to_delete->parent_node->node_lesser_hash = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the parent

        node_to_delete->parent_node = NULL;
        // the node to delete is disconnected from its parent
        // from the side of the children
    }
}


// --------------------------------------- parent_node_case --------------------------------------------------------------------


void from_greater_to_lesser_path(Node *node_to_delete);
void from_lesser_to_greater_path(Node *node_to_delete);

void remplacement_of_node(Node *node_to_delete, Node *remplacement_node);

void parent_node_case(Node *node_to_delete)
{
    printf("Node parent à suprimer %p", (void *)node_to_delete);

    /**/
    // The node to replace the node to delete must be the next higher one
    if (node_to_delete->node_lesser_hash == NULL)
    // if the node to delete, does not 
    // have a lesser child that mean the next higher hash is the one 
    // on the greater branche or the lesser one 

    // if the node on the greater branch, of the node to delete
    // have a lesser child that mean the next higher hash is the
    // one with the lesser hash on the lesser path
    {
        from_greater_to_lesser_path(node_to_delete);
    }
    else if (node_to_delete->node_greater_hash == NULL)
    // if the node to delete, does not 
    // have a greater child that mean the next higher hash is the one 
    // on the greater branche or the lesser one 

    // if the node on the greater branch, of the node to delete
    // have a lesser child that mean the next higher hash is the
    // one with the lesser hash on the lesser path
    {
        from_lesser_to_greater_path(node_to_delete);
    }
}


// --------------------------------------- from_greater_to_lesser_path --------------------------------------------------------------------


void from_greater_to_lesser_path(Node *node_to_delete) {
        
    Node *linked_list_iterator_node = node_to_delete->node_greater_hash;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS; ++jump_thought_nodes)
    // we will iterate through the nodes by the lesser path because 
    // the less hash value in this path is the next greater hash after 
    // the hash to delete (because we are starting by its greater branche)
    {
        if (linked_list_iterator_node->node_lesser_hash == NULL)
        // if there are no lesser hash, the iterator node 
        // is considered to be the node of remplacement
        {
            Node *remplacement_node = linked_list_iterator_node;
            remplacement_of_node(node_to_delete, remplacement_node);
            break;
        }
        else if (linked_list_iterator_node->node_lesser_hash != NULL)
        // if there are a lesser hash, the iterator node 
        // is considered to have a hash value greater than 
        // another node, this is not the next greater node 
        // of the node to delete, the iteration continu
        {
            linked_list_iterator_node = linked_list_iterator_node->node_lesser_hash;
        }
         
        if (jump_thought_nodes == NUM_MAX_JUMPS)
        {
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.", jump_thought_nodes + 1);
        }
    }
}


// --------------------------------------- from_lesser_to_greater_path --------------------------------------------------------------------


void from_lesser_to_greater_path(Node *node_to_delete) {
        
    Node *linked_list_iterator_node = node_to_delete->node_lesser_hash;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS; ++jump_thought_nodes)
    // we will iterate through the nodes by the lesser path because 
    // the less hash value in this path is the next greater hash after 
    // the hash to delete (because we are starting by its greater branche)
    {
        if (linked_list_iterator_node->node_greater_hash == NULL)
        // if there are no lesser hash, the iterator node 
        // is considered to be the node of remplacement
        {
            Node *remplacement_node = linked_list_iterator_node;
            remplacement_of_node(node_to_delete, remplacement_node);
            break;
        }
        else if (linked_list_iterator_node->node_greater_hash != NULL)
        // if there are a lesser hash, the iterator node 
        // is considered to have a hash value greater than 
        // another node, this is not the next greater node 
        // of the node to delete, the iteration continu
        {
            linked_list_iterator_node = linked_list_iterator_node->node_greater_hash;
        }
         
        if (jump_thought_nodes == NUM_MAX_JUMPS) 
        {
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.", jump_thought_nodes + 1);
        }
    }
}


// --------------------------------------- remplacement_of_node --------------------------------------------------------------------


void remplacement_of_node(Node *node_to_delete, Node *remplacement_node) {

    // the node who will replace the node to delete will inherit his pointe
    if ( (node_to_delete->node_lesser_hash != NULL) && 
         (node_to_delete->node_lesser_hash != remplacement_node) )
    // if the node to delete have a lesser child
    // who is not the node of replacement 
    // (to prevent the node to delete to give a pointer who 
    // point to the greater child to itself)
    {
        remplacement_node->node_lesser_hash = node_to_delete->node_lesser_hash;
        // the sister becam his lesser child
        node_to_delete->node_lesser_hash->parent_node = remplacement_node;
        // The greater child become the parent of its previous siter

        node_to_delete->node_lesser_hash = NULL;
    }

    if ( (node_to_delete->node_greater_hash != NULL) && 
         (node_to_delete->node_greater_hash != remplacement_node) )
    // if the node to delete has a greater child 
    // who is not the node of replacement 
    // (to prevent the node to delete to give a pointer who 
    // point to the greater child to itself)
    {
        remplacement_node->node_greater_hash = node_to_delete->node_greater_hash;
        // the sister becam his greater child
        node_to_delete->node_greater_hash->parent_node = remplacement_node;
        // The greater child become the parent of its previous siter

        node_to_delete->node_greater_hash = NULL;
    }

    if (node_to_delete->parent_node != NULL)
    // if the node to delete has a parent
    // if the node to delete is not the root node
    {
        remplacement_node->parent_node = node_to_delete->parent_node;
        // the remplacement node recognize the parent of the node 
        // to delete as its parent
        node_to_delete->parent_node->node_greater_hash = remplacement_node;
        // the parent of the node to delete adopt its greater child    
        
        node_to_delete->parent_node = NULL;
    }
    //if else (node_to_delete->parent_node == NULL)
    // if the node to delete is the root node
    //{}
}