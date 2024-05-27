/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Font
*/

#pragma once
#include <filesystem>
#include "../utils/attributes.hpp"
#include "Color.hpp"

#define DEFAULT_FONT_PATH "assets/font/default.ttf"
#define DEFAULT_BOLD_FONT_PATH "assets/font/defaultBold.ttf"

namespace arc
{
    typedef std::filesystem::path path;

    class TextStyle {
        public:
            TextStyle(PairColor pairColor = PairColor(), TextConf conf = TextConf()) : _pairColor(pairColor), _conf(conf) {};
            ~TextStyle() = default;

            void setConf(const TextConf &conf) { _conf = conf; };
            void setBold(const bool &bold) { _conf.bold = bold; };
            void setUnderline(const bool &underline) { _conf.underline = underline; };
            void setInvisible(const bool &invisible) { _conf.invisible = invisible; };
            void setReverse(const bool &reverse) { _conf.reverse = reverse; };

            const TextConf &getConfig(void) const { return _conf; };
            bool isBold(void) const { return _conf.bold; };
            bool isUnderline(void) const { return _conf.underline; };
            bool isInvisible(void) const { return _conf.invisible; };
            bool isReverse(void) const { return _conf.reverse; };

            void setFontPath(const path fontPath)
            {
                _fontPath = fontPath;
            }

            path getFontPath(void) const
            {
                if (isBold())
                    return _fontboldPath;
                return _fontPath;
            }

            void setFontBoldPath(const path fontboldPath)
            {
                _fontboldPath = fontboldPath;
            }

            void setPairColor(const PairColor &pairColor) { _pairColor = pairColor; };
            const PairColor &getPairColor(void) const { return _pairColor; };

        private:
            PairColor _pairColor = PairColor();
            TextConf _conf = TextConf();
            path _fontPath = DEFAULT_FONT_PATH;
            path _fontboldPath = DEFAULT_BOLD_FONT_PATH;
    };
}

