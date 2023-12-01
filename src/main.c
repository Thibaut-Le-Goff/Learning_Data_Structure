#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list/new.h"
#include "../include/linked_list/crud/read.h"

int main() {
    int value = 1;

    Node *table_test = new_linked_list(&value);

    print_node(table_test);

    free(table_test);
}