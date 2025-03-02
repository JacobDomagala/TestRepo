#include <iostream>
#include <vector>

// Class to process data, with intentional issues for static analysis checks.
class DataProcessor {
public:
    // Constructor allocates memory, but the destructor doesn't free it.
    DataProcessor(int size) : size_(size) {
        data_ = new int[size_];  // Dynamic allocation (potential memory leak)
    }

    // Destructor intentionally missing delete[] to trigger memory leak warning.
    ~DataProcessor() {
        // Memory cleanup omitted intentionally.
    }

    // Process data by filling the array.
    void processData() {
        // Potential issue: if size_ is 0, this loop does nothing,
        // and accessing data_[0] later may be unsafe.
        for (int i = 0; i < size_; ++i) {
            data_[i] = i * 2;
        }
        if (size_ > 0) {
            std::cout << "First element: " << data_[0] << std::endl;
        }
    }

    // Returns an element at the given index.
    int getElement(int index) {
        // Improper bounds checking: if index is invalid, returns -1.
        // A static analyzer might flag this for potential misuse.
        if (index < 0 || index >= size_) {
            return -1;
        }
        return data_[index];
    }

private:
    int* data_;
    int size_;
};

int main() {
    // Create a processor with a valid size.
    DataProcessor processor(10);
    processor.processData();

    // Retrieve an element within bounds.
    int val = processor.getElement(5);
    std::cout << "Element at index 5: " << val << std::endl;

    // Intentional bug: using an uninitialized variable.
    int uninitialized;
    std::cout << "Uninitialized value: " << uninitialized << std::endl;

    // Intentional potential division by zero.
    int a = 10, b = 0;
    if (b == 0) {
        std::cerr << "Warning: Division by zero avoided" << std::endl;
    } else {
        std::cout << "Division result: " << a / b << std::endl;
    }

    return 0;
}