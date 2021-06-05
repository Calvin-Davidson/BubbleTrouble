#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Time.h"

class Circle
{
public:
	Circle(Time& time);
	~Circle();
	void Update();
	void Draw(sf::RenderWindow& window);
	void IsColliding(Circle* circle);
	static void ResolveCollision(Circle* cirlce1, Circle* circle2);
private:
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	float _radius;
	sf::CircleShape _shape;
	Time* _time;
};

