#ifndef __READ_H__
#define __READ_H__

    void print_node(Node *linked_list_first_element, float hash_node_to_print);
    void print_node_recursion(Node *linked_list_first_element, float hash_node_to_print);

    void show_next_node(Node *linked_list_first_element, Node *node_hash_to_show);
    void show_previous_node(Node *linked_list_first_element, Node *node_hash_to_show);

    ////////////////////// STDR OUTPUTS ////////////////////

    void show_next_node_stdr(Node *linked_list_first_element, Node *node_hash_to_show);
    void show_previous_node_stdr(Node *linked_list_first_element, Node *node_hash_to_show);

    void show_node_stdr(Node *node_to_show);

#endif //__READ_H__