#pragma once
#include <SFML/Graphics.hpp>
#include "GameEvents.h";

class GameObject
{
public:
	void virtual HookEvents(GameEvents& events);
	void virtual Update();
	void virtual LateUpdate();
	void virtual Render(sf::RenderWindow& renderWindow);
};

