#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

extern std::string currentCardSet;

void loadDataToVector(std::vector<std::string>& termDef);

void setLowercaseAndRemoveSpaces(std::string& term, std::string& definition);

void matchTermFormat(std::string& term);

bool verifyTerm(std::string term, std::vector<std::string> termDef);

std::string combineTermDef(std::string newTerm, std::string newDef);

void separateTermDef(std::vector<std::string> flashCards, int index, std::string& term, std::string& def);

void setReadableFormat(std::string& term, std::string& def);

bool checkIfFlashcardExists(std::string cardSetName);

template <typename T>

std::string getTerm(T line);

std::string getCardSetFile();

#endif