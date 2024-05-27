/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** test
*/

#pragma once

#include "../AGameModule.hpp"
#include "../../core/Input.hpp"
#include "Direction.hpp"
#include "Ghost.hpp"
#include "Player.hpp"
#include "Assets.hpp"
// #include "Sprite.hpp"

#include <thread>
#include <chrono>
#include <future>
#include <deque>
#include <list>
#include <utility>

#define LIB_TYPE arc::LibType::GAME
#define LIB_NAME "pacman"

#define FPS 60

namespace arc
{
    using positionList = std::vector<Position>;


    class Pacman : public AGameModule
    {

        public:
            Pacman() {
                srand(time(NULL));
                restartGame();
                _pacmanTexture = Texture(PACMAN_SPRITE_PATH);
                _pacmanSprite = Sprite(_pacmanTexture, {40, 40}, 3);
            };
            ~Pacman() {};

            static std::string getName(void) { return "pacman"; };

            void initGame(std::unique_ptr<IDisplayModule> &display);
            void updateGame(std::unique_ptr<IDisplayModule> &display);
            void resetGhosts(void);
            void updateGhost(Ghost &ghost);
            void updateGhosts(void);
            bool isPosEqual(Position pos1, Position pos2);
            bool canMoveAround(positionList aroundPos);

            void initMap(void);
            void displayMap(std::unique_ptr<IDisplayModule> &display, int x, int y, int mapStartX, int mapStartY);
            void assignPositions(int x, int y);
            void renderGame(std::unique_ptr<IDisplayModule> &display);
            void handleInput(std::unique_ptr<IDisplayModule> &display);
            void throwErrors(void);

            void displayTitles(std::unique_ptr<IDisplayModule> &display);

            void restartMap(void);
            void restartGame(void);

            positionList getAroundPos(Position pos)
            {
                positionList aroundPos = {
                    {pos.x, (pos.y - 1 + (int)_map.size()) % (int)_map.size()},
                    {pos.x, (pos.y + 1) % (int)_map.size()},
                    {(pos.x - 1 + (int)_map[0].size()) % (int)_map[0].size(), pos.y},
                    {(pos.x + 1) % (int)_map[0].size(), pos.y}
                };
                return aroundPos;
            }

            Position getRandPos(Ghost ghost)
            {
                Position ghostPos = ghost.getPos();
                positionList aroundPosList = getAroundPos(ghostPos);
                positionList possiblePos;
                for (auto pos : aroundPosList)
                {
                    if (_map[pos.y][pos.x] == ' ' || _map[pos.y][pos.x] == 'P'
                        || _map[pos.y][pos.x] == '.' || _map[pos.y][pos.x] == 'L'
                        || _map[pos.y][pos.x] == 'R' || _map[pos.y][pos.x] == 'o') {
                            if (!isPosEqual(pos, ghost.getOldPos()) && !isPosEqual(pos, ghost.getInitialPos()))
                                possiblePos.push_back(pos);
                        }
                }

                if (possiblePos.size() == 0) {
                    return ghostPos;
                }

                return possiblePos[rand() % possiblePos.size()];
            }


        private:
            float _lastFrameTime;
            std::vector<std::vector<char>> _map;

            // int _score = 0;
            float _refreshRate = 200; // ms
            float _refreshRateAcc = 50; // ms

            Player _player = Player({0, 0});
            Position _rightTP = {0, 0};
            Position _leftTP = {0, 0};
            Position _door = {0, 0};
            std::vector<Ghost> _ghosts = {
                Ghost({0, 0}, {Color::White, Color::Red}),
                Ghost({0, 0}, {Color::White, Color::Pink}),
                Ghost({0, 0}, {Color::White, Color::Cyan}),
                Ghost({0, 0}, {Color::White, Color::Orange})
            };
            std::vector<Position> _ghostsInitialPos = {
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0}
            };

            int _maxPoints = 0;
            int _increment = 0;
            bool _isAccelerated = false;
            int _accelerateTime = 0;
            bool _ghostSkip = false;
            bool _pressReset = false;
            int frameNumber = 0;
            Texture _pacmanTexture;
            Sprite _pacmanSprite;
    };
}
