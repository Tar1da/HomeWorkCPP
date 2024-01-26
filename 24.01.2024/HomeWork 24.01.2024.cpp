#include <iostream>
#define random(a,b) a+rand()%(b+1-a)
using namespace std;

class Garage;
class Car;

class Car {
	int number;
	long price;
	float engCapac;
	string color;
	string model;
public:
	Car() {};
	Car(string model, string color, float engCapac, long price) {
		this->model = model;
		this->color = color;
		this->engCapac = engCapac;
		this->price = price;
	}
	long getPrice() {
		return price;
	}
	float getEngCapoc() {
		return engCapac;
	}
	string getColor() {
		return color;
	};
	string getModel() {
		return model;
	};
	int getNumber() {
		return number;
	}
	void setPrice(long price) {
		this->price = price;
	}
	void setEngCapoc(float engCapac) {
		this->engCapac = engCapac;
	}
	void setColor(string color) {
		this->color = color;
	};
	void setModel(string model) {
		this->model = model;
	};
	void setNumber(int number) {
		this->number = number;
	}
	void show() {
		cout << "Number: " << number << endl << "Model: " << model << endl << "Color: " << color << endl 
			<< "engCapac: " << engCapac << "l" << endl << "Price" << price << endl;
	}
};

class Garage {
	Car* cars = nullptr;
	int countOfCars = 0;
public:
	Garage() {};
	int getCountOfCars() {
		return countOfCars;
	}
    void addCars(Car newCar) {
        Car* buf = new Car[countOfCars + 1];
        for (int i = 0; i < countOfCars; i++) {
            buf[i] = cars[i];
        }
        buf[countOfCars++] = newCar;
        delete[]cars;
        cars = buf;
    }
	void removeCarByIndex(int index){
		if (countOfCars == 0 || index < 0 || index > countOfCars - 1) 
			return;
		Car* buf = new Car[countOfCars - 1];
		for (int i = 0; i < index; i++) {
		    buf[i] = cars[i];
		}
		for (int i = index + 1; i < countOfCars; i++) {
		    buf[i - 1] = cars[i];
		}
		delete[]cars;
		cars = buf;
		countOfCars--;
	}
	void showInfo() {
		cout << "countOfCars : \t\033[96m" << countOfCars << endl << "\033[0mCars: " << endl;
		for (int i = 0; i < countOfCars; i++) {
			cout << "\033[96m"; 
			cars[i].show();
			cout << "\033[0m" << endl;
		}
		cout << endl;
	}
	void setNumberByIndex(int index) {
		int num = random(100, 999);
		while (true) {
			for (int i = 0; i < countOfCars; i++) {
				if (i == index)
					continue;
				else if (num == cars[i].getNumber())
					num = random(100, 999);
				else {
					cars[index].setNumber(num);
					return;
				}
			}
		}
	}
};

int main() {

	Car auto1("Hyundai", "white", 2.0, 1249000);
	Car auto2("Kia Rio", "red", 1.6, 1500000);
	Car auto3("Ford Mondeo", "black", 2.0, 900000);
	Car auto4("Honda Civic", "blue", 2.0, 2749000);

	Garage garage;
	garage.addCars(auto1);
	garage.addCars(auto2);
	garage.addCars(auto3);
	garage.addCars(auto4);

	garage.showInfo();

	garage.setNumberByIndex(0);
	garage.setNumberByIndex(1);
	garage.setNumberByIndex(2);
	garage.setNumberByIndex(3);

	garage.showInfo();

	system("pause");
	return 0;
}