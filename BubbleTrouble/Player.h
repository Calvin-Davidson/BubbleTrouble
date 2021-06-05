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
private:
	sf::RectangleShape _shape;
	Time* _time;
	PlayerRope* _playerRope;
	float _movemoventSpeed = 0.7f;
};

