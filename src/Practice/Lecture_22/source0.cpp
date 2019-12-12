#include <thread>
#include <iostream>

int main() {
    unsigned int t = std::thread::hardware_concurrency();
    std:: cout<< t << std::endl;
    return 0;
}