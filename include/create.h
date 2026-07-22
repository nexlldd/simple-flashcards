#ifndef CREATE_H
#define CREATE_H

#include <string>

void createFlashCardSet(std::string cardSetName);

void addFlashCard(std::string term);

void editFlashCard(std::string term);

void deleteFlashCard(std::string term);

void saveFlashCard(std::string term, std::string defintion);

void saveNewFlashCard(std::string cardSetFile,  std::vector<std::string> termDef);

void saveFlashCardSet(std::string cardSetName);

#endif