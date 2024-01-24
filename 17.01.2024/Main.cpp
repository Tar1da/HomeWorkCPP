#include <iostream>
#include <conio.h>
using namespace std;

class Fraction {
private:
	int num;
	int denom;
public:
	Fraction(int num, int denom) {
		this->num = num;
		this->denom = denom;
	}
	void setNum(int num) {
		this->num = num;
	}
	void setDenom(int denom) {
		this->denom = denom;
	}
	int getNum() {
		return this->num;
	}
	int getDenom() {
		return this->denom;
	}
	Fraction add(Fraction& fraction) {
		int newNum;
		int newDenom;
		if (this->denom == fraction.denom) {
			newNum = this->num + fraction.num;
			newDenom = this->denom;
		}
		else
		{
			newNum = (this->num * fraction.denom) + (fraction.num * this->denom);
			newDenom = this->denom * fraction.denom;
		}

		Fraction newFraction(newNum, newDenom);
		return newFraction;
	}
	Fraction subt(Fraction& fraction) {
		int newNum;
		int newDenom;
		if (this->denom == fraction.denom) {
			newNum = this->num - fraction.num;
			newDenom = this->denom;
		}
		else
		{
			newNum = (this->num * fraction.denom) - (fraction.num * this->denom);
			newDenom = this->denom * fraction.denom;
		}
		Fraction newFraction(newNum, newDenom);
		return newFraction;
	}
	Fraction mult(Fraction& fraction) {
		int newNum = this->num * fraction.num;
		int newDenom = this->denom * fraction.denom;
		Fraction newFraction(newNum, newDenom);
		return newFraction;
	}

	Fraction divis(Fraction fraction) {
		swap(fraction.num, fraction.denom);
		int newNum = this->num * fraction.num;
		int newDenom = this->denom * fraction.denom;
		Fraction newFraction(newNum, newDenom);
		return newFraction;
	}
	void show() {
		cout << num << "/" << denom << endl;
	}
};

int main() {

	Fraction d1(2, 6);
	Fraction d2(3, 9);

	d2.add(d1).show();
	d2.subt(d1).show();
	d2.mult(d1).show();
	d2.divis(d1).show();

	_getch();
	return 0;
}