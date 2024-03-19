#include "PixelDrawing.h"

PixelDrawing::PixelDrawing() :
	window(sf::VideoMode(1000, 1000), "Pixel Drawing Program")
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			sf::Color setColor = sf::Color::White;
			fieldOfPixels.push_back(
				Pixel(sf::Vector2f(98, 98),
					setColor,
					sf::Vector2f(j * 100, i * 100))
			);
		}
	}
}

void PixelDrawing::run() {
	while (window.isOpen())
	{
		processEvent();
		update();
		render();
	}

}

void PixelDrawing::update()
{
	for (auto& el : fieldOfPixels) {
		el.update();
	}
}

void PixelDrawing::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			for (auto& key : fieldOfPixels) {
				if ((mousePos.x >= key.getPosition().x) &&
					(mousePos.x <= (key.getPosition().x + key.getSize().x)) &&
					(mousePos.y >= key.getPosition().y) &&
					(mousePos.y <= (key.getPosition().y + key.getSize().y))) {
					key.changeActive();
				}
			}

		}

	}
}

void PixelDrawing::render()
{
	window.clear();
	for (auto el : fieldOfPixels) {
		el.draw(window);
	}
	window.display();
}