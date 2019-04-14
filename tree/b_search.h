//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_B_SEARCH_H
#define DATASTRUCT_B_SEARCH_H

#include "tree.h"

// 二叉搜索树
template <typename T>
class BSearchTree: public Tree<T> {
public:
    explicit BSearchTree(TreeNode<T>* node): Tree<T>(node) {}

    TreeNode<T>* find(const T& v) {
        return find(Tree<T>::root, v);
    }

    TreeNode<T>* find(TreeNode<T>* node, const T& v) {
        if(node == nullptr) {
            return nullptr;
        }

        if (v == node->value) {
            return node;
        }

        if (v < node->value) {
            return find(node->lchild(), v);
        } else {
            return find(node->rchild(), v);
        }
    }

    virtual void insert(const T& v) {
//        if (Tree<T>::root == nullptr) {
//            Tree<T>::root = node;
//            return;
//        }

        TreeNode<T> *cur = Tree<T>::root;
        while(cur) {
            if (v == cur->value) {
                return;
            }

            if (v < cur->value) {
                if (cur->lchild() == nullptr) {
                    cur->set_lchild(v);
                    return;
                }
                cur = cur->lchild();
            } else {
                if (cur->rchild() == nullptr) {
                    cur->set_rchild(v);
                    return;
                }
                cur = cur->rchild();
            }
        }
    }
};


#endif //DATASTRUCT_B_SEARCH_H
