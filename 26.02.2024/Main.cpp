#include <iostream>
#include <vector>
#include "Refrigerator.h"
#include "Milk.h"
#include "Meet.h"
#include "Fish.h"
using namespace std;

int main() {
	Refrigerator ref1(2, 2, 3); //int countSh, int maxCountSh, int maxCountPr
	Milk* milk = new Milk("Moloko");
	Meet* meet = new Meet("Meet");
	Fish* fish = new Fish("Fish");
	Fish* fish2 = new Fish("Fish2");
	Fish* fish3 = new Fish("Fish3");
	ref1.addProductToShelf(milk);
	ref1.addProductToShelf(meet);
	ref1.addProductToShelf(fish);
	ref1.addProductToShelf(fish2);
	ref1.showAllShelves();

	cout << "\033[95m";
	ref1.getProductFromShelfByIndex(0, 1); // int indexSh, int indexPr
	ref1.showAllShelves();

	cout << "\033[96m";
	ref1.addProductToShelf(fish3);
	ref1.showAllShelves(); 
	cout << "\033[0m";

	return 0;
}