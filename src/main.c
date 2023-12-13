#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/linked_list/new.h"
#include "../include/linked_list/crud/read.h"
#include "../include/linked_list/crud/create.h"
#include "../include/linked_list/crud/delete.h"

#include "../include/hash/hash.h"

int main() {
    int value = 50;

    Node *first_node = new_linked_list(&value);

    printf("The first node before the creation of a second node :\n");
    print_node(first_node, 50);

    int seconde_value = 60;
    create_node_recursion(first_node, &seconde_value);

    printf("\nAfter the creation of a second node :\n");
    print_node(first_node, 50);

    printf("\nThe seconde node :\n");
    print_node(first_node, 60);

    int thrid_value = 55;
    create_node(first_node, &thrid_value);

    printf("\nThe seconde node after the creation of a thrid node :\n");
    print_node(first_node, 60);

    printf("\nThe thrid node :\n");
    print_node_recursion(first_node, 55);

    int fourth_value = 4;
    create_node(first_node, &fourth_value);

    printf("\nThe first node after the creation of a fourth node :\n");
    print_node(first_node, 50);

    printf("\nThe fourth node :\n");
    print_node_recursion(first_node, 4);
    
    delete_node(first_node, 60);
    delete_node(first_node, 4);
    delete_node(first_node, 55);

    printf("\n\nThe first node after the deletions :\n");
    print_node_recursion(first_node, 50);
    delete_node(first_node, 50);

    /// test hash :

    char test_char[] = "George Washington";
    float hash = create_hash(test_char);
    printf("\nhash of %s : %f\n", test_char, hash);


    char test1_char[] = "John Adams";
    float hash1 = create_hash(test1_char);
    printf("hash1 of %s : %f\n", test1_char, hash1);

    /*
    printf("\nThe rest of the nodes after the deletion :\n");
    delete_node(first_node, 4);
    delete_node(first_node, 50);
    delete_node(first_node, 60);
    */
    
    /*
    int num_max_jumps = 10;
    Node *linked_list_iterator_node = linked_list_first_element;

    for (int jump_thought_nodes = 0; jump_thought_nodes <= num_max_jumps; ++jump_thought_nodes)
    {
        create_node(first_node, &fourth_value);
        print_node(first_node, 50);
    }

    for (int jump_thought_nodes = 0; jump_thought_nodes <= num_max_jumps; ++jump_thought_nodes)
    {
        delete_node(first_node, 50);
        print_node(first_node, 50);
    }
    */
}