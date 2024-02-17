#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/binary_tree/new.h"
#include "../include/binary_tree/balanced_tree/balancing.h"

#include "../include/binary_tree/crud/read.h"
#include "../include/binary_tree/crud/create.h"
#include "../include/binary_tree/crud/delete.h"

#include "../include/stdr_outputs/binary_tree/examine_tree.h"

#include "../include/tests/random.h"

void random_binary_tree_test(int *num_node) {
//Random_Binary_Tree *random_binary_tree_creation(int *num_node) {

    float list_hash_node_created[*num_node];
    //float *list_hash_node_created = (float *)malloc(*num_node * sizeof(float));
    //Random_Binary_Tree *random_tree = (Random_Binary_Tree *)malloc(sizeof(Random_Binary_Tree));

    // create a random value for the creation of the first node
    srand(time(NULL));
    
    float rand_hash_root_node_to_create = ((float)rand() / RAND_MAX) * (2 * *num_node) - *num_node;
    Node *first_node_binary_tree = new_binary_tree(&rand_hash_root_node_to_create);
    //random_tree->first_node_binary_tree = &new_binary_tree(&rand_hash_root_node_to_create);
    

    //printf("\n\nThe root node has been created :\n");
    //print_node(first_node_binary_tree, rand_hash_root_node_to_create);

    list_hash_node_created[0] = rand_hash_root_node_to_create;

    for (int number_nodes_created = 1; number_nodes_created <= *num_node - 1; ++number_nodes_created)
    {
        // create a random value for the creation of the node
        float rand_hash_node_to_create = ((float)rand() / RAND_MAX) * (2 * *num_node) - *num_node;

        //create_node(first_node_binary_tree, &rand_hash_node_to_create);
        create_node_recursion(first_node_binary_tree, &rand_hash_node_to_create);

        //printf("\n\nA new node has been created :\n");
        //print_node(first_node_binary_tree, rand_hash_node_to_create);

        // the hash value is stored in the array
        list_hash_node_created[number_nodes_created] = rand_hash_node_to_create;
    }
/*
    return random_tree;
}


void random_binary_tree_deletion(int *num_node, Random_Binary_Tree *random_tree) {
*/
    // delette the nodes in a random order
    for (int number_nodes_to_delete = *num_node; number_nodes_to_delete != 0; --number_nodes_to_delete)
    {
        // create a random index for the deletion of the node
        int rand_index_node_to_delete = rand() % *num_node;

        //printf("\n\nindex node to delete : %d\n", rand_index_node_to_delete);

        if (list_hash_node_created[rand_index_node_to_delete] != -1)
        //if (random_tree->list_hash_node_created[rand_index_node_to_delete] != -1)
        // if the node was not already deleted
        {
            //printf("\nThe node to delete is :\n");
            //balance_binary_tree(&first_node_binary_tree);

            //delete_node(random_tree->first_node_binary_tree, random_tree->list_hash_node_created[rand_index_node_to_delete]);
            delete_node(&first_node_binary_tree, list_hash_node_created[rand_index_node_to_delete]);

            //random_tree->list_hash_node_created[rand_index_node_to_delete] = -1;
            list_hash_node_created[rand_index_node_to_delete] = -1;
        }
        else
        {
            //printf("\nthe node has already been deleted.\n");
            ++number_nodes_to_delete;
        }
    }
}