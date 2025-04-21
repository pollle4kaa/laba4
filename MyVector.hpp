#pragma once
#include <iostream>
#include <algorithm>

class MyVector {
    int* data;
    size_t size;
public:
    //Простой конструктор
    MyVector(size_t s = 0) : size(s), data(new int[s]) {
        for (size_t i = 0; i < size; i++) {
            data[i] = i;
        }
    }

    //Конструктор копирования
    MyVector(const MyVector& another) : size(another.size), data(new int[another.size]) {
        std::copy(another.data, another.data + size, data);
    }

    //Оператор присваивания копированием
    MyVector& operator=(const MyVector& another) {
        if (this != &another) {
            delete[] data;
            size = another.size;
            data = new int[size];
            std::copy(another.data, another.data + size, data);
        }
        return *this;
    }

    //Move конструктор
    MyVector(MyVector&& another) noexcept : data(another.data), size(another.size) {
        another.data = nullptr;
        another.size = 0;
    }

    //Move оператор присваивания
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

    //Деструктор
    ~MyVector() {
        delete[] data;
    }
};