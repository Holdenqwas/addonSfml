#ifndef FORM
#define FORM

//
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Button
{
public:
    Button(std::string str = "", std::string fontPath= "C:\\Windows\\Fonts\\Arial.ttf", int size = 15,
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
    TextEdit(int wdth = 80, std::string fontPath = "C:\\Windows\\Fonts\\Arial.ttf",
            int size = 15, sf::Color clr = sf::Color::Black);
    void setString(sf::String str);
    void setWidth(int wdth);
    void setColor(sf::Color c);
    void setFont(sf::Font &fnt);
    void setPosition(sf::Vector2f pos);
    void setSize(int sz);
    std::string process(sf::Event ev);
    void render(sf::RenderWindow &wnd);

private:
    sf::String textInput = "";
    sf::Text text;
    sf::Font font;
    sf::Color c;
    sf::RectangleShape rect;
    sf::RectangleShape cursor;
    bool write = false;
};

class CheckBox
{
public:
    CheckBox();
    void setPosition(sf::Vector2f pos);
    bool process(sf::Event ev);
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
    int process(sf::Event ev);
    void render(sf::RenderWindow &wnd);

private:
    sf::CircleShape point;
    std::vector<sf::CircleShape *> vector;
    int state = 0;
    int count;
};

class Text
{
public:
    Text(std::string str = "", std::string fontPath = "C:\\Windows\\Fonts\\Arial.ttf",
        int size = 15, sf::Color clr = sf::Color::Black);
    void setPosition(sf::Vector2f pos);
    void render(sf::RenderWindow &wnd);

private:
    sf::String str;
    sf::Text text;
    sf::Font font;
};

class ListText
{
public:
    ListText(int hight, int width, int cnt);
    void setPosition(sf::Vector2f pos);
    void process(sf::Event ev);
    void render(sf::RenderWindow &wnd);

private:
    bool del = false;
    bool add = false;
    int count = 0;
    int curr = 0;
    std::string str;
    std::vector<std::string> arrStr;
    sf::RectangleShape rect;
    std::vector<Text *> vector;
    Button addButton = Button("Add", "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
    Button delButton = Button("Delete all", "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
    Button prevButton = Button("<<", "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
    Button nextButton = Button(">>", "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
};
#endif // !FORM