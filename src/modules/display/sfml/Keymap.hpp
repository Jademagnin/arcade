/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Keymap
*/

#pragma once

#include "SFML.hpp"
#include <unordered_map>

/*
    enum InputKey {
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
        UP, DOWN, LEFT, RIGHT, SPACE, TAB, ENTER, ESCAPE, BACKSPACE, DELETE,
        CLOSE, NONE
    };
*/

namespace arc {
    static const std::unordered_map<sf::Keyboard::Key, InputKey> Keymap = {
        {sf::Keyboard::Key::A, InputKey::A},
        {sf::Keyboard::Key::B, InputKey::B},
        {sf::Keyboard::Key::C, InputKey::C},
        {sf::Keyboard::Key::D, InputKey::D},
        {sf::Keyboard::Key::E, InputKey::E},
        {sf::Keyboard::Key::F, InputKey::F},
        {sf::Keyboard::Key::G, InputKey::G},
        {sf::Keyboard::Key::H, InputKey::H},
        {sf::Keyboard::Key::I, InputKey::I},
        {sf::Keyboard::Key::J, InputKey::J},
        {sf::Keyboard::Key::K, InputKey::K},
        {sf::Keyboard::Key::L, InputKey::L},
        {sf::Keyboard::Key::M, InputKey::M},
        {sf::Keyboard::Key::N, InputKey::N},
        {sf::Keyboard::Key::O, InputKey::O},
        {sf::Keyboard::Key::P, InputKey::P},
        {sf::Keyboard::Key::Q, InputKey::Q},
        {sf::Keyboard::Key::R, InputKey::R},
        {sf::Keyboard::Key::S, InputKey::S},
        {sf::Keyboard::Key::T, InputKey::T},
        {sf::Keyboard::Key::U, InputKey::U},
        {sf::Keyboard::Key::V, InputKey::V},
        {sf::Keyboard::Key::W, InputKey::W},
        {sf::Keyboard::Key::X, InputKey::X},
        {sf::Keyboard::Key::Y, InputKey::Y},
        {sf::Keyboard::Key::Z, InputKey::Z},
        {sf::Keyboard::Key::F1, InputKey::F1},
        {sf::Keyboard::Key::F2, InputKey::F2},
        {sf::Keyboard::Key::F3, InputKey::F3},
        {sf::Keyboard::Key::F4, InputKey::F4},
        {sf::Keyboard::Key::F5, InputKey::F5},
        {sf::Keyboard::Key::F6, InputKey::F6},
        {sf::Keyboard::Key::F7, InputKey::F7},
        {sf::Keyboard::Key::F8, InputKey::F8},
        {sf::Keyboard::Key::F9, InputKey::F9},
        {sf::Keyboard::Key::F10, InputKey::F10},
        {sf::Keyboard::Key::F11, InputKey::F11},
        {sf::Keyboard::Key::F12, InputKey::F12},
        {sf::Keyboard::Key::Num0, InputKey::NUM0},
        {sf::Keyboard::Key::Num1, InputKey::NUM1},
        {sf::Keyboard::Key::Num2, InputKey::NUM2},
        {sf::Keyboard::Key::Num3, InputKey::NUM3},
        {sf::Keyboard::Key::Num4, InputKey::NUM4},
        {sf::Keyboard::Key::Num5, InputKey::NUM5},
        {sf::Keyboard::Key::Num6, InputKey::NUM6},
        {sf::Keyboard::Key::Num7, InputKey::NUM7},
        {sf::Keyboard::Key::Num8, InputKey::NUM8},
        {sf::Keyboard::Key::Num9, InputKey::NUM9},
        {sf::Keyboard::Key::Up, InputKey::UP},
        {sf::Keyboard::Key::Down, InputKey::DOWN},
        {sf::Keyboard::Key::Left, InputKey::LEFT},
        {sf::Keyboard::Key::Right, InputKey::RIGHT},
        {sf::Keyboard::Key::Space, InputKey::SPACE},
        {sf::Keyboard::Key::Tab, InputKey::TAB},
        {sf::Keyboard::Key::Return, InputKey::ENTER},
        {sf::Keyboard::Key::Escape, InputKey::ESCAPE},
        {sf::Keyboard::Key::BackSpace, InputKey::BACKSPACE},
        {sf::Keyboard::Key::Delete, InputKey::DELETE},
        {sf::Keyboard::Key::Unknown, InputKey::NONE},
    };

    static const std::unordered_map<sf::Mouse::Button, InputKey> Mousemap = {
        {sf::Mouse::Button::Left, InputKey::MOUSE_LEFT},
        {sf::Mouse::Button::Right, InputKey::MOUSE_RIGHT},
        {sf::Mouse::Button::Middle, InputKey::MOUSE_MIDDLE},
    };

    class KeyMapper {
        public:
            static InputKey getKey(sf::Keyboard::Key sfmlKey) {
                if (Keymap.find(sfmlKey) != Keymap.end())
                    return Keymap.at(sfmlKey);
                return InputKey::NONE;
            }

            static InputKey getKey(sf::Mouse::Button sfmlButton) {
                if (Mousemap.find(sfmlButton) != Mousemap.end())
                    return Mousemap.at(sfmlButton);
                return InputKey::NONE;
            }
    };
} // namespace arc
