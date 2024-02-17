#ifndef __RANDOM_H__
#define __RANDOM_H__

    typedef struct Random_Binary_Tree Random_Binary_Tree;

    struct Random_Binary_Tree {
        
        Node **first_node_binary_tree;
        float *list_hash_node_created;
    };

    //float *andom_binary_tree_creation(int *num_node);
    //void random_binary_tree_deletion(int *num_node, Random_Binary_Tree *random_tree);
    void random_binary_tree_test(int *num_node);

#endif //__RANDOM_H__