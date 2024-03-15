#pragma once
#include <iostream>
class MyString
{
private:
	char* str;
	int size;

public:
	MyString(const char arr[]);
	void operator<<(const char arr[]);
	void operator=(const char arr[]);
	void operator+(const char arr[]);
	void operator+=(const char ch);
	bool operator==(const char arr[]);
	bool operator!=(const char arr[]);
	bool operator>=(const char arr[]);
	bool operator<=(const char arr[]);
	bool operator>(const char arr[]);
	bool operator<(const char arr[]);
	char& operator[](int index);

	void show();
	int sizeStr();
	bool empty();
	void clear();
	void append(const char arr[]);
	void append(const MyString& newString);
	int compare(const char arr[]);
	int compare(const MyString& newString);
	int find(const char arr[]);
	int rfind(const char arr[]);
	int erase(char value);
	void replace(int first, int last, const char string[]);
	void insert(int pos, const char string[]);
	int stoi(const char arr[]);
};
