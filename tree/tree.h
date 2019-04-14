//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_TREE_H
#define DATASTRUCT_TREE_H

#include <iostream>

template <typename T>
class TreeNode {
public:
    T val;

    TreeNode(T val): val(val) {}
};

template <typename T>
class Tree {
protected:
    T *root; // 树根节点
private:
    void pre_order_traversal(T *node) {
        if (node== nullptr) {
            return;
        }

        std::cout << node->val << std::endl;
        pre_order_traversal(node->left);
        pre_order_traversal(node->right);
    }

    void delete_tree(T *node) {
        if (node == nullptr) {
            return;
        }
        std::cout << "destruct!!!" << std::endl;

        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
public:
    Tree(T *node): root(node) {}
    ~Tree() { delete_tree(root); }

    T* get_root() { return root; }
    void pre_order_traversal() { pre_order_traversal(root); }
};

#endif //DATASTRUCT_TREE_H
