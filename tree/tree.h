//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_TREE_H
#define DATASTRUCT_TREE_H

#include <iostream>
#include <stack>

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
public:
    static void delete_tree(T *node);
    static void pre_order_traversal(T *node);

    virtual T* get_root() = 0;
    virtual void pre_order_traversal() { Tree<T>::pre_order_traversal(get_root()); }
};

template <typename T>
void Tree<T>::delete_tree(T *node) {
    // 递归方式
//    if (node == nullptr) {
//        return;
//    }
//
//    delete_tree(node->left);
//    delete_tree(node->right);
//    delete node;
    // 非递归方式
    if (node == nullptr) {
        return ;
    }

    std::stack<T*> s = std::stack<T*>();
    s.push(node);
    while (s.size()) {
        node = s.top();
        s.pop();
        if (node->right) {
            s.push(node->right);
        }

        if (node->left) {
            s.push(node->left);
        }
        delete node;
    }
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
