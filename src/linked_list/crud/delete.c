#include <stdio.h>
#include <stdlib.h>

#include "../../../include/linked_list/new.h"
#include "../../../include/linked_list/crud/read.h"

#define NUM_MAX_JUMPS 100


void leaf_node_case(Node *node_to_delete);
void parent_node_case(Node **linked_list_first_element, Node *node_to_delete);


void delete_node(Node **linked_list_first_element, float hash_node_to_delete) {

    Node *linked_list_iterator_node = *linked_list_first_element;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS - 1; ++jump_thought_nodes)
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
                //printf("enfant");
                leaf_node_case(linked_list_iterator_node);
            }
            else if ( (linked_list_iterator_node->node_greater_hash != NULL) || 
                      (linked_list_iterator_node->node_lesser_hash != NULL) )
            // if the node to delete is a parent node :
            // it has at least one child
            {
                //printf("parent");
                parent_node_case(linked_list_first_element, linked_list_iterator_node);
            }
            /*
            else
            {
                printf("racine");
            }

            printf("\n");*/

            /*
            there is a third case when the node does not 
            have parent nor children.
            In that case its the only one node of the linked list
            its point to nothing and nothing point to it
            it can be freed right away
            */

            free(linked_list_iterator_node);
            break;
        }

        if (jump_thought_nodes == NUM_MAX_JUMPS) 
        {
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.", jump_thought_nodes);
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


void from_greater_node_to_smallest_hash(Node **linked_list_first_element, Node *node_to_delete);
void from_lesser_node_to_biggest_hash(Node **linked_list_first_element, Node *node_to_delete);

void replacement_of_node(Node **linked_list_first_element, Node *node_to_delete, Node *replacement_node);


void parent_node_case(Node **linked_list_first_element, Node *node_to_delete)
{
    /**/
    // The node to replace the node to delete must be the next higher one
    if ( (node_to_delete->node_lesser_hash == NULL) ||
    // if the node to delete, does not have a lesser 
    // child that mean the next higher hash is the one 
    // on the greater branche with the lesser hash
         (node_to_delete->node_lesser_hash != NULL &&
         node_to_delete->node_greater_hash != NULL) )
    // or if the node to delete has a greater and a esser child 
    {
        // we will look for the smallest hash 
        // from the greater child
        from_greater_node_to_smallest_hash(linked_list_first_element, node_to_delete);
    }
    else if (node_to_delete->node_greater_hash == NULL)
    // if the node to delete, does not have a greater 
    // child that mean the next higher hash is the one 
    // on the lesser branche with the greater hash 
    {
        // we will look for the biggest hash 
        // from the lesser child
        from_lesser_node_to_biggest_hash(linked_list_first_element, node_to_delete);
    }
}


// --------------------------------------- from_greater_node_to_smallest_hash --------------------------------------------------------------------


void from_greater_node_to_smallest_hash(Node **linked_list_first_element, Node *node_to_delete) {
        
    Node *linked_list_iterator_node = node_to_delete->node_greater_hash;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS; ++jump_thought_nodes)
    // we will iterate through the nodes by the lesser path because 
    // the smallest hash value in this path is the next greater hash after 
    // the hash to delete (because we are starting by its greater branche)
    {
        if (linked_list_iterator_node->node_lesser_hash == NULL)
        // if there are no lesser hash, the iterator node 
        // is considered to be the node of remplacement
        {
            Node *replacement_node = linked_list_iterator_node;
            replacement_of_node(linked_list_first_element, node_to_delete, replacement_node);
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
            fprintf(stderr, "Error : The node wanted was not found in %d jumps.", jump_thought_nodes);
        }
    }
}


// --------------------------------------- from_lesser_node_to_biggest_hash --------------------------------------------------------------------


void from_lesser_node_to_biggest_hash(Node **linked_list_first_element, Node *node_to_delete) {
      
    Node *linked_list_iterator_node = node_to_delete->node_lesser_hash;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= NUM_MAX_JUMPS; ++jump_thought_nodes)
    // we will iterate through the nodes by the greater path because 
    // the biggest hash value in this path is the next greater hash after
    // the hash to delete (because we are starting by its lesser branche)
    {
        if (linked_list_iterator_node->node_greater_hash == NULL)
        // if there are no greater hash, the iterator node 
        // is considered to be the node of remplacement
        {
            Node *replacement_node = linked_list_iterator_node;
            replacement_of_node(linked_list_first_element, node_to_delete, replacement_node);
            break;
        }
        else if (linked_list_iterator_node->node_greater_hash != NULL)
        // if there are a greater hash, the iterator node 
        // is considered to have a hash value smaller than 
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




// --------------------------------------- replacement_of_node --------------------------------------------------------------------


void path_redirection(Node *replacement_node);
//void path_redirection(Node *node_to_delete, Node *replacement_node);

void lesser_child_inheritance(Node *node_to_delete, Node *replacement_node);
void greater_child_inheritance(Node *node_to_delete, Node *replacement_node);
void parent_inheritance(Node **linked_list_first_element, Node *node_to_delete, Node *replacement_node);


void replacement_of_node(Node **linked_list_first_element, Node *node_to_delete, Node *replacement_node) {

    /*
    lors du deplacement du node de remplacement il y a deux posibilités :
    - déplacer uniquement le node est combler le trou créer par celui ci 
      en redirigent les pointers

    - déplacer le node de remplacement mais aussi son fils (petit ou grand)

    The replacement node is disconected from the tree 
    to be reconnected in anothe location this may create 
    a gap who need to be filed by redirecting some
    pointers 
    */

    //printf("\n\nLe node de remplacement avant la redirection du chemin et l'héritage:\n");
    //print_node(*linked_list_first_element, replacement_node->hash_value);

    path_redirection(replacement_node);

    /*if (replacement_node->parent_node != node_to_delete)
    {
        path_redirection(replacement_node);
    }

    
    The replacement node will inherit of the pointer 
    of the node to delete and its pointer are set to NULL
    */

    lesser_child_inheritance(node_to_delete, replacement_node);
    greater_child_inheritance(node_to_delete, replacement_node);
    parent_inheritance(linked_list_first_element, node_to_delete, replacement_node);


    //printf("\nLe node de remplacement après l'héritage :\n");
    //printf("\nLe node de remplacement après la redirection du chemin et l'héritage:\n");
    //print_node(*linked_list_first_element, replacement_node->hash_value);

    /*
    path_redirection(replacement_node);

    printf("\n\nLe node de remplacement avant la redirection du chemin :\n");
    print_node(*linked_list_first_element, replacement_node->hash_value);*/
}


//---------------------------------------- redirection of the path to the new node ------------------------------------------------------------------


//void path_redirection(Node *node_to_delete, Node *replacement_node) {
void path_redirection(Node *replacement_node) {

    /*
    The replacement node is disconected from the tree
    to be reconnected in anothe location this may create
    a gap who need to be filed by redirecting some pointers
    */

    // we need to know if the replacement node is the lesser or 
    // greater child of its parent to know wich pointer 
    // to redirect
    if (replacement_node->parent_node->node_lesser_hash == replacement_node)
    // if the node of replacement is the lessser child of its parent
    // in that case, we need to redirect the pointer, of the parent of the 
    // replacement node, dedicated to the the lesser child
    {
        /**/
        if (replacement_node->node_greater_hash != NULL)
        // if the replacement node has a greater child we need to give it
        // to another node because it will be disconnected from it
        // the child will be adopted by its ancestor (the parent of its parent)
        {
            //replacement_node->parent_node->node_lesser_hash = replacement_node->node_greater_hash;
            // the parent of the replacement node 
            // accept its lesser child as its greater
            replacement_node->node_greater_hash->parent_node = replacement_node->parent_node;
            // the greater child of the replacement node 
            // accept the parent of the replacement node 
            // as its own
        }
        
        replacement_node->parent_node->node_lesser_hash = replacement_node->node_greater_hash;

    }
    else if (replacement_node->parent_node->node_greater_hash == replacement_node)
    // if the node of replacement is the greater child of its parent
    // in that case, we need to redirect the pointer, of the parent of the 
    // replacement node, dedicated to the the greater child
    {
        /**/
        if (replacement_node->node_lesser_hash != NULL)
        // if the replacement node has a lesser child we need to give it
        // to another node because it will be disconnected from it
        // the child will be adopted by its ancestor (the parent of its parent)
        {
            //replacement_node->parent_node->node_greater_hash = replacement_node->node_lesser_hash;
            // the parent of the replacement node 
            // accept its greater child as its lesser
            replacement_node->node_lesser_hash->parent_node = replacement_node->parent_node;
            // the lesser child of the replacement node 
            // accept the parent of the replacement node 
            // as its own
        }

        replacement_node->parent_node->node_greater_hash = replacement_node->node_lesser_hash;
    }
}


//---------------------------------------- lesser child inheritance ------------------------------------------------------------------


void lesser_child_inheritance(Node *node_to_delete, Node *replacement_node) {

    // the node who will replace the node to delete will inherit his pointe
    //replacement_node->node_lesser_hash = node_to_delete->node_lesser_hash;
    // the node of replacement adopte the lesser
    // child of the node to delete

    if ( (node_to_delete->node_lesser_hash != NULL) && 
         (node_to_delete->node_lesser_hash != replacement_node) )
    //if (node_to_delete->node_lesser_hash != replacement_node)
    // if the node to delete have a lesser child
    // who is not the node of replacement 
    // (to prevent the node to delete to give a pointer who 
    // point to the lesser child to itself)
    {
        node_to_delete->node_lesser_hash->parent_node = replacement_node;
        // The lesser child of the node to delete
        // accept the replacement node as its parent

        replacement_node->node_lesser_hash = node_to_delete->node_lesser_hash;//

        node_to_delete->node_lesser_hash = NULL;
    }
}


//---------------------------------------- greater child inheritance ------------------------------------------------------------------


void greater_child_inheritance(Node *node_to_delete, Node *replacement_node) {

    //replacement_node->node_greater_hash = node_to_delete->node_greater_hash;
    // the node of replacement adopte the greater 
    // child of the node to delete

    if ( (node_to_delete->node_greater_hash != NULL) && 
         (node_to_delete->node_greater_hash != replacement_node) )
    //if (node_to_delete->node_greater_hash != replacement_node)
    // if the node to delete has a greater child 
    // who is not the node of replacement 
    // (to prevent the node to delete to give a pointer who 
    // point to the greater child to itself)
    {
        node_to_delete->node_greater_hash->parent_node = replacement_node;
        // The greater child of the node to delete
        // accept the replacement node as its parent

        replacement_node->node_greater_hash = node_to_delete->node_greater_hash;//

        node_to_delete->node_greater_hash = NULL;
    }
}


//---------------------------------------- parent inheritance ------------------------------------------------------------------


void parent_inheritance(Node **linked_list_first_element, Node *node_to_delete, Node *replacement_node) {

    replacement_node->parent_node = node_to_delete->parent_node;
    // the replacement node recognize the parent of the node
    // to delete as its parent

    if (node_to_delete->parent_node != NULL)
    // if the node to delete has a parent
    // if the node to delete is not the root node
    {
        // the parent of the node to delete must recognize
        // the node to delete as its child
        if (node_to_delete->parent_node->node_greater_hash == node_to_delete)
        // if the node to delete was the greater child 
        // of its parent
        {
            node_to_delete->parent_node->node_greater_hash = replacement_node;
            // the parent of the node to delete adopt 
            // the replacement node as its greater child
        }
        else if (node_to_delete->parent_node->node_lesser_hash == node_to_delete)
        // if the node to delete was the lesser child 
        // of its parent
        {
            node_to_delete->parent_node->node_lesser_hash = replacement_node;
            // the parent of the node to delete adopt 
            // the replacement node as its lesser child            
        }
                    
        //replacement_node->parent_node = node_to_delete->parent_node
        // the node of replacement accept the parent of the node to 
        // delete as its own

        node_to_delete->parent_node = NULL;
    }
    else if (node_to_delete->parent_node == NULL)
    // if the node to delete is the root node
    {
        *linked_list_first_element = replacement_node;
    }
}

/*
    list:             Show the source code.
    print <variable>: Print the value of a variable.
    backtrace or bt:  Display a backtrace of the call stack.
    step or s:        Execute a single instruction, stepping into function calls.
    next or n:        Execute a single instruction, stepping over function calls.
    continue or c:    Continue running until the next breakpoint.
*/