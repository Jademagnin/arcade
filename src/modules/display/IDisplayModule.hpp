/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** IDisplayModule
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../core/core.hpp"

namespace arc
{
    /**
     * @class IDisplayModule
     * @brief An interface for display modules.
     */
    class IDisplayModule
    {
    public:
        /**
         * @brief Destroy the IDisplayModule object.
         */
        virtual ~IDisplayModule() = default;

        virtual void createWindow(int width, int height, const std::string &name = "arcade") = 0;
        virtual void createFullScreenWindow(const std::string &name = "arcade") = 0;
        virtual void clearWindow(void) = 0;
        virtual void displayWindow(void) = 0;
        virtual void destroyWindow(void) = 0;
        virtual ArcSize getCurWindowSize(void) = 0;

        virtual void updateInput(void) = 0;
        virtual void addInput(const InputKey &key) = 0;
        virtual void addMouseClick(const InputKey &key, const Position &pos) = 0;
        virtual Input &getInput(void) = 0;
        virtual void resetInput(void) = 0;

        virtual void restartClock(void) = 0;
        virtual float getElapsedTime(void) = 0;

        virtual void fillBackground(const Pixel &pixel) = 0;
        virtual void draw(const Pixel &pixel, const Position &pos) = 0;
        virtual void draw(const Text &text) = 0;
        virtual void draw(const Rectangle &rect) = 0;
        virtual void draw(const Line& line) = 0;
        virtual void draw(const Sprite &sprite) = 0;
        virtual void draw(const Texture &texture, const Position pos) = 0;
    };
}