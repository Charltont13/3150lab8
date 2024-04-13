// test_LinkedList.cpp

#include "LinkedList.h"
#include <iostream>
#include <cassert>

// Helper function to count nodes in the list
int countNodes(const LinkedList& list) {
    int count = 0;
    auto weakNodes = list.generateWeakNodeList();
    for (const auto& weakNode : weakNodes) {
        if (auto sp = weakNode.nodePtr.lock()) {
            ++count;
        }
    }
    return count;
}

void testConstructList() {
    LinkedList list;
    list.constructList(5);
    assert(countNodes(list) == 5 && "testConstructList failed.");
    std::cout << "testConstructList passed." << std::endl;
}

void testGenerateWeakNodeList() {
    LinkedList list;
    list.constructList(5);
    auto weakNodes = list.generateWeakNodeList();
    assert(weakNodes.size() == 5 && "testGenerateWeakNodeList failed.");
    std::cout << "testGenerateWeakNodeList passed." << std::endl;
}

void testClearList() {
    LinkedList list;
    list.constructList(5);
    list.clear();
    assert(countNodes(list) == 0 && "testClearList failed.");
    std::cout << "testClearList passed." << std::endl;
}



