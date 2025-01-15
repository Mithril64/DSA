#include <iostream>
#include <stdexcept>

template <typename T, size_t N>
class StaticArray {
private:
    T data[N];

public:
    StaticArray() {
        for (size_t i = 0; i < N; ++i) {
            data[i] = N;
        }
    }

    T& at(size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Const overload
    const T& at(size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& operator[](size_t index) {
        return data[index];
    }

    // Const overload
    const T& operator[](size_t index) const {
        return data[index];
    }

    constexpr size_t size() const {
        return N;
    }

    // Fill all elements with the same value
    void fill(const T& value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }

    T* begin() { return data; }
    T* end() { return data + N; }
    const T* begin() const { return data; }
    const T* end() const { return data + N; }
};