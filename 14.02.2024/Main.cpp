#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;

	Node(T value) {
		this->value = value;
	}
};

template <typename T>
class LinkedList {
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int count = 0;
public:
	LinkedList() {}
	~LinkedList() {
		while (head != nullptr)
			pop_front();
	}

	Node<T>* push_front(T value) {
		Node<T>* buf = new Node<T>(value);
		buf->next = head;
		if (head != nullptr)
			head->prev = buf;
		if (tail == nullptr)
			tail = buf;
		head = buf;
		count++;
		return buf;
	}
	Node<T>* push_back(T value) {
		Node<T>* buf = new Node<T>(value);
		buf->prev = tail;
		if (tail != nullptr)
			tail->next = buf;
		if (head == nullptr)
			head = buf;
		tail = buf;
		count++;
		return buf;
	}
	Node<T>* pop_front() {
		if (head == nullptr) return NULL;
		Node<T>* buf = head->next;
		if (buf != nullptr)
			buf->prev = nullptr;
		else
			tail = buf;
		delete head;
		head = buf;
		count--;
	}
	Node<T>* pop_back() {
		if (tail == nullptr) return NULL;
		Node<T>* buf = tail->prev;
		if (buf != nullptr)
			buf->next = nullptr;
		else
			head = buf;
		delete tail;
		tail = buf;
		count--;
	}
	Node<T>* at(int index) {
		Node<T>* buf = head;
		int n = 0;
		while (n != index) {
			if (buf == nullptr)
				return buf;
			buf = buf->next;
			n++;
		}
		return buf;
	}
	Node<T>* operator[](int index) {
		return at(index);
	}
	Node<T>* insert(int index, T value) {
		Node<T>* right = at(index);
		if (right == nullptr)
			return push_back(value);
		Node<T>* left = right->prev;
		if (left == nullptr)
			return push_front(value);
		Node<T>* buf = new Node<T>(value);
		buf->prev = left;
		buf->next = right;
		left->next = buf;
		right->prev = buf;
		return buf;
	}
	void erase(int index) {
		Node<T>* buf = at(index);
		if (buf == nullptr)
			return;
		if (buf->prev == nullptr){
			pop_front();
			return;
		}
		if (buf->next == nullptr) {
			pop_back();
			return;
		}
		Node<T>* left = buf->prev;
		Node<T>* right = buf->next;
		left->next = right;
		right->prev = left;
		delete buf;
		count--;
	}
	void showFrTheBegin() {
		Node <T>* buf = head;
		while (buf->next != nullptr) {
			cout << buf->value << " ";
			buf = buf->next;
		}
		cout << buf->value;
	}
	void showFrTheEnd() {
		Node <T>* buf = tail;
		while (buf->prev != nullptr) {
			cout << buf->value << " ";
			buf = buf->prev;
		}
		cout << buf->value;
	}
};

int main() {

	LinkedList<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);

	list1.insert(1, 25);
	list1.showFrTheBegin(); cout << endl;
	list1.erase(1);
	list1.showFrTheBegin(); cout << endl;
	list1[0]->value = 20;
	list1.showFrTheBegin(); cout << endl;
	list1.showFrTheEnd();	cout << endl;

	system("pause");
	return 0;
}