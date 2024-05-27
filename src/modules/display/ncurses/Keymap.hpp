/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Keymap
*/

#pragma once

#include "NCurses.hpp"
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
    static const std::unordered_map<int, InputKey> Keymap = {
        {'A', InputKey::A},
        {'B', InputKey::B},
        {'C', InputKey::C},
        {'D', InputKey::D},
        {'E', InputKey::E},
        {'F', InputKey::F},
        {'G', InputKey::G},
        {'H', InputKey::H},
        {'I', InputKey::I},
        {'J', InputKey::J},
        {'K', InputKey::K},
        {'L', InputKey::L},
        {'M', InputKey::M},
        {'N', InputKey::N},
        {'O', InputKey::O},
        {'P', InputKey::P},
        {'Q', InputKey::Q},
        {'R', InputKey::R},
        {'S', InputKey::S},
        {'T', InputKey::T},
        {'U', InputKey::U},
        {'V', InputKey::V},
        {'W', InputKey::W},
        {'X', InputKey::X},
        {'Y', InputKey::Y},
        {'Z', InputKey::Z},
        {'0', InputKey::NUM0},
        {'1', InputKey::NUM1},
        {'2', InputKey::NUM2},
        {'3', InputKey::NUM3},
        {'4', InputKey::NUM4},
        {'5', InputKey::NUM5},
        {'6', InputKey::NUM6},
        {'7', InputKey::NUM7},
        {'8', InputKey::NUM8},
        {'9', InputKey::NUM9},
        {KEY_F(1), InputKey::F1},
        {KEY_F(2), InputKey::F2},
        {KEY_F(3), InputKey::F3},
        {KEY_F(4), InputKey::F4},
        {KEY_F(5), InputKey::F5},
        {KEY_F(6), InputKey::F6},
        {KEY_F(7), InputKey::F7},
        {KEY_F(8), InputKey::F8},
        {KEY_F(9), InputKey::F9},
        {KEY_F(10), InputKey::F10},
        {KEY_F(11), InputKey::F11},
        {KEY_F(12), InputKey::F12},
        {KEY_UP, InputKey::UP},
        {KEY_DOWN, InputKey::DOWN},
        {KEY_LEFT, InputKey::LEFT},
        {KEY_RIGHT, InputKey::RIGHT},
        {' ', InputKey::SPACE},
        {9, InputKey::TAB},
        {10, InputKey::ENTER},
        {27, InputKey::ESCAPE},
        {8, InputKey::BACKSPACE},
        {46, InputKey::DELETE},
    };

    static const std::unordered_map<int, InputKey> MouseKeymap = {
        {BUTTON1_CLICKED, InputKey::MOUSE_LEFT},
        {BUTTON2_CLICKED, InputKey::MOUSE_MIDDLE},
        {BUTTON3_CLICKED, InputKey::MOUSE_RIGHT},
    };

    class KeyMapper {
        public:
            static InputKey getKey(int key) {
                if (Keymap.find(key) != Keymap.end())
                    return Keymap.at(key);
                return InputKey::NONE;
            }

            static InputKey getMouseKey(mmask_t key) {
                for (auto &it : MouseKeymap) {
                    if (key & it.first)
                        return it.second;
                }
                return InputKey::NONE;
            }
    };
} // namespace arc
