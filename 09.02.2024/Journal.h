#pragma once
#include <iostream>
#include "Sheet.h"
using namespace std;
class Journal
{
private:
	Sheet** sheets;
	int countSheets = 0;
public:
	void addSheet(Sheet sheet);
	void showSheet(int index);
	void showInfo();
};

