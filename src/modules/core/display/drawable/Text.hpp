/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Text
*/

#pragma once

#include <string>
#include "../TextStyle.hpp"
#include "../Actor.hpp"

namespace arc
{
    class Text : public TextStyle, public Actor
    {
    public:
        Text() = default;
        Text(const std::string str, Position pos) : Actor(pos), _str(str) {};
        ~Text() = default;

        const char &operator[](size_t index) const
        {
            if (index >= _str.size())
                return _str[_str.size() - 1];
            return _str[index];
        };

        const std::string &operator*(void) const { return _str; };

        void setString(const std::string str) { _str = str; };
        const std::string& getStr(void) const { return _str; };

    private:
        std::string _str = "";
    };
}
