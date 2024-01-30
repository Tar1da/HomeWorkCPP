#include <iostream>
#include <conio.h>
using namespace std;

class Converter {
private:
	float RUB = 89.5159;
	const float USD = 1;
	float EUR = 0.9219;
public:
	Converter() {};
	void convert(int choice1, int choice2) {
		float convert_cur;
		int count = 0;
		switch (choice1) {
		case 1:		//RUB
			cout << "How many RUB? Count: \033[96m";
			cin >> count; cout << endl << "\033[30;47m";

			switch (choice2) {
			case 1:		//to RUB//
				convert_cur = count * RUB / RUB;
				printf("%d RUB\t%.4f RUB\n", count, convert_cur);
				break;
			case 2:		//to USD//
				convert_cur = count * USD / RUB;
				printf("%d RUB\t%.4f USD\n", count, convert_cur);
				break;
			case 3:		//to EUR//
				convert_cur = count * EUR / RUB;
				printf("%d RUB\t%.4f EUR\n", count, convert_cur);
				break;
			}
			break;

		case 2:		//USD
			cout << "How many USD? Count: \033[96m";
			cin >> count; cout << endl << "\033[30;47m";

			switch (choice2) {
			case 1:		//to RUB// 
				convert_cur = count * RUB / USD;
				printf("%d USD\t%.4f RUB\n", count, convert_cur);
				break;
			case 2:		//to USD//
				convert_cur = count * USD / USD;
				printf("%d USD\t%.4f USD\n", count, convert_cur);
				break;
			case 3:		//to EUR//
				convert_cur = count * EUR / USD;
				printf("%d USD\t%.4f EUR\n", count, convert_cur);
				break;
			}
			break;

		case 3:		//EUR
			cout << "How many EUR? Count: \033[96m";
			cin >> count; cout << endl << "\033[30;47m";

			switch (choice2) {
			case 1:		//to RUB//
				convert_cur = count * RUB / EUR;
				printf("%d EUR\t%.4f RUB\n", count, convert_cur);
				break;
			case 2:		//to USD//
				convert_cur = count * USD / EUR;
				printf("%d EUR\t%.4f USD\n", count, convert_cur);
				break;
			case 3:		//to EUR//
				convert_cur = count * EUR / EUR;
				printf("%d EUR\t%.4f EUR\n", count, convert_cur);
				break;
			}
			break;
		default:
			cout << "error" << endl;
		}
	}
	float getRUB() {
		return this->RUB;
	}
	float getUSD() {
		return this->USD;
	}
	float getEUR() {
		return this->EUR;
	}
	void setRUB(float RUB) {
		this->RUB = RUB;
	}
	void setEUR(float EUR) {
		this->EUR = EUR;
	}
};


int main() {
	int choice1, choice2;
	bool go = true;
	Converter converter1;
	do {
		system("cls");
		cout << "Select" << endl;
		cout << "1.RUB" << endl;
		cout << "2.USD" << endl;
		cout << "3.EUR" << endl << endl;

		cout << "Convert \033[96m"; 
		cin >> choice1; 
		cout << "\033[0mto \033[96m"; 
		cin >> choice2;
		cout << "\033[0m" << endl;

		if ((choice1 >= 1 && choice1 <= 3) &&
			(choice2 >= 1 && choice2 <= 3))
			converter1.convert(choice1, choice2);
		else
			cout << "error" << endl;

		here:
		cout << endl << "\033[0mWant to continue working with the converter ? (y/n)" << endl;

		switch (_getch()){
		case 'y': break;
		case 'n':
			system("cls");
			cout << "\033[96mGoodbye\033[0m" << endl;
			go = false;
			break;
		default:
			cout << "error" << endl;
			goto here;
		}

	} while (go);

	system("pause");
	return 0;
}