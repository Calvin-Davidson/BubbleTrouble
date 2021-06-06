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
	_totalGameTime += GetDeltaTime();
	_deltatime.restart();
}

float Time::GetDeltaTime()
{
	return (float) _deltatime.getElapsedTime().asMicroseconds() / (float)1000.0f;
}

float Time::GetTotalGameTime()
{
	return _totalGameTime;
}

void Time::ResetTotalGameTime()
{
	_totalGameTime = 0.0f;
}
