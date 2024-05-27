/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** main
*/


#include <iostream>
#include "Arcade.hpp"

std::string getPlayerName()
{
    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    while (username.length() >= 12 || username.length() < 1 ||
        std::all_of(username.begin(), username.end(), isspace) ||
        username.find(";") != std::string::npos) {
        std::cout << "Username is" << (username.length() >= 12 ? " too long"
                    : " invalid") << std::endl;
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);
    }
    return username;
}

int main(int ac, char **av)
{
    srand(time(0));
    if (ac != 2) {
        std::cerr << "Usage: ./arcade path_to_graphic_library" << std::endl;
        return 84;
    }
    try {
        std::string username = getPlayerName();
        if (username.empty())
            return 84;
        arc::Arcade arcade(av[1], username);
        arcade.start();
    }
    catch (const arc::ArcadeError &e) {
        std::cerr << "Arcade : " << e.what() << std::endl;
        return 84;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
