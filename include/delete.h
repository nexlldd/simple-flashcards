#ifndef DELETE_H
#define DELETE_H

#include <string>

void deleteFlashCardSet(std::string cardSetName);

void deleteFlashCardSetFile(std::string setFile);

void deleteFlashCardSetList(std::string cardSetName);

void loadSetsToVector(std::vector<std::string>& flashcardSets);

#endif