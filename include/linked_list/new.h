#ifndef NEW_H
#define NEW_H

    typedef struct Node Node;

    struct Node {
        
        // for binary search
        Node *node_greater_hash;
        Node *node_lesser_hash;

        // for iteration
        // Node *next_node

        int value;

        int hash_value;
    };

    Node *new_linked_list(int *value);

#endif