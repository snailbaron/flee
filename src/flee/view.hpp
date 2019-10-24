#pragma once

#include "widget.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <type_traits>
#include <vector>

class View {
public:
    View();

    bool isAlive() const;
    void processInput();
    void draw();

    template <class T>
    T& addWidget()
    {
        static_assert(std::is_base_of<Widget, T>());

        _widgets.push_back(std::make_unique<T>());
        return *static_cast<T*>(_widgets.back().get());
    }

private:
    sf::RenderWindow _window;
    std::vector<std::unique_ptr<Widget>> _widgets;
};
