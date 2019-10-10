//
// Created by Eduardo Ribeiro da Silva on 04/10/19.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class BinaryTree {
public:
    explicit BinaryTree();
    virtual ~BinaryTree();

    bool find(const T &data) const;
    BinaryTree<T>* add(const T &data);
    bool empty() const;
    size_t size() const;
private:
    bool find(shared_ptr<Node<T>> node, const T &data) const;
    void add(shared_ptr<Node<T>> node, const T&data);

    shared_ptr<Node<T>> root;
    size_t _size;
};

template<typename T>
BinaryTree<T>::BinaryTree(): _size(0)
{

}

template<typename T>
BinaryTree<T>::~BinaryTree() = default;


template<typename T>
bool BinaryTree<T>::find(const T &data) const
{
    return find(root, data);
}

template<typename T>
bool BinaryTree<T>::find(shared_ptr<Node<T>> node, const T &data) const
{
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

template<typename T>
BinaryTree<T>* BinaryTree<T>::add(const T &data)
{
    if (root == nullptr) {
        root = make_shared<Node<T>>(data);
        _size++;
    } else {
        add(root, data);
    }

    return this;
}

template<typename T>
void BinaryTree<T>::add(shared_ptr<Node<T>> node, const T &data)
{
    if (data >= node->getData()) {
        if (node->right() == nullptr) {
            shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
            node->setRight(newNode);
            _size++;
        } else {
            add(node->right(), data);
        }
    } else {
        if (node->left() == nullptr) {
            shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
            node->setLeft(newNode);
            _size++;
        } else {
            add(node->left(), data);
        }
    }
}

template<typename T>
bool BinaryTree<T>::empty() const {
    return _size == 0;
}

template<typename T>
size_t BinaryTree<T>::size() const {
    return _size;
}

#endif //BINARYTREE_BINARYTREE_H
