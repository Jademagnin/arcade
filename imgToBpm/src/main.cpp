/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** main
*/

#include "myParser.hpp"
#include <opencv2/opencv.hpp>

cv::Mat getImage(const std::string &path)
{
    cv::Mat image = cv::imread(path);
    if (image.empty())
        throw std::runtime_error("Could not open or find the image");
    return image;
}

void imgToArc(const std::string &path, int blockSize, const std::string &nameFile)
{
    cv::Mat image = getImage(path);
    cv::Mat pixelated;

    cv::resize(image, pixelated, cv::Size(image.cols / blockSize, image.rows / blockSize), 0, 0, cv::INTER_LINEAR);
    cv::imwrite(nameFile, pixelated);
}

int main(int ac, char *av[])
{
    argparse::ArgumentParser *program = myParser(ac, av);

    try
    {
        std::string image_path = program->get<std::string>("imagePath");
        std::string nameFile = program->get<std::string>("-f") + ".bmp";
        int size = std::stoi(program->get<std::string>("-s"));

        imgToArc(image_path, size, nameFile);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 84;
    }
}