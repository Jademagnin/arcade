/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** sfml
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "../ADisplayModule.hpp"
#include "Keymap.hpp"

#define LIB_TYPE arc::LibType::GRAPHIC
#define LIB_NAME "sfml"

#define CHAR_SIZE 20
#define HEIGHT_ADJUST -5

namespace arc
{
    /**
     * @class SFML
     * @brief SFML implementation of the ADisplayModule abstract class.
     */
    class SFML : public ADisplayModule {
        public:
            /**
             * @brief Construct a new SFML object.
             */
            SFML();

            /**
             * @brief Destroy the SFML object.
             */
            ~SFML();

            /**
             * @brief Create a Window object.
             * @param width - The width of the window.
             * @param height - The height of the window.
             * @param name - The name of the window.
             */
            void createWindow(int width, int height, const std::string &name = "arcade") override;

            /**
             * @brief Create a Full Screen Window object.
             * @param name - The name of the window.
             */
            void createFullScreenWindow(const std::string &name = "arcade") override;

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
            void draw(const Pixel& pixel, const Position& pos) override;
            void draw(const Text& text) override;

            /**
             * @brief Get the Font object.
             * @param path - The path to the font file.
             * @return sf::Font& - The font object.
             */
            sf::Font &getFont(const std::string &path) {
                if (_fonts.find(path) == _fonts.end()) {
                    sf::Font font;
                    font.loadFromFile(path);
                    _fonts[path] = font;
                }
                return _fonts[path];
            }

        private:
            sf::RenderWindow _window;
            std::map<std::string, sf::Font> _fonts;
    };
}