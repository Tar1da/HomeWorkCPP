#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Deque {
private:
	T* deque = nullptr;
	int count = 0;
	int capacity;
public:
	Deque(int capacity)
	{
		deque = new T[capacity];
		this->capacity = capacity;
	}
	Deque(Deque& deq)
	{
		this->count = deq.count;
		this->capacity = deq.capacity;
		if (deque != nullptr) delete[] deque;
		deque = new T[capacity];
		for (int k = 0; k < count; k++) deque[k] = deq.deque[k];
	}
	void operator= (Deque& deq)
	{
		this->count = deq.count;
		this->capacity = deq.capacity;
		if (deque != nullptr) delete[] deque;
		deque = new T[capacity];
		for (int k = 0; k < count; k++) deque[k] = deq.deque[k];
	}
	~Deque()
	{
		if (deque != nullptr){
			delete[] deque;
			count = 0;
		}
	}
	T& operator[](int index)
	{
		return this->deque[index];
	}

	T& front() 
	{
		return deque[0];
	}
	T& back() 
	{
		return deque[count - 1];
	}
	bool empty() 
	{
		return !count;
	}
	int size() 
	{
		return count;
	}
	int max_size() 
	{
		return capacity;
	}
	void clear()
	{
		delete[] deque;
		count = 0;
	}
	T& at(int index)
	{
		if (index < 0 || index >= count) throw;
		return this->deque[index];
	}
	void push_front(T el)
	{
		if (count == capacity) return;
		for (int k = count; k >= 0; k--) deque[k] = deque[k - 1];
		deque[0] = el;
		count++;
	}
	void push_back(T el)
	{
		if (count == capacity) return;
		deque[count++] = el;
	}
	T pop_front()
	{
		if (count == 0) return NULL;
		for (int k = 0; k < count - 1; k++) deque[k] = deque[k + 1];
		count--;
		return deque[0];
	}
	T pop_back()
	{
		if (count == 0) return NULL;
		count--;
		return deque[count];
	}
	void prepend_range(Deque& deq) {
		if (deq.count == 0) return;
		if ((count + deq.count) > capacity) return;
		for (int k = count + deq.count - 1, n = count - 1; k >= count - 1; k--, n--) deque[k] = deque[n];

		for (int k = 0; k < deq.count; k++) deque[k] = deq.deque[k];
		count += deq.count;
	}
	void append_range(Deque& deq) {
		if ((count + deq.count) > capacity) return;
		for (int k = count, n = 0; k < count + deq.count; k++, n++) deque[k] = deq.deque[n];
		count += deq.count;
	}
	void erase(int index)
	{
		if (index < 0 || index >= count) return;
		for (int k = index; k < count - 1; k++) deque[k] = deque[k + 1];
		count--;
	}
};

template <typename T>
void showDeque(Deque<T>& deq) {
	for (int k = 0; k < deq.size(); k++)
		cout << deq.at(k) << " ";
}