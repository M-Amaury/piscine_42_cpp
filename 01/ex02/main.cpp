#include <iostream>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string* strp = &str;
    std::string& strr = str;

    std::cout << "Memory address of str: " << &str << std::endl;
    std::cout << "Memory address of strp: " << &strp << std::endl;
    std::cout << "Memory address of strr: " << &strr << std::endl;

    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value of strp: " << *strp << std::endl;
    std::cout << "Value of strr: " << strr << std::endl;
}