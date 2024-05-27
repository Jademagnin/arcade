/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** NColor
*/

#pragma once
#include <map>
#include "../ADisplayModule.hpp"

namespace arc
{
    class NColor {
        public:
            NColor(unsigned max = 0) : _max(max) { initMap(); }
            ~NColor() = default;

            unsigned addColor(Color color)
            {
                if (_curID >= _max)
                    _curID = 8;
                _map[_curID] = color;
                return _curID++;
            }

            // find the id of Color, if not found return 0
            unsigned findColor(Color color)
            {
                for (auto &it : _map) {
                    if (it.second == color)
                        return it.first;
                }
                return 0;
            }

            unsigned findOrAdd(Color color)
            {
                unsigned id = findColor(color);

                if (id == 0)
                    id = addColor(color);
                return id;
            }

            void reset(void)
            {
                _curID = 8;
                _map.clear();
                initMap();
            }

            void setMax(unsigned max)
            {
                _max = max;
            }

        private:
            void initMap(void)
            {
                _map[0] = Color::Black;
                _map[1] = Color::Red;
                _map[2] = Color::Green;
                _map[3] = Color::Yellow;
                _map[4] = Color::Blue;
                _map[5] = Color::Magenta;
                _map[6] = Color::Cyan;
                _map[7] = Color::White;
            }

        private:
            unsigned _max;
            std::map<unsigned, Color> _map;
            unsigned _curID = 8;
    };
}
