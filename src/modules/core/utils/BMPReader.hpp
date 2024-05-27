/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** BMPReader
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "../display/Color.hpp"

using ColorMap = std::vector<std::vector<arc::Color>>;
class BmpReader {
    #pragma pack(push, 1)
    struct BMPHeader {
        uint16_t type;
        uint32_t size;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset;
        uint32_t dib_header_size;
        int32_t  width_px;
        int32_t  height_px;
        uint16_t num_planes;
        uint16_t bits_per_pixel;
        uint32_t compression;
        uint32_t image_size_bytes;
        int32_t  x_resolution_ppm;
        int32_t  y_resolution_ppm;
        uint32_t num_colors;
        uint32_t important_colors;
    };
    #pragma pack(pop)

    public:
        BmpReader(const std::string& filePath) {
            readFromFile(filePath);
        }
        BmpReader() = default;
        ~BmpReader() {
            _file.close();
        }

        void readFromFile(const std::string& filePath) {
            _file.open(filePath, std::ios::binary);
            if (!_file) {
                throw std::runtime_error("Error: Unable to open image: " + filePath);
            }
            _pixelMap.clear();
            readHeader();
            readPixels();
        }

        void readHeader() {
            _file.read(reinterpret_cast<char*>(&header), sizeof(header));
            _dimensions = {header.width_px, header.height_px};
        }

        ColorMap readPixels() {
            _file.seekg(header.offset, std::ios::beg);
            _pixelMap.resize(header.height_px, std::vector<arc::Color>(header.width_px));

            for (int i = 0; i < header.height_px; ++i) {
                for (int j = 0; j < header.width_px; ++j) {
                    _pixelMap[i][j] = readPixel();
                }
            }

            return _pixelMap;
        }

        arc::Color readPixel() {
            arc::Color pixel;
            uint8_t pixelData[4] = {0};

            _file.read(reinterpret_cast<char*>(pixelData), header.bits_per_pixel / 8);
            pixel = arc::Color{pixelData[2], pixelData[1], pixelData[0], pixelData[3]};

            return pixel;
        }

        ColorMap getPixelMap() {
            return _pixelMap;
        }

        arc::ArcSize getDimensions() {
            return _dimensions;
        }

    public:
        ColorMap _pixelMap;

    private:
        BMPHeader header;
        std::ifstream _file;
        arc::ArcSize _dimensions;
};
