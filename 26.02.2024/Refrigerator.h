#pragma once
#include "Shelf.h"
#include <vector>
#include <iostream>
using namespace std;

class Refrigerator
{
	vector<Shelf*> shelves;
	int maxCount;
	int countShelves;
public:
	Refrigerator(int countSh, int maxCountSh, int maxCountPr);
	void addShelf(Shelf* shelf);
	void addProductToShelf(Product* product);
	void showAllShelves();
	Product* getProductFromShelfByIndex(int indexSh, int indexPr);
};

