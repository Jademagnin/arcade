/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** arcade
*/

#pragma once

#include "handlers/LibManager.hpp"
#include "modules/display/IDisplayModule.hpp"
#include "modules/games/IGameModule.hpp"
#include "ScoreManager.hpp"

namespace arc
{
    /**
     * @brief Custom exception class for Arcade errors.
     */
    class ArcadeError : public std::runtime_error
    {
        public:
            /**
             * @brief Construct a new Arcade Error object.
             * 
             * @param message The error message.
             */
            explicit ArcadeError(const std::string &message) : std::runtime_error(message) {}
    };

    /**
     * @brief Main class for the Arcade game.
     */
    class Arcade
    {
        public:
            /**
             * @brief Construct a new Arcade object.
             * 
             * @param path The path to the game resources.
             */
            Arcade(const std::string &path, const std::string &username);
            ~Arcade();

            /**
             * @brief Start the game menu.
             */
            void menu(void);

            /**
             * @brief Run the game.
             */
            void run();

            /**
             * @brief Start the game.
             */
            void start(void);

            /**
             * @brief Manage game inputs.
             * 
             * @return true If the input was successfully managed.
             * @return false Otherwise.
             */
            bool inputManager(void);

            /**
             * @brief Get the game input.
             * 
             * @return Input& The game input.
             */
            Input& getInput(void);

            /**
             * @brief Fetch the menu request.
             * 
             * @return true If the menu request was successfully fetched.
             * @return false Otherwise.
             */
            bool fetchMenuRequest(void);

            /**
             * @brief Update the game score.
             */
            void updateScore(void);

        private:
            LibManager _lib; ///< The library manager.
            ScoreManager& _scoreManager = ScoreManager::getInstance(); ///< The score manager.
    };
}
