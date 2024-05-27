/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Menu
*/

#include "Menu.hpp"

namespace arc
{
    Menu::Menu() {};
    Menu::~Menu() {};

    void Menu::initGame(std::unique_ptr<IDisplayModule> &display)
    {
        _lastFrameTime = display->getElapsedTime();
        // display->createFullScreenWindow("Arcade");
        display->createWindow(75, 50, "Arcade");
        _scoreManager.loadFile();
    };

    void Menu::updateGame(std::unique_ptr<IDisplayModule> &display)
    {
        (void)display;
    };

    void Menu::renderGame(std::unique_ptr<IDisplayModule> &display)
    {
        float deltaTime = display->getElapsedTime() - _lastFrameTime;

        if (deltaTime < 1/FPS)
            return;

        display->clearWindow();
        ArcSize size = display->getCurWindowSize();

        renderTitle(display, size);
        renderHighScore(display, size);
        renderGames(display, size);
        renderGraphics(display, size);

        handleInput(display);
        display->displayWindow();
        _lastFrameTime = display->getElapsedTime();
        _graphicMax = 0;
        _gameMax = 0;
    };

    void Menu::handleInput(std::unique_ptr<IDisplayModule>& display)
    {
        Input input = display->getInput();
        InputEvent event = input.getFrontKey();

        if (!handleMouseInput(event))
            handleKeyboardInput(event);

        input.reset();
        _gamePos.clear();
        _graphicPos.clear();
    }
}
