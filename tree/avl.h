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
class AVL: public Tree<AVLNode<T>> {
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

    AVL() = default;
    explicit AVL(AVLNode<T> *node): root(node) {}
    explicit AVL(const T& v): root(new AVLNode<T>(v)) {}

    AVLNode<T>* get_root() { return root; }

    AVLNode<T>* insert(AVLNode<T> *root, const T& v);
    AVLNode<T>* insert(const T& v) {
        root = insert(root, v);
        return root;
    }
};

template <typename T>
AVLNode<T>* AVL<T>::LL_rotate(AVLNode<T> *node) {
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
AVLNode<T>* AVL<T>::RR_rotate(AVLNode<T> *node) {
    AVLNode<T> *rchild = node->right;

    node->right = rchild->left;
    rchild->left = node;

    // 调整失衡点及其右孩子节点的高度
    node->height = 1 + max(height(node->left), height(node->right));
    rchild->height = 1 + max(height(rchild->right), node->height);

    return rchild;
}

template <typename T>
AVLNode<T>* AVL<T>::LR_rotate(AVLNode<T> *node) {
    // 先左旋， 后右旋
    node->left = RR_rotate(node->left);
    return LL_rotate(node);
}

template <typename T>
AVLNode<T>* AVL<T>::RL_rotate(AVLNode<T> *node) {
    // 先右旋， 后左旋
    node->right = LL_rotate(node->right);
    return RR_rotate(node);
}

template<typename T>
AVLNode<T>* AVL<T>::insert(AVLNode<T>* node, const T& v) {
    if (node == nullptr) {
        node = new AVLNode<T>(v);
        return node;
    }

    if (v < (node->value)) {
        // 插入的值小于节点值
        node->left = insert(node->left, v);
        if (height(node->left) - height(node->right) > 1) {
            if (v < node->left->value) {
                // LL 失衡
                node = LL_rotate(node);
            } else {
                // LR 失衡
                node = LR_rotate(node);
            }
        }
    } else {
        node->right = insert(node->right, v);
        if (height(node->left) - height(node->right) > 1) {
            if (v > node->right->value) {
                // RR 失衡
                node = RR_rotate(node);
            } else {
                // RL 失衡
                node = RL_rotate(node);
            }
        }
    }

    int l_height = 1 + height(node->left);
    int r_height = 1 + height(node->right);
    node->height = l_height > r_height ? l_height: r_height;

    return node;
}

#endif //DATASTRUCT_AVL_TREE_H
