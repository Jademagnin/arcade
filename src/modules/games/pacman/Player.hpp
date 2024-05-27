#pragma once

#include "../../core/Input.hpp"
#include "../AGameModule.hpp"
#include "Direction.hpp"

namespace arc
{
    using positionList = std::vector<Position>;

    /**
     * @brief Class for the Player in the game.
     */
    class Player
    {
        public:
            Player(Position pos) {
                _initialPos = pos;
                setPos(pos);
            }
            Player() {};
            ~Player() {};

            void setPos(Position pos) {
                _oldPos = _pos;
                _pos = pos;
            };

            Position getPos(void) { return _pos; };
            void setOldPos(Position pos) { _oldPos = pos; };
            Position getOldPos(void) { return _oldPos; };
            Position getInitialPos(void) { return _initialPos; };
            Direction getDir(void) { return _dir; };
            void setDir(Direction dir) { _dir = dir; };

            /**
             * @brief Reset the player to its initial state.
             */
            void reset(void) {
                _pos = _initialPos;
                _oldPos = _initialPos;
                _dir = DIR_RIGHT;
            };

        private:
            Position _initialPos = {0, 0}; ///< The initial position of the player.
            Position _pos = {0, 0}; ///< The current position of the player.
            Position _oldPos = {0, 0}; ///< The old position of the player.
            Direction _dir = DIR_RIGHT; ///< The current direction of the player.
    };
}