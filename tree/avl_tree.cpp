//
// Created by jvm on 4/12/19.
// AVL 树
// 平衡二叉树(AVL)实现
// Doc: https://blog.csdn.net/u014634338/article/details/42465089
// Doc: http://www.cnblogs.com/gaochundong/p/binary_search_tree.html
// Doc: https://blog.zhenlanghuo.top/2017/08/22/AVL%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%AE%9E%E7%8E%B0/
//
#include "avl_tree.h"

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
