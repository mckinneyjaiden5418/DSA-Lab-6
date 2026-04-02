#include <iostream>
#include "include/binary_search_tree.h"

// AI generated main function for testing.
int main() {
    BST* bst = new BST();

    // Build this tree:
    //        5
    //       / \
    //      3   7
    //     / \ / \
    //    2  4 6  8
    //   /
    //  1
    bst->insert(5);
    bst->insert(3);
    bst->insert(7);
    bst->insert(2);
    bst->insert(4);
    bst->insert(6);
    bst->insert(8);
    bst->insert(1);

    std::cout << "\nIn-order:    "; bst->in_order_traversal();    // 1 2 3 4 5 6 7 8
    std::cout << "\nPre-order:   "; bst->pre_order_traversal();   // 5 3 2 1 4 7 6 8
    std::cout << "\nPost-order:  "; bst->post_order_traversal();  // 1 2 4 3 6 8 7 5
    std::cout << "\nLevel-order: "; bst->level_order_traversal(); // 5 3 7 2 4 6 8 1

    delete bst;
    return 0;
}