#pragma once
#include <stdexcept>

template <typename T, size_t N>
class MyArray {
    T data[N];
public:
    T& operator[](size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t size() const {
        return N;
    }

    void fill(const T& value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }
};