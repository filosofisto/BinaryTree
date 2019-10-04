//
// Created by Eduardo Ribeiro da Silva on 04/10/19.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include "Node.h"

template <typename T>
class BinaryTree {
public:
    explicit BinaryTree(shared_ptr<Node<T>> root);
    virtual ~BinaryTree();

    bool find(const T &data) const;
private:
    bool find(shared_ptr<Node<T>> node, const T &data) const;

    shared_ptr<Node<T>> root;
};

template<typename T>
BinaryTree<T>::BinaryTree(shared_ptr<Node<T>> root): root(root) {

}

template<typename T>
BinaryTree<T>::~BinaryTree() = default;


template<typename T>
bool BinaryTree<T>::find(const T &data) const {
    return find(root, data);
}

template<typename T>
bool BinaryTree<T>::find(shared_ptr<Node<T>> node, const T &data) const {
    if (node == nullptr) {
        //cout << "x" << endl;
        return false;
    }

    if (node->getData() == data) {
        //cout << "o" << endl;
        return true;
    }

    if (data < node->getData()) {
        //cout << "<--" << endl;
        return find(node->left(), data);
    }

    //cout << "-->" << endl;
    return find(node->right(), data);
}

#endif //BINARYTREE_BINARYTREE_H
