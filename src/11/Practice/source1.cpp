#include <map>
#include <iostream>
#include <set>

int main() {
    std::map<std::string,int> myMap;

    myMap.insert(std::pair<std::string,int>("Str",100));
    myMap.insert(std::pair<std::string,int>("Astr",101));
    myMap.insert(std::pair<std::string,int>("Abstr",101));

    for (std::map<std::string,int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
        std::cout << it -> first << ":" << it -> second << std::endl;
    }
//    или
    for (auto & it : myMap) {
        std::cout << it.first << ":" << it.second << std::endl;
    }
}