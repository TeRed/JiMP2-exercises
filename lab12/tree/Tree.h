//
// Created by duzalber on 30.05.17.
//

#ifndef JIMP_EXERCISES_BST_H
#define JIMP_EXERCISES_BST_H

#include <iostream>
#include <memory>
#include <algorithm>

namespace tree {
    template<class T> class Tree;
    template<class T> class Node;

    template<class T>
    bool operator<(const Node<T> &a, const Node<T> &b) {
        return (a.value < b.value);
    }

    template<class T>
    bool operator!=(const Node<T> &a, const Node<T> &b) {
        return (a.value != b.value);
    }

    template<class T>
    class Node {
    public:
        Node();
        Node(const T &val);
        ~Node();
    private:
        friend class Tree<T>;
        friend bool operator< <>(const Node<T> &a, const Node<T> &b);
        friend bool operator!= <>(const Node<T> &a, const Node<T> &b);
        T value;
        Node<T> *right;
        Node<T> *left;
    };

    template<class T>
    Node<T>::Node() {
        right = nullptr;
        left = nullptr;
    }

    template<class T>
    Node<T>::Node(const T &value) {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }

    template<class T>
    Node<T>::~Node() {
        delete right;
        delete left;
    }

    template<class T>
    class Tree {
    public:
        Tree();
        Tree(std::initializer_list<T> list);
        ~Tree();
        void Insert(const T &e);
        bool Find(const T &e);
        size_t Depth() const;
        size_t Size() const;
        T Value() const;
    private:
        Node<T>* root;
        size_t size;
        size_t depth;
    };

    template<class T>
    Tree<T>::Tree() {
        root = nullptr;
        size = depth = 0;
    }

    template<class T>
    Tree<T>::Tree(std::initializer_list<T> list) {
        root = nullptr;
        size = depth = 0;
        for(const auto &n : list) {
            Insert(n);
        }
    }

    template<class T>
    Tree<T>::~Tree() {
        delete root;
    }

    template<class T>
    void Tree<T>::Insert(const T &e){
        size++;
        Node<T> *node = new Node<T>;
        node->value = e;

        if(!root) {
            root = node;
            depth = 1;
            return;
        }

        size_t actual_depth = 1;

        Node<T> *current = root;

        while(current->left != nullptr && current->right != nullptr) {
            if(*node < *current) current = current->left;
            else current = current->right;
            actual_depth++;
        }

        if(*node < *current) current->left = node;
        else current->right = node;

        depth = std::max(++actual_depth, depth);

        return;
    }

    template<class T>
    bool Tree<T>::Find(const T &e){
        Node<T> *current = root;
        Node<T> node(e);

        while(*current != node && current != nullptr) {
            if(node < (*current)) current = current->left;
            else current = current->right;
        }

        return current;
    }

    template<class T>
    size_t Tree<T>::Depth() const {
        return depth;
    };

    template<class T>
    size_t Tree<T>::Size() const {
        return size;
    };

    template<class T>
    T Tree<T>::Value() const {
        return root->value;
    }
}
#endif //JIMP_EXERCISES_BST_H
