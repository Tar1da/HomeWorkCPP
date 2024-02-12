#pragma once
#include "Record.h"
class Sheet
{
private:
	int countRecords = 0;
	Record** records;
public:
	int getIndexRecordById(int id);
	void addRecord(Record item);
	void removeRecord(int id);
	void showInfo();
};

