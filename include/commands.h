#ifndef COMMANDS_H
#define COMMANDS_H

#include <unordered_map>
#include <iostream>
#include <functional>

void setMainCommands(std::unordered_map<std::string, std::function<void(std::string)>>& mainCommands);

void setCreateCommands(std::unordered_map<std::string, std::function<void(std::string)>>& createCommands);

void setViewCommands(std::unordered_map<std::string, std::function<void(std::string)>>& viewCommands);

void separateCommands(std::string userCommand, std::string& selectedComamnd, std::string& param);

#endif