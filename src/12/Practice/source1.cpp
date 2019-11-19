#include <iostream>

class myC {

    int pref;
protected:
    std::string str;
public:
    std::string getStr() {return str;};
    int getPref() {return pref;};

    myC(int _pref, std::string _str) {
        this->pref = _pref;
        this->str = std::move(_str);
    }

    myC():pref(100),str("List Initialization"){};

};

int main() {
    myC newCC(0, "New string");
    std::cout << "Pref: " << newCC.getPref() << '\n' << "Str: " << newCC.getStr() << '\n';

    myC newC;
    std::cout << "Pref: " << newC.getPref() << '\n' << "Str: " << newC.getStr() << '\n';

    return 0;
}