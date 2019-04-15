#include <iostream>
#include "tree/bst.h"

int main(int argc, char* argv[]) {
    //  测试二叉搜索树
    auto t = new BST<int>(7);

    t->insert(5);
    t->insert(4);
    t->insert(6);
    t->insert(new TreeNode<int>(15));
    t->insert(new TreeNode<int>(18));
    t->insert(17);
    t->insert(14);

    t->remove(7);
    t->pre_order_traversal();

    delete t;

    // 测试AVL树
//    auto t = new AVLTree<int>(7);
//
//    t->insert(5);
//    t->insert(4);
//    t->insert(6);
//    t->insert(new AVLNode<int>(15));
//    t->insert(new AVLNode<int>(18));
//    t->insert(17);
//
//    t->pre_order_traversal();

//    delete t;

    return 0;
}
