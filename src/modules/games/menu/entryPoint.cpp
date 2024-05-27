/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** main
*/

#include "Menu.hpp"

extern "C" std::unique_ptr<arc::IGameModule> entryPoint(void) {
    return std::make_unique<arc::Menu>();
}

extern "C" arc::LibType getLibType(void) {
    return LIB_TYPE;
}

extern "C" const std::string getName(void) {
    return LIB_NAME;
}
