/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** sfml
*/

#pragma once

#include <ncurses.h>

#include "../ADisplayModule.hpp"
#include "NColor.hpp"
#include "NPairColor.hpp"
#include "Keymap.hpp"

#define LIB_TYPE arc::LibType::GRAPHIC
#define LIB_NAME "ncurses"

#define NCOLOR(x) (x * 1000 / 255)

namespace arc
{
    /**
     * @class NCurses
     * @brief NCurses implementation of the ADisplayModule abstract class.
     */
    class NCurses : public ADisplayModule
    {
    public:
        /**
         * @brief Construct a new NCurses object.
         */
        NCurses();

        /**
         * @brief Destroy the NCurses object.
         */
        ~NCurses();

        /**
         * @brief Create a Window object.
         * @param width - The width of the window.
         * @param height - The height of the window.
         * @param name - The name of the window.
         */
        void createWindow(int width, int height, const std::string &name) override;

        /**
         * @brief Create a Full Screen Window object.
         * @param name - The name of the window.
         */
        void createFullScreenWindow(const std::string &name) override;

        /**
         * @brief Clear the window.
         */
        void clearWindow(void) override;

        /**
         * @brief Display the window.
         */
        void displayWindow(void) override;

        /**
         * @brief Destroy the window.
         */
        void destroyWindow(void) override;

        /**
         * @brief Get the current window size.
         * @return ArcSize - The current window size.
         */
        ArcSize getCurWindowSize(void) override;

        /**
         * @brief Update the input.
         */
        void updateInput(void) override;

        /**
         * @brief Draw a pixel at a given position.
         * @param pixel - The pixel to draw.
         * @param pos - The position where the pixel should be drawn.
         */
        void draw(const Pixel &pixel, const Position &pos) override;

    private:
        /**
         * @brief Initialize color.
         * @param color - The color to initialize.
         */
        void initColor(Color color);

        /**
         * @brief Initialize pair color.
         * @param pairColor - The pair color to initialize.
         */
        void initPair(PairColor pairColor);

        /**
         * @brief Initialize attributes.
         * @param conf - The configuration for the attributes.
         */
        void initAttributes(TextConf conf);

        /**
         * @brief Initialize all attributes.
         * @param pairColor - The pair color for the attributes.
         * @param conf - The configuration for the attributes.
         */
        void initAllAttributes(PairColor pairColor, TextConf conf);

    private:
        WINDOW *_window = nullptr;
        NColor _ncolor;
        NPairColor _npaircolor;
        bool _hasColor = false;
        bool _canChangeColor = false;
        bool _isFullScreen = false;
        ArcSize _windowSize = {0, 0};
    };
}