/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Menu
*/

#include "Menu.hpp"

namespace arc {
    static std::string addSpaces(std::string str, int size)
    {
        for (int i = str.size(); i < size; i++)
            str += " ";
        return str;
    }

    void Menu::renderTitle(std::unique_ptr<IDisplayModule> &display, const ArcSize &size)
    {
        Text title("Arcade", {size.width / 2 - 3, size.height / 10});
        title.setPairColor(PairColor(Color::White, Color::Transparent));
        display->draw(title);
    }

    void Menu::renderHighScore(std::unique_ptr<IDisplayModule> &display, const ArcSize &size)
    {
        Score score = _scoreManager.getHighScore();
        Text highScore("Highscore : " + score.player + " > " + std::to_string(score.score), {size.width / 2 - 10, size.height / 10 + 2});
        highScore.setPairColor(PairColor(Color::White, Color::Transparent));
        display->draw(highScore);
    }

    void Menu::renderGames(std::unique_ptr<IDisplayModule> &display, const ArcSize &size)
    {
        Text gamesTitle("Select a game :", {size.width / 3 - 6, size.height / 2 - 2});
        gamesTitle.setPairColor(PairColor(Color::White, Color::Transparent));
        display->draw(gamesTitle);

        libVector games = _games;
        for (long unsigned int i = 0; i < games.size(); i++) {
            Position pos = {size.width / 3 - 6, size.height / 2 + (int) i};
            Text text(addSpaces(games[(int) i].name, 15), pos);
            if ((int) i == _cursor && _libIndex == 0) {
                text.setPairColor(PairColor(Color::Black, Color::Yellow));
            }
            else {
                text.setPairColor(PairColor(Color::White, Color::Transparent));
            }
            display->draw(text);
            _gamePos.push_back({pos, {15, 1}});
            _gameMax += 1;
        }
    }

    void Menu::renderGraphics(std::unique_ptr<IDisplayModule> &display, const ArcSize &size)
    {
        Text graphicsTitle("Select a graphic :", {size.width / 3 * 2 - 8, size.height / 2 - 2});
        graphicsTitle.setPairColor(PairColor(Color::White, Color::Transparent));
        display->draw(graphicsTitle);

        libVector graphics = _graphics;
        for (long unsigned int i = 0; i < graphics.size(); i++) {
            Position pos = {size.width / 3 * 2 - 8, size.height / 2 + (int) i};
            Text text(addSpaces(graphics[(int) i].name, 20), pos);
            if ((int) i == _cursor && _libIndex == 1) {
                text.setPairColor(PairColor(Color::Black, Color::Yellow));
            }
            else {
                text.setPairColor(PairColor(Color::White, Color::Transparent));
            }
            display->draw(text);
            _graphicPos.push_back({pos, {20, 1}});
            _graphicMax += 1;
        }
    }
}
