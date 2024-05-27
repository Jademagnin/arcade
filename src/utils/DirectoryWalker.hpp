/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** DirectoryWalker
*/

#pragma once

#include <vector>
#include <filesystem>
#include "modules/games/IGameModule.hpp"
#include "DLLoader.hpp"
#include <iostream>

namespace arc
{
    typedef std::filesystem::path path;

    class DirectoryWalker
    {
        public:
            DirectoryWalker() = default;
            DirectoryWalker(const path& directoryPath)
            {
                changeDirectory(directoryPath);
            }

            void changeDirectory(const path& directoryPath)
            {
                if (!std::filesystem::is_directory(directoryPath))
                    throw std::runtime_error(directoryPath.string() + " is not a directory");
                _directoryPath = directoryPath;
            }

            const std::vector<path> getFiles() const
            {
                std::vector<path> files;
                if (_directoryPath.empty())
                    throw std::runtime_error("Invalid or empty directory");
                for (const auto& entry : std::filesystem::directory_iterator(_directoryPath)) {
                    auto& path = entry.path();
                    files.push_back(path);
                }
                return files;
            }

            const std::vector<path> getFilesByExt(const std::string& ext) const
            {
                std::vector<path> files;
                if (_directoryPath.empty())
                    throw std::runtime_error("Invalid or empty directory");
                for (const auto& entry : std::filesystem::directory_iterator(_directoryPath)) {
                    auto& path = entry.path();
                    if (path.extension() == ext)
                        files.push_back(path);
                }
                return files;
            }

        private:
            path _directoryPath = ".";

    };
}
