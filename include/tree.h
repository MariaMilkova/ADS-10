// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> pointers;
    };
    Node* root;
    std::vector<std::vector<char>> vectV;
    Node* addNode(Node* root, std::vector<char> help) {
        if (root == nullptr) {
            root = new Node;
        }
        if (help.empty()) {
            return root;
        }
        for (int i = 0; i < help.size(); i++) {
            Node* child = new Node;
            child->value = help[i];
            root->pointers.push_back(child);
            std::vector<char> temp = help;
            temp.erase(temp.begin() + i);
            addNode(root->pointers[i], temp);
        }
        return root;
    }
    std::vector<char> permutation(Node* root, std::vector<char>* character) {
        for (int i = 0; i < root->pointers.size(); i++) {
            character->push_back(root->pointers[i]->value);
            permutation(root->pointers[i], character);
            if (root->pointers[i]->pointers.empty()) return *character;
            permutation(root->pointers[i], character);
            if (character->size() != 1) {
                vectV.push_back(*character);
            }
            for (int j = 0; j < character->size(); j++) {
                character->pop_back();
            }
        }
        return *character;
    }

 public:
    explicit Tree(std::vector<char> poineters) {
        root = nullptr;
        root = addNode(root, poineters);
        std::vector<char> ch;
        permutation(root, &ch);
    }
    std::vector<char> perm(int i) const {
        if (vectV.size() < i) {
            return std::vector<char>();
        }
        return vectV[i];
    }
};
#endif // INCLUDE_TREE_H_
