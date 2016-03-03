#pragma once

#include "Resource.h"
#include <set>

class PowerPlant {
private:
	int price = 0;
	int power = 0;
	int capacity = 0;
	std::set<Resource> resources;
public:
	PowerPlant() {};
	PowerPlant(int price, int power, int capacity) : price(price), power(power), capacity(capacity) {};
	~PowerPlant();
	std::set<Resource> getResources() const { return resources; };
	int getPrice() const { return price; };
	int getPower() const { return power; };
	int getCapcity() const { return capacity; };
};

