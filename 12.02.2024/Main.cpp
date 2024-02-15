#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
	Deque <int> deque(10);
	Deque <int> deque2(10);

	deque.push_front(0);
	deque.push_front(1);
	deque.push_back(2);
	deque2.push_front(1);
	deque2.push_front(1);

	showDeque(deque);
	cout << endl;

	deque.pop_front();
	showDeque(deque);
	cout << endl;

	deque.pop_back();
	showDeque(deque);
	cout << endl;

	deque.append_range(deque2);
	showDeque(deque);
	cout << endl;

	deque2.push_front(1);
	deque2.push_front(1);
	deque2.push_front(1);
	deque2.push_front(1);
	deque2.push_front(1);

	deque.prepend_range(deque2);
	showDeque(deque);
	cout << endl;

	deque.erase(7);
	showDeque(deque);

	system("pause");
	return 0;
}