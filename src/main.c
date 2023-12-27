#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/linked_list/new.h"
#include "../include/linked_list/crud/read.h"
#include "../include/linked_list/crud/create.h"
#include "../include/linked_list/crud/delete.h"

#include "../include/hash/hash.h"

#define NUM_NODES 10

int main() {

    float list_hash_node_created[NUM_NODES];

    // create a random value for the creation of the first node
    srand(time(NULL));
    float rand_hash_root_node_to_create = (float)rand() / RAND_MAX * (NUM_NODES);
    Node *first_node_linked_list = new_linked_list(&rand_hash_root_node_to_create);

    printf("\n\nThe root node has been created :\n");
    print_node(first_node_linked_list, rand_hash_root_node_to_create);

    list_hash_node_created[0] = rand_hash_root_node_to_create;

    for (int number_nodes_created = 1; number_nodes_created <= NUM_NODES - 1; ++number_nodes_created)
    {
        // create a random value for the creation of the node
        //srand(time(NULL));
        float rand_hash_node_to_create = (float)rand() / RAND_MAX * (NUM_NODES);

        create_node_recursion(first_node_linked_list, &rand_hash_node_to_create);

        printf("\n\nA new node has been created :\n");
        print_node(first_node_linked_list, rand_hash_node_to_create);

        // the hash value is stored in the array
        list_hash_node_created[number_nodes_created] = rand_hash_node_to_create;
    }

    printf("\n\nevery nodes has been created\n\n");

    for (int number_nodes_to_delete = NUM_NODES; number_nodes_to_delete != 0; --number_nodes_to_delete)
    {
        // create a random value for the deletion of the node
        int rand_index_node_to_delete = rand() % NUM_NODES;  

        printf("\n\nindex node to delete : %d\n", rand_index_node_to_delete);

        if (list_hash_node_created[rand_index_node_to_delete] != -1)
        // if the node was not already deleted
        {
            printf("\nThe node to delete is :\n");
            print_node(first_node_linked_list, list_hash_node_created[rand_index_node_to_delete]);

            delete_node(&first_node_linked_list, list_hash_node_created[rand_index_node_to_delete]);

            list_hash_node_created[rand_index_node_to_delete] = -1;
        }
        else
        {
            printf("\nthe node has already been deleted.\n");
            ++number_nodes_to_delete;
        }
    }



    /*
    /// test hash :

    char test_char[] = "George Washington";
    float hash = create_hash(test_char);
    printf("\nhash of %s : %f\n", test_char, hash);


    char test1_char[] = "John Adams";
    float hash1 = create_hash(test1_char);
    printf("hash1 of %s : %f\n", test1_char, hash1);


    // test and uftu have the same hash
    char test3_char[] = "test";
    float hash3 = create_hash(test3_char);
    printf("hash3 of %s : %f\n", test3_char, hash3);

    char test4_char[] = "uftu";
    float hash4 = create_hash(test4_char);
    printf("hash4 of %s : %f\n", test4_char, hash4);
    */
}