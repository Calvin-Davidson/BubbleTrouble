#pragma once
#include <SFML/Graphics.hpp>

class Time
{
public:
	Time();
	~Time();
	void Restart();
	float GetDeltaTime();

	float GetTotalGameTime();
	void ResetTotalGameTime();
private:
	sf::Clock _deltatime;
	float _totalGameTime = 0.0f;
};

