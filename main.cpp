#include <SFML/Graphics.hpp>
#include "Form.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    sf::Font font;
	font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");

    Button btn;
    btn.setString("Hello");
    btn.setColor(sf::Color::Blue);
    btn.setFont(font);
    btn.setPosition(sf::Vector2f(30, 30));
    //btn.setSize(20);
  
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            btn.process(event);

        }

        window.clear();
        btn.render(window);
        //window.draw(shape);
        window.display();
    }

    return 0;
}
