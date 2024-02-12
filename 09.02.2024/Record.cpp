#include "Record.h"

Record::Record(string text, string date)
{
	uniqId = id++;
	this->text = text;
	this->date = date;
}

int Record::getId()
{
	return uniqId;
}

void Record::showInfo()
{

	cout << uniqId << " " << text << " " << date << endl;
}
int Record::id = 0;