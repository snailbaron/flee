#include "view.hpp"

View::View()
{
    _window.create(sf::VideoMode(1024, 768), "Flee!");
}

bool View::isAlive() const
{
    return _window.isOpen();
}

void View::processInput()
{
    auto event = sf::Event{};
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
    }
}

void View::draw()
{
    _window.clear(sf::Color{50, 50, 50});
    _window.display();
}
