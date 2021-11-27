#ifndef FORM
#define FORM

#include <SFML/Graphics.hpp>

class Button {
public:
    Button();
    void setString(sf::String str);
    void setColor(sf::Color c);
    void setFont(sf::Font& fnt);
    void setPosition(sf::Vector2f pos);
    void setSize(int sz);
    bool process(sf::Event ev);
    void render(sf::RenderWindow& wnd);
private:
    sf::Text text;
    sf::Color c;
};
#endif // !FORM