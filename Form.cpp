#include "Form.h"
#include <iostream>

Button::Button(std::string str, int size, sf::Color clr)
{
    
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(clr);
    c = clr;
    texture.loadFromFile("./resurses/button.png");
    sprite.setTexture(texture);
	font.loadFromFile(
        "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
    text.setFont(font);
    //std::cout << text.getColor().toInteger() << std::endl;
}

void Button::setString(sf::String str)
{
    text.setString(str);
}

void Button::setColor(sf::Color color)
{
    text.setFillColor(color);
    c = color;
}

void Button::setFont(sf::Font &fnt)
{
    text.setFont(fnt);
}

void Button::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
    text.setPosition(sf::Vector2f(pos.x + 15, pos.y + 2));
}

void Button::setSize(int sz)
{
    text.setCharacterSize(sz);
}

bool Button::process(sf::Event ev)
{
    if (ev.type == sf::Event::MouseMoved)
    {
        bool flag = sprite.getGlobalBounds()
            .contains(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y));
        
        sprite.setColor(flag ? sf::Color(0, 0, 0, 100) : sf::Color(255, 255, 255, 255));
        return false;
    }

    if (ev.type == sf::Event::MouseButtonReleased)
    {
        bool flag = sprite.getGlobalBounds()
            .contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
        return flag;
    }

    return false;
}

void Button::render(sf::RenderWindow &wnd)
{
    wnd.draw(sprite);
    wnd.draw(text);
}