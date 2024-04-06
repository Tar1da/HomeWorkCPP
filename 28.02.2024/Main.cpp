#include <iostream>
#include "Singleton.h"
#include "Builder.h"
//#define SINGLETON
//#define BUILDER
using namespace std;

int main() {
#ifdef SINGLETON
	DialogBox* db1 = DialogBox::getInstance("Exit");
	db1->render();

	cout << endl;

	DialogBox* db2 = DialogBox::getInstance("Go out");
	db2->render();

	cout << endl;
#endif

#ifdef BUILDER
	HouseBuilder builder1;
	Director dr1;
	dr1.buildHouseWithGardenGarage(&builder1);
	builder1.getResult().showInfo();

	cout << endl;

	dr1.buildHouseWithStatuesPool(&builder1);
	builder1.getResult().showInfo();

#endif

	return 0;
}