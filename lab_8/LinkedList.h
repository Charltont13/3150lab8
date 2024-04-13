// LinkedList.h

#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include <iostream>
#include <memory>
#include <vector>

class LinkedList {
    struct Node {
        int value;
        std::shared_ptr<Node> nextNode;

        // Constructors
        explicit Node(int val = 0, std::shared_ptr<Node> next = nullptr)
            : value(val), nextNode(std::move(next)) {}
    };

    struct WeakNode {
        std::weak_ptr<Node> nodePtr;

        explicit WeakNode(std::shared_ptr<Node> ptr)
            : nodePtr(std::move(ptr)) {}
    };

public:
    LinkedList() : head(nullptr), size(0) {}

    // Build the list with a series of nodes
    void constructList(int count) {
        if (count <= 0) return;

        head = std::make_shared<Node>(1);
        auto temp = head;

        for (int i = 2; i <= count; ++i, temp = temp->nextNode) {
            temp->nextNode = std::make_shared<Node>(i);
        }

        size = count;
    }

    // Generate a vector of WeakNodes pointing to each Node in the list
    std::vector<WeakNode> generateWeakNodeList() const {
        std::vector<WeakNode> weakNodes;
        auto temp = head;

        while (temp) {
            weakNodes.emplace_back(temp);
            temp = temp->nextNode;
        }

        return weakNodes;
    }

    // Clear the list
    void clear() {
        head.reset();
        size = 0;
    }

    // Display the list using shared pointers
    void displayList() const {
        for (auto temp = head; temp; temp = temp->nextNode) {
            std::cout << temp->value << " -> ";
        }
        std::cout << "End" << std::endl;
    }

    // Display the list using weak pointers
    void displayWeakList(const std::vector<WeakNode>& weakNodes) const {
        for (const auto& weakNode : weakNodes) {
            if (auto sp = weakNode.nodePtr.lock()) {
                std::cout << sp->value << " -> ";
            } else {
                std::cout << "Expired -> ";
            }
        }
        std::cout << "End" << std::endl;
    }

    ~LinkedList() = default;

private:
    std::shared_ptr<Node> head;
    int size;
};

#endif // LINKED_LIST_CPP
