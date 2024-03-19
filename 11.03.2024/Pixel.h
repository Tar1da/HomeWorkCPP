#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Pixel
{
	sf::RectangleShape shape;
	bool active = false;
	sf::Color btnColor;
public:
	Pixel(sf::Vector2f size,
		sf::Color color,
		sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void changeActive();
	void update();
};

