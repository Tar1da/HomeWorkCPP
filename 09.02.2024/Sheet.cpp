#include "Sheet.h"

int Sheet::getIndexRecordById(int id)
{
	for (int k = 0; k < countRecords; k++)
		if (records[k]->getId() == id) return k;
	return -1;
}

void Sheet::addRecord(Record record)
{
	auto buf = new Record * [countRecords + 1];
	for (int k = 0; k < countRecords; k++) buf[k] = records[k];
	buf[countRecords++] = new Record(record);
	delete[] records;
	records = buf;
}

void Sheet::removeRecord(int id)
{
	if (countRecords == 0) return;
	int index = getIndexRecordById(id);
	if (index == -1) return;

	auto buf = new Record * [countRecords - 1];
	for (int k = 0; k < index; k++) buf[k] = records[k];
	for (int k = index; k < countRecords; k++) buf[k] = records[k + 1];

	delete[] records;
	records = buf;
	countRecords--;
}

void Sheet::showInfo()
{
	for (int k = 0; k < countRecords; k++) records[k]->showInfo();
}
