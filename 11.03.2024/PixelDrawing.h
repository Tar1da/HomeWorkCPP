#pragma once
#include <SFML/Graphics.hpp>
#include "Pixel.h"
class PixelDrawing
{
	sf::RenderWindow window;
	std::vector<Pixel> fieldOfPixels;
public:
	PixelDrawing();
	void run();
private:
	void update();
	void processEvent();
	void render();
};

