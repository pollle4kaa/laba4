#pragma once
#include <iostream>
#include <algorithm>

class MyVector {
    int* data;
    size_t size;
public:
    //������� �����������
    MyVector(size_t s = 0) : size(s), data(new int[s]) {
        for (size_t i = 0; i < size; i++) {
            data[i] = i;
        }
    }

    //����������� �����������
    MyVector(const MyVector& another) : size(another.size), data(new int[another.size]) {
        std::copy(another.data, another.data + size, data);
    }

    //�������� ������������ ������������
    MyVector& operator=(const MyVector& another) {
        if (this != &another) {
            delete[] data;
            size = another.size;
            data = new int[size];
            std::copy(another.data, another.data + size, data);
        }
        return *this;
    }

    //Move �����������
    MyVector(MyVector&& another) noexcept : data(another.data), size(another.size) {
        another.data = nullptr;
        another.size = 0;
    }

    //Move �������� ������������
    MyVector& operator=(MyVector&& another) noexcept {
        if (this != &another) {
            delete[] data;
            data = another.data;
            size = another.size;
            another.data = nullptr;
            another.size = 0;
        }
        return *this;
    }

    //����������
    ~MyVector() {
        delete[] data;
    }
};