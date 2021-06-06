#include "GameLoader.h"
#include <iostream>

sf::Font GameLoader::LoadFont()
{
    sf::Font font;
    if (!font.loadFromFile("waltographUI.ttf"))
    {
        std::cout << "Could not load font";
    }
    return font;
}

sf::Text GameLoader::CreateDefaultText(std::string defaultText, sf::Font& font, bool centered)
{
    sf::Text text;;

    text.setString(defaultText);
    text.setFont(font);
    text.setCharacterSize(200);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    if (centered) {
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.width / 2, textRect.height / 2);
        text.setPosition(sf::Vector2f(1366 / 2.0f, 768 / 2.0f));
    }

    return text;
}

sf::Texture GameLoader::LoadBackground()
{
    sf::Texture t;
    t.loadFromFile("C:/Users/Calvin/source/repos/BubbleTrouble/BubbleTrouble/Images/Background.png");
    t.setRepeated(true);
    return (t);
}

