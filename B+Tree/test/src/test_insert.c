#include <acutest.h>

#include <memory.h>


#include <BPlusTree.h>

void test_example(void) {

    int testDeMerde = 1;
    int b = 2;
    int r = add(testDeMerde, b);
    TEST_CHECK(r == (testDeMerde + b));
}

void test_insert_simple_1(void)
{
    // ASUME ---
    struct BPlusTree* tree = BPT_init(4);

    const int i1 = 2;
    const int d1 = 20;
    const int*const d1_ptr = &d1;

    const int i2 = 3;
    const int d2 = 40;
    const int*const d2_ptr = &d2;

    const int i3 = 1;
    const int d3 = 10;
    const int*const d3_ptr = &d3;
    // END ASUME ---

    BPT_insert(tree, i1, (void*)d1_ptr);
    TEST_ASSERT(tree->root->index[0] == i1);
    TEST_ASSERT(tree->root->child[1] == (void*)d1_ptr);

    BPT_insert(tree, i2, (void*)d2_ptr);
    TEST_ASSERT(tree->root->index[0] == i1);
    TEST_ASSERT(tree->root->index[1] == i2);

    BPT_insert(tree, i3, (void*)d3_ptr);
    TEST_ASSERT(tree->root->index[1] == i1);
    TEST_ASSERT(tree->root->index[2] == i2);
    TEST_ASSERT(tree->root->index[0] == i3);

    TEST_ASSERT(tree->root->child[1+1] == (void*)d1_ptr);
    TEST_ASSERT(tree->root->child[2+1] == (void*)d2_ptr);
    TEST_ASSERT(tree->root->child[0+1] == (void*)d3_ptr);
}




TEST_LIST = {
   { "test_insert_simple_1", test_insert_simple_1 },
   { NULL, NULL }     /* zeroed record marking the end of the list */
};
