#include <iostream>
#include "tree/avl.h"

int main(int argc, char* argv[]) {
    //  测试二叉搜索树
//    auto t = new BST<int>(7);
//
//    t->insert(5);
//    t->insert(4);
//    t->insert(6);
//    t->insert(new TreeNode<int>(15));
//    t->insert(new TreeNode<int>(18));
//    t->insert(17);
//    t->insert(14);
//
//    t->remove(7);
//
//    std::cout << "find: " << t->find(15)->value << std::endl;
//    t->pre_order_traversal();
//    t->in_order_traversal();
//    t->post_order_traversal();
//    std::cout << "============" << std::endl;
//    t->pre_order();
//    t->in_order();
//    t->post_order();
//    t->level_order();
//    delete t;

    // 测试AVL树
    auto t = new AVL<int>(7);

    t->insert(5);
    t->insert(4);
    t->insert(6);
    t->insert(15);
    t->insert(14);
    t->insert(17);
    t->insert(20);

    t->level_order();
    std::cout << "==================" << std::endl;
    t->remove(5);
    t->level_order();
    t->remove(6);
    std::cout << "==================" << std::endl;
    t->level_order();

    delete t;

    return 0;
}
