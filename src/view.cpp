#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <random>
#include "../include/view.h"
#include "../include/utils.h"
#include "../include/commands.h"

struct FlashCard {

    std::vector<std::string> cards;
    std::string term;
    std::string def;
    int currentSide = 0;
    int currentCard = 0;

}flashCard;

//FIXME: std::out_of_range() in the vector

void viewFlashCardSet(std::string cardSetName){

    if(cardSetName.empty()){

        std::cout << "Enter a Flashcard Set!" << '\n';

    }

    if(cardSetName == "--all"){

        showAllCardSets();
        return;

    }

    //FlashCardSet cardSet;
    std::string userCommand;
    std::string selectedCommand;
    std::string param;
    bool isActive = true;
    currentCardSet = cardSetName;

    loadDataToVector(flashCard.cards);

    std::unordered_map<std::string, std::function<void(std::string)>> viewCommands;
    setViewCommands(viewCommands);

    do{

        try{

            formatFlashCard(flashCard.cards, flashCard.currentCard);
            
            std::cout << "set-" << currentCardSet << ": ";
            std::getline(std::cin, userCommand);

            if(userCommand == "return"){

                isActive = false;
                return;

            }

            separateCommands(userCommand, selectedCommand, param);
            viewCommands[selectedCommand](param);

        } catch(const std::bad_function_call& e){

            std::cerr << "Unknown Command! type help for available commands." << '\n';

        }

    } while(isActive == true);

}

void formatFlashCard(std::vector<std::string> flashCards, int& index){

    std::string currentTerm;
    std::string currentDef;

    separateTermDef(flashCards, index, currentTerm, currentDef);
    setReadableFormat(currentTerm, currentDef);

    flashCard.term = currentTerm;
    flashCard.def = currentDef;

    switch(flashCard.currentSide){

        case 0:
            std::cout << currentDef << '\n';
            break;
        case 1:
            std::cout << currentTerm << '\n';
            break;

    }

}

void flipCard(std::string param){

    if(flashCard.currentSide == 0){

        flashCard.currentSide = 1;

    } else if(flashCard.currentSide == 1){

        flashCard.currentSide = 0;

    }

}

//TODO: fix the next and previous

void nextCard(std::string param){

    flashCard.currentCard++;
    flashCard.currentSide = 0;

}

void previousCard(std::string param){

    flashCard.currentCard--;
    flashCard.currentSide = 0;

}

void findCard(std::string term){

    std::string termFind;
    int findCard = 0;

    std::vector<std::string> flashCards;
    loadDataToVector(flashCards);

    matchTermFormat(term);

    if(verifyTerm(term, flashCards) == false){

        std::cout << "Flashcard not found!" << '\n';
        return;

    }

    for(const auto& line : flashCards){

        termFind = getTerm(line);

        if(termFind == term){

            flashCard.currentCard = findCard;

        }

        findCard++;

    }

}

void shuffleCards(std::string param){

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(flashCard.cards.begin(), flashCard.cards.end(), g);

}

void showAllCardSets(){

    std::string cardSets;

    std::ifstream flashCardSetsRead("data/flashcardSets.txt");

    while(std::getline(flashCardSetsRead, cardSets)){

        std::cout << cardSets << '\n';

    }

    flashCardSetsRead.close();

}