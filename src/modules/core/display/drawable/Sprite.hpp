/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Sprite
*/

#pragma once

#include <vector>
#include "Texture.hpp"
#include "../Actor.hpp"

namespace arc
{
    class Sprite : public Actor
    {
        public:
            Sprite() = default;

            // calculate Rect automatically
            Sprite(Texture texture, Position pos, int framesNb) :
                _pos(pos), _texture(texture), _frameIndex(framesNb)
            {
                _rect = {0, 0, texture.getWidth() / framesNb, texture.getHeight()};
            };
            ~Sprite() = default;

            // Getters
            Position getPosition() const { return _pos; }
            Rect getRect() const { return _rect; }
            Texture getTexture() const { return _texture; }

            // Setters
            void setPosition(const Position& pos) { _pos = pos; }
            void setRect(const Rect& r) { _rect = r; }
            void setTexture(const Texture& texture) { _texture = texture; }

            // Handlers
            void incrementFrame() {
                _rect.x += _rect.w;
                if (_rect.x >= _texture.getWidth())
                    _rect.x = 0;
            }
            void resetFrame() { _rect.x = 0; }
            void setFrameIndex(int index) {
                _frameIndex = index;
                _rect.x = _rect.w * index;
            }

        private:
            Position _pos;
            Rect _rect;
            Texture _texture;
            short _frameIndex;
    };
}
