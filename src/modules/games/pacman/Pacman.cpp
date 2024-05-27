/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Pacman
*/

#include "Pacman.hpp"

void arc::Pacman::assignPositions(int x, int y)
{
    if (_map[y][x] == 'P')
        _player.setPos({x, y});
    if (_map[y][x] == 'L')
        _leftTP = {x, y};
    if (_map[y][x] == 'R')
        _rightTP = {x, y};
    if (_map[y][x] == 'D')
        _door = {x, y};
    if (_map[y][x] >= '1' && _map[y][x] <= '4') {
        _ghosts[_map[y][x] - '1'].setPos({x, y});
        _ghostsInitialPos[_map[y][x] - '1'] = {x, y};
    }
    if (_map[y][x] == '.' || _map[y][x] == 'o')
        _maxPoints++;
}

void arc::Pacman::throwErrors(void)
{
    if (_player.getPos().x == 0 && _player.getPos().y == 0)
        throw std::runtime_error("Player not found in map");
    if (_leftTP.x == 0 && _leftTP.y == 0)
        throw std::runtime_error("Left TP not found in map");
    if (_rightTP.x == 0 && _rightTP.y == 0)
        throw std::runtime_error("Right TP not found in map");
    if (_door.x == 0 && _door.y == 0)
        throw std::runtime_error("Door not found in map");
    if (_maxPoints == 0)
        throw std::runtime_error("No points found in map");
    for (int i = 0; i < 4; i++)
    {
        if (_ghosts[i].getPos().x == 0 && _ghosts[i].getPos().y == 0)
            throw std::runtime_error("Ghost not found in map");
    }
}

void arc::Pacman::initMap(void)
{
    std::ifstream file("assets/pacman/map.txt");
    std::string line;
    _map.clear();
    _maxPoints = 0;

    while (std::getline(file, line))
    {
        std::vector<char> row(line.begin(), line.end());
        _map.push_back(row);
    }

    for (int y = 0; y < (int) _map.size(); y++)
    {
        for (int x = 0; x < (int) _map[y].size(); x++)
            assignPositions(x, y);
    }
    throwErrors();
};

void arc::Pacman::displayTitles(std::unique_ptr<IDisplayModule> &display)
{
    ArcSize size = display->getCurWindowSize();
    Text title("Press q to quit", {size.width / 2 - 6, size.height / 10});
    title.setPairColor(PairColor(Color::White, Color::Transparent));
    display->draw(title);

    Text score("Score:", {size.width / 10, size.height / 10 + 2});
    score.setPairColor(PairColor(Color::White, Color::Transparent));
    Text scoreValue(std::to_string(_score), {size.width / 10 + 7, size.height / 10 + 2});
    scoreValue.setPairColor(PairColor(Color::White, Color::Transparent));
    display->draw(score);
    display->draw(scoreValue);
};


void arc::Pacman::displayMap(std::unique_ptr<IDisplayModule> &display, int x, int y, int mapStartX, int mapStartY)
{
    Pixel cell(_map[y][x], PairColor(Color::White, Color::Transparent));

    if (_map[y][x] == '#')
    {
        cell.setChar(' ');
        cell.setPairColor(PairColor(Color::Blue, Color::Blue));
    }
    if (_map[y][x] == ' ')
        cell.setPairColor(PairColor(Color::Black, Color::Black));

    if (_map[y][x] == '.' || _map[y][x] == 'o')
        cell.setPairColor(PairColor(Color::Yellow, Color::Black));
    if (_map[y][x] == 'D')
    {
        cell.setChar(' ');
        cell.setPairColor(PairColor(Color::Pink, Color::Pink));
    }
    if (_map[y][x] == 'P') {
        cell.setChar('C');
        cell.setPairColor(PairColor(Color::Yellow, Color::Black));
    }
    if (_map[y][x] == 'L' || _map[y][x] == 'R') {
        cell.setChar(' ');
        cell.setPairColor(PairColor(Color::Black, Color::Black));
    }
    if (_map[y][x] >= '1' && _map[y][x] <= '4') {
        cell.setChar('"');
        if (_isAccelerated)
            cell.setPairColor(PairColor(Color::White, Color::Cyan));
        else
            cell.setPairColor(_ghosts[_map[y][x] - '1'].getColor());
        if (_ghosts[_map[y][x] - '1'].getIsDead())
            cell.setPairColor(PairColor(Color::White, Color::Black));
    }
    display->draw(cell, {x + mapStartX, y + mapStartY});
};

void arc::Pacman::renderGame(std::unique_ptr<IDisplayModule> &display)
{
    float deltaTime = display->getElapsedTime() - _lastFrameTime;
    if (deltaTime < 1 / FPS)
        return;

    display->clearWindow();
    ArcSize size = display->getCurWindowSize();
    displayTitles(display);
    display->draw(_pacmanSprite);

    if (_maxPoints == 0)
        initMap();

    int mapStartX = size.width / 2 - _map[0].size() / 2;
    int mapStartY = size.height / 2 - _map.size() / 2;

    for (int y = 0; y < (int) _map.size(); y++)
    {
        for (int x = 0; x < (int) _map[y].size(); x++)
            displayMap(display, x, y, mapStartX, mapStartY);
    }

    display->displayWindow();
    _lastFrameTime = display->getElapsedTime();
    if (_isAccelerated) {
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(_refreshRateAcc)));
        _accelerateTime++;
        _ghostSkip = !_ghostSkip;
        if (_accelerateTime >= 100) {
            _isAccelerated = false;
            _accelerateTime = 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (_ghosts[i].getIsDead()) {
                _ghosts[i].setTimeDead(_ghosts[i].getTimeDead() + 1);
                if (_ghosts[i].getTimeDead() >= 100) {
                    _ghosts[i].setIsDead(false);
                    _ghosts[i].setTimeDead(0);
                    _ghosts[i].setAlreadyReset(false);
                }
            }
        }
    }
    else {
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(_refreshRate)));
        for (int i = 0; i < 4; i++)
        {
            if (_ghosts[i].getIsDead()) {
                _ghosts[i].setTimeDead(_ghosts[i].getTimeDead() + 1);
                if (_ghosts[i].getTimeDead() >= 100) {
                    _ghosts[i].setIsDead(false);
                    _ghosts[i].setTimeDead(0);
                    _ghosts[i].setAlreadyReset(false);
                }
            }
        }
    }

    _pacmanSprite.incrementFrame();
    _increment++;
    if (_increment >= 50)
        _map[_door.y][_door.x] = ' ';
};

void arc::Pacman::handleInput(std::unique_ptr<IDisplayModule> &display)
{
    Input input = display->getInput();

    if (input.getFrontKey().key== InputKey::UP)
        _player.setDir(DIR_UP);
    if (input.getFrontKey().key== InputKey::DOWN)
        _player.setDir(DIR_DOWN);
    if (input.getFrontKey().key== InputKey::RIGHT)
        _player.setDir(DIR_RIGHT);
    if (input.getFrontKey().key== InputKey::LEFT)
        _player.setDir(DIR_LEFT);
    if (input.getFrontKey().key== InputKey::R) {
        _pressReset = true;
        restartGame();
    }
}

void arc::Pacman::initGame(std::unique_ptr<IDisplayModule> &display)
{
    _lastFrameTime = display->getElapsedTime();
    display->createFullScreenWindow();
    // display->createWindow(75, 40, "Pacman");
    // set position to bottom left corner of the window
    ArcSize size = display->getCurWindowSize();
    _pacmanSprite.setPosition({_pacmanSprite.getRect().w / 2, size.height -
                                (_pacmanSprite.getRect().h + _pacmanSprite.getRect().h / 2)});
};

void arc::Pacman::resetGhosts(void)
{
    for (auto &ghost : _ghosts)
        ghost.reset();
}

bool arc::Pacman::canMoveAround(positionList aroundPos)
{
    for (auto pos : aroundPos)
    {
        if (_map[pos.y][pos.x] == ' ' || _map[pos.y][pos.x] == 'P'
            || _map[pos.y][pos.x] == '.' || _map[pos.y][pos.x] == 'L'
            || _map[pos.y][pos.x] == 'R' || _map[pos.y][pos.x] == 'o')
            return true;
    }
    return false;
}

bool arc::Pacman::isPosEqual(Position pos1, Position pos2)
{
    return pos1.x == pos2.x && pos1.y == pos2.y;
}


void arc::Pacman::updateGhost(Ghost &ghost)
{
    if (_ghostSkip)
        return;

    if (ghost.getIsDead()) {
        ghost.setPos(ghost.getInitialPos());
        for (int i = 1; i < 4; i++)
        {
            _map[_ghosts[i].getPos().y][_ghosts[i].getPos().x] = '1' + i;
            ghost.setPos(ghost.getInitialPos());
        }
        ghost.setAlreadyReset(true);
        return;
    }

    Position nextPos = getRandPos(ghost);


    if (_map[nextPos.y][nextPos.x] == 'L')
        nextPos = {_rightTP.x - 1, _rightTP.y};

    if (_map[nextPos.y][nextPos.x] == 'R')
        nextPos = {_leftTP.x + 1, _leftTP.y};

    if (_map[nextPos.y][nextPos.x] == 'P' && !_isAccelerated)
    {
        restartGame();
        return;
    }

    if (_map[nextPos.y][nextPos.x] == 'P' && _isAccelerated)
    {
        nextPos = ghost.getInitialPos();
        _ghosts[0].setIsDead(true);
        _ghosts[0].setTimeDead(0);
        _ghosts[0].setAlreadyReset(true);
    }

    if (_ghosts[0].getPrevChar() == '.')
        _map[_ghosts[0].getPos().y][_ghosts[0].getPos().x] = '.';
    else if (_ghosts[0].getPrevChar() == 'o')
        _map[_ghosts[0].getPos().y][_ghosts[0].getPos().x] = 'o';
    else
        _map[_ghosts[0].getPos().y][_ghosts[0].getPos().x] = ' ';

    _ghosts[0].setPrevChar(_map[nextPos.y][nextPos.x]);

    _map[nextPos.y][nextPos.x] = '1';

    for (int i = 1; i < 4; i++)
    {
        _map[_ghosts[i].getPos().y][_ghosts[i].getPos().x] = '1' + i;
        ghost.setPos(ghost.getInitialPos());
    }
    ghost.setPos(nextPos);
}

void arc::Pacman::updateGhosts(void)
{
    if (_ghostSkip)
        return;

    if (_increment <= 10) {
        updateGhost(_ghosts[0]);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_ghosts[i].getIsDead()) {
            _ghosts[i].setPos(_ghostsInitialPos[i]);
            _ghosts[i].setAlreadyReset(true);
            continue;
        }

        Position nextPos = getRandPos(_ghosts[i]);

        if (_map[nextPos.y][nextPos.x] == 'L')
        nextPos = {_rightTP.x - 1, _rightTP.y};

        if (_map[nextPos.y][nextPos.x] == 'R')
        nextPos = {_leftTP.x + 1, _leftTP.y};

        if (_map[nextPos.y][nextPos.x] == 'P' && !_isAccelerated)
        {
            restartGame();
            return;
        }
        if (_map[nextPos.y][nextPos.x] == 'P' && _isAccelerated)
        {
            //ghost go to initial pos with _ghostsInitialPos
            nextPos = _ghostsInitialPos[i];
            _ghosts[i].setIsDead(true);
            _ghosts[i].setTimeDead(0);
            _ghosts[i].setAlreadyReset(true);
        }

        if (_ghosts[i].getPrevChar() == '.')
            _map[_ghosts[i].getPos().y][_ghosts[i].getPos().x] = '.';
        else if (_ghosts[i].getPrevChar() == 'o')
            _map[_ghosts[i].getPos().y][_ghosts[i].getPos().x] = 'o';
        else
            _map[_ghosts[i].getPos().y][_ghosts[i].getPos().x] = ' ';

        _ghosts[i].setPrevChar(_map[nextPos.y][nextPos.x]);

        _map[nextPos.y][nextPos.x] = '1' + i;

        _ghosts[i].setPos(nextPos);

    }
}

void arc::Pacman::updateGame(std::unique_ptr<IDisplayModule> &display)
{
    handleInput(display);
    if (_pressReset) {
        _pressReset = false;
        return;
    }

    float deltaTime = display->getElapsedTime() - _lastFrameTime;
    if (deltaTime < 1 / FPS)
        return;

    Position currentPos = _player.getPos();
    Position nextPos = _player.getPos();
    switch (_player.getDir())
    {
    case DIR_UP:
        nextPos.y = (nextPos.y - 1 + _map.size()) % _map.size();
        break;
    case DIR_DOWN:
        nextPos.y = (nextPos.y + 1) % _map.size();
        break;
    case DIR_LEFT:
        nextPos.x = (nextPos.x - 1 + _map[0].size()) % _map[0].size();
        break;
    case DIR_RIGHT:
        nextPos.x = (nextPos.x + 1) % _map[0].size();
        break;
    default:
        break;
    }

    if (_map[nextPos.y][nextPos.x] == '#') {
        updateGhosts();
        return;
    }
    if (_map[nextPos.y][nextPos.x] == 'L')
        nextPos = {_rightTP.x - 1, _rightTP.y};

    if (_map[nextPos.y][nextPos.x] == 'R')
        nextPos = {_leftTP.x + 1, _leftTP.y};

    if (_map[nextPos.y][nextPos.x] >= '1' && _map[nextPos.y][nextPos.x] <= '4' && _isAccelerated)
    {
        int number = _map[nextPos.y][nextPos.x] - '1';
        Position ghostInitialPos = _ghostsInitialPos[number];
        //set ghost is dead
        _ghosts[number].setIsDead(true);
        _ghosts[number].setTimeDead(0);
        if (_ghosts[number].getPrevChar() == '.')
            _map[_ghosts[number].getPos().y][_ghosts[number].getPos().x] = '.';
        else if (_ghosts[number].getPrevChar() == 'o')
            _map[_ghosts[number].getPos().y][_ghosts[number].getPos().x] = 'o';
        else
            _map[_ghosts[number].getPos().y][_ghosts[number].getPos().x] = ' ';
        _ghosts[number].setAlreadyReset(true);
        _ghosts[number].setPos(ghostInitialPos);
    }

    if (_map[nextPos.y][nextPos.x] == '.')
    {
        _score++;
        _refreshRate -= 0.1;
        _maxPoints--;
    }
    if (_map[nextPos.y][nextPos.x] == 'o')
    {
        _score ++;
        _refreshRate -= 0.1;
        _maxPoints--;
        _isAccelerated = true;
    }
    if (_map[nextPos.y][nextPos.x] >= '1' && _map[nextPos.y][nextPos.x] <= '4' && !_isAccelerated)
    {
        restartGame();
        return;
    }

    _map[nextPos.y][nextPos.x] = 'P';
    _map[currentPos.y][currentPos.x] = ' ';
    _player.setPos(nextPos);
    updateGhosts();
    _lastFrameTime = display->getElapsedTime();
};

void arc::Pacman::restartMap(void)
{
    _player.reset();
    resetGhosts();
    initMap();
    for (int i = 0; i < 4; i++)
        _ghosts[i].setPrevChar(' ');
    _increment = 0;
    _map[_door.y][_door.x] = 'D';
    _isAccelerated = false;
    _accelerateTime = 0;
    for (int i = 0; i < 4; i++)
    {
        _ghosts[i].setIsDead(false);
        _ghosts[i].setTimeDead(0);
        _ghosts[i].setAlreadyReset(false);
    }
}

void arc::Pacman::restartGame(void)
{
    _score = 0;
    _refreshRate = 200;
    _player.reset();
    resetGhosts();
    initMap();
    _increment = 0;
    _map[_door.y][_door.x] = 'D';
    _isAccelerated = false;
    _accelerateTime = 0;
    for (int i = 0; i < 4; i++)
    {
        _ghosts[i].setPrevChar(' ');
        _ghosts[i].setIsDead(false);
        _ghosts[i].setTimeDead(0);
        _ghosts[i].setAlreadyReset(false);
    }
}
