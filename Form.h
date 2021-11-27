#ifndef FORM
#define FORM

#include <SFML/Graphics.hpp>
#include <string>

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

#endif // !FORM