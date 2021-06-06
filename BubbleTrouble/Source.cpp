#include <SFML/Graphics.hpp>
#include "Circle.h";
#include "Time.h";
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Bubble trouble", sf::Style::Titlebar | sf::Style::Close);

    Time time = Time();
    Circle circle = Circle(time, sf::Vector2f(200, 100));
   
    sf::Font font;
    if (!font.loadFromFile("waltographUI.ttf"))
    {
        std::cout << "error";
    }

    sf::Text text;
    text.setString("Testing text system :D");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    while (window.isOpen())
    {
   
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        circle.Update();
        circle.Draw(window);
        window.display();

        time.Restart();
    }

    return 0;
}