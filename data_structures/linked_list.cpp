#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        size_t data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t size;

public: 
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        for (Node* current = other.head; current != nullptr; current = current->next) {
            push_back(current->data);
        }
    }

    LinkedList(LinkedList&& other) noexcept
        : head(other.head), tail(other.tail), size(other.size) {
        other.head = other.tail = nullptr;
        other.size = 0;
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) return *this; 
        head = tail = nullptr;
        size = 0;
        clear();
        for (Node* current = other.head; current != nullptr; current = current->next) {
            push_back(current->data);
        }
        return *this;
    }

    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this == &other) return *this;
        clear();
        head = other.head;
        tail = other.tail;
        size = other.size;
        other.head = other.tail = nullptr;
        other.size = 0;

        return *this;
    }

    void push_back(const T& value) {
        Node new_node = new Node(value);

        if (tail) {
            tail->next = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;
        ++size;
    }

    void push_front(const T& value) {
        Node new_node = new Node(value);

        if (!head) tail = new_node;
        new_node->next = head;
        head = new_node;
        ++size;
    }

    void pop_front() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        --size;
    }

    void pop_back() {
        if (!head) {
            throw std::out_of_range("List is empty");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            current->next = nullptr;
        }
        --size;
    }

    
};