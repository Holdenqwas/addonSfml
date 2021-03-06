#include "Form.h"
#include <iostream>

sf::Color HOWER = sf::Color(0, 0, 0, 60);

// Button

Button::Button(std::string str, std::string fontPath, int size, sf::Color clr)
{
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(clr);
	c = clr;
	rect = sf::RectangleShape(sf::Vector2f(80, 25));
	rect.setFillColor(sf::Color::White);
	rect.setOutlineThickness(1);
	rect.setOutlineColor(HOWER);
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(clr);
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

void Button::setFont(sf::Font& fnt)
{
	text.setFont(fnt);
}

void Button::setPosition(sf::Vector2f pos)
{
	float width = text.getLocalBounds().width;
	if (width > 70)
	{
		rect.setScale((width + 20) / 80, 1);
		text.setPosition(sf::Vector2f(pos.x + 10, pos.y + 2));
	}
	else
	{
		text.setPosition(sf::Vector2f(pos.x + ((80 - width) / 2), pos.y + 2));
	}
	rect.setPosition(pos);
}

void Button::setSize(int sz)
{
	text.setCharacterSize(sz);
}

bool Button::process(sf::Event ev)
{
	if (ev.type == sf::Event::MouseMoved)
	{
		bool flag = rect.getGlobalBounds()
			.contains(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y));

		rect.setFillColor(flag ? HOWER : sf::Color(255, 255, 255, 255));
		return false;
	}

	if (ev.type == sf::Event::MouseButtonReleased)
	{
		bool flag = rect.getGlobalBounds()
			.contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
		return flag;
	}

	return false;
}

void Button::render(sf::RenderWindow& wnd)
{
	wnd.draw(rect);
	wnd.draw(text);
}

// TextEdit

TextEdit::TextEdit(int wdth, std::string fontPath, int size,
	sf::Color clr)
{
	rect = sf::RectangleShape(sf::Vector2f(wdth, 25));
	rect.setFillColor(sf::Color::White);
	rect.setOutlineThickness(1);
	rect.setOutlineColor(HOWER);
	text.setCharacterSize(size);
	text.setFillColor(clr);
	c = clr;
	font.loadFromFile(fontPath);
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
	rect.setSize(sf::Vector2f(wdth, 25));
}

void TextEdit::setColor(sf::Color color)
{
	text.setFillColor(color);
	c = color;
}

void TextEdit::setFont(sf::Font& fnt)
{
	text.setFont(fnt);
}

void TextEdit::setPosition(sf::Vector2f pos)
{
	text.setPosition(sf::Vector2f(pos.x + 5, pos.y + 2));
	rect.setPosition(pos);
}

void TextEdit::setSize(int sz)
{
	text.setCharacterSize(sz);
}

sf::String TextEdit::process(sf::Event ev)
{
	if (ev.type == sf::Event::MouseMoved)
	{
		bool flag = rect.getGlobalBounds()
			.contains(sf::Vector2f(ev.mouseMove.x, ev.mouseMove.y));

		rect.setFillColor(flag ? HOWER : sf::Color(255, 255, 255, 255));
	}

	if (ev.type == sf::Event::MouseButtonReleased)
	{
		write = rect.getGlobalBounds()
			.contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
	}

	if (write)
	{
		cursor.setPosition(text.getGlobalBounds().left + text.getLocalBounds().width + 3, rect.getGlobalBounds().top + 4);
		// cursor.setPosition(200, 50);
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.control && ev.key.code == sf::Keyboard::V)
			{
				//std::cout << sf::Clipboard::getString().toAnsiString() << std::endl;
				text.setString(sf::Clipboard::getString());
			}
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
				if (text.getLocalBounds().width < rect.getLocalBounds().width - 10)
				{
					textInput += ev.text.unicode;
					text.setString(textInput);
				}
			}
		}
	}
	return text.getString();
}

void TextEdit::render(sf::RenderWindow& wnd)
{
	wnd.draw(rect);
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

bool CheckBox::process(sf::Event ev)
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
	return state;
}

void CheckBox::render(sf::RenderWindow& wnd)
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

int RadioButton::process(sf::Event ev)
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
	return state;
}

void RadioButton::render(sf::RenderWindow& wnd)
{

	for (int i = 0; i < count; i++)
	{
		wnd.draw(*vector[i]);
	}
	wnd.draw(point);
}

// Text

Text::Text(std::string str, std::string fontPath, int size, sf::Color clr)
{
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(clr);
	font.loadFromFile(fontPath);
	text.setFont(font);
}

void Text::setPosition(sf::Vector2f pos)
{
	text.setPosition(pos);
}

void Text::render(sf::RenderWindow& wnd)
{
	wnd.draw(text);
}

// ListText

ListText::ListText(int hight, int width, int cnt)
{
	rect = sf::RectangleShape(sf::Vector2f(hight, width));
	rect.setFillColor(sf::Color::White);
	rect.setOutlineColor(HOWER);
	rect.setOutlineThickness(1);
	count = cnt;
}

void ListText::setPosition(sf::Vector2f pos)
{
	rect.setPosition(pos);
	prevButton.setPosition(sf::Vector2f(pos.x, pos.y + rect.getLocalBounds().height + 10));
	nextButton.setPosition(sf::Vector2f(pos.x + 90, pos.y + rect.getLocalBounds().height + 10));
	addButton.setPosition(sf::Vector2f(pos.x, pos.y + rect.getLocalBounds().height + 40));
	delButton.setPosition(sf::Vector2f(pos.x + 90, pos.y + rect.getLocalBounds().height + 40));
}

std::vector<std::string> ListText::process(sf::Event ev)
{
	if (addButton.process(ev))
	{
		add = true;
	}
	if (delButton.process(ev))
	{
		del = true;
	}
	if (prevButton.process(ev) && curr > 0)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			delete vector[i];
		}
		vector.clear();

		for (size_t i = --curr; vector.size() < count && curr >= 0; i--, curr--)
		{
			vector.insert(vector.begin(), new Text(arrStr[i], "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf"));
		}
		for (size_t i = 0; i < vector.size(); i++)
		{
			vector[i]->setPosition(sf::Vector2f(rect.getGlobalBounds().left + 10, rect.getGlobalBounds().top + i * 25 + 5));
		}
	}
	if (nextButton.process(ev) && curr < arrStr.size())
	{
		for (int i = 0; i < vector.size(); i++)
		{
			delete vector[i];
		}
		vector.clear();

		for (size_t i = 0; i < count && curr < arrStr.size(); i++, curr++)
		{
			vector.push_back(new Text(arrStr[curr], "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf"));
		}
		for (size_t i = 0; i < vector.size(); i++)
		{
			vector[i]->setPosition(sf::Vector2f(rect.getGlobalBounds().left + 10, rect.getGlobalBounds().top + i * 25 + 5));
		}
	}
	if (add && ev.key.control && ev.key.code == sf::Keyboard::V)
	{
		str = sf::Clipboard::getString();
		size_t pos = 0;
		std::string delimiter = "\n";
		std::string token;
		while ((pos = str.find(delimiter)) != std::string::npos)
		{
			token = str.substr(0, pos);
			arrStr.push_back(token);
			str.erase(0, pos + delimiter.length());
		}

		for (size_t i = 0; i < count && curr < arrStr.size(); i++, curr++)
		{
			vector.push_back(new Text(arrStr[curr], "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf"));
		}

		for (int i = 0; i < vector.size(); i++)
		{
			vector[i]->setPosition(sf::Vector2f(rect.getGlobalBounds().left + 10, rect.getGlobalBounds().top + i * 25 + 5));
		}
		curr = count;
		add = false;
	}
	if (del)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			delete vector[i];
		}
		vector.clear();
		arrStr.clear();
		curr = 0;
		str = "";
		del = false;
	}
	return arrStr;
}

void ListText::render(sf::RenderWindow& wnd)
{
	wnd.draw(rect);
	for (int i = 0; i < vector.size(); i++)
	{
		vector[i]->render(wnd);
	}
	prevButton.render(wnd);
	nextButton.render(wnd);
	addButton.render(wnd);
	delButton.render(wnd);
}

std::string GetClipboardText()
{
  // Try opening the clipboard
  if (! OpenClipboard(nullptr))
    ... // error

  // Get handle of clipboard object for ANSI text
  HANDLE hData = GetClipboardData(CF_TEXT);
  if (hData == nullptr)
    ... // error

  // Lock the handle to get the actual text pointer
  char * pszText = static_cast<char*>( GlobalLock(hData) );
  if (pszText == nullptr)
    ... // error

  // Save text in a string class instance
  std::string text( pszText );

  // Release the lock
  GlobalUnlock( hData );

  // Release the clipboard
  CloseClipboard();

  return text;
}