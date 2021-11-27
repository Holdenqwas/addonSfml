#include "Form.h"

Button::Button() {

}

void Button::setString(sf::String str) {
    text.setString(str);
}

void Button::setColor(sf::Color c) {
    text.setFillColor(c);
    this->c;
}

void Button::setFont(sf::Font& fnt) {
    text.setFont(fnt);
}

void Button::setPosition(sf::Vector2f pos) {
    text.setPosition(pos);
}

void Button::setSize(int sz) {
    text.setCharacterSize(sz);
}

bool Button::process(sf::Event ev) {
    if (ev.type == sf::Event::MouseMoved) {
        bool flag = text.getGlobalBounds().contains(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y));
        text.setFillColor(flag ? sf::Color::Yellow : c);
        return false;
    }

    if (ev.type == sf::Event::MouseButtonReleased) {
        bool flag = text.getGlobalBounds().contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
        return flag;
    }

    return false;
}

void Button::render(sf::RenderWindow& wnd) {
    wnd.draw(text);
}