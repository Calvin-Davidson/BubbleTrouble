#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Time.h"
#include "Player.h"
#include "GameObject.h";

class Circle : GameObject
{
public:
	Circle(Time& time, sf::Vector2f, float radius = 100.0f);
	~Circle();
	void Update();
	void HookEvents(GameEvents* events);
	void Render(sf::RenderWindow& window);
	void IsColliding(Circle* circle);
	float GetRadius();
	static void ResolveCollision(Circle* cirlce1, Circle* circle2);
	bool CollidesWithRope(PlayerRope* rope);
	void SplitBall(std::vector<Circle>* circles);
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
