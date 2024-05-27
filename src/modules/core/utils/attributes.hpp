/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Position
*/

#pragma once

#include <cstddef>

namespace arc
{
    struct Position
    {
        int x = 0;
        int y = 0;
    };

    struct ArcSize
    {
        int width = 1;
        int height = 1;
    };

    struct TextConf
    {
        bool bold = false;
        bool underline = false;
        bool reverse = false;
        bool invisible = false;
    };
}
