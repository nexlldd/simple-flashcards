#include <iostream>
#include "../include/help.h"

void showAllHelp(std::string param){

    std::cout << "Available Commands:" << '\n';
    std::cout << '\n';
    std::cout << "help" << '\t' << '\t' << '\t' << '\t' << "shows available commands" << '\n';
    std::cout << "create [set]" << '\t' << '\t' << '\t' << "creates a new flashcard set" << '\n';
    std::cout << "view [set]" << '\t' << '\t' << '\t' << "display specific flashcard set" << '\n';
    std::cout << "view --all" << '\t' << '\t' << '\t' << "displays all flashcard sets" << '\n';
    std::cout << "edit [set]" << '\t' << '\t' << '\t' << "edit a specific flashcard set" << '\n';
    std::cout << "delete [set]" << '\t' << '\t' << '\t' << "deletes a flashcard set" << '\n';
    std::cout << "exit" << '\t' << '\t' << '\t' << '\t' << "exits the program" << '\n';

}

void showCreateHelp(std::string param){

    std::cout << "Available Commands:" << '\n';
    std::cout << '\n';
    std::cout << "help" << '\t' << '\t' << '\t' << '\t' << "shows available commands" << '\n';
    std::cout << "add [term]" << '\t' << '\t' << '\t' << "creates a flashcard in the set" << '\n';
    std::cout << "edit [term]" << '\t' << '\t' << '\t' << "edit a specific flashcard" << '\n';
    std::cout << "delete [term]" << '\t' << '\t' << '\t' << "deletes a flashcard" << '\n';
    std::cout << "return" << '\t' << '\t' << '\t' << '\t' << "go back" << '\n';

}

void showViewHelp(std::string param){

    std::cout << "Available Commands:" << '\n';
    std::cout << '\n';
    std::cout << "help" << '\t' << '\t' << '\t' << '\t' << "shows available commands" << '\n';
    std::cout << "flip" << '\t' << '\t' << '\t' << "flips the flashcard" << '\n';
    std::cout << "next" << '\t' << '\t' << '\t' << "moves to next card" << '\n';
    std::cout << "back" << '\t' << '\t' << '\t' << "moves to previous card" << '\n';
    std::cout << "find [term]" << '\t' << '\t' << '\t' << "finds a specific flashcard" << '\n';
    std::cout << "shuffle" << '\t' << '\t' << '\t' << "shuffles the set" << '\n';
    std::cout << "return" << '\t' << '\t' << '\t' << '\t' << "go back" << '\n';

}