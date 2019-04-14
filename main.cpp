#include <iostream>
#include "tree/avl_tree.h"

int main(int argc, char* argv[]) {
    auto *tr = new AVLTree<int>(6);

    auto root = tr->get_root();
    root->left = new AVLNode<int>(5);
    root->right = new AVLNode<int>(13);

    tr->pre_order_traversal();

    delete tr;
    return 0;
}
