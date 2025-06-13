
#include <iostream>

void foo(int x) {
    int unused;                     // -Wunused-variable
    if (x = 0) {                    // -Wparentheses (assignment in condition)
        std::cout << "never\n";
    }
}

int main() {
    unsigned int u = 0;
    for (int i = 10; i >= 0; --i) { // -Wsign-compare
        u += i;
    }
    char c = 300;                   // -Woverflow / -Wconversion
    foo(c);                         // -Wconversion
    return 0;
}
