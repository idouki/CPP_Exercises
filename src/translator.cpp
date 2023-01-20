#include <iostream>
#include <unordered_set>
#include <map>
#include <sstream>
#include <vector>
#include <ofstream>


std::map<std::string, std::string> translator = {};
std::vector<std::string> add_instrs = {};

std::unordered_set<std::string> make_exit_commands(){
    return {"q", "quit", "e", "exit"};
}

bool parse_command(std::string command){
  
        std::stringstream ss;
        const auto exit_commands = make_exit_commands();

        ss << command;

        std::string instr;
        ss >> instr;

        if(exit_commands.count(command)){
            return false;
        }

        if( instr == "add" ){
            std::string arg1, arg2;
            ss >> arg1 >> arg2;
            translator[arg1] = arg2;
            add_instrs.push_back("add " + arg1 + " " + arg2);
            std::cout << arg1 << " => " << arg2 << std::endl;
        }

        if(instr == "translate") {
            std::string arg;

            while(ss >> arg){
                std::string translated = (translator.count(arg) == 0) ? "???" : translator.at(arg);
                std::cout << translated << " ";
            }

            std::cout << std::endl;
            
        }

        if(instr == "print"){
            for(auto entry : translator){
                std::cout << entry.first << " => " << entry.second << std::endl;
            }
        }

        if(instr =="save"){
            auto file_name = std::string {};
            ofstream file;

            ss >> file_name;
            file.open(file_name);

            for(auto addInstr : history){
                file << addInstr;
            }

            file.close();
        }

        return true;
}

int main()
{
    
    auto command = std::string {};

    while (true)
    {
        
        std::getline(std::cin, command);
        if(parse_command(command) == false){
            break;
        }
        
    }

    return 0;
}


// Pour compiler : cmake --build . && ./exe (équivalent à "make")

/* 
-- Exercice 01

2. unordered_set

-- Exercice 02 



*/