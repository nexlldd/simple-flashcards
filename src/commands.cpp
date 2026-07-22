#include <iostream>
#include <unordered_map>
#include <functional>
#include <sstream>
#include "../include/commands.h"
#include "../include/help.h"
#include "../include/create.h"
#include "../include/view.h"
#include "../include/edit.h"
#include "../include/delete.h"

void setMainCommands(std::unordered_map<std::string, std::function<void(std::string)>>& mainCommands){

    mainCommands["help"] = showAllHelp;
    mainCommands["create"] = createFlashCardSet;
    mainCommands["view"] = viewFlashCardSet;
    mainCommands["edit"] = editFlashCardSet;
    mainCommands["delete"] = deleteFlashCardSet;

}

void setCreateCommands(std::unordered_map<std::string, std::function<void(std::string)>>& createCommands){

    createCommands["help"] = showCreateHelp;
    createCommands["add"] = addFlashCard;
    createCommands["edit"] = editFlashCard;   
    createCommands["delete"] = deleteFlashCard;

}

void setViewCommands(std::unordered_map<std::string, std::function<void(std::string)>>& viewCommands){

    viewCommands["help"] = showViewHelp;
    viewCommands["flip"] = flipCard;
    viewCommands["next"] = nextCard;
    viewCommands["back"] = previousCard;
    viewCommands["find"] = findCard;
    viewCommands["shuffle"] = shuffleCards;

}

void separateCommands(std::string userCommand, std::string& selectedCommand, std::string& param){

    std::stringstream ss(userCommand);

    std::getline(ss, selectedCommand, ' ');
    std::getline(ss, param);

}



