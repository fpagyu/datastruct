//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_TREE_H
#define DATASTRUCT_TREE_H

#include <iostream>

template <typename T>
class TreeNode {
public:
    T value;
    virtual TreeNode<T>* lchild() = 0;
    virtual TreeNode<T>* rchild() = 0;
    virtual void set_lchild(const T&) = 0;
    virtual void set_rchild(const T&) = 0;

    virtual ~TreeNode() = default;
};

template <typename T>
class Tree {
protected:
    TreeNode<T> *root; // 树根节点
private:
    void pre_order_traversal(TreeNode<T> *node) {
        if (node== nullptr) {
            return;
        }

        std::cout << node->value << std::endl;
        pre_order_traversal(node->lchild());
        pre_order_traversal(node->rchild());
    }

    void delete_tree(TreeNode<T> *node) {
        if (node == nullptr) {
            return;
        }
        std::cout << "destruct!!!" << std::endl;

        delete_tree(node->lchild());
        delete_tree(node->rchild());
        delete node;
    }
public:
    Tree(): root(nullptr) {}
    explicit Tree(TreeNode<T> *node): root(node) {}
    ~Tree() { delete_tree(root); }

    TreeNode<T>* get_root() { return root; }
    void pre_order_traversal() { pre_order_traversal(root); }
};

#endif //DATASTRUCT_TREE_H
