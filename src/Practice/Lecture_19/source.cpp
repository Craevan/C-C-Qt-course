#include <algorithm>
#include <iostream>
void my_swap(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int main() {
    int a =10;
    int b = 11;
    my_swap(a, b);
    std::cout << a << b;
    return EXIT_SUCCESS;
}