#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameLoader
{
public:
	static sf::Font LoadFont();
	static sf::Text CreateDefaultText(std::string defaultText, sf::Font& font, bool centered = false);
private:
};

