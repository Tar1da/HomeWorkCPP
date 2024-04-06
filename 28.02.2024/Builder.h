#pragma once
#include <iostream>
using namespace std;

class House {
private:
	string garden = "-";
	string pool = "-";
	string garage = "-";
	string statues = "-";
public:
	void showInfo() {
		cout << "garden: " << garden << endl
			<< "pool: " << pool << endl
			<< "garage: " << garage << endl
			<< "statues: " << statues << endl;
	}
	friend class HouseBuilder;
};

class Builder {
public:
	virtual void buildGarden(string garden) = 0;
	virtual void buildPool(string pool) = 0;
	virtual void buildGarage(string garage) = 0;
	virtual void buildStatues(string statues) = 0;
};

class HouseBuilder : public Builder {
private:
	House house;
public:
	void buildGarden(string garden) {
		house.garden = garden;
	}
	void buildPool(string pool) {
		house.pool = pool;
	}
	void buildGarage(string garage) {
		house.garage = garage;
	}
	void buildStatues(string statues) {
		house.statues = statues;
	}
	House getResult() {
		return house;
	}
};

class Director {
public:
	void buildHouseWithGardenGarage(Builder* builder) {
		builder->buildGarden("20m/20m");
		builder->buildGarage("5m/6m");
	}

	void buildHouseWithStatuesPool(Builder* builder) {
		builder->buildStatues("3m");
		builder->buildPool("6m/6m");
	}
};
