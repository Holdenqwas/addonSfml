#include "Form.h"
#include <iostream>

sf::Color HOWER = sf::Color(0, 0, 0, 60);

// Button

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
    float width = text.getLocalBounds().width;
    if (width > 70)
    {
        sprite.setScale((width + 20) / 80, 1);
        text.setPosition(sf::Vector2f(pos.x + 10, pos.y + 2));
    }
    else
    {
        text.setPosition(sf::Vector2f(pos.x + ((80 - width) / 2), pos.y + 2));
    }
    sprite.setPosition(pos);
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

        sprite.setColor(flag ? HOWER : sf::Color(255, 255, 255, 255));
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

// TextEdit

TextEdit::TextEdit(int wdth, int size,
                   sf::Color clr)
{
    sprite.setScale(wdth / 80, 1);
    text.setCharacterSize(size);
    text.setFillColor(clr);
    c = clr;
    texture.loadFromFile("./resurses/TextEdit.png");
    sprite.setTexture(texture);
    font.loadFromFile(
        "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
    text.setFont(font);
    cursor = sf::RectangleShape(sf::Vector2f(2, 16));
    cursor.setFillColor(sf::Color::Black);
}

void TextEdit::setString(sf::String str)
{
    text.setString(str);
}

void TextEdit::setWidth(int wdth)
{
    sprite.setScale(wdth / 80, 1);
}

void TextEdit::setColor(sf::Color color)
{
    text.setFillColor(color);
    c = color;
}

void TextEdit::setFont(sf::Font &fnt)
{
    text.setFont(fnt);
}

void TextEdit::setPosition(sf::Vector2f pos)
{
    text.setPosition(sf::Vector2f(pos.x + 5, pos.y + 2));
    sprite.setPosition(pos);
}

void TextEdit::setSize(int sz)
{
    text.setCharacterSize(sz);
}

void TextEdit::process(sf::Event ev)
{
    if (ev.type == sf::Event::MouseMoved)
    {
        bool flag = sprite.getGlobalBounds()
                        .contains(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y));

        sprite.setColor(flag ? HOWER : sf::Color(255, 255, 255, 255));
    }

    if (ev.type == sf::Event::MouseButtonReleased)
    {
        write = sprite.getGlobalBounds()
                    .contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
    }

    if (write)
    {
        cursor.setPosition(text.getGlobalBounds().left + text.getLocalBounds().width + 3, sprite.getGlobalBounds().top + 4);
        // cursor.setPosition(200, 50);
        if (ev.type == sf::Event::KeyPressed)
        {
            if (ev.key.control && ev.key.code == sf::Keyboard::V)
                text.setString(sf::Clipboard::getString());
        }
        else if (ev.type == sf::Event::TextEntered)
        {
            if (ev.text.unicode == '\b')
            {
                if (text.getString().getSize())
                {
                    textInput.erase(textInput.getSize() - 1, 1);
                    text.setString(textInput);
                }
            }
            else // if (ev.text.unicode < 128)
            {
                if (text.getLocalBounds().width < sprite.getLocalBounds().width - 10)
                {
                    textInput += ev.text.unicode;
                    text.setString(textInput);
                }
            }
        }
    }
}

void TextEdit::render(sf::RenderWindow &wnd)
{
    wnd.draw(sprite);
    wnd.draw(text);
    if (write)
        wnd.draw(cursor);
}

// CheckBox

CheckBox::CheckBox()
{
    check.setPointCount(5);

    check.setPoint(0, sf::Vector2f(5, 5));
    check.setPoint(1, sf::Vector2f(10, 15));
    check.setPoint(2, sf::Vector2f(20, 0));
    check.setPoint(3, sf::Vector2f(19, 0));
    check.setPoint(4, sf::Vector2f(8, 10));

    check.setFillColor(sf::Color::Black);

    rect = sf::RectangleShape(sf::Vector2f(15, 15));
    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color(0, 0, 0, 80));
}

void CheckBox::setPosition(sf::Vector2f pos)
{
    check.setPosition(sf::Vector2f(pos.x - 4, pos.y - 2));
    rect.setPosition(pos);
}

void CheckBox::process(sf::Event ev)
{
    if (ev.type == sf::Event::MouseMoved)
    {
        bool flag = rect.getGlobalBounds()
                        .contains(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y));

        rect.setFillColor(flag ? HOWER : sf::Color(255, 255, 255, 255));
    }

    if (ev.type == sf::Event::MouseButtonReleased)
    {
        bool flag = rect.getGlobalBounds()
                        .contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
        if (flag)
            state = !state;
    }
}

void CheckBox::render(sf::RenderWindow &wnd)
{
    wnd.draw(rect);
    if (state)
        wnd.draw(check);
}

// RadioButton

RadioButton::RadioButton(int count) : count(count)
{
    for (int i = 0; i < count; i++)
    {
        vector.push_back(new sf::CircleShape);
        vector[i]->setRadius(7);
        vector[i]->setFillColor(sf::Color::White);
        vector[i]->setOutlineThickness(2);
        vector[i]->setOutlineColor(sf::Color(0, 0, 0, 80));
    }
    point = sf::CircleShape(5);
    point.setFillColor(sf::Color::Black);
}

RadioButton::~RadioButton()
{
    for (int i = 0; i < count; i++)
    {
        delete vector[i];
    }
}
void RadioButton::setPosition(sf::Vector2f pos)
{
    for (int i = 0; i < count; i++)
    {
        vector[i]->setPosition(sf::Vector2f(pos.x, pos.y + i * 30));
    }
    point.setPosition(sf::Vector2f(pos.x + 2, pos.y + 2));
}

void RadioButton::process(sf::Event ev)
{
    if (ev.type == sf::Event::MouseMoved)
    {
        for (int i = 0; i < count; i++)
        {
            if (vector[i]->getGlobalBounds().contains(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y)))
            {
                vector[i]->setFillColor(HOWER);
                break;
            }
            else
            {
                vector[i]->setFillColor(sf::Color::White);
            }
        }
    }

    if (ev.type == sf::Event::MouseButtonReleased)
    {
        for (int i = 0; i < count; i++)
        {
            if (vector[i]->getGlobalBounds().contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y)))
            {
                state = i;
                point.setPosition(sf::Vector2f(vector[i]->getPosition().x + 2, vector[i]->getPosition().y + 2));
                break;
            }
        }
    }
}

void RadioButton::render(sf::RenderWindow &wnd)
{

    for (int i = 0; i < count; i++)
    {
        wnd.draw(*vector[i]);
    }
    wnd.draw(point);
}