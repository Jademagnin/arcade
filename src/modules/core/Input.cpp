/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Input
*/

#include "Input.hpp"

namespace arc {
    Input::Input()
    {

    }

    Input::~Input()
    {

    }

    void Input::addKey(const InputKey &key)
    {
        _queueKey.push({
            key,
            false,
            {-1, -1}
        });
    }

    void Input::addMouseClick(const InputKey &key, const Position &pos)
    {
        if (pos.x < 0 || pos.y < 0 || key == NONE)
            return;

        _queueKey.push({
            key,
            true,
            pos
        });
    }

    InputEvent Input::getFrontKey(void) const
    {
        if (_queueKey.empty())
            return {
                NONE,
                false,
                {-1, -1}
            };
        return _queueKey.front();
    }

    InputEvent Input::getKey(void)
    {
        InputEvent key;

        if (_queueKey.empty())
            return {
                NONE,
                false,
                {-1, -1}
            };

        key =  _queueKey.front();
        _queueKey.pop();
        return key;
    }

    void Input::reset(void)
    {
        while (!_queueKey.empty())
            _queueKey.pop();
    }
} // namespace arc
