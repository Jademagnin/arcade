/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** LibManager
*/

#include "LibManager.hpp"

namespace arc {
    LibManager::LibManager() : _walker(LIB_PATH)
    {
        fetchLibs(LIB_PATH);
    }

    LibManager::LibManager(const path &pathGrahic) : _walker(LIB_PATH)
    {
        fetchLibs(LIB_PATH);
        loadGraphic(pathGrahic);
    }

    LibManager::~LibManager(void)
    {
        currentGame.release();
        currentGraphic.release();
    }

    void LibManager::nextGame(void)
    {
        currentGraphic->clearWindow();
        _indexCurGame = (_libs.game.size() - 1 <= _indexCurGame) ? 0 : _indexCurGame + 1;
        loadCurGame();
    }

    void LibManager::prevGame(void)
    {
        currentGraphic->clearWindow();
        _indexCurGame = (_indexCurGame <= 0) ? _libs.game.size() - 1 : _indexCurGame - 1;
        loadCurGame();
    }

    void LibManager::nextGraphic(void)
    {
        currentGraphic->destroyWindow();
        _indexCurGraph = (_libs.graphic.size() - 1 <= _indexCurGraph) ? 0 : _indexCurGraph + 1;
        loadCurGraphic();
    }

    void LibManager::prevGraphic(void)
    {
        currentGraphic->destroyWindow();
        _indexCurGraph = (_indexCurGraph <= 0) ? _libs.graphic.size() - 1 : _indexCurGraph - 1;
        loadCurGraphic();
    }

    void LibManager::loadCurGame(void)
    {
        if (currentGame != nullptr)
            currentGraphic->clearWindow();
        currentGame.release();
        _gameLoader.open(_libs.game[_indexCurGame].path);
        currentGame.reset(_gameLoader.getInstance().release());
    }

    void LibManager::loadCurGraphic(void)
    {
        if (currentGraphic != nullptr)
            currentGraphic->destroyWindow();
        currentGraphic.release();
        _graphicLoader.open(_libs.graphic[_indexCurGraph].path);
        currentGraphic.reset(_graphicLoader.getInstance().release());
    }

    void LibManager::fetchLibs(const path &dirPath)
    {
        _indexCurGame = 0;
        _indexCurGraph = 0;
        _walker.changeDirectory(dirPath);
        _libs.game.clear();
        _libs.graphic.clear();

        const auto files = _walker.getFilesByExt(".so");
        if (files.empty())
            throw ErrorLibManager("No game or graphic library found");
        for (const auto &file : files)
        {
            _gameLoader.open(file);
            std::string name = _gameLoader.getName();

            LibType type = _gameLoader.getLibType();

            switch (type) {
                case LibType::GAME:
                    _libs.game.push_back({name, file});
                    break;
                case LibType::GRAPHIC:
                    _libs.graphic.push_back({name, file});
                    break;
                case LibType::MENU:
                    _libs.menu = {name, file};
                    break;
                default:
                    throw ErrorLibManager("Library type not found");
            }
        }
    }

    void LibManager::loadGraphic(const std::string &name)
    {
        std::cout << "Loading graphic library: " << name << std::endl;
        if (currentGraphic != nullptr)
            currentGraphic->destroyWindow();

        for (size_t i = 0; i < _libs.graphic.size(); i++) {
            try {
                if (_libs.graphic[i].name == name ||
                    std::filesystem::canonical(_libs.graphic[i].path) ==
                    std::filesystem::canonical(name))
                {
                    _indexCurGraph = i;
                    loadCurGraphic();
                    return;
                }
            } catch (const std::filesystem::filesystem_error &e) {
                continue;
            }
        }
        throw ErrorLibManager("Graphic library not found");
    }

    void LibManager::loadGame(const std::string &name)
    {
        for (size_t i = 0; i < _libs.game.size(); i++) {
            try {
                if (_libs.game[i].name == name ||
                    std::filesystem::canonical(_libs.game[i].path) ==
                    std::filesystem::canonical(name))
                {
                    _indexCurGame = i;
                    loadCurGame();
                    return;
                }
            } catch (const std::filesystem::filesystem_error &e) {
                continue;
            }
        }
        throw ErrorLibManager("Game library not found");
    }

    void LibManager::loadMenu(void)
    {
        if (_libs.menu.name.empty())
            throw ErrorLibManager("No menu library found");
        if (currentGraphic != nullptr)
            currentGraphic->clearWindow();
        currentGame.release();
        _gameLoader.open(_libs.menu.path);
        currentGame.reset(_gameLoader.getInstance().release());
    }
} // namespace arc
