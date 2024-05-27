/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Input
*/

#pragma once

#include <queue>
#include <chrono>
#include <iostream>
#include "utils/attributes.hpp"

#define DOUBLE_CLICK_THRESHOLD 350

namespace arc
{
    /**
     * @enum InputKey
     * @brief Enum for all possible input keys.
     */
    enum InputKey {
        // Keyboard keys
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        UP, DOWN, LEFT, RIGHT, SPACE, TAB, ENTER, ESCAPE, BACKSPACE, DELETE,
        CLOSE,
        // Mouse clicks
        MOUSE_LEFT, MOUSE_RIGHT, MOUSE_MIDDLE,
        NONE
    };

    struct InputEvent {
        InputKey key;
        bool isMouseEvent;
        Position mousePos;
    };

    /**
     * @class Input
     * @brief Class for handling input.
     */
    class Input
    {
        public:
            /**
             * @brief Construct a new Input object.
             */
            Input();

            /**
             * @brief Destroy the Input object.
             */
            ~Input();

            /**
             * @brief Add a key to the input queue.
             * @param key - The key to add.
             */
            void addKey(const InputKey &key);

            /**
             * @brief Add a mouse click to the input queue.
             * @param key - The key to add.
             */
            void addMouseClick(const InputKey &key, const Position &mousePos);

            /**
             * @brief Get the front key from the input queue.
             * @return InputKey - The front key.
             */
            InputEvent getFrontKey(void) const;

            /**
             * @brief Get a key from the input queue.
             * @return InputKey - The key.
             */
            InputEvent getKey(void);

            /**
             * @brief Reset the input queue.
             */
            void reset(void);

        private:
            std::queue<InputEvent> _queueKey; ///< Queue of input keys.
    };
}
