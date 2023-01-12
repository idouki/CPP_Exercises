#include <iostream>

int main(){
    auto stringVar = std::string {}; // #include <string>

    std::cout << "What's ur name ?";

    std::getline(std::cin, stringVar); // lis toute uneligne 
    //std::cin >> stringVar; // lis que le premier mot

    std::cout << "Hello " << stringVar << std::endl;

    return 0;
}