#include "PlayerRope.h"

PlayerRope::PlayerRope(Time& time)
{
	_time = (Time*)&time;
}

PlayerRope::~PlayerRope()
{
}

void PlayerRope::Update()
{
	_scale += _time->GetDeltaTime() / 60.0f;

	if (_scale >= 1)
		isDone = true;
	else
		isDone = false;
}

void PlayerRope::Draw(sf::RenderWindow& window)
{
	if (isDone && _scale > 1) return;
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(_position.x, 768)),
		sf::Vertex(sf::Vector2f(_position.x, 768 * (1 - Mathf().Clamp(_scale, 0.0f, 1.0f))))
	};

	window.draw(line, 2, sf::Lines);
}

void PlayerRope::MoveTo(sf::Vector2f newPosition)
{
	_scale = 0.0f;
	_position = newPosition;
}

float PlayerRope::GetScale()
{
	return _scale;
}

sf::Vector2f PlayerRope::GetPosition()
{
	return _position;
}

void PlayerRope::OnCollision()
{
	isDone = true;
	_scale = 10.0f;
}
