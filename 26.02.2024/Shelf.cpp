#include "Shelf.h"

Shelf::Shelf(int maxCount)
{
	id++;
	uniqId = id;
	this->maxCount = maxCount;
}

void Shelf::addProduct(Product* product) {
	if (countProducts < maxCount) {
		int count = 0;
		bool flag = true;
		for (auto& el : products) {
			if (el == nullptr) {
				flag = false;
				products[count] = product;
				break;
			}
			count++;
		}
		if (flag) products.push_back(product);
		countProducts++;
	}

}

void Shelf::showAllProducts()
{
	for (auto& el : products) {
		if (el == nullptr) cout << "----" << endl;
		else el->getInfo();
	}
}

Product* Shelf::getProductByIndex(int index)
{
	Product* buf = *(products.begin() + index);
	products[index] = nullptr;
	countProducts--;
	return buf;
}

int Shelf::getUniqId()
{
	return this->uniqId;
}

int Shelf::getCountProducts()
{
	return countProducts;
}

int Shelf::getMaxCount() 
{
	return maxCount;
}

int Shelf::id = 0;