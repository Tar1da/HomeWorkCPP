#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Button
{
	sf::RectangleShape shape;
	sf::Text text;
	sf::Font font;
	bool active = false;
	sf::Color btnColor;
public:
	Button(sf::Vector2f size, sf::Color color, sf::Vector2f position, string str, int k, int n);
	void draw(sf::RenderWindow& win);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void changeActive();
	void update();
};

