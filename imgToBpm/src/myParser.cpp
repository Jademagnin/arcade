/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** argParser
*/

#include "myParser.hpp"

static void setArgs(argparse::ArgumentParser *program)
{
    program->add_argument("imagePath")
      .help("set image path");

    program->add_argument("--file", "-f")
      .default_value(std::string("output"))
      .help("output file name");

    program->add_argument("--size", "-s")
      .default_value(std::string("10"))
      .help("Block size for pixelation, representing how many original pixels will be grouped into a single pixel in the pixelated image");
}

argparse::ArgumentParser* myParser(int argc, char* argv[])
{
    argparse::ArgumentParser *program = new argparse::ArgumentParser("imgToBpm");

    setArgs(program);
    try {
        program->parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        exit(84);
    }
    return program;
}