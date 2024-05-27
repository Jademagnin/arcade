/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Menu
*/

#pragma once
#include "../AGameModule.hpp"
#include "../../core/Input.hpp"
#include <thread>
#include <chrono>
#include <future>
#include <fstream>
#include <vector>
#include <string>

#define LIB_TYPE arc::LibType::GAME
#define LIB_NAME "snake"

#define FPS 60

namespace arc
{
    /**
     * @brief Class for the Snake game module.
     * 
     * This class inherits from the AGameModule abstract base class and implements the Snake game.
     */
    class Snake : public AGameModule
    {
    public:
        /**
         * @brief Construct a new Snake object.
         * 
         * Initializes the game map and adds the first fruit.
         */
        Snake()
        {
            srand(time(NULL));
            initMap();
            addFruit();
        }
        ~Snake(){};

        /**
         * @brief Get the name of the game.
         * 
         * @return std::string The name of the game.
         */
        static std::string getName(void) { return "snake"; }

        /**
         * @brief Initialize the game with the provided display module.
         * 
         * @param display The display module.
         */
        void initGame(std::unique_ptr<IDisplayModule> &display)
        {
            _lastFrameTime = display->getElapsedTime();
            // display->createWindow(50, 25, "Arcade");
            display->createFullScreenWindow();
        };

        void updateGame(std::unique_ptr<IDisplayModule> &display);
        void addFruit(void);
        void setNextPos(std::pair<int, int> &nextPos);
        void initMap(void);
        void displayMap(std::unique_ptr<IDisplayModule> &display, int x, int y, int mapStartX, int mapStartY);
        void renderGame(std::unique_ptr<IDisplayModule> &display);
        void displayTitles(std::unique_ptr<IDisplayModule> &display);
        void handleInput(std::unique_ptr<IDisplayModule> &display);
        void restartGame(void);

    private:
        /**
         * @brief Enum for the possible directions of the snake.
         */
        enum Direction
        {
            DIR_UP,
            DIR_DOWN,
            DIR_LEFT,
            DIR_RIGHT,
            DIR_NONE
        };

    private:
        float _lastFrameTime; ///< The time of the last frame.
        std::vector<std::vector<char>> _map; ///< The game map.
        std::deque<std::pair<int, int>> _snake; ///< The snake.
        int _snakeSize = 4; ///< The size of the snake.
        // int _score = 0;
        Direction _dir = DIR_RIGHT; ///< The current direction of the snake.
        float _refreshRate = 300; // ms
    };
}
