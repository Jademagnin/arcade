/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** AMenuModule
*/

#pragma once

#include "IGameModule.hpp"

namespace arc
{
    /**
     * @brief Abstract base class for menu modules.
     * 
     * This class provides the basic interface for menu modules.
     */
    class AMenuModule : public IGameModule
    {
        public:
            /**
             * @brief Get the Score object
             * 
             * @return int Always returns -1 for menu modules.
             */
            int getScore(void) override { return -1; };

            /**
             * @brief Initialize the menu with the provided game and graphics lists.
             * 
             * @param games The list of games.
             * @param graphics The list of graphics.
             */
            void initMenu(const libVector &games, const libVector &graphics) override
            {
                _games = games;
                _graphics = graphics;
            }

        protected:
            libVector _games; ///< The list of games.
            libVector _graphics; ///< The list of graphics.
    };
}