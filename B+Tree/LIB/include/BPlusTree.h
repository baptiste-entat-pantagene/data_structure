#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <stddef.h>
#include <stdint.h>

struct BPlusTree
{
    size_t order;
    size_t level;
    struct BPT_Node* root;
};

struct BPT_Node
{
    size_t* index;
    struct BPT_Node** child;
    struct BPT_Node* link;
};



struct BPlusTree* BPT_init(const size_t order);

void BPT_insert(const struct BPlusTree *tree, const int32_t index, void *data);



int add(int a, int b);


#endif //BPLUSTREE_H
