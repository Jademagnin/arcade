/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Color
*/

#include "Color.hpp"

namespace arc
{
    // Color
    const Color Color::Black = Color(0, 0, 0);
    const Color Color::White = Color(255, 255, 255);
    const Color Color::Red = Color(255, 0, 0);
    const Color Color::Green = Color(0, 255, 0);
    const Color Color::DarkGreen = Color(0, 128, 0);
    const Color Color::Blue = Color(0, 0, 255);
    const Color Color::Yellow = Color(255, 255, 0);
    const Color Color::Orange = Color(255, 165, 0);
    const Color Color::Magenta = Color(255, 0, 255);
    const Color Color::Purple = Color(128, 0, 128);
    const Color Color::Pink = Color(255, 192, 203);
    const Color Color::Cyan = Color(0, 255, 255);
    const Color Color::Transparent = Color(0, 0, 0, 0);

    Color::Color() : r(0), g(0), b(0), a(255) {}
    Color::Color(UChar red, UChar green, UChar blue, UChar alpha) : r(red), g(green), b(blue), a(alpha) {}
    bool Color::operator==(const Color &color) const
    {
        return (r == color.r && g == color.g && b == color.b && a == color.a);
    }

    bool Color::operator!=(const Color &color) const
    {
        return !(*this == color);
    }

    // PairColor
    PairColor::PairColor(Color text, Color background) : _text(text), _background(background){};

    bool PairColor::operator==(const PairColor &color) const
    {
        return _text == color._text && _background == color._background;
    }
    bool PairColor::operator!=(const PairColor &color) const { return !(*this == color); }
}
