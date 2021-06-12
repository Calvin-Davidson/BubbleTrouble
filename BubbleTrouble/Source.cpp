#include <SFML/Graphics.hpp>
#include "Circle.h";
#include "Player.h"
#include "Time.h";
#include "GameLoader.h";
#include <iostream>
#include <vector>
#include "GameObject.h";


int main()
{
	GameEvents* gameEvents = new GameEvents();
	std::vector<Circle>* balls = new std::vector<Circle>;

	sf::RenderWindow window(sf::VideoMode(1366, 768), "Bubble trouble", sf::Style::Titlebar | sf::Style::Close);

	Time time = Time();
	Circle circle = Circle(time, sf::Vector2f(200, 300));
	circle.HookEvents(gameEvents);

	balls->push_back(circle);

	sf::Font font = GameLoader().LoadFont();
	sf::Text text = GameLoader().CreateDefaultText("GET READY!!", font, true);

	sf::Texture background = GameLoader().LoadBackground();
	sf::Sprite backgroundSprite(background);
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1366, 768));

	Player player = Player(time, sf::Vector2f(50, 50), sf::Vector2f(window.getSize().x / 2, window.getSize().y - 25));
	player.HookEvents(gameEvents);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(backgroundSprite);

		if (time.GetTotalGameTime() < 2000) {
			
			window.draw(text);

			window.display();

			time.Restart();
			continue;
		}
		if (time.GetTotalGameTime() < 7000) {
			int counter = (7000 - time.GetTotalGameTime()) / 1000 + 1;
			text.setString(std::to_string(counter));

			sf::FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.width / 2, textRect.height / 2);
			text.setPosition(sf::Vector2f(1366 / 2.0f, 768 / 2.0f));

			window.draw(text);
			window.display();

			time.Restart();
			continue;
		}

		__raise gameEvents->Update();
		__raise gameEvents->LateUpdate();
		__raise gameEvents->Render(window);

		bool collided = false;
		for (int i = 0; i < balls->size(); i++) {
			balls->at(i).Update();

			if (!collided && !player.playerRope->isDone && balls->at(i).CollidesWithRope(player.playerRope)) {
				collided = true;
				player.playerRope->OnCollision();
				
				balls->at(i).SplitBall(balls);
				balls->erase(balls->begin() + i);
			}
		}




		window.display();

		time.Restart();
	}

	return 0;
}