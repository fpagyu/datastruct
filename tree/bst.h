//
// Created by zhijun yu on 2019/4/14.
// 二叉搜索树
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
    // 非递归方式
    while (node) {
        if (v == node->value) {
            break;
        }
        node = (v < node->value) ? node->left : node->right;
    }

    return node;
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
TreeNode<T> *BST<T>::remove_node(TreeNode<T> *node, const T &v) {
    // 找到待删节点, 及其父节点
    TreeNode<T> *parent = nullptr;
    while (node != nullptr) {
        if (v == node->value) {
            break;
        }
        parent = node;
        node = (v < node->value) ? node->left : node->right;
    }

    if (node == nullptr) {
        // 未找到待删节点
        return nullptr;
    }

    // 此时, 待删节点及其父节点已经确定
    // 考虑删除节点的算法, 其本质就是在待删节点的左右子树中找到一个合适的节点来代替待删节点
    // 这个“合适”的标准, 便是满足代替新节点后, 其左子树都小于该节点, 右子树都大于该节点
    // 由此可得, 这个合适的节点便是待删节点右子树中的最小节点(考虑为什么不是左子树的最大节点?),
    // 因为该节点一定是叶子节点
    // 算法:
    // 1. 假如待删节点的右子树为null, 则直接已待删节点左孩子节点代替待删节点
    // 2. 如果待删除节点右子树不为null, 找出右子树中的最小节点, 代替待删除节点, 同时移除右子树中的这个最小节点
    // 3. 将待删节点的父节点重新指向新节点
    TreeNode<T> *new_node;
    if (node->right == nullptr) {
        new_node = node->left;
    } else {
        new_node = find_min(node->right);
        remove_node(node->right, new_node->value);
        new_node->left = node->left;
        new_node->right = node->right;
    }

    node->left = nullptr;
    node->right = nullptr;
    if (parent != nullptr) {
        if (parent->left == node) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }

    if (node == root) {
        // 待删节点是根节点
        root = new_node;
    }

    return node;
}

template <typename T>
void BST<T>::remove(const T& v) {
    auto node = remove_node(root, v);
    if (node != nullptr) {
        delete node;
    }
}

#endif //DATASTRUCT_B_SEARCH_H
