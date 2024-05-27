/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#pragma once

#include <dlfcn.h>
#include <stdexcept>
#include "IDLLoader.hpp"
#include <filesystem>

namespace arc
{
    typedef std::filesystem::path path;

    template <typename T>
    class DLLoader : public IDLLoader<T>
    {
        public:
            class DLLoaderError : public std::runtime_error
            {
            public:
                explicit DLLoaderError(const std::string &message) : std::runtime_error(message) {}
            };

            DLLoader() : _handler(nullptr) {}
            DLLoader(const path &path) : _handler(nullptr) { open(path); }
            ~DLLoader() { close(); }

            LibType getLibType(void) const
            {
                if (_handler == nullptr)
                    throw DLLoaderError("getLibType : No library loaded");
                LibType (*getLibType)(void) = (LibType (*)(void))dlsym(_handler, "getLibType");
                if (getLibType == NULL)
                    throw DLLoaderError(dlerror());
                if (getLibType() == LibType::UNKNOWN)
                    throw DLLoaderError("getLibType : Unknown library type");
                return getLibType();
            }

            std::string getName(void) const
            {
                if (_handler == nullptr)
                    throw DLLoaderError("getName : No library loaded");
                std::string (*getName)(void) = (std::string (*)(void))dlsym(_handler, "getName");
                if (getName == NULL)
                    throw DLLoaderError(dlerror());
                return getName();
            }

            T getInstance(void) const
            {
                if (_handler == nullptr)
                    throw DLLoaderError("getInstance : No library loaded");
                T (*entryPoint)(void) = (T (*)(void)) dlsym(_handler, "entryPoint");
                if (entryPoint == NULL)
                    throw DLLoaderError(dlerror());
                return entryPoint();
            }

            void *open(const path &path)
            {
                close();
                _handler = dlopen(path.c_str(), RTLD_LAZY);
                if (!_handler)
                    throw DLLoaderError(dlerror());
                return _handler;
            }

            void close(void)
            {
                if (_handler)
                    dlclose(_handler);
                _handler = nullptr;
            }

        private:
            void *_handler;
    };
}
