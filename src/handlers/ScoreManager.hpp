/*
** EPITECH PROJECT, 2024
** arcade_copy
** File description:
** ScoreManager
*/

#ifndef SCOREMANAGER_HPP_
#define SCOREMANAGER_HPP_

#define SCORE_PATH "./config/score.cfg"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

struct Score {
    std::string player;
    int score;
};

class ScoreManager {
    public:
        static ScoreManager& getInstance() {
            static ScoreManager instance;
            return instance;
        }

        ScoreManager(ScoreManager const&) = delete;
        void operator=(ScoreManager const&) = delete;

        void setUsername(const std::string& username) {
            _username = username;
        }

        std::string getUsername() {
            return _username;
        }

        int getScore(const std::string& game) {
            // ensure the player has a score for the game
            if (_scores[game].find(_username) == _scores[game].end())
                _scores[game][_username] = 0;
            return _scores[game][_username];
        }

        void setScore(const std::string& game, int score) {
            if (_scores[game][_username] < score)
                _scores[game][_username] = score;
        }

        void saveScore() {
            std::ofstream file(SCORE_PATH);
            for (const auto &game : _scores) {
                file << "[" << game.first << "]\n";
                for (const auto &player : game.second) {
                    file << player.first << "=" << player.second << "\n";
                }
            }
            file.close();
        }

        Score getHighScore(const std::string& game)
        {
            Score highScore;
            highScore.score = 0;
            for (const auto &player : _scores[game]) {
                if (player.second > highScore.score) {
                    highScore.player = player.first;
                    highScore.score = player.second;
                }
            }

            return highScore;
        }

        Score getHighScore(void)
        {
            Score highScore;
            highScore.score = 0;
            for (const auto &game : _scores) {
                for (const auto &player : game.second) {
                    if (player.second > highScore.score) {
                        highScore.player = player.first;
                        highScore.score = player.second;
                    }
                }
            }

            return highScore;
        }

        void loadFile() {
            std::ifstream file(SCORE_PATH);
            std::string line, game;
            while (std::getline(file, line)) {
                if (line[0] == '[') {
                    game = line.substr(1, line.size() - 2);
                } else {
                    std::istringstream is_line(line);
                    std::string key;
                    if (std::getline(is_line, key, '=')) {
                        std::string value;
                        if (std::getline(is_line, value)) {
                            _scores[game][key] = std::stoi(value);
                        }
                    }
                }
            }
            file.close();
        }

        void reloadFile() {
            _scores.clear();
            loadFile();
        }

    protected:
    private:
        ScoreManager() {
            loadFile();
        }

        ~ScoreManager() {
            saveScore();
        }

        std::map<std::string, std::map<std::string, int>> _scores;
        std::string _username = "Player";
};

#endif /* !SCOREMANAGER_HPP_ */
