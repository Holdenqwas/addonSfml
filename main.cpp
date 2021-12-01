#include <SFML/Graphics.hpp>
#include "Form.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "Autoreload");

    Button btn("Старт");
    btn.setPosition(sf::Vector2f(600, 600));

    TextEdit edit;
    edit.setPosition(sf::Vector2f(30, 70));

    CheckBox check;
    check.setPosition(sf::Vector2f(30, 110));

    RadioButton radio(5);
    radio.setPosition(sf::Vector2f(30, 150));

    ListText list(200, 200, 5);
    list.setPosition(sf::Vector2f(30, 190));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            //btn.process(event);
            //edit.process(event);
            //check.process(event);
            //radio.process(event);
            list.process(event);
        }

        window.clear(sf::Color::White);
        //btn.render(window);
        //edit.render(window);
        //check.render(window);
        //radio.render(window);
        list.render(window);
        window.display();
    }

    return 0;
}
