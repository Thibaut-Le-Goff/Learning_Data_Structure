typedef struct Node Node;

struct Node {
    
    Node *next_node;
    Node *previous_node;

    int value;

    int hash_value;
};