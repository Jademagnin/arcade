/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** Texture
*/

#pragma once

#include "Pixel.hpp"
#include "../../utils/BMPReader.hpp"
#include <vector>
#include <filesystem>
#include <fstream>

namespace arc
{
    struct Rect
    {
        int x;
        int y;
        int w;
        int h;
    };
    using PixelMap = std::vector<std::vector<Pixel>>;

    class errorTexture : public std::runtime_error {
        public:
            explicit errorTexture(const std::string &message) : std::runtime_error(message) {}
    };
    class Texture
    {
        public:
            Texture(const std::filesystem::path &path)
            {
                loadTexture(path);
            }
            Texture() = default;
            ~Texture() = default;

            void loadTexture(const std::filesystem::path &path)
            {
                if (!isBmp(path)) {
                    throw errorTexture("Error: Invalid texture file");
                }
                BmpReader reader(path);

                ColorMap map = reader.getPixelMap();
                _dimensions = reader.getDimensions();

                // iterate through ColorMap
                for (size_t y = 0; y < map.size(); y++) {
                    std::vector<Pixel> row;
                    for (size_t x = 0; x < map[y].size(); x++) {
                        Pixel pixel(' ', PairColor(map[y][x], map[y][x]));
                        row.push_back(pixel);
                    }
                    _texture.push_back(row);
                }
            }

            PixelMap getTexture() const { return _texture; }
            bool isEmpty() const { return _texture.size() == 0; }

            ArcSize getDimensions() const { return _dimensions; }
            int getWidth() const { return _dimensions.width; }
            int getHeight() const { return _dimensions.height; }
            int getSize() const { return _size; }

        private:
            bool isBmp(const std::filesystem::path &path) { return path.extension() == ".bmp"; };
            PixelMap _texture;
            ArcSize _dimensions;
            int _size;
    };
}
