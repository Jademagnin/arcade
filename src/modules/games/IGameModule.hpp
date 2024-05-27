/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** IGameModule
*/

#pragma once

#include "../display/IDisplayModule.hpp"

namespace arc
{
    /**
     * @brief Interface for game modules.
     * 
     * This interface defines the necessary methods for game modules.
     */
    class IGameModule {
        public:
            virtual ~IGameModule() = default;

            /**
             * @brief Initialize the game with the provided display module.
             * 
             * @param display The display module.
             */
            virtual void initGame(std::unique_ptr<IDisplayModule> &display) = 0;

            /**
             * @brief Update the game state with the provided display module.
             * 
             * @param display The display module.
             */
            virtual void updateGame(std::unique_ptr<IDisplayModule> &display) = 0;

            /**
             * @brief Render the game with the provided display module.
             * 
             * @param display The display module.
             */
            virtual void renderGame(std::unique_ptr<IDisplayModule> &display) = 0;

            /**
             * @brief Restart the game.
             */
            virtual void restartGame(void) = 0;

            /**
             * @brief Get the current score.
             * 
             * @return int The current score.
             */
            virtual int getScore(void) = 0;

            /**
             * @brief Get the module request.
             * 
             * @return Module The requested module.
             */
            virtual Module getModuleRequest(void) = 0;

            /**
             * @brief Initialize the menu with the provided game and graphics lists.
             * 
             * @param games The list of games.
             * @param graphics The list of graphics.
             */
            virtual void initMenu(const libVector &games, const libVector &graphics) = 0;
    };
}