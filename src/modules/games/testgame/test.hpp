/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** TestGame
*/

#pragma once

#include "../AGameModule.hpp"

#define LIB_TYPE arc::LibType::GAME
#define LIB_NAME "testgame"

#define FPS 20

namespace arc
{
    class TestGame : public AGameModule
    {
        public:
            TestGame() {
                srand(time(NULL));
                _random = rand() % 100;
            };
            ~TestGame() {};
            int getScore(void) { return _score; };
            void setScore(int score) { _score = score; };

            void initGame(std::unique_ptr<arc::IDisplayModule> &display)
            {
                _lastFrameTime = display->getElapsedTime();
                // display->createWindow(50, 25, "test");
                display->createFullScreenWindow();
            };

            void updateGame(std::unique_ptr<arc::IDisplayModule> &display)
            {
                (void)display;
            };

            void renderGame(std::unique_ptr<arc::IDisplayModule> &display)
            {
                float deltaTime = display->getElapsedTime() - _lastFrameTime;

                if (deltaTime < 1/FPS)
                    return;
                display->clearWindow();
                ArcSize size = display->getCurWindowSize();

                char c = 'B' + _random % 25;
                (void)c;
                // std::cout << "RandomChar: " << c << std::endl;

                Pixel randomPixel(c, PairColor(Color::Yellow, Color::Green));
                Pixel pixel('A', PairColor(Color::Green, Color::Red), {true, true, true});
                Pixel bluePixel(' ', PairColor(Color::Blue, Color::Blue));
                Pixel whitePixel(' ', PairColor(Color::White, Color::White));
                Pixel greenPixel(' ', PairColor(Color::Green, Color::Green));
                Text text("Hello World", {1, size.height - 1});
                Texture texture("./assets/pacman/sprites/player.bmp");
                Sprite sprite(texture, {2, 2}, 3);
                text.setPairColor(PairColor(Color::Blue, Color::Red));

                Rectangle rect({0, 1}, {5, 5}, bluePixel);
                Line line({1, 0}, 5, greenPixel, true);

                display->fillBackground(whitePixel);
                display->draw(pixel, {0, 0});
                display->draw(pixel, {1, 0});
                display->draw(pixel, {size.width - 1, size.height - 1});
                display->draw(randomPixel, {5, 5});

                display->draw(rect);
                display->draw(line);
                display->draw(text);
                // display->draw(texture, {10, 10});
                // sprite.setFrameIndex(2);
                sprite.incrementFrame();
                sprite.incrementFrame();
                display->draw(sprite);

                display->displayWindow();
                _lastFrameTime = display->getElapsedTime();
            };

            void restartGame(void) {
                _random = rand() % 100;
            };

        private:
            float _lastFrameTime;
            int _random;
            int _score = 0;
    };
}
