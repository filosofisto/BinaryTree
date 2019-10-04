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
    void setLeft(shared_ptr<Node<T>> node);
    void setRight(shared_ptr<Node<T>> node);

    shared_ptr<Node<T>> left() const;
    shared_ptr<Node<T>> right() const;
private:
    T data;
    shared_ptr<Node<T>> _left;
    shared_ptr<Node<T>> _right;
};

template<typename T>
Node<T>::Node(const T &data): data(data)
{

}

template<typename T>
Node<T>::~Node() = default;

template<typename T>
T Node<T>::getData() const {
    return data;
}

template<typename T>
void Node<T>::setLeft(shared_ptr<Node<T>> node) {
    this->_left = node;
}

template<typename T>
void Node<T>::setRight(shared_ptr<Node<T>> node) {
    this->_right = node;
}

template<typename T>
shared_ptr<Node<T>> Node<T>::left() const {
    return this->_left;
}

template<typename T>
shared_ptr<Node<T>> Node<T>::right() const {
    return this->_right;
}

#endif //BINARYTREE_NODE_H
