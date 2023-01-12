#include <iostream>

int main(){
    auto stringVar = std::string {}; // #include <string>

    std::cout << "What's ur name ?";

    std::cin >> stringVar;

    std::cout << "Hello " << stringVar << std::endl;

    return 0;
}