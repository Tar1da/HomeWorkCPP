#include "Calculator.h"

Calculator::Calculator() :
	win(sf::VideoMode(398, 598), "I-calculator"),
	gray(127, 127, 127, 255),
	white(20, 20, 20, 255),
	orange(198, 114, 57, 255),
	defaultColor(sf::Color::White)
{
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			sf::Color setColor = (i == 1 || j == 3) ? orange : gray;
			
			if(keyboardText[i - 1][j] == ".")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 40, 30));
			if(keyboardText[i - 1][j] == "/")
				keyboard.push_back(Button(sf::Vector2f(98, 98), setColor, sf::Vector2f(j * 100, i * 100), keyboardText[i - 1][j], 45, 30));
			if(keyboardText[i - 1][j].size() == 1 && 
				keyboardText[i - 1][j] != "." &&
				keyboardText[i - 1][j] != "/")
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
	text.setFillColor(defaultColor);
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
			for (auto& key : keyboard){
				if ((mousePos.x >= key.getPosition().x) &&
					(mousePos.x <= (key.getPosition().x + key.getSize().x)) &&
					(mousePos.y >= key.getPosition().y) &&
					(mousePos.y <= (key.getPosition().y + key.getSize().y))) {
					key.changeActive();
					if (event.type == sf::Event::MouseButtonReleased) {
						if (key.getText()[0] >= '0' && key.getText()[0] <= '9' ||
							key.getText()[0] == '.') {
							if (text.getFillColor() == sf::Color::Cyan) text.setFillColor(sf::Color::White);
							if (fieldText == "0" && key.getText() != ".") fieldText = "";
							if (fieldText.length() == 9)
								break;
							if (key.getText() == "." &&
								fieldText.find(".") <= fieldText.size()) {
								break;
							}
							fieldText += key.getText();
						}
						else {
							if (key.getText()[0] == 'C') {
								fieldText = "0";
								text.setFillColor(defaultColor);
								prevNum = "";
							}
							else if (key.getText() == "CE") {
								fieldText = "0";
								text.setFillColor(defaultColor);
							}
							else if (key.getText()[0] == '=') {
								if (operation != "" && text.getFillColor() == sf::Color::White) {
									std::cout << operation;///////////////////////
									std::cout << fieldText;///////////////////////
									std::cout << "=";/////////////////////////////
									fieldText = to_string(getResult(operation));
									eraseZerosBack();
									std::cout << fieldText << endl;///////////////
									text.setFillColor(sf::Color::Cyan);
								}
								else if(fieldText == "0" || text.getFillColor() == sf::Color::Cyan) {
									std::cout << "=";/////////////////////////////
									std::cout << fieldText << endl;///////////////
								}
								else if (operation == "")
									std::cout << "empty" << std::endl;//////////////
							}
							else if (key.getText() == "sqrt") {
								prevNum = fieldText;
								operation = key.getText();
								prevNum = to_string(getResult(operation));
								fieldText = prevNum;
								eraseZerosBack();
								text.setFillColor(sf::Color::Cyan);
							}
							else if(key.getText()[0] == '+' ||
									key.getText()[0] == '-' ||
									key.getText()[0] == '*' ||
									key.getText()[0] == '/' ||
									key.getText()[0] == 'X'){
									prevNum = fieldText;
									std::cout << prevNum;/////////////////////////////
									operation = key.getText();
									fieldText = "0";
									text.setFillColor(defaultColor);
							
							}

						}

					}


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

float Calculator::getResult(string operation)
{
	float res;
	if (operation == "+") {
		res = stof(prevNum) + stof(fieldText);
	}
	else if (operation == "-") {
		res = stof(prevNum) - stof(fieldText);
	}
	else if (operation == "*") {
		res = stof(prevNum) * stof(fieldText);
	}
	else if (operation == "/") {
		res = stof(prevNum) / stof(fieldText);
	}
	else if (operation == "X^") {
		res = pow(stof(prevNum), stof(fieldText));
	}
	else if (operation == "sqrt") {
		res = sqrt(stof(prevNum));
	}
	return res;
}

void Calculator::eraseZerosBack()
{
	if (fieldText.find('.')) {
		while (fieldText[fieldText.size() - 1] == '0')
			fieldText.pop_back();
		if (fieldText[fieldText.size() - 1] == '.')
			fieldText.pop_back();
	}
}
