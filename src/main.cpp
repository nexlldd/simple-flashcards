#include <iostream>
#include <unordered_map>
#include <functional>
#include <stdexcept>
#include "../include/commands.h"

int main(){

    std::string userCommand;
    std::string selectedCommand;
    std::string param;
    std::unordered_map<std::string, std::function<void(std::string)>> commands;
    bool isRunning = true;
    setMainCommands(commands);

    do{

        try{

            std::cout << "Enter command: ";
            std::getline(std::cin, userCommand);

            separateCommands(userCommand, selectedCommand, param);

            if(selectedCommand == "exit"){

                isRunning = false;
                break;

            }
            
            commands[selectedCommand](param);

        } catch (const std::bad_function_call& e){

            std::cerr << "Command does not exist! type help for available commands." << '\n';

        }

    } while(isRunning == true);

    return 0;
}
