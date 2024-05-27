/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Actor
*/

#pragma once
#include "../utils/attributes.hpp"

namespace arc
{
    class Actor {
        public:
            Actor(const Position pos = {0, 0}) : _pos(pos) {};
            ~Actor() = default;

            void setPosition(const Position pos) { _pos = pos; };
            Position getPosition(void) const { return _pos; };

        private:
            Position _pos = {0, 0};
    };
}

