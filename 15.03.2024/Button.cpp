#include "Button.h"

Button::Button(sf::Vector2f size, sf::Color color, sf::Vector2f position, string str, int k, int n)

{
	btnColor = color;
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setPosition(position);
	text.setString(str);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(position.x + k, position.y + n));
}

void Button::draw(sf::RenderWindow& win)
{
	font.loadFromFile("arialbd.ttf");
	text.setFont(font);
	win.draw(shape);
	win.draw(text);
}

sf::Vector2f Button::getPosition()
{
	return shape.getPosition();
}

sf::Vector2f Button::getSize()
{
	return shape.getSize();
}

void Button::changeActive()
{
	active = !active;
}

void Button::update()
{
	if (active) {
		//sf::Color color = shape.getFillColor();
		shape.setFillColor(sf::Color(30, 30, 30));
	}
	else {
		shape.setFillColor(btnColor);
	}

}

string Button::getText()
{
	return text.getString();
}

sf::Color Button::getFillColor()
{
	return shape.getFillColor();
}

