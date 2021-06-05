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
	float GetRadius();
	static void ResolveCollision(Circle* cirlce1, Circle* circle2);
private:
	void BorderCollision();
	void UpdateVelocity();
	void UpdatePosition();

	bool _falling;
	sf::Vector2f _velocity;
	sf::Vector2f _startVelocity;
	float _radius;
	sf::CircleShape _shape;
	Time* _time;
};

