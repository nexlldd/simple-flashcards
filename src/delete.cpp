#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "../include/delete.h"
#include "../include/commands.h"
#include "../include/utils.h"

void deleteFlashCardSet(std::string cardSetName){

    std::string setFile;

    if(cardSetName.empty()){

        std::cout << "Please enter a flashcard set name!" << '\n';
        return;

    }

    currentCardSet = cardSetName;

    if(checkIfFlashcardExists(cardSetName) == true){

        deleteFlashCardSetFile(setFile);
        deleteFlashCardSetList(cardSetName);

    } else {

        std::cout << "Flashcard does not exist!" << '\n';
        return;

    }


}

void deleteFlashCardSetFile(std::string setFile){

    setFile = getCardSetFile();

    std::ofstream cardSetFile(setFile);
    cardSetFile.close();

    if(std::filesystem::remove(setFile)){

        std::cout << "Flashcard set successfully deleted!" << '\n'; 

    } else {

        std::cout << "Flashcard set not found!" << '\n';

    }

}

void deleteFlashCardSetList(std::string cardSetName){

    int index = 0;
    std::vector<std::string> flashcardSets;
    loadSetsToVector(flashcardSets);

    for(const auto& line : flashcardSets){

        if(line == cardSetName){

            flashcardSets.erase(flashcardSets.begin() + index);

        }

        index++;

    }

    std::ofstream flashCardSetWrite("data/flashcardSets.txt");

    for(const auto& line : flashcardSets){

        flashCardSetWrite << line << '\n';

    }

    flashCardSetWrite.close();

}

void loadSetsToVector(std::vector<std::string>& flashcardSets){

    std::string line;

    std::ifstream flashcardSetsRead("data/flashcardSets.txt");

    while(std::getline(flashcardSetsRead, line)){

        flashcardSets.push_back(line);

    }

    flashcardSetsRead.close();

}
