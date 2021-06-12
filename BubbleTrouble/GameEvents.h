#pragma once
#include <SFML/Graphics.hpp>

class GameEvents {
public:
	__event void Update();
	__event void LateUpdate();
	__event void Render(sf::RenderWindow& renderWindow);
};