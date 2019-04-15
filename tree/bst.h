//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_B_SEARCH_H
#define DATASTRUCT_B_SEARCH_H

#include "tree.h"

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;

    explicit TreeNode(const T& v): value(v), left(nullptr), right(nullptr) {}
    ~TreeNode() = default;
};

// 二叉搜索树
template <typename T>
class BST: public Tree<TreeNode<T>> {
private:
    TreeNode<T> *root;

    TreeNode<T>* remove_node(TreeNode<T>* node, const T& v);
public:
    BST() = default;
    explicit BST(TreeNode<T> *node):root(node) {}
    explicit BST(const T& v): root(new TreeNode<T>(v)) {}
    ~BST() {
        this->delete_tree(root);
    }

    TreeNode<T>* get_root() { return root; }
    TreeNode<T>* find(TreeNode<T>* node, const T& v);
    TreeNode<T>* find(const T& v);
    int insert(TreeNode<T> *node);
    int insert(const T& v);
    void remove(const T& v);

    TreeNode<T>* find_min(TreeNode<T> *node) {
        TreeNode<T> *cur = node;
        while (cur) {
            if (cur->left == nullptr) {
                return cur;
            }
            cur = cur->left;
        }

        return nullptr;
    }

    TreeNode<T>* find_max(TreeNode<T> *node) {
        TreeNode<T> *cur = node;
        while (cur) {
            if (cur->right == nullptr) {
                return cur;
            }
            cur = cur->right;
        }
        return nullptr;
    }

    TreeNode<T>* find_min() {
        return find_min(root);
    }

    TreeNode<T>* find_max() {
        return find_max(root);
    }
};

template <typename T>
TreeNode<T>* BST<T>::find(TreeNode<T>* node, const T& v) {
    // 递归方式
//    if (node == nullptr) {
//        return nullptr;
//    }
//
//    if (v == node->value) {
//        return node;
//    }
//
//    if (v < node->value) {
//        return find(node->left, v);
//    }
//
//    return find(node->right, v);
    // 非递归方式
    TreeNode<T> *cur = node;
    while (cur) {
        if (v == cur->value) {
            break;
        }

        cur = (v < cur->value) ? cur->left: cur->right;
    }

    return cur;
}

template <typename T>
TreeNode<T>* BST<T>::find(const T& v) {
    return find(root, v);
}

template <typename T>
int BST<T>::insert(TreeNode<T> *node) {
    // 返回0表示插入成功, -1 插入失败
    if (root == nullptr) {
        root = node;
        return 0;
    }

    TreeNode<T> *cur = root;

    // 寻找插入点
    while(cur) {
        // 如果已存在， 则放弃插入
        if (node->value == cur->value) {
            return -1;
        }

        if (node->value < cur->value) {
            // 插入点在当前节点的左子树中
            if (cur->left == nullptr) {
                cur->left = node;
                break;
            }
            cur = cur->left;
        } else {
            // 插入点在当前节点的右子树中
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
int BST<T>::insert(const T& v) {
    auto node = new TreeNode<T>(v);
    int r = insert(node);
    if (r == -1) {
        delete node;
    }

    return r;
}

template <typename T>
TreeNode<T>* BST<T>::remove_node(TreeNode<T>* node, const T& v) {
    TreeNode<T>* parent = nullptr;
    TreeNode<T>* cur = node;
    while(cur) {
        // 查找删除点
        if (v == cur->value) {
            break;
        }

        parent = cur;
        if (v < cur->value) {
            if (cur->left == nullptr) {
                return nullptr;
            }
            cur = cur->left;
        } else {
            if (cur->right == nullptr) {
                return nullptr;
            }
            cur = cur->right;
        }
    }
    if (cur == nullptr) {
        return nullptr;
    }

    // 算法: 1. 找到待删节点
    // 2. 以待删节点的右子树中最小的节点代替待删节点
    // 3. 如果待删节点的右子树为null, 则以待删节点的左节点代替待删节点
    // 注解： 其本质就是找到一个合适的值, 能替代待删节点, 满足大于所有左子树节点同时小于所有右子树节点
    TreeNode<T>* min_node;
    if (cur->right == nullptr) {
        min_node = cur->left;
    } else {
        min_node = find_min(cur->right);
        min_node = remove_node(cur->right, min_node->value);
        min_node->left = cur->left;
        min_node->right = cur->right;
    }

    if (parent == nullptr) {
        node = min_node;
    } else if (parent->left == cur) {
        parent->left = min_node;
    } else {
        parent->right = min_node;
    }

    if (cur == root) {
        root = node;
    }

    // 待删除节点有一个左节点
    return cur;
}

template <typename T>
void BST<T>::remove(const T& v) {
    auto node = remove_node(root, v);
    if (node != nullptr) {
        delete node;
    }
}

#endif //DATASTRUCT_B_SEARCH_H
