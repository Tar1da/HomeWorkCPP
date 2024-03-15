#include "MyString.h"

MyString::MyString(const char arr[])
{
	size = 0;
	for (int i = 0; arr[i] != '\0'; i++) size++;
	str = new char[size + 1];
	for (int i = 0; i < size + 1; i++) str[i] = arr[i];
}

char& MyString::operator[](int index)
{
	return this->str[index]; 
}

void MyString::show()
{
	if (size > 0)
		std::cout << str << std::endl;
}

int MyString::sizeStr()
{
	return this->size;
}

bool MyString::empty()
{
	return !size;
}

void MyString::clear()
{
	delete[] str;
	size = 0;
}

void MyString::append(const char arr[])
{
	int size2 = 0;
	for (int i = 0; arr[i] != '\0'; i++) size2++;
	char* buf = new char[size + size2 + 1];
	for (int i = 0; i < size; i++) {
		buf[i] = str[i];
	}
	for (int i = 0; i <= size2; i++) {
		buf[size + i] = arr[i];
	}
	delete[] str;
	str = buf;
	size += size2;
}

void MyString::append(const MyString& newString)
{
	append(newString.str);
}

void MyString::operator<<(const char arr[]) {
	append(arr);
}

void MyString::operator=(const char arr[])
{
	if (size > 0) delete[] str;
	size = 0;
	for (int i = 0; arr[i] != '\0'; i++) size++;
	str = new char[size + 1];
	for (int i = 0; i < size + 1; i++) str[i] = arr[i];
}

bool MyString::operator==(const char arr[])
{
	for (int i = 0; i < size + 1; i++)
		if(str[i] != arr[i]) return false;
	return true;
}

bool MyString::operator!=(const char arr[])
{
	return !(operator==(arr));
}

bool MyString::operator>=(const char arr[])
{
	return (compare(arr) == -1) ? false : true;
}

bool MyString::operator<=(const char arr[])
{
	return (compare(arr) == 1) ? false : true;
}

bool MyString::operator>(const char arr[])
{
	return (compare(arr) == 0 || compare(arr) == -1)? false: true;
}

bool MyString::operator<(const char arr[])
{
	return (compare(arr) == 0 || compare(arr) == 1) ? false : true;
}

void MyString::operator+(const char arr[])
{
	int size2 = 0;
	for (int i = 0; arr[i] != '\0'; i++) size2++;
	char* buf = new char[size + size2 + 1];
	for (int i = 0; i < size; i++) {
		buf[i] = str[i];
	}
	for (int i = 0; i <= size2; i++) {
		buf[size + i] = arr[i];
	}
	delete[] str;
	str = buf;
	size += size2;
}

void MyString::operator+=(const char ch)
{
	int size2 = 1;
	char* buf = new char[size + size2 + 1];
	for (int i = 0; i < size; i++) {
		buf[i] = str[i];
	}
	for (int i = 0; i < size2; i++) {
		buf[size + i] = ch;
	}
	buf[size + size2] = '\0';
	delete[] str;
	str = buf;
	size += size2;
}

int MyString::compare(const char arr[])
{
	for (int i = 0; i <= size; i++) {
		if (str[i] > arr[i]) return 1;
		else if (str[i] < arr[i]) return -1;
	}
	return 0;
}

int MyString::compare(const MyString& string)
{
	return compare(string.str);
}

int MyString::find(const char arr[])
{
	int pos = -1;
	int count = 0;
	for (int k = 0; arr[k] != '\0'; k++) 
		count++;

	if (count == 0) return pos;

	int substring = 0;

	for (int k = 0; k < size; k++) {
		if (arr[0] == str[k]) {
			for (int n = 0, m = k; n < count; n++, m++) {
				if (str[m] == arr[n])
					substring++;
			}
			if (substring == count) {
				pos = k;
				return pos;
			}
		}
	}
	pos = -1;
	return pos;
}

int MyString::rfind(const char arr[])
{
	int pos = -1;
	int count = 0;
	for (int k = 0; arr[k] != '\0'; k++)
		count++;

	if (count == 0) return pos;

	int substring = 0;

	for (int k = size - 1; k >= 0; k--) {
		if (arr[count - 1] == str[k]) {
			for (int n = count - 1, m = k; n >= 0; n--, m--) {
				if (str[m] == arr[n])
					substring++;
			}
			if (substring == count) {
				pos = k;
				return pos;
			}
		}
	}
	pos = -1;
	return pos;
}

int MyString::erase(char value)
{
	int countDelEl = 0;
	for (int k = 0; str[k] != '\0'; k++) {
		if (str[k] == value) countDelEl++;
	}
	int size2 = this->size - countDelEl;

	char* buf = new char[size2 + 1];
	for (int k = 0, n = 0; k < this->size + 1; k++) {
		if (str[k] == value)
			n++;
		buf[k - n] = str[k];
	}
	delete[] str;
	str = buf;
	this->size = size2;

	return countDelEl;
}

void MyString::replace(int first, int last, const char string[])
{
	int size2 = size;
	int count2 = 0, count = 0;
	for (int k = 0; string[k] != '\0'; k++)
		count2++;

	if (first == last) count = 1;
	else if (first < last) count = (first - first) + (last - first) + 1;
	else if (first > last) return;
	if (count == 0) return;

	if (count == count2) {
		for(int k = 0; k < count; k++)
			str[first + k] = string[k];
	}
	else if (count < count2) {
		size2 = size + (count2 - count);
		char* buf = new char[size2 + 1];
		for (int k = 0; k < first; k++) {
			buf[k] = str[k];
		}
		for (int k = first, n = 0; k <= last + (count2 - count); k++, n++) {
			buf[k] = string[n];
		}
		for (int k = last + 1 + (count2 - count); k <= size2; k++) {
			buf[k] = str[k - (count2 - count)];
		}
		delete[] str;
		str = buf;
	}
	else if (count > count2) {
		size2 = size - (count - count2);
		char* buf = new char[size2 + 1];
		for (int k = 0; k < first; k++) {
			buf[k] = str[k];
		}
		for (int k = first, n = 0; k <= last - (count - count2); k++, n++) {
			buf[k] = string[n];
		}
		for (int k = last + 1 - (count - count2); k <= size2; k++) {
			buf[k] = str[k - (count2 - count)];
		}
		delete[] str;
		str = buf;
		
	}
	size = size2;
}

void MyString::insert(int pos, const char string[])
{
	int count2 = 0;
	for (int k = 0; string[k] != '\0'; k++)
		count2++;

	int size2 = size + count2;
	char* buf = new char[size2 + 1];
	for (int k = 0; k < pos; k++) {
		buf[k] = str[k];
	}
	for (int k = pos, n = 0; k < pos + count2; k++, n++) {
		buf[k] = string[n];
	}
	for (int k = pos + count2; k < size2 + 1; k++) {
		buf[k] = str[pos++];
	}
	delete[] str;
	str = buf;
	size = size2;
}

int MyString::stoi(const char arr[])
{
	int size2 = 0;
	
	for (int i = 0; arr[i] != '\0'; i++) size2 ++;

	int num = 0;
	int ten;
	bool signFlag = true;
	for (int i = 0; i < size2; i++) {
		if (arr[i] < '0' || arr[i] > '9') {
			if (i == 0 && arr[i] == '-') {
				signFlag = false;
				continue;
			}
			else if (i == 0 && arr[i] == '+') {
				signFlag = true;
				continue;
			}
			else return NULL;
		}
		ten = 1;
		for (int j = 0; j < size2 - 1 - i; j++) {
			ten *= 10;
		}

		num += ten * (arr[i] - '0');
	}

	if (signFlag) {
		return num;
	}
	else {
		num *= -1;
		return num;
	}
}