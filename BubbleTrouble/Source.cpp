#include <SFML/Graphics.hpp>
#include "Circle.h";
#include "Player.h"
#include "Time.h";

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Bubble trouble", sf::Style::Titlebar | sf::Style::Close);

    Time time = Time();

    Circle circle = Circle(time);
    Player player = Player(time, sf::Vector2f(50, 50), sf::Vector2f(window.getSize().x/2, window.getSize().y - 25));


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

        player.Update();
        player.Draw(window);

        window.display();

        time.Restart();
    }

    return 0;
}