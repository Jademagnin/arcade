/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Events
*/

#include "Menu.hpp"

namespace arc {
    static bool isMouseInArea(const InputEvent &event, const PosRange &area) {
        return event.mousePos.x >= area.first.x && event.mousePos.x <= area.first.x + area.second.width &&
            event.mousePos.y >= area.first.y && event.mousePos.y <= area.first.y + area.second.height;
    }

    void Menu::handleClickOnGame(const InputEvent &event)
    {
        for (long unsigned int i = 0; i < _gamePos.size(); i++) {
            if (isMouseInArea(event, _gamePos[i])) {
                _cursor = i;
                _libIndex = 0;
                if (event.key == InputKey::MOUSE_LEFT)
                    setModuleRequest({ _games[_cursor].name, arc::LibType::GAME });
            }
        }
    }

    void Menu::handleClickOnGraphic(const InputEvent &event)
    {
        for (long unsigned int i = 0; i < _graphicPos.size(); i++) {
            if (isMouseInArea(event, _graphicPos[i])) {
                _cursor = i;
                _libIndex = 1;
                if (event.key == InputKey::MOUSE_LEFT)
                    setModuleRequest({ _graphics[_cursor].name, arc::LibType::GRAPHIC });
            }
        }
    }

    bool Menu::handleMouseInput(const InputEvent &event)
    {
        if (event.isMouseEvent && event.key)
        {
            handleClickOnGame(event);
            handleClickOnGraphic(event);

            return true;
        }

        return false;
    }

    bool Menu::handleKeyboardInput(const InputEvent &event)
    {
        switch (event.key)
        {
            case InputKey::UP:
                if (_cursor > 0)
                    _cursor--;
                break;
            case InputKey::DOWN:
                if (_libIndex == 0 && _cursor < _gameMax - 1)
                    _cursor++;
                if (_libIndex == 1 && _cursor < _graphicMax - 1)
                    _cursor++;
                break;
            case InputKey::RIGHT:
                if (_libIndex == 0) {
                    _libIndex = 1;
                    _cursor = 0;
                }
                break;
            case InputKey::LEFT:
                if (_libIndex != 0) {
                    _libIndex = 0;
                    _cursor = 0;
                }
                break;
            case InputKey::ENTER:
                if (_libIndex == 0)
                    setModuleRequest({ _games[_cursor].name, arc::LibType::GAME });
                if (_libIndex == 1)
                    setModuleRequest({ _graphics[_cursor].name, arc::LibType::GRAPHIC });
                break;
            default:
                return false;
                break;
        }
        return true;
    }
} // namespace arc