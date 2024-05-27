/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** ADisplayModule
*/

#pragma once

#include "IDisplayModule.hpp"
#include <ctime>

#define PIXEL_WIDTH 20
#define PIXEL_HEIGHT 20

namespace arc
{
    class ADisplayModule : public IDisplayModule
    {
    public:
        using IDisplayModule::draw;
        Input& getInput() override { return _input; }
        void resetInput() override { _input.reset(); }
        void addInput(const InputKey &key) override { _input.addKey(key); }
        void addMouseClick(const InputKey &key, const Position &pos) override {
            _input.addMouseClick(key, pos);
        }

        void restartClock(void) override
        {
            _startTime = std::chrono::system_clock::now();
        }

        float getElapsedTime(void) override
        {
            std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
            return std::chrono::duration<float>(now - _startTime).count();
        }


        void fillBackground(const Pixel &pixel) override
        {
            for (int y = 0; y < getCurWindowSize().height; y++) {
                for (int x = 0; x < getCurWindowSize().width; x++) {
                    draw(pixel, {x, y});
                }
            }
        }

        void draw(const Text &text) override
        {
            std::string str = text.getStr();
            Position pos = text.getPosition();
            for (int i = 0; i < (int)str.size(); i++) {
                Pixel pixel(str[i], text.getPairColor(), text.getConfig());
                draw(pixel, {pos.x + i, pos.y});
            }
        }

        void draw(const Rectangle &rect) override
        {
            Pixel pixel = rect.getPixel();
            Position pos = rect.getPosition();
            ArcSize size = rect.getSize();

            if (rect.isFill()) {
                for (int y = 0; y < rect.getSize().height; y++) {
                    for (int x = 0; x < rect.getSize().width; x++) {
                        draw(pixel, {pos.x + x, pos.y + y});
                    }
                }
                return;
            }
            Line line;
            line.setPixel(pixel);
            line.setPosition(pos);
            line.setLength(size.width);
            draw(line);
            line.setPosition({pos.x, pos.y + size.height - 1});
            draw(line);
            line.setVertical(true);
            line.setLength(size.height);
            line.setPosition(pos);
            draw(line);
            line.setPosition({pos.x + size.width - 1, pos.y});
            draw(line);
        }

        void draw(const Line &line) override
        {
            Pixel pixel = line.getPixel();
            Position pos = line.getPosition();
            int length = line.getLength();
            bool vertical = line.isVertical();

            for (int i = 0; i < length; i++) {
                draw(pixel, {pos.x + (vertical ? 0 : i), pos.y + (vertical ? i : 0)});
            }
        }

        void draw(const Texture &texture, const Position pos) override
        {
            PixelMap map = texture.getTexture();
            for (int y = 0; y < texture.getHeight(); y++) {
                for (int x = 0; x < texture.getWidth(); x++) {
                    draw(map[y][x], {pos.x + x, pos.y + y});
                }
            }
        }

        void draw(const Sprite &sprite) override
        {
            Texture texture = sprite.getTexture();
            Rect rect = sprite.getRect();
            for (int y = 0; y < rect.h; y++) {
                for (int x = 0; x < rect.w; x++) {
                    draw(texture.getTexture()[rect.y + y][rect.x + x], {sprite.getPosition().x + x, sprite.getPosition().y + y});
                }
            }
        }

    private:
        Input _input;
        std::chrono::time_point<std::chrono::system_clock> _startTime;
    };
}
