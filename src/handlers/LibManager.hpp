/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** LibManager
*/

#pragma once

#include "DLLoader.hpp"
#include "DirectoryWalker.hpp"
#include "modules/games/IGameModule.hpp"
#include "modules/display/IDisplayModule.hpp"
#include <filesystem>
#include <iostream>
#define LIB_PATH "./lib/"

namespace arc
{
    /**
     * @class ErrorLibManager
     * @brief A class to handle library management errors.
     */
    class ErrorLibManager : public std::runtime_error
    {
        public:
            /**
             * @brief Construct a new ErrorLibManager object.
             * @param message The error message.
             */
            explicit ErrorLibManager(const arc::path &message) : std::runtime_error(message) {}
    };

    /**
     * @class LibManager
     * @brief A class to manage libraries.
     */
    class LibManager
    {
        public:
            /**
             * @brief Construct a new LibManager object.
             */
            LibManager(void);

            /**
             * @brief Construct a new LibManager object.
             * @param pathGrahic The path to the graphic library.
             */
            LibManager(const path &pathGrahic);

            /**
             * @brief Destroy the LibManager object.
             */
            ~LibManager(void);

            void nextGame(void);
            void prevGame(void);
            void nextGraphic(void);
            void prevGraphic(void);
            void loadCurGame(void);
            void loadCurGraphic(void);
            void fetchLibs(const path &dirPath);
            void loadGraphic(const std::string &name);
            void loadGame(const std::string &name);
            void loadMenu(void);

            const Libs &getLibs(void) const { return _libs; };
            const libVector &getGames(void) const { return _libs.game; };
            const libVector &getGraphics(void) const { return _libs.graphic; };

            std::unique_ptr<arc::IGameModule> currentGame = nullptr;
            std::unique_ptr<arc::IDisplayModule> currentGraphic = nullptr;

            const Lib &getCurrentGameLib(void) const { return _libs.game[_indexCurGame]; };
            const Lib &getCurrentGraphicLib(void) const { return _libs.graphic[_indexCurGraph]; };

        private:
            Libs _libs;
            DLLoader<std::unique_ptr<arc::IGameModule>> _gameLoader;
            DLLoader<std::unique_ptr<arc::IDisplayModule>> _graphicLoader;
            DirectoryWalker _walker;
            size_t _indexCurGraph = 0;
            size_t _indexCurGame = 0;
    };
}