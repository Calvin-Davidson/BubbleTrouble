#include "Circle.h"
#include "Time.h"

Circle::Circle(Time& time, sf::Vector2f startPosition)
{
	_time = (Time*)&time;

	_velocity = sf::Vector2f(2.0f,1.0f);
	_startVelocity = _velocity;

	float _radius = 25.0f;
	
	sf::CircleShape shape(_radius);
	_shape = shape;
	_shape.setOrigin(_radius, _radius);
	_shape.setPosition(startPosition);
}

Circle::~Circle()
{
}

void Circle::Update()
{
	BorderCollision();
	UpdateVelocity();
	UpdatePosition();
}

void Circle::Draw(sf::RenderWindow& window)
{
	window.draw(_shape);
}

void Circle::IsColliding(Circle* circle)
{
}

float Circle::GetRadius()
{
	return _radius;
}

void Circle::ResolveCollision(Circle* cirlce1, Circle* circle2)
{
}

void Circle::BorderCollision()
{
	if (_shape.getPosition().x <= _shape.getRadius())
		_velocity.x = abs(_velocity.x);
	if (_shape.getPosition().x >= 1366 - _shape.getRadius())
		_velocity.x = -abs(_velocity.x);
	if (_shape.getPosition().y <= _shape.getRadius())
		_velocity.y = abs(_velocity.y);
	if (_shape.getPosition().y >= (768 - _shape.getRadius())) 
		_velocity.y = -abs(_velocity.y);
}

void Circle::UpdateVelocity()
{
		_velocity.y += 0.2 * _time->GetDeltaTime();
}

void Circle::UpdatePosition()
{
	_shape.setPosition(_shape.getPosition().x + _velocity.x * _time->GetDeltaTime(), _shape.getPosition().y + _velocity.y * _time->GetDeltaTime());
}
