//
// Created by zhijun yu on 2019/4/14.
//

#ifndef DATASTRUCT_TREE_H
#define DATASTRUCT_TREE_H

#include <iostream>
#include <stack>
#include <queue>

/*
 * Tree nodes' structure
 *   template <typename T>
 *   struct TreeNode {
 *       T value;
 *       TreeNode<T>* left;
 *       TreeNode<T>* right;
 *   };
 */

template <typename T>
class Tree {
protected:
    void delete_tree(T *node);
    void pre_order_traversal(T *node);
    void in_order_traversal(T *node);
    void post_order_traversal(T *node);
public:
    virtual T* get_root() = 0;

    int  get_height(T *node);

    // 递归方式遍历一棵树
    void pre_order_traversal() { pre_order_traversal(get_root()); }
    void in_order_traversal() { in_order_traversal(get_root()); }
    void post_order_traversal() { post_order_traversal(get_root()); }

    // 非递归遍历树
    void pre_order();
    void in_order();
    void post_order();
    void level_order();
};

template <typename T>
void Tree<T>::delete_tree(T *node) {
    // 递归方式
    if (node == nullptr) {
        return;
    }

    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <typename T>
int Tree<T>::get_height(T *node) {
    if (node == nullptr) {
        return 0;
    }

    int l = 1 + get_height(node->left);
    int r = 1 + get_height(node->right);

    return (l > r) ? l : r;
}

template <typename T>
void Tree<T>::pre_order_traversal(T *node) {
    if (node== nullptr) {
        return;
    }

    std::cout << node->value << std::endl;
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

template <typename T>
void Tree<T>::in_order_traversal(T *node) {
    if (node == nullptr) {
        return;
    }

    in_order_traversal(node->left);
    std::cout << node->value << std::endl;
    in_order_traversal(node->right);
}

template <typename T>
void Tree<T>::post_order_traversal(T *node) {
    if (node == nullptr) {
        return;
    }

    post_order_traversal(node->left);
    post_order_traversal(node->right);
    std::cout << node->value << std::endl;
}

template <typename T>
void Tree<T>::pre_order() {
    T* root = get_root();
    if (root == nullptr) {
        return;
    }

    auto st = std::stack<T*>();
    st.push(root);
    while(!st.empty()) {
        auto node = st.top();
        st.pop();
        std::cout << node->value << std::endl;
        if (node->right != nullptr) {
            st.push(node->right);
        }
        if (node->left != nullptr) {
            st.push(node->left);
        }
    }
}

template <typename T>
void Tree<T>::in_order() {
    T* root = get_root();
    if (root == nullptr) {
        return;
    }

    auto st = std::stack<T*>();
    st.push(root);
    T* node = root;
    while(!st.empty()) {
        while (node != nullptr && node->left != nullptr) {
            st.push(node->left);
            node = node->left;
        }

        // 此时node==nullptr
        T* tmp = st.top();
        st.pop();
        std::cout << tmp->value << std::endl;
        if (tmp->right != nullptr) {
            node = tmp->right;
            st.push(node);
        }
    }
}

template <typename T>
void Tree<T>::post_order() {
    T* root = get_root();
    if (root == nullptr) {
        return;
    }

    auto st = std::stack<T*>();
    st.push(root);
    T* node = root;
    T* last = nullptr;  // 用于记录上一次打印的节点
    while(!st.empty()) {
        while(node != nullptr && node->left != nullptr) {
            node = node->left;
            st.push(node);
        }

        // 此时node==nullptr
        T* tmp = st.top();
        if (tmp->right != nullptr && tmp->right != last) {
            node = tmp->right;
            st.push(node);
        } else {
            std::cout << tmp->value << std::endl;
            last = tmp;
            st.pop();
        }
    }
}

template <typename T>
void Tree<T>::level_order() {
    T* root = get_root();
    if (root == nullptr) {
        return ;
    }

    auto q = std::queue<T*>();
    q.push(root);
    T* last = root;   // 记录当前行最后一个节点
    T* nlast = nullptr; // 记录下一行最后一个节点
    while (!q.empty()) {
        T* tmp = q.front();
        q.pop();

        std::cout << tmp->value << "\t";
        if (tmp->left != nullptr) {
            q.push(tmp->left);
            nlast = tmp->left;
        }

        if (tmp->right != nullptr) {
            q.push(tmp->right);
            nlast = tmp->right;
        }

        if (tmp == last) {
            last = nlast;
            std::cout << std::endl;
        }
    }
}

#endif //DATASTRUCT_TREE_H
