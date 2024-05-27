/*
** EPITECH PROJECT, 2024
** arcade_copy
** File description:
** Snake
*/

#include "Snake.hpp"

void arc::Snake::setNextPos(std::pair<int, int> &nextPos)
{
    switch (_dir)
    {
    case DIR_UP:
        nextPos.second--;
        break;
    case DIR_DOWN:
        nextPos.second++;
        break;
    case DIR_LEFT:
        nextPos.first--;
        break;
    case DIR_RIGHT:
        nextPos.first++;
        break;
    default:
        break;
    }
}

void arc::Snake::updateGame(std::unique_ptr<IDisplayModule> &display)
{
    handleInput(display);
    float deltaTime = display->getElapsedTime() - _lastFrameTime;
    if (deltaTime < 1 / FPS)
        return;
    std::pair<int, int> nextPos = _snake.front();
    setNextPos(nextPos);
    if (_map[nextPos.second][nextPos.first] == '#')
    {
        restartGame();
        return;
    }
    if (_map[nextPos.second][nextPos.first] == 'P')
    {
        restartGame();
        return;
    }
    if (_map[nextPos.second][nextPos.first] == 'F')
    {
        _score++;
        if ((size_t)_snakeSize != (_map.size() - 2) * (_map[0].size() - 2) - 1) {
            _snakeSize++;
            _snake.push_front(nextPos);
            _refreshRate -= 5;
        }
        _map[_snake.front().second][_snake.front().first] = 'P';
        addFruit();
    }
    if (_map[nextPos.second][nextPos.first] == ' ') {
        _snake.push_front(nextPos);
        _map[_snake.front().second][_snake.front().first] = 'P';
        _map[_snake.back().second][_snake.back().first] = ' ';
        _snake.pop_back();
    }

    _lastFrameTime = display->getElapsedTime();
};

void arc::Snake::addFruit(void)
{
    int x = rand() % _map[0].size();
    int y = rand() % _map.size();
    if (_map[y][x] == ' ')
    {
        _map[y][x] = 'F';
    }
    else
    {
        addFruit();
    }
}

void arc::Snake::initMap(void)
{
    std::ifstream file("assets/snake/map.txt");
    if (!file.is_open())
        throw std::runtime_error("Cannot open file");
    std::string line;
    _map.clear();

    while (std::getline(file, line))
    {
        std::vector<char> row(line.begin(), line.end());
        _map.push_back(row);
    }
    _snake.push_back({_map[0].size() / 2, _map.size() / 2});
    _snake.push_back({_map[0].size() / 2 - 1, _map.size() / 2});
    _snake.push_back({_map[0].size() / 2 - 2, _map.size() / 2});
    _snake.push_back({_map[0].size() / 2 - 3, _map.size() / 2});
};

void arc::Snake::displayTitles(std::unique_ptr<IDisplayModule> &display)
{
    ArcSize size = display->getCurWindowSize();

    Text title("Press q to quit", {size.width / 2 - 6, size.height / 10});
    title.setPairColor(PairColor(Color::White, Color::Transparent));
    display->draw(title);

    Text scoreText("Score: " + std::to_string(_score), {size.width / 10, size.height / 10});
    scoreText.setPairColor(PairColor(Color::White, Color::Transparent));

    Text scoreValue(std::to_string(_score), {size.width / 10 + 7, size.height / 10 + 2});
    scoreValue.setPairColor(PairColor(Color::White, Color::Transparent));
    display->draw(scoreText);
};

void arc::Snake::displayMap(std::unique_ptr<IDisplayModule> &display, int x, int y, int mapStartX, int mapStartY)
{
    Pixel cell(_map[y][x], PairColor(Color::White, Color::Transparent));
    if (_map[y][x] == '#')
    {
        cell.setChar(' ');
        cell.setPairColor(PairColor(Color::DarkGreen, Color::DarkGreen));
    }
    if (_map[y][x] == 'F')
    {
        cell.setChar(' ');
        cell.setPairColor(PairColor(Color::Red, Color::Red));
    }
    if (_map[y][x] == 'P') {
        cell.setChar(' ');
        cell.setPairColor(PairColor(Color::Blue, Color::Blue));
    }
    if (_map[y][x] == 'P' && (y == _snake.front().second && x == _snake.front().first)) {
        cell.setChar('"');
        cell.setPairColor(PairColor(Color::White, Color::Blue));
    }
    if (_map[y][x] == ' ')
        cell.setPairColor(PairColor(Color::Green, Color::Green));

    display->draw(cell, {x + mapStartX, y + mapStartY});
}

void arc::Snake::renderGame(std::unique_ptr<IDisplayModule> &display)
{
    float deltaTime = display->getElapsedTime() - _lastFrameTime;
    if (deltaTime < 1 / FPS)
        return;

    display->clearWindow();
    ArcSize size = display->getCurWindowSize();

    displayTitles(display);

    int mapStartX = size.width / 2 - _map[0].size() / 2;
    int mapStartY = size.height / 2 - _map.size() / 2;

    for (int y = 0; y < (int) _map.size(); y++)
    {
        for (int x = 0; x < (int) _map[y].size(); x++)
        {
            displayMap(display, x, y, mapStartX, mapStartY);
        }
    }

    display->displayWindow();
    _lastFrameTime = display->getElapsedTime();
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(_refreshRate)));
};

void arc::Snake::handleInput(std::unique_ptr<IDisplayModule> &display)
{
    Input input = display->getInput();
    if (input.getFrontKey().key == InputKey::UP && _dir != DIR_DOWN)
        _dir = DIR_UP;
    if (input.getFrontKey().key == InputKey::DOWN && _dir != DIR_UP)
        _dir = DIR_DOWN;
    if (input.getFrontKey().key == InputKey::RIGHT && _dir != DIR_LEFT)
        _dir = DIR_RIGHT;
    if (input.getFrontKey().key == InputKey::LEFT && _dir != DIR_RIGHT)
        _dir = DIR_LEFT;
    if (input.getFrontKey().key == InputKey::R)
        restartGame();
}

void arc::Snake::restartGame(void)
{
    _snake.clear();
    _dir = DIR_RIGHT;
    _score = 0;
    initMap();
    _snakeSize = 4;
    _refreshRate = 300;
    addFruit();
}
