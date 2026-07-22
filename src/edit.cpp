#include <iostream>
#include <unordered_map>
#include <fstream>
#include "../include/edit.h"
#include "../include/utils.h"
#include "../include/create.h"


void editFlashCardSet(std::string cardSetName){

    if(cardSetName.empty()){

        std::cout << "Please enter a flashcard set name!" << '\n';
        return;

    }

    if(checkIfFlashcardExists(cardSetName) == true){

        createFlashCardSet(cardSetName);

    } else {

        std::cout << "Flashcard does not exist!" << '\n';
        return;

    }

}