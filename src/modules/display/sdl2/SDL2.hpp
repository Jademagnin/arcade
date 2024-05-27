/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** sdl2
*/

#pragma once

#include "../ADisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Keymap.hpp"

#define LIB_TYPE arc::LibType::GRAPHIC
#define LIB_NAME "sdl2"

#define PIXEL_WIDTH 20
#define PIXEL_HEIGHT 20
#define CHAR_SIZE 20

namespace arc
{
    /**
     * @class SDL2
     * @brief SDL2 implementation of the ADisplayModule abstract class.
     */
    class SDL2 : public ADisplayModule {
        public:
            /**
             * @brief Construct a new SDL2 object.
             */
            SDL2();

            /**
             * @brief Destroy the SDL2 object.
             */
            ~SDL2();

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

            /**
             * @brief Get the Font object.
             * @param path - The path to the font file.
             * @return TTF_Font* - The font object.
             */
            TTF_Font *getFont(const std::string &path) {
                if (_fonts.find(path) == _fonts.end()) {
                    TTF_Font *font = TTF_OpenFont(path.c_str(), 20);
                    _fonts[path] = font;
                }

                return _fonts[path];
            }

        private:
            SDL_Window* _window = nullptr;
            SDL_Renderer* _renderer = nullptr;
            std::map<std::string, TTF_Font*> _fonts;
    };
}