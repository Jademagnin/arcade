/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** sfml
*/

#include "SFML.hpp"

arc::SFML::SFML()
{
    restartClock();
}

arc::SFML::~SFML()
{
    destroyWindow();
}

void arc::SFML::createWindow(int width, int height, const std::string &name)
{
    _window.create(sf::VideoMode(width * PIXEL_WIDTH, height * PIXEL_HEIGHT), name, sf::Style::Default);
    _window.setPosition(sf::Vector2i(0, 0));
}

void arc::SFML::createFullScreenWindow(const std::string &name)
{
    destroyWindow();
    _window.create(sf::VideoMode::getDesktopMode(), name, sf::Style::Fullscreen);
}

void arc::SFML::clearWindow(void)
{
    _window.clear();
}

void arc::SFML::displayWindow(void)
{
    _window.display();
}

void arc::SFML::destroyWindow(void)
{
    _window.close();
}

arc::ArcSize arc::SFML::getCurWindowSize(void)
{
    int width, height;

    if (!_window.isOpen()) {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        width = desktop.width / PIXEL_WIDTH;
        height = desktop.height / PIXEL_HEIGHT;
    } else {
        sf::Vector2u size = _window.getSize();
        width = size.x / PIXEL_WIDTH;
        height = size.y / PIXEL_HEIGHT;
    }

    return {width, height};
}

void arc::SFML::updateInput(void)
{
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            return addInput(CLOSE);
        if (event.type == sf::Event::Resized)
            _window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

        if (event.type == sf::Event::KeyPressed)
            addInput(KeyMapper::getKey(event.key.code));
        if (event.type == sf::Event::MouseButtonPressed) {
            addMouseClick(
                KeyMapper::getKey(event.mouseButton.button),
                {
                    event.mouseButton.x / PIXEL_WIDTH,
                    event.mouseButton.y / PIXEL_HEIGHT
                }
            );
        }
    }
}

void arc::SFML::draw(const Pixel& pixel, const Position& absPos)
{
    if (pixel.isInvisible())
        return;
    Position pos = {absPos.x * PIXEL_WIDTH, absPos.y * PIXEL_HEIGHT};
    PairColor pcolor = pixel.getPairColor();
    Color ctext = (!pixel.isReverse()) ? pcolor._text : pcolor._background;
    Color cback = (!pixel.isReverse()) ? pcolor._background : pcolor._text;
    sf::Text text;

    sf::Font font = getFont(pixel.getFontPath());
    text.setFont(font);
    text.setString(pixel.getChar());
    text.setCharacterSize(CHAR_SIZE);
    text.setFillColor(sf::Color(ctext.r, ctext.g, ctext.b, ctext.a));

    sf::RectangleShape rectangle(sf::Vector2f(PIXEL_WIDTH, PIXEL_WIDTH));
    rectangle.setPosition(pos.x, pos.y);
    rectangle.setFillColor(sf::Color(cback.r, cback.g, cback.b, cback.a));

    text.setOrigin(
        text.getLocalBounds().width / 2,
        text.getLocalBounds().height / 2
    );

    text.setPosition(
        pos.x + PIXEL_WIDTH / 2,
        pos.y + PIXEL_HEIGHT / 2 + HEIGHT_ADJUST
    );

    if (pixel.isUnderline())
        text.setStyle(sf::Text::Underlined);

    _window.draw(rectangle);
    _window.draw(text);
}

void arc::SFML::draw(const Text& text)
{
    Position pos = {text.getPosition().x * PIXEL_WIDTH, text.getPosition().y * PIXEL_HEIGHT};
    PairColor pcolor = text.getPairColor();
    Color ctext = pcolor._text;
    Color cback = pcolor._background;
    sf::Font font;
    sf::Text stext;

    font.loadFromFile(text.getFontPath());
    stext.setFont(font);
    stext.setString(text.getStr());
    stext.setCharacterSize(CHAR_SIZE);
    stext.setFillColor(sf::Color(ctext.r, ctext.g, ctext.b, ctext.a));

    sf::RectangleShape rectangle(sf::Vector2f(stext.getLocalBounds().width, PIXEL_HEIGHT));
    rectangle.setPosition(pos.x, pos.y);
    rectangle.setFillColor(sf::Color(cback.r, cback.g, cback.b, cback.a));

    stext.setOrigin(
        0,
        stext.getLocalBounds().height / 2
    );

    stext.setPosition(
        pos.x,
        pos.y + PIXEL_HEIGHT / 2 + HEIGHT_ADJUST
    );

    _window.draw(rectangle);
    _window.draw(stext);
}
