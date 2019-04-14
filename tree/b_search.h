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

//    bool insert(TreeNode<T> *node) {
//        if (root == nullptr) {
//            root = node;
//            return true;
//        }
//
//        TreeNode<T> *cur = root;
//        while(cur) {
//            if (node->value() == cur->value()) {
//                return false;
//            }
//
//            if (node->value() < cur->value()) {
//                if (cur->lchild() == nullptr) {
//                    cur->set_lchild(node);
//                    return true;
//                }
//                cur = cur->lchild();
//            } else {
//                if (cur->rchild() == nullptr) {
//                    cur->set_rchild(node);
//                    return true;
//                }
//                cur = cur->rchild();
//            }
//        }
//
//        return false;
//    }
};


#endif //DATASTRUCT_B_SEARCH_H
