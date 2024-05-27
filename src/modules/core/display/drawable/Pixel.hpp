/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Chtype
*/

#pragma once

#include "../TextStyle.hpp"

namespace arc
{
    class Pixel : public TextStyle
    {
        public:
            Pixel(char ch = ' ', PairColor pairColor = PairColor(), TextConf conf = TextConf()) : TextStyle(pairColor, conf), _ch(ch) {};
            Pixel(const Pixel &other) = default;
            Pixel(Pixel &&other) = default;
            Pixel &operator=(const Pixel &other) = default;
            Pixel &operator=(Pixel &&other) = default;
            ~Pixel() = default;

            Pixel &operator=(const char &ch)
            {
                _ch = ch;
                return *this;
            };
            Pixel &operator=(const PairColor &color)
            {
                setPairColor(color);
                return *this;
            };
            Pixel &operator=(const TextConf &conf)
            {
                setConf(conf);
                return *this;
            };
            bool operator==(const Pixel &other) const { return _ch == other._ch; };
            bool operator==(const char &ch) const { return _ch == ch; };
            bool operator!=(const Pixel &other) const { return _ch != other._ch; };
            bool operator!=(const char &ch) const { return _ch != ch; };
            bool operator<(const Pixel &other) const { return _ch < other._ch; };
            bool operator<(const char &ch) const { return _ch < ch; };
            bool operator>(const Pixel &other) const { return _ch > other._ch; };
            bool operator>(const char &ch) const { return _ch > ch; };
            bool operator<=(const Pixel &other) const { return _ch <= other._ch; };
            bool operator<=(const char &ch) const { return _ch <= ch; };
            bool operator>=(const Pixel &other) const { return _ch >= other._ch; };
            bool operator>=(const char &ch) const { return _ch >= ch; };
            const char &operator*(void) const { return _ch; };

            void setChar(const char &ch) { _ch = ch; };
            char getChar(void) const { return _ch; };
            std::string str(void) const { return std::string(1, _ch); };

        private:
            char _ch = ' ';
    };
}
