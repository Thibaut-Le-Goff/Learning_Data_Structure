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

#include "../include/hash/create_hash.h"

#include "../include/tests/random.h"

//#define NUM_NODES 2
// the programme can crash at 4,000 nodes due to hash collisions.

int main() {

    // the number of nodes the tree will have 
    int num_node = 5;
    //random_binary_tree_test(&num_node);

    // creation of the tree
    Random_Binary_Tree *random_tree = random_binary_tree_creation(&num_node);

    // variouse tests, collision, balancing, ect...
    random_tree->first_node_binary_tree = balance_binary_tree(&random_tree->first_node_binary_tree);
    //balance_binary_tree(&random_tree->first_node_binary_tree);

    // deletion of the tree
    random_binary_tree_deletion(&num_node, random_tree);




/// test hash for the binary tree:
    char test_char[] = "George Washington";
    int hash = create_hash_tree(test_char);
    printf("\nhash of %s : %d\n", test_char, hash);

    char test1_char[] = "John Adams";
    int hash1 = create_hash_tree(test1_char);
    printf("hash1 of %s : %d\n", test1_char, hash1);


    char test3_char[] = "test";
    int hash3 = create_hash_tree(test3_char);
    printf("hash3 of %s : %d\n", test3_char, hash3);

    char test4_char[] = "uftu";
    int hash4 = create_hash_tree(test4_char);
    printf("hash4 of %s : %d\n", test4_char, hash4);


/// test hash for the table:

    int array_length = 25;

    char test_char_table[] = "George Washington";
    int hash_table = create_hash_table(test_char_table, &array_length);
    printf("\nhash of %s : %d\n", test_char_table, hash_table);

    char test1_char_table[] = "John Adams";
    int hash1_table = create_hash_table(test1_char_table, &array_length);
    printf("hash1 of %s : %d\n", test1_char_table, hash1_table);


    char test3_char_table[] = "test";
    int hash3_table = create_hash_table(test3_char_table, &array_length);
    printf("hash3 of %s : %d\n", test3_char_table, hash3_table);

    char test4_char_table[] = "uftu";
    int hash4_table = create_hash_table(test4_char_table, &array_length);
    printf("hash4 of %s : %d\n", test4_char_table, hash4_table);
}