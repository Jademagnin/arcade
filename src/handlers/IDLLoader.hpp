/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IDLLoader
*/

#pragma once

#include <string>
#include <filesystem>

#include "modules/core/core.hpp"

namespace arc
{
    /**
     * @class IDLLoader
     * @brief An interface for a DLL loader.
     * @tparam T The type of the instance to be loaded.
     */
    template <typename T>
    class IDLLoader
    {
        public:
            /**
             * @brief Destroy the IDLLoader object.
             */
            virtual ~IDLLoader() = 0;

            /**
             * @brief Get the type of the library.
             * @return arc::LibType The type of the library.
             */
            virtual arc::LibType getLibType(void) const = 0;

            /**
             * @brief Get an instance of the loaded library.
             * @return T The instance of the loaded library.
             */
            virtual T getInstance(void) const = 0;

            /**
             * @brief Open a library.
             * @param path The path to the library.
             * @return void* A pointer to the loaded library.
             */
            virtual void *open(const std::filesystem::path &path) = 0;

            /**
             * @brief Close the loaded library.
             */
            virtual void close(void) = 0;
    };

    template <typename T>
    IDLLoader<T>::~IDLLoader() {}
}