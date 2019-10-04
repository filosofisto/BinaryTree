//
// Created by Eduardo Ribeiro da Silva on 04/10/19.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

#include <memory>

using namespace std;

template <typename T>
class Node {
public:
    explicit Node(const T &data);
    ~Node();

    T getData() const;
    void setLeft(Node<T> *node);
    void setRight(Node<T> *node);

    Node<T> *left() const;
    Node<T> *right() const;
private:
    T data;
    Node<T> *_left;
    Node<T> *_right;
};

template<typename T>
Node<T>::Node(const T &data): data(data), _left(nullptr), _right(nullptr)
{

}

template<typename T>
Node<T>::~Node() = default;

template<typename T>
T Node<T>::getData() const {
    return data;
}

template<typename T>
void Node<T>::setLeft(Node<T> *node) {
    this->_left = node;
}

template<typename T>
void Node<T>::setRight(Node<T> *node) {
    this->_right = node;
}

template<typename T>
Node<T>* Node<T>::left() const {
    return this->_left;
}

template<typename T>
Node<T>* Node<T>::right() const {
    return this->_right;
}

#endif //BINARYTREE_NODE_H
