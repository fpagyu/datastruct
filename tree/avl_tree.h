//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_AVL_TREE_H
#define DATASTRUCT_AVL_TREE_H

#include "tree.h"
#include "b_search.h"

template<typename T>
class AVLNode: public TreeNode<T> {
public:
    int height;
    AVLNode<T> *left;
    AVLNode<T> *right;

    AVLNode<T>* lchild() { return left; }
    AVLNode<T>* rchild() { return right; }
    void set_lchild(const TreeNode<T>* node) { left = (AVLNode<T>*)node; }
    void set_rchild(const TreeNode<T>* node) { right = (AVLNode<T>*)node; }

    explicit AVLNode(T val): height(0), left(nullptr), right(nullptr) { TreeNode<T>::value = val; }
};

template <typename T>
class AVLTree: public BSearchTree<T> {
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
    AVLTree(): BSearchTree<T>(nullptr) {}
    explicit AVLTree(T val): BSearchTree<T>(new AVLNode<T>(val)) {}

    void insert(const T& v) {
        auto *node = new AVLNode<T>(v);
        if (!BSearchTree<T>::insert(node)) {
            // 插入失败
            delete node;
        }
    }
};

#endif //DATASTRUCT_AVL_TREE_H
