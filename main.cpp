#include <SFML/Graphics.hpp>
#include "Form.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    Button btn("input");
    btn.setPosition(sf::Vector2f(30, 30));

    TextEdit edit;
    edit.setPosition(sf::Vector2f(30, 70));

    CheckBox check;
    check.setPosition(sf::Vector2f(30, 110));

    RadioButton radio(5);
    radio.setPosition(sf::Vector2f(30, 150));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            btn.process(event);
            edit.process(event);
            check.process(event);
            radio.process(event);
        }

        window.clear(sf::Color::White);
        btn.render(window);
        edit.render(window);
        check.render(window);
        radio.render(window);
        window.display();
    }

    return 0;
}
