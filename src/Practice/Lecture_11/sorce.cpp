#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector <std::string> myVector;
//    auto iter = myVector.begin(); // тоже самое, но лучше

    if (myVector.empty())
        std::cout << "EMPTY" << std::endl;

    myVector.push_back("String");
    myVector.push_back("String2");
    std::vector<std::string>::iterator iter = myVector.begin();
    myVector.insert(iter, "New String");

    for (std::vector<std::string>::iterator it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << std::endl;

    }

    for (auto & it : myVector) {
        std::cout << it << std::endl;
    }
    return 0;
}