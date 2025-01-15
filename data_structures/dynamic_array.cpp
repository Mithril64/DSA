#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    DynamicArray(size_t initial_capacity = 4) 
        : data(new T[initial_capacity]), capacity(initial_capacity), size(0) {}
    
    ~DynamicArray() {
        delete[] data;
    }

    // Copy constructor
    DynamicArray(const DynamicArray& other)
        : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
        std::copy(other.data, other.data + size, data);
    }
    
    // Move constructor
    DynamicArray(DynamicArray&& other) noexcept
        : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }

    DynamicArray& operator=(const DynamicArray other) {
        if (this == &other) return *this;
        delete[] data;        
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        std::copy(other.data, other.data + size, data);

        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) return *this;
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        size = other.size;
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;

        return *this;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }
        --size;
    }

    T& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& at(const size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& operator=(size_t index) {
        return data[index];
    }

    T& operator=(const size_t index) const {
        return data[index];
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    void clear() {
        size = 0;
    }
};