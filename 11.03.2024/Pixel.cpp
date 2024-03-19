#include "Pixel.h"

Pixel::Pixel(sf::Vector2f size,
	sf::Color color,
	sf::Vector2f position)

{
	btnColor = color;
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setPosition(position);
}

void Pixel::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Vector2f Pixel::getPosition()
{
	return shape.getPosition();
}

sf::Vector2f Pixel::getSize()
{
	return shape.getSize();
}

void Pixel::changeActive()
{
	active = !active;
}

void Pixel::update()
{
	if (active) {
		sf::Color color = shape.getFillColor();
		shape.setFillColor(sf::Color::Black);
	}
	else {
		shape.setFillColor(btnColor);
	}
}
