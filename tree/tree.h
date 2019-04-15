//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_TREE_H
#define DATASTRUCT_TREE_H

#include <iostream>

/*
 * Tree nodes' structure
 *   template <typename T>
 *   struct TreeNode {
 *       T value;
 *       TreeNode<T>* left;
 *       TreeNode<T>* right;
 *   };
 */

template <typename T>
class Tree {
protected:
    void delete_tree(T *node);
    void pre_order_traversal(T *node);
public:
    virtual T* get_root() = 0;
    virtual int  get_height(T *node);
    virtual void pre_order_traversal() { pre_order_traversal(get_root()); }
};

template <typename T>
void Tree<T>::delete_tree(T *node) {
    // 递归方式
    if (node == nullptr) {
        return;
    }

    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <typename T>
int Tree<T>::get_height(T *node) {
    if (node == nullptr) {
        return 0;
    }

    int l = 1 + get_height(node->left);
    int r = 1 + get_height(node->right);

    return (l > r) ? l : r;
}

template <typename T>
void Tree<T>::pre_order_traversal(T *node) {
    if (node== nullptr) {
        return;
    }

    std::cout << node->value << std::endl;
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

#endif //DATASTRUCT_TREE_H
