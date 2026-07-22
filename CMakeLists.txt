cmake_minimum_required(VERSION 3.20)

project(SimpleFlashcards)

add_executable(SimpleFlashcards
src/main.cpp
src/commands.cpp
src/utils.cpp
src/help.cpp
src/create.cpp
src/view.cpp
src/edit.cpp
src/delete.cpp
)