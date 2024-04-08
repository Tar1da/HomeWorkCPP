#pragma once
#include "Product.h"
#include <vector>
using namespace std;

class Shelf
{
	static int id;
	int uniqId;
	vector<Product*> products;
	int maxCount;
	int countProducts = 0;
public:
	Shelf(int maxCount);
	void addProduct(Product* product);
	void showAllProducts();
	Product* getProductByIndex(int index);
	int getUniqId();
	int getCountProducts();
	int getMaxCount();
};
