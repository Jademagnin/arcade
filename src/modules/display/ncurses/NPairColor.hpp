/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** PairColor
*/

#pragma once
#include <map>
#include "../ADisplayModule.hpp"

namespace arc
{
    class NPairColor {
        public:
            NPairColor(unsigned max = 0) : _max(max) {};
            ~NPairColor() = default;

            unsigned addColor(PairColor pcolor)
            {
                if (_curID >= _max)
                    _curID = 1;
                _map[_curID] = pcolor;
                return _curID++;
            }

            // find the id of PairColor, if not found return 0
            unsigned findPairColor(PairColor pcolor)
            {
                for (auto &it : _map) {
                    if (it.second == pcolor)
                        return it.first;
                }
                return 0;
            }

            unsigned findOrAdd(PairColor pcolor)
            {
                unsigned id = findPairColor(pcolor);

                if (id == 0)
                    id = addColor(pcolor);
                return id;
            }

            void reset(void)
            {
                _curID = 1;
                _map.clear();
            }

            void setMax(unsigned max)
            {
                _max = max;
            }

        private:
            unsigned _max;
            std::map<unsigned, PairColor> _map;
            unsigned _curID = 1;
    };
}
