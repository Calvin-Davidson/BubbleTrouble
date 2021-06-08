#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Time.h"
#include "PlayerRope.h"

class Player
{
public:
	Player(Time& time, sf::Vector2f size, sf::Vector2f p);
	~Player();

	void Update();
	void Draw(sf::RenderWindow& renderWindow);
	PlayerRope* playerRope;
private:
	sf::RectangleShape _shape;
	Time* _time;
	float _movemoventSpeed = 1.5f;
};
