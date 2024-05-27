/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Arcade
*/

#include "Arcade.hpp"

arc::Arcade::Arcade(const std::string& path, const std::string &username) : _lib(path)
{
    _scoreManager.setUsername(username);
}

arc::Arcade::~Arcade(void)
{

}

arc::Input& arc::Arcade::getInput(void)
{
    _lib.currentGraphic->resetInput();
    _lib.currentGraphic->updateInput();
    return _lib.currentGraphic->getInput();
}

bool arc::Arcade::inputManager(void)
{
    switch (getInput().getFrontKey().key) {
        case ESCAPE:
        case CLOSE:
            return true;
        case F2:
            _lib.nextGraphic();
            run();
            return true;
        case F1:
            _lib.prevGraphic();
            run();
            return true;
        case NUM1:
            //_lib.currentGame->;
            _lib.prevGame();
            run();
            return true;
        case NUM2:
            //_lib.currentGame->;
            _lib.nextGame();
            run();
            return true;
        // if press Q, quit game and return to menu
        case Q:
            _scoreManager.saveScore();
            _lib.loadMenu();
            _lib.currentGame->initMenu(_lib.getGames(), _lib.getGraphics());
            return false;
        default:
            return false;
    }
}

bool arc::Arcade::fetchMenuRequest(void)
{
    arc::Module moduleRequest = _lib.currentGame->getModuleRequest();
    if (moduleRequest.name.empty() || moduleRequest.type == arc::LibType::UNKNOWN
        || moduleRequest.type == arc::LibType::MENU)
        return false;
    if (moduleRequest.type == arc::LibType::GAME) {
        _lib.loadGame(moduleRequest.name);
        moduleRequest = {"", arc::LibType::UNKNOWN};
        run();
    } else if (moduleRequest.type == arc::LibType::GRAPHIC) {
        _lib.loadGraphic(moduleRequest.name);
        moduleRequest = {"", arc::LibType::UNKNOWN};
        run();
    }

    moduleRequest = {"", arc::LibType::UNKNOWN};
    return true;
}

void arc::Arcade::updateScore(void)
{
    int currentScore = _lib.currentGame->getScore();
    Lib lib = _lib.getCurrentGameLib();
    if (currentScore > _scoreManager.getScore(lib.name))
        _scoreManager.setScore(lib.name, currentScore);
}

void arc::Arcade::run()
{
    _lib.currentGame->initMenu(_lib.getGames(), _lib.getGraphics());
    _lib.currentGame->initGame(_lib.currentGraphic);

    while (true) {
        if (fetchMenuRequest())
            return;
        if (inputManager())
            return;
        updateScore();
        _lib.currentGame->updateGame(_lib.currentGraphic);
        _lib.currentGame->renderGame(_lib.currentGraphic);
    }
    _lib.currentGraphic->destroyWindow();
}

void arc::Arcade::menu(void)
{
    _lib.loadMenu();
    run();
}

void arc::Arcade::start(void)
{
    menu();
}
