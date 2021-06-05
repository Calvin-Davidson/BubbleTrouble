#include "Circle.h"
#include "Time.h"

Circle::Circle(Time& time)
{
	_time = (Time*)&time;

	_position = sf::Vector2f(0, 0);
	_velocity = sf::Vector2f(0,1);
	float _radius = 25;
	
	sf::CircleShape shape(_radius);
	_shape = shape;

	_shape.setOrigin(_radius, _radius);
	_position.x += _radius * 2;
}

Circle::~Circle()
{
}

void Circle::Update()
{
	_position.x += _velocity.x * _time->GetDeltaTime();
	_position.y += _velocity.y * _time->GetDeltaTime();
	_shape.setPosition(_position);
}

void Circle::Draw(sf::RenderWindow& window)
{
	window.draw(_shape);
}

void Circle::IsColliding(Circle* circle)
{
}

void Circle::ResolveCollision(Circle* cirlce1, Circle* circle2)
{
}
