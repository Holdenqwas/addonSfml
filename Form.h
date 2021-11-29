#ifndef FORM
#define FORM

//
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


class Button
{
public:
    Button(std::string str = "", int size = 15, 
            sf::Color clr = sf::Color::Black);
    void setString(sf::String str);
    void setColor(sf::Color c);
    void setFont(sf::Font &fnt);
    void setPosition(sf::Vector2f pos);
    void setSize(int sz);
    bool process(sf::Event ev);
    void render(sf::RenderWindow &wnd);

private:
    sf::Text text;
    sf::Font font; 
    sf::Color c;
    sf::Texture texture;
    sf::Sprite sprite;
};

class TextEdit
{
public:
    TextEdit(int wdth = 80, int size = 15, 
            sf::Color clr = sf::Color::Black);
    void setString(sf::String str);
    void setWidth(int wdth);
    void setColor(sf::Color c);
    void setFont(sf::Font &fnt);
    void setPosition(sf::Vector2f pos);
    void setSize(int sz);
    void process(sf::Event ev);
    void render(sf::RenderWindow &wnd);

private:
    sf::String textInput = "";
    sf::Text text;
    sf::Font font; 
    sf::Color c;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape cursor;
    bool write = false;
};

class CheckBox
{
public:
    CheckBox();
    void setPosition(sf::Vector2f pos);
    void process(sf::Event ev);
    void render(sf::RenderWindow &wnd);

private:
    sf::ConvexShape check;
    sf::RectangleShape rect;
    bool state = false;
};

class RadioButton
{
public:
    RadioButton(int count = 2);
    ~RadioButton();
    void setPosition(sf::Vector2f pos);
    void process(sf::Event ev);
    void render(sf::RenderWindow &wnd);

private:
    sf::CircleShape point;
    std::vector<sf::CircleShape*> vector;
    int state = 0;
    int count;
};
#endif // !FORM