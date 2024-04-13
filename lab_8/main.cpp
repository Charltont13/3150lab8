#include "LinkedList.h"
#include "LinkedListTests.h"  // Include the header with test declarations

#include <iostream>



int main() {
    LinkedList list;
    list.constructList(5);
    
    std::cout << "Main list:" << std::endl;
    list.displayList();
    
    auto copyNodes = list.generateWeakNodeList();
    
    std::cout << "\nCopy nodes (weak_ptrs) before deletion:" << std::endl;
    list.displayWeakList(copyNodes);
    
    list.clear();
    
    std::cout << "\nCopy nodes (weak_ptrs) after deletion:" << std::endl;
    list.displayWeakList(copyNodes);
    



    testConstructList();
    testGenerateWeakNodeList();
    testClearList();
    return 0;
}
