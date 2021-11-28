#include <SFML/Graphics.hpp>
#include "Form.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    Button btn("input");
    btn.setPosition(sf::Vector2f(30, 30));

    TextEdit edit;
    edit.setPosition(sf::Vector2f(130, 30));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            btn.process(event);
            edit.process(event);

        }

        window.clear(sf::Color::White);
        btn.render(window);
        edit.render(window);
        //window.draw(shape);
        window.display();
    }

    return 0;
}
