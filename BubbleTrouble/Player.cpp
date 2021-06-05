#include "Player.h"

Player::Player(Time& time, sf::Vector2f size, sf::Vector2f position)
{
	_time = (Time*)&time;

	sf::RectangleShape shape(size);
	_shape = shape;


	_shape.setOrigin(size.x/2, size.y/2);
	_shape.setPosition(position);
}

Player::~Player()
{
}

void Player::Update()
{
//	if (_shape.getPosition().x <= _shape.getRadius())
//		_velocity.x = abs(_velocity.x);
//	if (_shape.getPosition().x >= 1366 - _shape.getRadius())
//		_velocity.x = -abs(_velocity.x);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _shape.getPosition().x - 2 * _time->GetDeltaTime() >= _shape.getSize().x / 2) {
		_shape.setPosition(_shape.getPosition().x - 2 * _time->GetDeltaTime(), _shape.getPosition().y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _shape.getPosition().x + 2 * _time->GetDeltaTime() <= 1366 - _shape.getSize().x / 2) {
		_shape.setPosition(_shape.getPosition().x + 2 * _time->GetDeltaTime(), _shape.getPosition().y);
	}
}

void Player::Draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(_shape);
}
