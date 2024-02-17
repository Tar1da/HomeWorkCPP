#include <iostream>
#include "Deque.h"
using namespace std;

int main() {

	Deque <int> deque(20);
	Deque <int> deque2(20);
	Deque <int> deque3(20);

	deque3.push_front(12);
	deque3.push_front(12);
	deque3.push_front(12);

	deque.push_front(0);
	deque.push_front(1);
	deque.push_back(2);
	deque2.push_front(1);
	deque2.push_front(1);

	showDeque(deque);
	cout << endl;
	cout << "deque.pop_front();" << endl;
	deque.pop_front();
	showDeque(deque);
	cout << endl;
	cout << "deque.pop_back();" << endl;
	deque.pop_back();
	showDeque(deque);
	cout << endl;
	cout << "deque.append_range(deque2);" << endl;
	deque.append_range(deque2);
	showDeque(deque);
	cout << endl;

	deque2.push_front(1);
	deque2.push_front(1);
	deque2.push_front(1);
	deque2.push_front(1);
	deque2.push_front(1);

	cout << "deque.prepend_range(deque2);" << endl;
	deque.prepend_range(deque2);
	showDeque(deque);
	cout << endl;
	cout << "deque.erase(7);" << endl;
	deque.erase(7);
	showDeque(deque);
	cout << endl;
	cout << "deque.erase_range(0, 2);" << endl;
	deque.erase_range(0, 2);
	showDeque(deque);
	cout << endl;
	cout << "deque.erase_range(0, 0);" << endl;
	deque.erase_range(0, 0);
	showDeque(deque);
	cout << endl;
	cout << "deque.insert_range(2, deque3);" << endl;
	deque.insert_range(2, deque3);
	showDeque(deque);
	cout << endl;
	cout << "deque.insert(3, 25);" << endl;
	deque.insert(3, 25);
	showDeque(deque);
	cout << endl;

	system("pause");
	return 0;
}