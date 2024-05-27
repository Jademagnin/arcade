/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Keymap
*/

#pragma once

#include "SDL2.hpp"
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
    static const std::unordered_map<SDL_Keycode, InputKey> Keymap = {
        {SDLK_a, InputKey::A},
        {SDLK_b, InputKey::B},
        {SDLK_c, InputKey::C},
        {SDLK_d, InputKey::D},
        {SDLK_e, InputKey::E},
        {SDLK_f, InputKey::F},
        {SDLK_g, InputKey::G},
        {SDLK_h, InputKey::H},
        {SDLK_i, InputKey::I},
        {SDLK_j, InputKey::J},
        {SDLK_k, InputKey::K},
        {SDLK_l, InputKey::L},
        {SDLK_m, InputKey::M},
        {SDLK_n, InputKey::N},
        {SDLK_o, InputKey::O},
        {SDLK_p, InputKey::P},
        {SDLK_q, InputKey::Q},
        {SDLK_r, InputKey::R},
        {SDLK_s, InputKey::S},
        {SDLK_t, InputKey::T},
        {SDLK_u, InputKey::U},
        {SDLK_v, InputKey::V},
        {SDLK_w, InputKey::W},
        {SDLK_x, InputKey::X},
        {SDLK_y, InputKey::Y},
        {SDLK_z, InputKey::Z},
        {SDLK_0, InputKey::NUM0},
        {SDLK_1, InputKey::NUM1},
        {SDLK_2, InputKey::NUM2},
        {SDLK_3, InputKey::NUM3},
        {SDLK_4, InputKey::NUM4},
        {SDLK_5, InputKey::NUM5},
        {SDLK_6, InputKey::NUM6},
        {SDLK_7, InputKey::NUM7},
        {SDLK_8, InputKey::NUM8},
        {SDLK_9, InputKey::NUM9},
        {SDLK_F1, InputKey::F1},
        {SDLK_F2, InputKey::F2},
        {SDLK_F3, InputKey::F3},
        {SDLK_F4, InputKey::F4},
        {SDLK_F5, InputKey::F5},
        {SDLK_F6, InputKey::F6},
        {SDLK_F7, InputKey::F7},
        {SDLK_F8, InputKey::F8},
        {SDLK_F9, InputKey::F9},
        {SDLK_F10, InputKey::F10},
        {SDLK_F11, InputKey::F11},
        {SDLK_F12, InputKey::F12},
        {SDLK_UP, InputKey::UP},
        {SDLK_DOWN, InputKey::DOWN},
        {SDLK_LEFT, InputKey::LEFT},
        {SDLK_RIGHT, InputKey::RIGHT},
        {SDLK_SPACE, InputKey::SPACE},
        {SDLK_TAB, InputKey::TAB},
        {SDLK_RETURN, InputKey::ENTER},
        {SDLK_ESCAPE, InputKey::ESCAPE},
        {SDLK_BACKSPACE, InputKey::BACKSPACE},
        {SDLK_DELETE, InputKey::DELETE},
        {SDLK_UNKNOWN, InputKey::NONE}
    };

    static const std::unordered_map<Uint8, InputKey> Mousemap = {
        {SDL_BUTTON_LEFT, InputKey::MOUSE_LEFT},
        {SDL_BUTTON_MIDDLE, InputKey::MOUSE_MIDDLE},
        {SDL_BUTTON_RIGHT, InputKey::MOUSE_RIGHT}
    };

    class KeyMapper {
        public:
            static InputKey getKey(SDL_Keycode sdlKey) {
                if (Keymap.find(sdlKey) != Keymap.end())
                    return Keymap.at(sdlKey);
                return InputKey::NONE;
            }

            static InputKey getKey(Uint8 sdlButton) {
                if (Mousemap.find(sdlButton) != Mousemap.end())
                    return Mousemap.at(sdlButton);
                return InputKey::NONE;
            }
    };
} // namespace arc
