#pragma once
#include <iostream>
using namespace std;

class DialogBox {
private:
	string title;
	string question = "Unsaved data will be deleted. Are you sure you want to leave?";
	string btn1 = "No";
	string btn2 = "Yes";
	static DialogBox* instance;
	DialogBox(string title) {
		this->title = title;
	}
public:
	static DialogBox* getInstance(string title) {
		if (instance == nullptr) {
			instance = new DialogBox(title);
		}
		return instance;
	}
	void render() {
		cout << title << endl
			<< question << endl
			<< btn1 << "\t" << btn2
			<< endl;
	}
};

DialogBox* DialogBox::instance = nullptr;
