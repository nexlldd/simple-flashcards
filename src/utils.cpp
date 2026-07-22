#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../include/utils.h"

std::string currentCardSet;

void loadDataToVector(std::vector<std::string>& termDef){

    std::string line;
    std::string cardSetFile = getCardSetFile();

    std::ifstream flashCardRead(cardSetFile);

    while(std::getline(flashCardRead, line)){

        termDef.push_back(line);

    }

    flashCardRead.close();

}

void setLowercaseAndRemoveSpaces(std::string& term, std::string& definition){

    std::transform(term.begin(), term.end(), term.begin(), [](unsigned char t){
        return std::tolower(t);
    });

    std::transform(definition.begin(), definition.end(), definition.begin(), [](unsigned char d){
        return std::tolower(d);
    });

    for(int i = 0; i < term.size(); i++){

        if(term[i] == ' '){

            term.replace(i, 1, "_");

        }

    }

    for(int j = 0; j < definition.size(); j++){

        if(definition[j] == ' '){

            definition.replace(j, 1, "_"); 
            
        }

    }

}

void matchTermFormat(std::string& term){

    std::transform(term.begin(), term.end(), term.begin(), [](unsigned char t){

        return std::tolower(t);

    });

    for(int i = 0; i < term.size(); i++){

        if(term[i] == ' '){

            term.replace(i, 1, "_");

        }

    }

}

bool verifyTerm(std::string term, std::vector<std::string> termDef){

    std::string termFind;

    for(const auto& line : termDef){

        termFind = getTerm(line);

        if(termFind == term){

            return true;

        }

    }

    return false;

}

std::string combineTermDef(std::string newTerm, std::string newDef){

    std::stringstream ss;
    ss << newTerm << " " << newDef;
    std::string newInput = ss.str();

    return newInput;
    
}

void separateTermDef(std::vector<std::string> flashCards, int index, std::string& term, std::string& def){

    std::string termDef = flashCards.at(index);

    for(int i = 0; i < termDef.size(); i++){

        if(termDef[i] == ' '){

            termDef.erase(0, term.size() + 1);
            def = termDef;
            break;

        }

        term += termDef[i];

    }

}

void setReadableFormat(std::string& term, std::string& def){

    char firstLetterTerm = term[0];
    char firstLetterDef = def[0];
    char uFirstLetterTerm;
    char uFirstLetterDef;
    
    //converts the first letter of term and definition to uppercase
    uFirstLetterTerm = static_cast<char>(std::toupper(static_cast<unsigned char>(firstLetterTerm)));
    uFirstLetterDef = static_cast<char>(std::toupper(static_cast<unsigned char>(firstLetterDef)));

    term[0] = uFirstLetterTerm;
    def[0] = uFirstLetterDef;

    for(int i = 0; i < term.size(); i++){

        if(term[i] == '_'){

            term.replace(i, 1, " ");

        }

    }

    for(int i = 0; i < def.size(); i++){

        if(def[i] == '_'){

            def.replace(i, 1, " ");

        }

    }

}

bool checkIfFlashcardExists(std::string cardSetName){

    std::string cardSet;

    std::ifstream flashCardSetsRead("data/flashcardSets.txt");

    while(std::getline(flashCardSetsRead, cardSet)){

        if(cardSet == cardSetName){

            return true;
            break;

        }

    }

    flashCardSetsRead.close();

    return false;

}

template <typename T>

std::string getTerm(T line){

    std::string termFind;

    for(int i = 0; i < line.size(); i++){

        if(line[i] == ' '){

            break;

        }

        termFind += line[i];

    }

    return termFind;

}

std::string getCardSetFile(){

    //FlashCardSet cardSet;

    std::stringstream ss;
    ss << "data/" << currentCardSet << ".txt";
    std::string cardSetFile = ss.str();

    return cardSetFile;

}