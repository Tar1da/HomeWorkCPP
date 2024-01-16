#include <iostream>

using namespace std;

class Car {
	long price;
	float engCapac;
	string color;
	string model;

public:
	Car(string model, string color, float engCapac, long price)
	{
		this->model = model;
		this->color = color;
		this->engCapac = engCapac;
		this->price = price;
	}

	long getPrice()
	{
		return price;
	}

	float getEngCapoc()
	{
		return engCapac;
	}

	string getColor()
	{
		return color;
	};

	string getModel()
	{
		return model;
	};

	void setPrice(long price)
	{
		this->price = price;
	}

	void setEngCapoc(float engCapac)
	{
		this->engCapac = engCapac;
	}

	void setColor(string color)
	{
		this->color = color;
	};

	void setModel(string model)
	{
		this->model = model;
	};

	void show() {
		cout << model << "\n" << color << "\n" << engCapac << "l \n" << price << endl << endl;
	}
};

int main() {

	Car auto1("Hyundai", "white", 2.0, 1249000);
	Car auto2("Kia Rio", "red", 1.6, 1500000);
	Car auto3("Ford Mondeo", "black", 2.0, 900000);
	Car auto4("Honda Civic", "blue", 2.0, 2749000);

	cout << "\033[96m auto1 \033[0m" << endl;
	auto1.show();
	cout << "\033[96m auto2 \033[0m" << endl;
	auto2.show();
	cout << "\033[96m auto3 \033[0m" << endl;
	auto3.show();
	cout << "\033[96m auto4 \033[0m" << endl;
	auto4.show();

	cout << "\033[96m Checking accessors for an object \"auto1\" \033[0m" << endl;
	cout << auto1.getModel() << endl;
	cout << auto1.getColor() << endl;
	cout << auto1.getEngCapoc() << endl;
	cout << auto1.getPrice() << endl;
	cout << endl;

	cout << "\033[96m Checking mutators for an object \"auto1\" \033[0m" << endl;
	auto1.setModel("Kia Rio");
	auto1.setColor("black");
	auto1.setEngCapoc(1.6);
	auto1.setPrice(2749000);
	auto1.show();

	system("pause");
	return 0;
}