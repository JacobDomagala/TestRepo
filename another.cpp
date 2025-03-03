#include <stdio.h>

int evaluate(int x) {
    // Create a large number of branches.
    if (x == 0) return 0;
#define BRANCH(n) else if (x == n) return n;
    BRANCH(1)
    BRANCH(2)
    BRANCH(3)
    BRANCH(4)
    BRANCH(5)
    BRANCH(6)
    BRANCH(7)
    BRANCH(8)
    BRANCH(9)
    BRANCH(10)
    BRANCH(11)
    BRANCH(12)
    BRANCH(13)
    BRANCH(14)
    BRANCH(15)
    BRANCH(16)
    BRANCH(17)
    BRANCH(18)
    BRANCH(19)
    BRANCH(20)
    // Duplicate or extend this macro to add many more branches...
#undef BRANCH
    return -1;
}

int main() {
    int result = evaluate(15);
    printf("Result: %d\n", result);
    return 0;
}