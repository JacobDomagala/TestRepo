#include <iostream>
#include <string>
#include <vector>

class Example {
    int* ptr;

public:
    Example() : ptr(new int(42)) {}  // Memory leak potential

    void setPtr(int* p) {
        delete ptr;  // Potential double delete
        ptr = p;
    }

    ~Example() {
        delete ptr;  // Potential double delete
    }
};

int divide(int a, int b) {
    if (b == 0) {
        std::cout << "Division by zero!" << std::endl;  // Exception not thrown
        return -1;
    }
    return a / b;
}

int main() {
    Example ex;
    int x = 10;
    int y = 0;
    std::cout << divide(x, y) << std::endl;  // Divide by zero at runtime

    int* ptr = nullptr;
    std::cout << *ptr << std::endl;  // Dereferencing null pointer

    std::vector<int> vec;
    std::cout << vec[10] << std::endl;  // Out of bounds vector access

    std::vector<int> unusedvec;

    return 0;
}
