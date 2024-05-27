/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** sfml
*/

#include "SDL2.hpp"

arc::SDL2::SDL2()
{
    SDL_Init(SDL_INIT_VIDEO);
    restartClock();
    if (TTF_Init() == -1) {
        std::cerr << "Error: " << TTF_GetError() << std::endl;
        return;
    }
}

arc::SDL2::~SDL2()
{
    SDL_Quit();
    // destroy fonts
    for (auto &font : _fonts)
        TTF_CloseFont(font.second);
    TTF_Quit();

    destroyWindow();
}

void arc::SDL2::createWindow(int width, int height, const std::string &name)
{
    destroyWindow();
    _window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width * PIXEL_WIDTH, height * PIXEL_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

void arc::SDL2::createFullScreenWindow(const std::string &name)
{
    SDL_DisplayMode dm;
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
    destroyWindow();
    _window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dm.w, dm.h, SDL_WINDOW_FULLSCREEN_DESKTOP);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

void arc::SDL2::clearWindow(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void arc::SDL2::displayWindow(void)
{
    SDL_RenderPresent(_renderer);
}

void arc::SDL2::destroyWindow(void)
{
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_window)
        SDL_DestroyWindow(_window);
    _window = nullptr;
    _renderer = nullptr;
}

arc::ArcSize arc::SDL2::getCurWindowSize(void)
{
    SDL_DisplayMode dm;
    int width, height;

    if (_window == nullptr) {
        if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
            SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        width = dm.w / PIXEL_WIDTH;
        height = dm.h / PIXEL_HEIGHT;
    } else {
        SDL_GetWindowSize(_window, &width, &height);
        width /= PIXEL_WIDTH;
        height /= PIXEL_HEIGHT;
    }

    return {width, height};
}

void arc::SDL2::updateInput(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT)
            return addInput(InputKey::CLOSE);
        if (event.type == SDL_KEYDOWN)
            addInput(KeyMapper::getKey(event.key.keysym.sym));
        // on click event
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            // std::cout << "Double click: " << event.button.clicks << std::endl;
            int x, y;
            SDL_GetMouseState(&x, &y);
            addMouseClick(
                KeyMapper::getKey(event.button.button),
                {
                    x / PIXEL_WIDTH,
                    y / PIXEL_HEIGHT
                }
            );
        }
    }
}

void arc::SDL2::draw(const Pixel &pixel, const Position &absPos)
{
    if (pixel.isInvisible())
        return;

    Position pos = {absPos.x * PIXEL_WIDTH, absPos.y * PIXEL_HEIGHT};
    PairColor pcolor = pixel.getPairColor();
    // Color ctext = pcolor._text;
    Color ctext = (!pixel.isReverse()) ? pcolor._text : pcolor._background; // Reverse the colors if needed
    Color cback = (!pixel.isReverse()) ? pcolor._background : pcolor._text; // Reverse the colors if needed
    SDL_Rect rect = {pos.x, pos.y, PIXEL_WIDTH, PIXEL_HEIGHT};

    // Init font
    TTF_Font *font = getFont(pixel.getFontPath());
    SDL_Surface *surface = TTF_RenderText_Solid(font, pixel.str().c_str(),
                            {ctext.r, ctext.g, ctext.b, ctext.a});
    if (!surface) {
        throw std::runtime_error("SDL-Error loading surface: " + std::string(TTF_GetError()));
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (!texture) {
        throw std::runtime_error("SDL-Error loading texture: " + std::string(SDL_GetError()));
    }

    // Adjust the position of the text rectangle to set the origin to the center
    SDL_Rect textRect = {
        pos.x + PIXEL_WIDTH / 2 - surface->w / 2,
        (pos.y + PIXEL_HEIGHT / 2 - surface->h / 2) + (CHAR_SIZE / 10),
        surface->w,
        surface->h
    };

    // Draw
    if (cback.a != 0) { // Only draw background if it's not transparent
        SDL_SetRenderDrawColor(_renderer, cback.r, cback.g, cback.b, cback.a);
        SDL_RenderFillRect(_renderer, &rect);
    }
    SDL_RenderCopy(_renderer, texture, NULL, &textRect);

    // Free memory
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
