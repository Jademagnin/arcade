/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Menu
*/

#pragma once

#include "../AMenuModule.hpp"
#include "../../../handlers/ScoreManager.hpp"
#include "../../core/Input.hpp"

#define LIB_NAME "menu"
#define LIB_TYPE arc::LibType::MENU

#define FPS 20

namespace arc
{
    using PosRange = std::pair<Position, ArcSize>;
    using PosRangeList = std::vector<PosRange>;

    class Menu : public AMenuModule
    {

        public:
            Menu();
            ~Menu();

            static std::string getName(void) { return "menu"; }

            void initGame(std::unique_ptr<IDisplayModule> &display);
            void updateGame(std::unique_ptr<IDisplayModule> &display);
            void renderGame(std::unique_ptr<IDisplayModule> &display);
            void handleInput(std::unique_ptr<IDisplayModule> &display);

            Module getModuleRequest(void) override {
                Module requestedModule = _moduleRequest;
                _moduleRequest = {"", arc::LibType::UNKNOWN};
                return requestedModule;
            };

            void setModuleRequest(Module module) { _moduleRequest = module; };
            void restartGame(void) {};

        private:
            bool handleMouseInput(const InputEvent &key);
            bool handleKeyboardInput(const InputEvent &key);
            void renderTitle(std::unique_ptr<IDisplayModule> &display, const ArcSize &size);
            void renderHighScore(std::unique_ptr<IDisplayModule> &display, const ArcSize &size);
            void renderGames(std::unique_ptr<IDisplayModule> &display, const ArcSize &size);
            void renderGraphics(std::unique_ptr<IDisplayModule> &display, const ArcSize &size);

            void handleClickOnGame(const InputEvent &event);
            void handleClickOnGraphic(const InputEvent &event);

        private:
            float _lastFrameTime;
            int _cursor = 0;
            int _gameMax = 0;
            int _libIndex = 0;
            int _graphicMax = 0;

            PosRangeList _gamePos;
            PosRangeList _graphicPos;

            Module _moduleRequest = {"", arc::LibType::UNKNOWN};
            ScoreManager& _scoreManager = ScoreManager::getInstance();
    };
}
