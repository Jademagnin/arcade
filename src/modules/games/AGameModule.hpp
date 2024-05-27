/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule
*/

#pragma once

#include <vector>
#include "IGameModule.hpp"

namespace arc
{
    /**
     * @brief Abstract base class for game modules.
     * 
     * This class provides the basic interface for game modules.
     */
    class AGameModule : public IGameModule {
        public:
            /**
             * @brief Get the Score object
             * 
             * @return int The current score.
             */
            int getScore(void) { return _score; }

            /**
             * @brief Get the Module Request object
             * 
             * @return Module A module with an empty name and UNKNOWN type.
             */
            Module getModuleRequest(void) { return {"", LibType::UNKNOWN};}

            /**
             * @brief Initialize the menu with the provided library and game lists.
             * 
             * @param libList The list of libraries.
             * @param gameList The list of games.
             */
            void initMenu(const libVector &libList, const libVector &gameList) {
                (void)libList;
                (void)gameList;
            }

        protected:
            int _score = 0; ///< The current score.
    };
}
