#include "MyVector.hpp"
#include "MyArray.hpp"
#include <chrono>
#include <iostream>
#include <iomanip> //��� std::fixed � std::setprecision
#include <vector>
#include <list>
#include <set>
#include <string> 

//�������, �������� �������� �������
template <typename T>
void mySwap(T& a, T& b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

//��������� � �������
template <typename Container>
std::string containerToString(const Container& c) {
    std::string res = "[";
    bool first = true;
    for (const auto& item : c) {
        if (!first) res += ", ";
        res += std::to_string(item); //��� �����
        first = false;
    }
    return res + "]";
}

int main() {
    const size_t N = 10000000;

    //���� �����������
    {
        MyVector v1(N);
        auto start = std::chrono::high_resolution_clock::now();
        MyVector v2 = v1; //�����������
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Copy time: " << std::fixed << std::setprecision(7) << std::chrono::duration<double>(end - start).count() << " sec" << std::endl;
    }

    //���� �����������
    {
        MyVector v1(N);
        auto start = std::chrono::high_resolution_clock::now();
        MyVector v2 = std::move(v1); //�����������
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Move time: " << std::fixed << std::setprecision(7) << std::chrono::duration<double>(end - start).count() << " sec" << std::endl;
    }

    //���� mySwap
    {
        int x = 1, y = 2;
        std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
        mySwap(x, y);
        std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    }

    //���� containerToString
    {
        std::vector<int> v = {1, 2, 3};
        std::cout << "Vector: " << containerToString(v) << std::endl;
    }

    //���� MyArray
    {
        MyArray<std::string, 3> arr;
        arr[0] = "Hello";
        arr[1] = "World";
        std::cout << "Array size: " << arr.size() << std::endl;
        std::cout << "First element: " << arr[0] << std::endl;
    }
    return 0;
}