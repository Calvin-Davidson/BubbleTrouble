#include <SFML/Graphics.hpp>
#include "Circle.h";
#include "Time.h";

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Bubble trouble");

    Time time = Time();

    Circle circle = Circle(time);
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