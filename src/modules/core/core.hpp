/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** graphic
*/

#pragma once

#include "display/drawable/all.hpp"
#include "Input.hpp"

/// @brief
namespace arc {
    /**
     * @enum LibType
     * @brief Enum for the type of library.
     */
    enum LibType {
        GRAPHIC, ///< Graphic library type.
        GAME, ///< Game library type.
        MENU, ///< Menu library type.
        UNKNOWN ///< Unknown library type.
    };

    /**
     * @struct Module
     * @brief Struct for a module.
     */
    struct Module {
        std::string name; ///< Name of the module.
        LibType type; ///< Type of the module.
    };

    /**
     * @struct Lib
     * @brief Struct for a library.
     */
    struct Lib
    {
        std::string name; ///< Name of the library.
        arc::path path; ///< Path to the library.
    };
    using libVector = std::vector<Lib>; ///< Vector of libraries.

    /**
     * @struct Libs
     * @brief Struct for a collection of libraries.
     */
    struct Libs
    {
        Lib menu; ///< Menu library.
        libVector game; ///< Vector of game libraries.
        libVector graphic; ///< Vector of graphic libraries.
    };
}