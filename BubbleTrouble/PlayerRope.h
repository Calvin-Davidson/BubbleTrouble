#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Time.h"
#include "Mathf.h"

class PlayerRope
{
public:
	PlayerRope(Time& time);
	~PlayerRope();

	void Update();
	void Draw(sf::RenderWindow& window);
	void MoveTo(sf::Vector2f newPosition);
	bool isDone = true;

private:
	Time* _time;
	sf::Vector2f _position = sf::Vector2f(-100, 100);
	float _scale = 0.0f;
	float const _growSpeed = 4.0f;
};

