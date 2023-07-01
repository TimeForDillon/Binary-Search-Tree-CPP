/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 6 : Binary Search Tree
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/25/2021
*******************************************************************************/

#include <iostream>
#include "EmployeeInfo.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    // PROCESSING - instantiate all employeeInfo objects
    EmployeeInfo e1(1021, "John Williams"), e2(1057, "Bill Witherspoon"),
            e3(2487, "Jennifer Twain"), e4(3769, "Sophia Lancaster"),
            e5(1017, "Debbie Reece"), e6(1275, "George McMullen"),
            e7(1899, "Ashley Smith"), e8(4218, "Josh Plemmons");

    // PROCESSING - load BST with employeeInfo objects
    BinarySearchTree<int> myTree;
    myTree.insertNode(e1.getID());
    myTree.insertNode(e2.getID());
    myTree.insertNode(e3.getID());
    myTree.insertNode(e4.getID());
    myTree.insertNode(e5.getID());
    myTree.insertNode(e6.getID());
    myTree.insertNode(e7.getID());
    myTree.insertNode(e8.getID());

    // OUTPUT - output all BST data below
    cout << "Displaying tree in order: ";
    myTree.displayInOrder();
    cout << endl;cout << "Displaying tree post order: ";
    myTree.displayPostOrder();
    cout << endl;
    cout << "Displaying tree pre order: ";
    myTree.displayPreOrder();
    cout << endl;
    cout << "Displaying tree size: " << myTree.size() << endl;
    cout << "Displaying leaf count: " << myTree.leafCount() << endl;
    cout << "Displaying non-leaf count: " << myTree.nonLeafCount() << endl << endl;

    cout << "Testing copy constructor..." << endl;
    BinarySearchTree<int> myTree2(myTree);
    cout << "Displaying tree2 in order: ";
    myTree2.displayInOrder();
    cout << endl;cout << "Displaying tree2 post order: ";
    myTree2.displayPostOrder();
    cout << endl;
    cout << "Displaying tree2 pre order: ";
    myTree2.displayPreOrder();
    cout << endl;
    cout << "Displaying tree2 size: " << myTree.size() << endl;
    cout << "Displaying tree2 leaf count: " << myTree2.leafCount() << endl;
    cout << "Displaying tree2 non-leaf count: " << myTree2.nonLeafCount() << endl << endl;

    cout << "Testing assignment operator..." << endl;
    BinarySearchTree<int> myTree3(myTree);
    cout << "Displaying tree2 in order: ";
    myTree3.displayInOrder();
    cout << endl;cout << "Displaying tree2 post order: ";
    myTree3.displayPostOrder();
    cout << endl;
    cout << "Displaying tree2 pre order: ";
    myTree3.displayPreOrder();
    cout << endl;
    cout << "Displaying tree2 size: " << myTree.size() << endl;
    cout << "Displaying tree2 leaf count: " << myTree3.leafCount() << endl;
    cout << "Displaying tree2 non-leaf count: " << myTree3.nonLeafCount() << endl << endl;

    return 0;
}
