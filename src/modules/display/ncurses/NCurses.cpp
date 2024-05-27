/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** Ncurses
*/

#include "NCurses.hpp"

arc::NCurses::NCurses()
{
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    restartClock();
    _hasColor = has_colors();
    if (!_hasColor)
        return;
    start_color();
    _ncolor.setMax(COLORS);
    _npaircolor.setMax(COLOR_PAIRS);
    _canChangeColor = can_change_color();
}

arc::NCurses::~NCurses()
{
    destroyWindow();
    endwin();
}

void arc::NCurses::createWindow(int width, int height, const std::string &name)
{
    (void)name;
    width*=2;
    _window = newwin(height, width, 0, 0);
    _windowSize = {width, height};

    keypad(_window, TRUE);
    nodelay(_window, TRUE);
    wresize(_window, LINES, COLS);
}

void arc::NCurses::createFullScreenWindow(const std::string &name)
{
    _isFullScreen = true;
    createWindow(COLS, LINES, name);
    wresize(_window, LINES, COLS);
}

void arc::NCurses::clearWindow(void)
{
    werase(_window);
}

void arc::NCurses::displayWindow(void)
{
    wrefresh(_window);
}

void arc::NCurses::destroyWindow(void)
{
    if (_window == nullptr)
        return;
    delwin(_window);
    endwin();
    _window = nullptr;
}

arc::ArcSize arc::NCurses::getCurWindowSize(void)
{
    int width, height;
    if (_window == nullptr || _isFullScreen)
        return {COLS, LINES};

    getmaxyx(_window, height, width);

    return {
        std::min(width, _windowSize.width),
        std::min(height, _windowSize.height)
    };
}

void arc::NCurses::updateInput(void)
{
    int ch = wgetch(_window);
    if (ch == ERR)
        return;

    // handle mouse input
    if (ch == KEY_MOUSE) {
        MEVENT event;
        if (getmouse(&event) == OK) {
            addMouseClick(
                KeyMapper::getMouseKey(event.bstate),
                {
                    event.x,
                    event.y
                }
            );
        }
        return;
    }

    addInput(KeyMapper::getKey(ch));
}

void arc::NCurses::draw(const Pixel &pixel, const Position &pos)
{
    PairColor pcolor = pixel.getPairColor();

    initPair(pcolor);

    initAllAttributes(pcolor, pixel.getConfig());
    wattron(_window, COLOR_PAIR(_npaircolor.findPairColor(pcolor))); // Set color
    mvwaddch(_window, pos.y, pos.x, pixel.getChar());
    wattroff(_window, COLOR_PAIR(_npaircolor.findPairColor(pcolor))); // Turn off color
}

void arc::NCurses::initColor(Color color)
{
    if (!_hasColor || !_canChangeColor || _ncolor.findColor(color) != 0)
        return;
    if (init_color(_ncolor.addColor(color), NCOLOR(color.r), NCOLOR(color.g), NCOLOR(color.b)))
        throw std::runtime_error("Error: init_color failed");
}

void arc::NCurses::initPair(PairColor pairColor)
{
    Color text = pairColor._text;
    Color background = pairColor._background;

    if (!_hasColor || _npaircolor.findPairColor(pairColor) != 0)
        return;
    initColor(text);
    initColor(background);
    if (init_pair(_npaircolor.addColor(pairColor), _ncolor.findColor(text), _ncolor.findColor(background)))
        throw std::runtime_error("Error: init_pair failed");
}

void arc::NCurses::initAttributes(TextConf conf)
{
    if (conf.bold)
        wattron(_window, A_BOLD);
    if (conf.underline)
        wattron(_window, A_UNDERLINE);
    if (conf.invisible)
        wattron(_window, A_INVIS);
    if (conf.reverse)
        wattron(_window, A_REVERSE);
}

void arc::NCurses::initAllAttributes(PairColor pairColor, TextConf conf)
{
    wattrset(_window, A_NORMAL | COLOR_PAIR(0));
    initPair(pairColor);
    wattron(_window, COLOR_PAIR(_npaircolor.findPairColor(pairColor)));
    initAttributes(conf);
}
