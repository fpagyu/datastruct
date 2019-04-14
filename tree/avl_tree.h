//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_AVL_TREE_H
#define DATASTRUCT_AVL_TREE_H

#include "tree.h"

template<typename T>
class AVLNode: public TreeNode<T> {
public:
    int val;
    int height;
    AVLNode<T> *left;
    AVLNode<T> *right;

    inline T value() { return val; }
    inline AVLNode<T>* lchild() { return left; }
    inline AVLNode<T>* rchild() { return right; }

    explicit AVLNode(T val): val(val), height(0), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVLTree: public Tree<T> {
private:
    int max(int a, int b) {
        return a>b ? a:b;
    }

    int height(const AVLNode<T> *node) {
        return (node == nullptr) ? -1: node->height;
    }

    // LL 型结构, 右旋操作
    AVLNode<T>* LL_rotate(AVLNode<T> *node);
    // RR 型结构, 左旋操作
    AVLNode<T>* RR_rotate(AVLNode<T> *node);
    // LR 型结构, 先左旋后右旋
    AVLNode<T>* LR_rotate(AVLNode<T> *node);
    // RL 型结构, 先右旋后左旋
    AVLNode<T>* RL_rotate(AVLNode<T> *node);

public:
    AVLTree(): Tree<T>(nullptr) {}
    explicit AVLTree(T val): Tree<T>(new AVLNode<T>(val)) {}
};

#endif //DATASTRUCT_AVL_TREE_H
