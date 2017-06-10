//
// Created by albert on 03.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "../tree/Tree.h"
#include <queue>
#include <stack>

namespace tree {
    
    //========================================================
    //INORDER
    //========================================================
    
    template<class T>
    class InOrderTreeIterator {
    private:
        std::queue<const Node<T> *> Queue;
    public:
        InOrderTreeIterator(){};
        InOrderTreeIterator(const Node<T>* root);

        void deQueue(const Node<T>* root);

        InOrderTreeIterator<T> & operator++();
        bool operator!= (const InOrderTreeIterator<T> other) const;
        T operator*();
    };

    template <class T>
    void InOrderTreeIterator<T>::deQueue(const Node<T>* root) {
        if(root) {
            deQueue(root->left.get());
            Queue.push(root);
            deQueue(root->right.get());
        }
    }

    template <class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(const Node<T>* root) {
        deQueue(root);
    }

    template <class T>
    InOrderTreeIterator<T> & InOrderTreeIterator<T>::operator++() {
        Queue.pop();

        return *this;
    }

    template <class T>
    T InOrderTreeIterator<T>::operator*() {
        return Queue.front()->value;
    }

    template <class T>
    bool InOrderTreeIterator<T>::operator!=(const InOrderTreeIterator<T> other) const {
        if(Queue.empty() && other.Queue.empty()) return false;
        else if(Queue.empty() || other.Queue.empty()) return true;
        else return (Queue.front() != other.Queue.front());
    }

    template <class T>
    class InOrderTreeView {
    private:
        const Node<T>* root;
    public:
        InOrderTreeView(const Tree<T>* tree) : root(tree->Root()) {};
        InOrderTreeIterator<T> begin();
        InOrderTreeIterator<T> end();
    };

    template <class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::begin() {
        return InOrderTreeIterator<T>(root);
    }

    template <class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::end() {
        return InOrderTreeIterator<T>();
    }

    template <class T>
    InOrderTreeView<T> InOrder(const Tree<T>* tree) {
        return InOrderTreeView<T>(tree);
    }

    //========================================================
    //POSTORDER
    //========================================================

    template<class T>
    class PostOrderTreeIterator {
    private:
        std::queue<const Node<T> *> Queue;
    public:
        PostOrderTreeIterator(){};
        PostOrderTreeIterator(const Node<T>* root);

        void deQueue(const Node<T>* root);

        PostOrderTreeIterator<T> & operator++();
        bool operator!= (const PostOrderTreeIterator<T> other) const;
        T operator*();
    };

    template <class T>
    void PostOrderTreeIterator<T>::deQueue(const Node<T>* root) {
        if(root) {
            deQueue(root->left.get());
            deQueue(root->right.get());
            Queue.push(root);
        }
    }

    template <class T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator(const Node<T>* root) {
        deQueue(root);
    }

    template <class T>
    PostOrderTreeIterator<T> & PostOrderTreeIterator<T>::operator++() {
        Queue.pop();

        return *this;
    }

    template <class T>
    T PostOrderTreeIterator<T>::operator*() {
        return Queue.front()->value;
    }

    template <class T>
    bool PostOrderTreeIterator<T>::operator!=(const PostOrderTreeIterator<T> other) const {
        if(Queue.empty() && other.Queue.empty()) return false;
        else if(Queue.empty() || other.Queue.empty()) return true;
        else return (Queue.front() != other.Queue.front());
    }

    template <class T>
    class PostOrderTreeView {
    private:
        const Node<T>* root;
    public:
        PostOrderTreeView(const Tree<T>* tree) : root(tree->Root()) {};
        PostOrderTreeIterator<T> begin();
        PostOrderTreeIterator<T> end();
    };

    template <class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::begin() {
        return PostOrderTreeIterator<T>(root);
    }

    template <class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::end() {
        return PostOrderTreeIterator<T>();
    }

    template <class T>
    PostOrderTreeView<T> PostOrder(const Tree<T>* tree) {
        return PostOrderTreeView<T>(tree);
    }
    
    //========================================================
    //POSTORDER
    //========================================================

    template<class T>
    class PreOrderTreeIterator {
    private:
        std::queue<const Node<T> *> Queue;
    public:
        PreOrderTreeIterator(){};
        PreOrderTreeIterator(const Node<T>* root);

        void deQueue(const Node<T>* root);

        PreOrderTreeIterator<T> & operator++();
        bool operator!= (const PreOrderTreeIterator<T> other) const;
        T operator*();
    };

    template <class T>
    void PreOrderTreeIterator<T>::deQueue(const Node<T>* root) {
        if(root) {
            Queue.push(root);
            deQueue(root->left.get());
            deQueue(root->right.get());
        }
    }

    template <class T>
    PreOrderTreeIterator<T>::PreOrderTreeIterator(const Node<T>* root) {
        deQueue(root);
    }

    template <class T>
    PreOrderTreeIterator<T> & PreOrderTreeIterator<T>::operator++() {
        Queue.pop();

        return *this;
    }

    template <class T>
    T PreOrderTreeIterator<T>::operator*() {
        return Queue.front()->value;
    }

    template <class T>
    bool PreOrderTreeIterator<T>::operator!=(const PreOrderTreeIterator<T> other) const {
        if(Queue.empty() && other.Queue.empty()) return false;
        else if(Queue.empty() || other.Queue.empty()) return true;
        else return (Queue.front() != other.Queue.front());
    }

    template <class T>
    class PreOrderTreeView {
    private:
        const Node<T>* root;
    public:
        PreOrderTreeView(const Tree<T>* tree) : root(tree->Root()) {};
        PreOrderTreeIterator<T> begin();
        PreOrderTreeIterator<T> end();
    };

    template <class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::begin() {
        return PreOrderTreeIterator<T>(root);
    }

    template <class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::end() {
        return PreOrderTreeIterator<T>();
    }

    template <class T>
    PreOrderTreeView<T> PreOrder(const Tree<T>* tree) {
        return PreOrderTreeView<T>(tree);
    }
}
#endif //JIMP_EXERCISES_TREEITERATORS_H
