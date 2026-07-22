#include <iostream>
#include <unordered_map>
#include <functional>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "../include/create.h"
#include "../include/utils.h"
#include "../include/commands.h"

//TODO: Check if the flashcard set already exists

void createFlashCardSet(std::string cardSetName){

    //FlashCardSet cardSet;
    std::string userCommand;
    std::string selectedCommand;
    std::string param;
    bool isActive = true;

    if(cardSetName.empty()){

        std::cout << "Please enter a flashcard set name!" << '\n';
        return;

    }

    std::unordered_map<std::string, std::function<void(std::string param)>> createCommands;
    setCreateCommands(createCommands);

    if(checkIfFlashcardExists(cardSetName) == false){

        saveFlashCardSet(cardSetName);
        std::cout << cardSetName << " set created!" << '\n';

    }

    currentCardSet = cardSetName;

    do{

        try{

            std::cout << "set-" << cardSetName << ": ";
            std::getline(std::cin, userCommand);

            if(userCommand == "return"){

                isActive = false;
                break;

            }

            separateCommands(userCommand, selectedCommand, param);
            createCommands[selectedCommand](param);

        } catch (const std::bad_function_call& e){

            std::cerr << "Unknown Command! type help for available commands." << '\n';

        }

    } while(isActive == true);

}

void addFlashCard(std::string term){

    std::string defintion;

    std::cout << "Add definition: ";
    std::getline(std::cin, defintion);

    saveFlashCard(term, defintion);

}

//TODO: check if term to edit really exists;

void editFlashCard(std::string term){

    std::string newTerm;
    std::string newDefinition;
    std::string newInput;
    std::string termFind;
    int index = 0;
    std::vector<std::string> termDef;

    loadDataToVector(termDef);
    matchTermFormat(term);

    if(verifyTerm(term, termDef) == false){

        std::cout << "Flashcard does not exist!" << '\n';
        return;

    }

    std::cout << "Enter new term: ";
    std::getline(std::cin, newTerm);

    std::cout << "Enter new definition: ";
    std::getline(std::cin, newDefinition);

    setLowercaseAndRemoveSpaces(newTerm, newDefinition);
    newInput = combineTermDef(newTerm, newDefinition);

    for(const auto& line : termDef){

        termFind = getTerm(line);

        if(term == termFind){

            termDef.at(index) = newInput;

        }

        index++;

    }

    std::string cardSetFile = getCardSetFile();

    saveNewFlashCard(cardSetFile, termDef);

}

void deleteFlashCard(std::string term){

    std::vector<std::string> termDef;
    std::string termFind;
    int index = 0;

    loadDataToVector(termDef);
    matchTermFormat(term);

    for(const auto& line : termDef){

        termFind = getTerm(line);

        if(term == termFind){

            termDef.erase(termDef.begin() + index);

        }

        index++;

    }

    std::string cardSetFile = getCardSetFile();

    saveNewFlashCard(cardSetFile, termDef);

}


void saveFlashCard(std::string term, std::string defintion){

    std::string cardSetFile = getCardSetFile();

    setLowercaseAndRemoveSpaces(term, defintion);

    std::ofstream flashcardWriter(cardSetFile, std::ios::app);

    flashcardWriter << term << " " << defintion << '\n';
    
    flashcardWriter.close();

}

void saveNewFlashCard(std::string cardSetFile,  std::vector<std::string> termDef){

    std::ofstream newInputRead(cardSetFile);

    for(const auto& line : termDef){
        newInputRead << line << '\n';
    }

    newInputRead.close();

}

void saveFlashCardSet(std::string cardSetName){

    std::ofstream cardSetWriter("data/flashcardSets.txt", std::ios::app);

    cardSetWriter << cardSetName << '\n';

    cardSetWriter.close();

}

