/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** main
*/

#include "SFML.hpp"

extern "C" std::unique_ptr<arc::IDisplayModule> entryPoint(void) {
    return std::make_unique<arc::SFML>();
}

extern "C" arc::LibType getLibType(void) {
    return LIB_TYPE;
}

extern "C" const std::string getName(void) {
    return LIB_NAME;
}
