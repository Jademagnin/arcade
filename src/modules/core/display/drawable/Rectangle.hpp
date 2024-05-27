/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Rect
*/

#pragma once

#include "Pixel.hpp"
#include "../Actor.hpp"

namespace arc
{
    class Rectangle : public Actor
    {
        public:
            Rectangle(Position pos, ArcSize size, Pixel pixel, bool fill = true) : Actor(pos), _size(size), _pixel(pixel), _fill(fill) {};
            Rectangle() = default;
            ~Rectangle() = default;

            void setSize(const ArcSize size) { _size = size; }
            void setPixel(const Pixel pixel) { _pixel = pixel; }
            ArcSize getSize(void) const { return _size; }
            Pixel getPixel(void) const { return _pixel; }
            PairColor getPairColor(void) const { return _pixel.getPairColor(); }
            void setFill(bool fill) { _fill = fill; }
            bool isFill(void) const { return _fill; }

        private:
            ArcSize _size = {2, 2};
            Pixel _pixel = Pixel();
            bool _fill = false;
    };
}
