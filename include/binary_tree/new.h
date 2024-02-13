#ifndef __NEW_H__
#define __NEW_H__

    typedef struct Node Node;

    struct Node {
        
        // for binary search
        Node *node_greater_hash;
        Node *node_lesser_hash;
        Node *parent_node;

        // to balance the binary tree
        // int index_weight_ascending;
        // will need to do an iteration

        // for iteration
        Node *next_node;
        Node *previous_node;

        // a tree is balanced if the number of
        // nodes on both side is not more different 
        // than 1 (ex 7 and 6)

        // during the creation of a node 
        // we can kept track of the path its
        // used and count the number of nodes
        // who passed throught the nodes
        int counter_node_passed_through;

        float value;

        float hash_value;
    };

    Node *new_binary_tree(float *value);

#endif //__NEW_H__