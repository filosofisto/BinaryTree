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

    unique_ptr<BinaryTree<int>> tree = make_unique<BinaryTree<int>>();
    tree
        ->add(15)
        ->add(6)
        ->add(7)
        ->add(13)
        ->add(9)
        ->add(3)
        ->add(2)
        ->add(4)
        ->add(18)
        ->add(17)
        ->add(20)
        ;

    cout << "BinaryTree size: " << tree->size() << endl;
    int value;

    cout << "Desire value: ";
    cin >> value;

    if (tree->find(value)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not Found" << endl;
    }


    return EXIT_SUCCESS;
}