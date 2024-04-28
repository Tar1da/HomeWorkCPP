#include <iostream>
#include "AbstractFactory.h"
using namespace std;

int main() {

	CookieFactory* factory = new CocosCookieFactory;
	Client client(factory);
	cout << client.getFactory()->nameFactory() << endl;
	client.getProduct()->getinfo();

	CookieFactory* factory2 = new ChocoCookieFactory;
	Client client2(factory2);
	cout << client2.getFactory()->nameFactory() << endl;
	client2.getProduct()->getinfo();

	return 0;
}