#include "Calculator.h"

Calculator::Calculator() : 
	win(sf::VideoMode(398, 598), "I-calculator"), 
	gray(127,127,127,255),
	white(20,20,20,255),
	orange(198,114,57,255)
{
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			sf::Color setColor = (i == 1 || j == 3) ? orange : gray;
			
			if(keyboardText[i - 1][j] == "*")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 46, 37));
			if(keyboardText[i - 1][j] == "+")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 43, 30));
			if(keyboardText[i - 1][j] == "-")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 45, 30));
			if(keyboardText[i - 1][j] == ".")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 45, 30));
			if(keyboardText[i - 1][j] == "/")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 47, 30));
			if(keyboardText[i - 1][j].size() == 1 && 
				keyboardText[i - 1][j] != "." &&
				keyboardText[i - 1][j] != "/" &&
				keyboardText[i - 1][j] != "*" &&
				keyboardText[i - 1][j] != "-" &&
				keyboardText[i - 1][j] != "+")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 40, 30));
			if(keyboardText[i - 1][j].size() == 2)
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 30, 30));
			if(keyboardText[i - 1][j].size() == 4)
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 20, 30));

		}
	}
	font.loadFromFile("arialbd.ttf");
	text.setFont(font);
	text.setCharacterSize(70);
	text.setString(fieldText);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(350, 5));
}

void Calculator::run()
{
	while (win.isOpen()) {
		processEvent();
		update();
		render();
	}
}

void Calculator::update()
{
	for (auto& el : keyboard) {
		el.update();
	}
	text.setString(fieldText);
	text.setPosition( sf::Vector2f(365 - fieldText.size() * 38, text.getPosition().y) );
}

void Calculator::processEvent()
{
	sf::Event event;
	while (win.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			win.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
			event.type == sf::Event::MouseButtonReleased)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(win);
			for (auto& key : keyboard) {
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

void Calculator::render()
{
	win.clear();
	for (auto& el : keyboard) {
		el.draw(win);
	}
	win.draw(text);
	win.display();
}
