#include "Refrigerator.h"

Refrigerator::Refrigerator(int countSh, int maxCountSh, int maxCountPr)
{
	this->maxCount = maxCountSh;
	
	for (int k = 0; k < countSh; k++) {
		Shelf* sh = new Shelf(maxCountPr);
		addShelf(sh);
	}
}

void Refrigerator::addShelf(Shelf* shelf) {
	if (countShelves < maxCount) {
		shelves.push_back(shelf);
		countShelves++;
	}

}

void Refrigerator::addProductToShelf(Product* product)
{
	for (auto& el : shelves) {
		if (el->getCountProducts() < el->getMaxCount()) {
			el->addProduct(product);
			break;
		}
		else continue;
	}
}

void Refrigerator::showAllShelves()
{
	for (auto& el : shelves) {
		cout << "Shelf " << el->getUniqId() << endl;
		el->showAllProducts();
		cout << endl;
	}
}

Product* Refrigerator::getProductFromShelfByIndex(int indexSh, int indexPr)
{
	Product* buf = shelves[indexSh]->getProductByIndex(indexPr);
	return (buf != nullptr) ? buf : NULL;
}


