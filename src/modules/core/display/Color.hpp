/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Color
*/

#pragma once

typedef unsigned char UChar;

namespace arc
{
    class Color
    {
    public:
        Color();
        Color(UChar red, UChar green, UChar blue, UChar alpha = 255);
        Color(const Color &color) = default;
        Color &operator=(const Color &color) = default;
        Color(Color &&color) noexcept = default;
        Color &operator=(Color &&color) noexcept = default;
        ~Color() = default;

        bool operator==(const Color &color) const;
        bool operator!=(const Color &color) const;

        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color DarkGreen;
        static const Color Blue;
        static const Color Yellow;
        static const Color Orange;
        static const Color Magenta;
        static const Color Purple;
        static const Color Pink;
        static const Color Cyan;
        static const Color Transparent;

        UChar r;
        UChar g;
        UChar b;
        UChar a;
    };

    class PairColor
    {
        public:
            PairColor(Color text = Color::White, Color background = Color::Black);
            PairColor(const PairColor &color) = default;
            PairColor &operator=(const PairColor &color) = default;
            PairColor(PairColor &&color) noexcept = default;
            PairColor &operator=(PairColor &&color) noexcept = default;
            ~PairColor() = default;

            bool operator==(const PairColor &color) const;
            bool operator!=(const PairColor &color) const;

            Color _text;
            Color _background;
    };
}
