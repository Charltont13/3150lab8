#include <cassert>
#include "LinkedList.cpp"

void testListConstruction() {
    LinkedList list;
    list.build_node_list(3);
    auto weakNodes = list.build_copyNodes_weak_ptrs(); // Assuming this now returns std::vector<std::weak_ptr<LinkedList::Node>>

    // The list should have exactly 3 nodes
    assert(weakNodes.size() == 3);

    // Validate the data in the list
    int expectedValue = 1;
    for (const auto& weakNode : weakNodes) {
        auto node = weakNode.lock(); // Directly use weak_ptr here
        assert(node != nullptr);
        assert(node->data == expectedValue++);
    }

    std::cout << "testListConstruction passed." << std::endl;
}

void testListClear() {
    LinkedList list;
    list.build_node_list(5);
    list.delete_node_shared_ptr_list();
    auto weakNodes = list.build_copyNodes_weak_ptrs(); // Adjusted for std::weak_ptr

    // After clearing, the list should have no nodes
    assert(weakNodes.empty());

    std::cout << "testListClear passed." << std::endl;
}

void tests() {
    testListConstruction();
    testListClear();

    std::cout << "All tests passed." << std::endl;
}
