#ifndef VIEW_H
#define VIEW_H

#include <string>

void viewFlashCardSet(std::string cardSetName);

void formatFlashCard(std::vector<std::string> flashCards, int& index);

void flipCard(std::string param);

void nextCard(std::string param);

void previousCard(std::string param);

void findCard(std::string term);

void shuffleCards(std::string param);

void showAllCardSets();

#endif