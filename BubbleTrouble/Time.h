#pragma once
#include <SFML/Graphics.hpp>

class Time
{
public:
	Time();
	~Time();
	void Restart();
	float GetDeltaTime();
private:
	sf::Clock _deltatime;
};

