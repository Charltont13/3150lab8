#include <iostream>
#include <memory>
#include <vector>
#include "LinkedList.h"

int main() {
    LinkedList list;

    // Constructing the list with 5 nodes
    list.constructList(5);
    std::cout << "Original Linked List: ";
    list.displayList();

    // Generating a vector of WeakNode objects from the list
    auto weakNodes = list.generateWeakNodeList();

    std::cout << "Weak Nodes Display before clearing the list: ";
    list.displayWeakList(weakNodes);

    // Clearing the list to demonstrate weak pointers
    list.clear();
    std::cout << "After clearing the main linked list:" << std::endl;

    std::cout << "Original Linked List: ";
    list.displayList();

    std::cout << "Weak Nodes Display after clearing the list: ";
    list.displayWeakList(weakNodes);

    return 0;
}
