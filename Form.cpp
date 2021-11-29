#include "Form.h"
#include <iostream>

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

// Botton end

// TextEdit

TextEdit::TextEdit(int wdth, int size,
                   sf::Color clr)
{
	sprite.setScale(wdth / 80);
    text.setCharacterSize(size);
    text.setFillColor(clr);
    c = clr;
    texture.loadFromFile("./resurses/TextEdit.png");
    sprite.setTexture(texture);
    font.loadFromFile(
        "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
    text.setFont(font);
}

void TextEdit::setString(sf::String str)
{
    text.setString(str);
}

void TextEdit::setWidth(int wdth)
{
	sprite.setScale(wdth / 80);
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

        sprite.setColor(flag ? sf::Color(0, 0, 0, 100) : sf::Color(255, 255, 255, 255));
    }

    if (ev.type == sf::Event::MouseButtonReleased)
    {
        write = sprite.getGlobalBounds()
                    .contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
    }

    if (write)
    {
        if (ev.type == sf::Event::TextEntered)
        {

            if (ev.text.unicode == '\b')
            {
                textInput.erase(textInput.getSize() - 1, 1);
                text.setString(textInput);
            }
            else if (ev.text.unicode < 128)
            {
				if (text.getLocalBounds().width < sprite.getLocaleBounds().width - 10)
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
}

char* clipboard()
{
	char* fromClipboard;//в эту переменную сохраним текст из буфера обмена
	if (OpenClipboard())//открываем буфер обмена
	{
		HANDLE hData = GetClipboardData(CF_TEXT);//извлекаем текст из буфера обмена
		char* chBuffer = (char*)GlobalLock(hData);//блокируем память
		fromClipboard = chBuffer;
		GlobalUnlock(hData);//разблокируем память
		CloseClipboard();//закрываем буфер обмена
	}
	return fromClipboard;
}