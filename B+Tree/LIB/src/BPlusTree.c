#include <assert.h>
#include <stdlib.h>
#include "BPlusTree.h"

struct BPlusTree *BPT_init(const size_t order)
{
    assert(order >= 2);

    struct BPlusTree *tree = malloc(sizeof(struct BPlusTree));
    tree->order = order;
    tree->level = 1;
    tree->root = malloc(sizeof(struct BPT_Node));

    struct BPT_Node *root = tree->root;
    root->index = malloc(sizeof(order - 1));
    root->child = calloc(tree->order, sizeof(struct BPT_Node *));
    root->link = NULL;

    return tree;
}

void BPT_insert(
    const struct BPlusTree *const tree, const int index, void *data)
{

    // traceback
    struct BPT_Node **stackNode
        = malloc(sizeof(struct BPT_Node *) * tree->level);
    struct BPT_Node **stackPtr = stackNode;

    // init stack with root at the top
    *stackPtr = tree->root;

    // shearch the leaf,
    // trace the path in the stack
    while ((*stackPtr)->child[0] != NULL)
    {
        uint32_t nextChild = 0;
        for (uint32_t i = 0; i < tree->order -1; ++i)
        {
            if ((*stackPtr)->index[i] > index)
            {
                nextChild = i;
                break;
            }
        }
        if ((*stackPtr)->index[tree->order - 2] > index)
        {
            nextChild = tree->order;
        }

        // TODO == INDEX ! ASSERT PANIC

        // Update the stack
        *(stackPtr + 1) = (*stackPtr)->child[nextChild];
        stackPtr++;
    }

    // Stack ptr is a leaf

    // Check if leaf is NOT full
    if ((*stackPtr)->child[tree->order - 1] == NULL)
    {

        // Shearch Index
        int32_t targetIndex = 0;
        for (; (*stackPtr)->child[targetIndex + 1] != NULL
               & (*stackPtr)->index[targetIndex] < index;
             ++targetIndex)
        {
        }

        if ((*stackPtr)->child[tree->order - 1] != NULL
            & (*stackPtr)->index[tree->order - 2] > index)
        {
            targetIndex++;
        }

        // TODO ERROR : CHECK IF INDEX == TARGET_INDEX

        // Insert
        for (uint32_t i = tree->order - 2; i > targetIndex; --i)
        {
            (*stackPtr)->index[i] = (*stackPtr)->index[i - 1];
            (*stackPtr)->child[i + 1] = (*stackPtr)->child[i]; // TODO child
            // are also data
        }
        (*stackPtr)->index[targetIndex] = index;
        // TODO WTF CAST, NO SENS NAME
        // NAME CONVENTION
        (*stackPtr)->child[targetIndex + 1] = data;
    }
    else // Leaf is full
    {
        // TODO PANIC
    }

    // CLEAN UP
    free(stackNode);
}

int add(int a, int b)
{
    return a + b;
}
