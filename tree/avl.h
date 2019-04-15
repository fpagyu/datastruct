//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_AVL_TREE_H
#define DATASTRUCT_AVL_TREE_H

#include "tree.h"
#include "bst.h"

template<typename T>
class AVLNode {
public:
    T value;
    int height;
    AVLNode<T> *left;
    AVLNode<T> *right;

    explicit AVLNode(const T& val): value(val), height(0), left(nullptr), right(nullptr) {}
    ~AVLNode() = default;
};

template <typename T>
class AVLTree: public Tree<AVLNode<T>> {
private:
    AVLNode<T> *root;

    int max(int a, int b) {
        return a>b ? a:b;
    }

    int height(const AVLNode<T> *node) {
        return (node == nullptr) ? -1: node->height;
    }
public:
    // LL 型结构, 右旋操作
    AVLNode<T>* LL_rotate(AVLNode<T> *node);
    // RR 型结构, 左旋操作
    AVLNode<T>* RR_rotate(AVLNode<T> *node);
    // LR 型结构, 先左旋后右旋
    AVLNode<T>* LR_rotate(AVLNode<T> *node);
    // RL 型结构, 先右旋后左旋
    AVLNode<T>* RL_rotate(AVLNode<T> *node);

public:
    AVLTree() = default;
    explicit AVLTree(AVLNode<T> *node): Tree<AVLNode<T>>(node) {}
    explicit AVLTree(const T& val): Tree<AVLNode<T>>(new AVLNode<T>(val)) {}

    int insert(AVLNode<T> *node);
    int insert(const T& v);
};

template <typename T>
AVLNode<T>* AVLTree<T>::LL_rotate(AVLNode<T> *node) {
    // node 为失衡点

    AVLNode<T> *lchild = node->left;

    node->left = lchild->right;
    lchild->right = node;

    // 调整失衡点及其左孩子节点的树高
    node->height = 1 + max(height(node->left), height(node->right));
    lchild->height = 1 + max(height(lchild->left),  node->height);

    return lchild;
}

template <typename T>
AVLNode<T>* AVLTree<T>::RR_rotate(AVLNode<T> *node) {
    AVLNode<T> *rchild = node->right;

    node->right = rchild->left;
    rchild->left = node;

    // 调整失衡点及其右孩子节点的高度
    node->height = 1 + max(height(node->left), height(node->right));
    rchild->height = 1 + max(height(rchild->right), node->height);

    return rchild;
}

template <typename T>
AVLNode<T>* AVLTree<T>::LR_rotate(AVLNode<T> *node) {
    // 先左旋， 后右旋
    node->left = RR_rotate(node->left);
    return LL_rotate(node);
}

template <typename T>
AVLNode<T>* AVLTree<T>::RL_rotate(AVLNode<T> *node) {
    // 先右旋， 后左旋
    node->right = LL_rotate(node->right);
    return RR_rotate(node);
}

template<typename T>
int AVLTree<T>::insert(AVLNode<T> *node) {
    if (root == nullptr) {
        root = node;
        return 0;
    }

    AVLNode<T> *cur = node;
    // 寻找插入点
    while(cur) {
        if (node->value == cur->value) {
            return -1;
        }

        if (node->value < cur->value) {
            // 往当前左子树中查找
            if (cur->left == nullptr) {
                cur->left = node;
                break;
            }
            cur = cur->left;
        } else {
            // 往当前右子树中查找
            if (cur->right == nullptr) {
                cur->right = node;
                break;
            }
            cur = cur->right;
        }
    }

    return 0;
}

template <typename T>
int AVLTree<T>::insert(const T& v) {
    auto node = new AVLNode<T>(v);
    int r = insert(node);
    if (r == -1) {
        delete node;
    }
    return r;
}

#endif //DATASTRUCT_AVL_TREE_H
