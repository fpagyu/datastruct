#include <iostream>
#include "tree/avl_tree.h"

int main(int argc, char* argv[]) {
    auto *tr = new AVLTree<int>(7);

//    auto root = (AVLNode<int>*)tr->get_root();
//    root->left = new AVLNode<int>(5);
//    root->right = new AVLNode<int>(13);
    tr->insert(5);
    tr->insert(13);
    tr->insert(4);
    tr->insert(6);

    tr->pre_order_traversal();

    delete tr;
    return 0;
}
