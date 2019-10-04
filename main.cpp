#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    cout << "----------------------------------------" << endl;
    cout << "Binary Search Sample with C++ Templates" << endl;
    cout << "----------------------------------------" << endl;

    cout << "                         15" << endl;
    cout << "                 6                18" << endl;
    cout << "             3       7        17       20" << endl;
    cout << "         2       4       13" << endl;
    cout << "                     9" << endl;

    // left path
    auto node15 = make_shared<Node<int>>(Node<int>(15)); //root
    auto node6 = make_shared<Node<int>>(Node<int>(6));
    auto node7 = make_shared<Node<int>>(Node<int>(7));
    auto node13 = make_shared<Node<int>>(Node<int>(13));
    auto node9 = make_shared<Node<int>>(Node<int>(9));
    auto node3 = make_shared<Node<int>>(Node<int>(3));
    auto node2 = make_shared<Node<int>>(Node<int>(2));
    auto node4 = make_shared<Node<int>>(Node<int>(4));
    node15->setLeft(node6);
    node6->setRight(node7);
    node7->setRight(node13);
    node13->setLeft(node9);
    node6->setLeft(node3);
    node3->setRight(node4);
    node3->setLeft(node2);

    //right path
    auto node18 = make_shared<Node<int>>(Node<int>(18));
    auto node17 = make_shared<Node<int>>(Node<int>(17));
    auto node20 = make_shared<Node<int>>(Node<int>(20));
    node15->setRight(node18);
    node18->setLeft(node17);
    node18->setRight(node20);

    BinaryTree<int> tree = BinaryTree<int>(node15);

    int value;

    cout << "Procurar por: ";
    cin >> value;

    if (tree.find(value)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    /*delete(node15);
    delete(node6);
    delete(node7);
    delete(node13);
    delete(node9);
    delete(node3);
    delete(node2);
    delete(node4);
    delete(node18);
    delete(node17);
    delete(node20);*/

    return EXIT_SUCCESS;
}