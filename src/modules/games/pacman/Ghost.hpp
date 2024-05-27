#pragma once

#include "../../core/Input.hpp"
#include "../AGameModule.hpp"
#include "Direction.hpp"



namespace arc
{
    using positionList = std::vector<Position>;

    /**
     * @class Ghost
     * @brief Class representing a Ghost in the game.
     */
    class Ghost
    {
        public:
            /**
             * @brief Construct a new Ghost object with a given position and color.
             * @param pos Initial position of the Ghost.
             * @param color Color of the Ghost.
             */
            Ghost(Position pos, PairColor color) {
                _initialPos = pos;
                _color = color;
                setPos(pos);
            }

            /**
             * @brief Default constructor.
             */
            Ghost() {};

            /**
             * @brief Default destructor.
             */
            ~Ghost() {};

            /**
             * @brief Set the position of the Ghost.
             * @param pos The new position of the Ghost.
             */
            void setPos(Position pos) {
                _oldPos = _pos;
                _pos = pos;
            };

            Position getPos(void) { return _pos; };
            void setOldPos(Position pos) { _oldPos = pos; };
            Position getOldPos(void) { return _oldPos; };
            void setColor(PairColor color) { _color = color; };
            PairColor getColor(void) { return _color; };
            Position getInitialPos(void) { return _initialPos; };
            char getPrevChar(void) { return prevChar; };
            void setPrevChar(char c) { prevChar = c; };
            void setIsDead(int isDead) { _isDead = isDead; };
            int getIsDead(void) { return _isDead; };
            int getTimeDead(void) { return _timeDead; };
            void setTimeDead(int timeDead) { _timeDead = timeDead; };
            void setAlreadyReset(bool alreadyReset) { _alreadyReset = alreadyReset; };
            bool getAlreadyReset(void) { return _alreadyReset; };
            /**
             * @brief Reset the Ghost to its initial position.
             */
            void reset(void) {
                _pos = _initialPos;
                _oldPos = _initialPos;
            };

        private:
            Position _initialPos = {0, 0}; ///< Initial position of the Ghost.
            Position _pos = {0, 0}; ///< Current position of the Ghost.
            Position _oldPos = {0, 0}; ///< Old position of the Ghost.
            PairColor _color = {Color::White, Color::Red}; ///< Color of the Ghost.
            char prevChar = ' '; ///< Previous character.
            int _isDead = 0; ///< Flag to indicate if the Ghost is dead.
            int _timeDead = 0; ///< Time the Ghost has been dead.
            bool _alreadyReset = false; ///< Flag to indicate if the Ghost has already been reset.
    };
}
