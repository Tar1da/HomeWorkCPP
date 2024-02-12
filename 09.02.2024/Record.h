#pragma once
#include <iostream>
using namespace std;
class Record
{
private:
	static int id;
	int uniqId;
	string text;
	string date;
public:
	Record(string text, string date);
	int getId();
	void showInfo();
};