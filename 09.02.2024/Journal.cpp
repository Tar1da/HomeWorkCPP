#include "Journal.h"

void Journal::addSheet(Sheet sheet)
{
	auto buf = new Sheet * [countSheets + 1];
	for (int k = 0; k < countSheets; k++) buf[k] = sheets[k];
	buf[countSheets++] = new Sheet(sheet);
	delete[] sheets;
	sheets = buf;
}

void Journal::showSheet(int index)
{
	sheets[index]->showInfo();
}

void Journal::showInfo()
{
	for (int k = 0; k < countSheets; k++) sheets[k]->showInfo();
}


