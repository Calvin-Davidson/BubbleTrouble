#include "Time.h"
#include <iostream>

Time::Time()
{
	sf::Clock deltaTime;
	_deltatime = deltaTime;
}

Time::~Time()
{

}

void Time::Restart()
{
	_deltatime.restart();
}

float Time::GetDeltaTime()
{
	return _deltatime.getElapsedTime().asMicroseconds() / 1000.0f;
}
