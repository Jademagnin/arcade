/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Line
*/

#pragma once

#include "Pixel.hpp"
#include "../Actor.hpp"
#include <vector>

namespace arc
{
    class Line : public Actor
    {
        public:
            Line() = default;
            Line(Position pos, size_t length,
                Pixel pixel = Pixel('.'),
                bool isVertical = false
            ) : Actor(pos), _length(length), _pixel(pixel), _isVertical(isVertical) {};
            const Pixel &getPixel() const { return _pixel; };
            const size_t &getLength() const { return _length; };
            bool isVertical() const { return _isVertical; };

            void setLength(size_t length) { _length = length; }
            void setPixel(Pixel _pixel) { _pixel = _pixel; }
            void setVertical(bool isVertical) { _isVertical = isVertical; }
            PairColor getPairColor(void) const { return _pixel.getPairColor(); }

        private:
            size_t _length = 0;
            Pixel _pixel;
            bool _isVertical = false;
    };
}