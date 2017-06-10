//
// Created by duzalber on 30.05.17.
//

#ifndef JIMP_EXERCISES_BST_H
#define JIMP_EXERCISES_BST_H

#include <iostream>
#include <memory>
#include <algorithm>

namespace tree {
    template <class T> class Tree;
    template <class T> class InOrderTreeIterator;
    template <class T> class PostOrderTreeIterator;
    template <class T> class PreOrderTreeIterator;

    template<class T>
    class Node {
    private:
        T value;
        std::unique_ptr<Node<T>> right;
        std::unique_ptr<Node<T>> left;
    public:
        Node(const T &value);

        friend class Tree<T>;
        friend class InOrderTreeIterator<T>;
        friend class PostOrderTreeIterator<T>;
        friend class PreOrderTreeIterator<T>;
    };

    template <class T>
    Node<T>::Node(const T &value) {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }

    template<class T>
    class Tree {
    private:
        std::unique_ptr<Node<T>> root;
        size_t size;
        size_t depth;
    public:
        Tree(): root(nullptr), size(0), depth(0) {};
        Tree(const T &value);
        Tree(const std::initializer_list<T> initializer_list);

        void Insert(const T & value);
        bool Find(const T & value) const;

        size_t Depth() const;
        size_t Size() const;

        T Value() const;
        Node<T>* Root() const;
    };

    template<class T>
    Tree<T>::Tree(const T &value) {
        root = nullptr;
        size = depth = 0;
        Insert(value);
    }

    template<class T>
    Tree<T>::Tree(const std::initializer_list<T> list) {
        root = nullptr;
        size = depth = 0;
        for(const auto &n : list) {
            Insert(n);
        }
    }

    template<class T>
    void Tree<T>::Insert(const T & value){
        size++;

        Node<T>* y = nullptr;
        auto x = root.get();
        size_t new_depth = 1;

        while(x) {
            y = x;
            if(value < x->value) x = x->left.get();
            else x = x->right.get();
            new_depth++;
        }

        if(y == nullptr){
            root = std::make_unique<Node<T>>(value);
            depth = 1;
            return;
        }
        else if(value < y->value) y->left = std::make_unique<Node<T>>(value);
        else y->right = std::make_unique<Node<T>>(value);

        depth = std::max(new_depth, depth);
    }

    template<class T>
    bool Tree<T>::Find(const T & value) const {
        Node<T>* current = root.get();

        while(current->value != value && current != nullptr) {
            if(value < (*current)) current = current->left.get();
            else current = current->right.get();
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

    template<class T>
    Node<T>* Tree<T>::Root() const {
        return root.get();
    }

}
#endif //JIMP_EXERCISES_BST_H
