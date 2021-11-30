/*
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
*/

#include <iostream>
#include <SFML/Graphics.hpp>

const int BOARD_SIZE = 40;
const float TILE_SIZE = 20.0f;

std::vector<std::unique_ptr<sf::Drawable>> projectsDrawables;
std::vector<std::unique_ptr<sf::Drawable>> allDrawables;

sf::Font font;

void drawProjects()
{
    sf::CircleShape base;
    base.setRadius(30);
    base.setFillColor(sf::Color::Blue);
    base.setPosition(1000, 1000);

    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setString("hello");
    text.setCharacterSize(96);
    text.setOrigin(1100, 1000);

    projectsDrawables.emplace_back(std::make_unique<sf::Text>(text));
    projectsDrawables.emplace_back(std::make_unique<sf::CircleShape>(base));

    sf::CircleShape base2;
    base2.setRadius(50);
    base2.setFillColor(sf::Color::Red);
    base2.setPosition(30, 80);

    sf::Text text2;
    text2.setFont(font);
    text2.setFillColor(sf::Color::Green);
    text2.setString("Cheese");
    text2.setCharacterSize(48);
    text2.setPosition(30, 30);

    allDrawables.emplace_back(std::make_unique<sf::Text>(text2));
    allDrawables.emplace_back(std::make_unique<sf::CircleShape>(base2));
}

int main()
{
    sf::RenderWindow mainWindow(sf::VideoMode((2 + BOARD_SIZE) * (int)TILE_SIZE, (2 + BOARD_SIZE) * (int)TILE_SIZE), "Snake");

    if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf"))
    {
        std::cerr << "Font error." << std::endl;
        exit(-1);
    }
    sf::Clock clock;

    auto scale = 1;
    auto projectsBox = sf::RectangleShape(sf::Vector2f(400, 225));
    projectsBox.setPosition(1000, 1000);
    projectsBox.setOutlineColor(sf::Color::Green);
    projectsBox.setOutlineThickness(10 * scale);
    projectsBox.setFillColor(sf::Color::Transparent);
    sf::View projectsView(projectsBox.getGlobalBounds());

    while (mainWindow.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() > 0.2f)
        {
            clock.restart();
        }

        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainWindow.close();
            // Respond to key pressed events
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    return 0;
                }
            }
        }

        mainWindow.clear(sf::Color::Black);

        mainWindow.setView(projectsView);
        mainWindow.draw(projectsBox);

        // Do project veiw
        drawProjects();
        for (std::unique_ptr<sf::Drawable> &i : projectsDrawables)
        {
            mainWindow.draw(*i);
        }

        // draw drawbles
        mainWindow.setView(mainWindow.getDefaultView());
        for (std::unique_ptr<sf::Drawable> &i : allDrawables)
        {
            mainWindow.draw(*i);
        }
        // projectsSlider.setSize(sf::Vector2f(15, slidersize()));
        // mainWindow.draw(projectsSlider);

        // render
        mainWindow.display();
    }
}