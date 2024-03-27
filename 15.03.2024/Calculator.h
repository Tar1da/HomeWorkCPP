#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace std;

class Calculator
{
	sf::RenderWindow win;
	sf::Color gray;
	sf::Color white;
	sf::Color orange;
	sf::Color defaultColor;
	vector <Button> keyboard;
	string keyboardText[5][4]{ {"C", "CE", "X^", "sqrt"},
							   {"7", "8", "9", "+"},
							   {"4", "5", "6", "-"},
							   {"1", "2", "3", "*"},
							   {".", "0", "=", "/"} };
	string fieldText = "0";
	string operation = "";
	string prevNum = "";
	sf::Text text;
	sf::Font font;
public:
	Calculator();
	void run();
private:
	void update();
	void processEvent();
	void render();
	float getResult(string operation);
	void eraseZerosBack();
};

