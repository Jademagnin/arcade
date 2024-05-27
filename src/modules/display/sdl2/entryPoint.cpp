/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** main
*/

#include "SDL2.hpp"

extern "C" std::unique_ptr<arc::IDisplayModule> entryPoint(void) {
    return std::make_unique<arc::SDL2>();
}

extern "C" arc::LibType getLibType(void) {
    return LIB_TYPE;
}

extern "C" const std::string getName(void) {
    return LIB_NAME;
}
