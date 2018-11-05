//
// Created by przemekk on 18.03.17.
//

#include "SmartTree.h"
#include <iostream>

namespace datastructures {
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        auto p = std::make_unique<SmartTree>();
        p->value = value;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left = move(left_subtree);
        return tree;
    }
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right = move(right_subtree);
        return tree;
    }
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left != nullptr) PrintTreeInOrder(unique_ptr->left, out);
        (*out) << unique_ptr->value << ", ";
        if(unique_ptr->right != nullptr) PrintTreeInOrder(unique_ptr->right, out);
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        std::string to_return = "";
        to_return += "[";
        to_return += std::to_string(tree->value);
        to_return += " ";
        if(tree->left != nullptr) to_return += DumpTree(tree->left);
        else to_return += "[none]";
        to_return += " ";
        if(tree->right != nullptr) to_return += DumpTree(tree->right);
        else to_return += "[none]";
        to_return += "]";
        return to_return;
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree){
        if(tree == "[none]") return nullptr;
        std::string number = "";
        std::string left = "[";
        std::string right = "[";
        std::string copy_tree = tree;
        int count = 1;
        copy_tree.erase(0,1);
        while(copy_tree[0] != ' '){
            number += copy_tree[0];
            copy_tree.erase(0,1);
        }
        copy_tree.erase(0,2);
        while(count != 0){
            if(copy_tree[0] == '[') count++;
            else if(copy_tree[0] == ']') count--;
            left += copy_tree[0];
            copy_tree.erase(0,1);
        }
        count = 1;
        copy_tree.erase(0,2);
        while(count != 0){
            if(copy_tree[0] == '[') count++;
            else if(copy_tree[0] == ']') count--;
            right += copy_tree[0];
            copy_tree.erase(0,1);
        }

        std::unique_ptr <SmartTree> root = CreateLeaf(std::stoi(number));
        root->left = std::move(RestoreTree(left));
        root->right = std::move(RestoreTree(right));
        return root;
    }
}