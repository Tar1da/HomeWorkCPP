#include <iostream>
#include "Journal.h"
#include "Sheet.h"
#include "Record.h"
using namespace std;

int main() {
	Journal journal1;
	Sheet sheet1;
	Sheet sheet2;
	
	sheet1.addRecord(Record("Hello1", "09.02.2024"));
	sheet1.addRecord(Record("Hello2", "09.02.2024"));

	sheet2.addRecord(Record("Hello3", "09.02.2024"));
	sheet2.addRecord(Record("Hello4", "09.02.2024"));
	sheet2.addRecord(Record("Hello5", "09.02.2024"));

	journal1.addSheet(sheet1);
	journal1.addSheet(sheet2);

	journal1.showInfo();

	cout << "\033[96m";
	journal1.showSheet(1);
	cout << "\033[0m";

	sheet1.removeRecord(1);
	sheet1.showInfo();


	system("pause");
	return 0;
}