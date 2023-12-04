#pragma once
#include <iostream>
#include <vector>
#include "LaptopComponent.h"

class LaptopComponentsTable
{
public:
	LaptopComponentsTable() = default;
	LaptopComponentsTable(std::vector<LaptopComponent*> components);
	~LaptopComponentsTable() = default;

	void addComponent(LaptopComponent* component);
	void removeComponent(std::string modelName);
	void removeLastComponent();
	LaptopComponent* getComponent(std::string modelName);
	void sortByComponentName();
	void sortByModelName();
	void print();
private:
	std::vector<LaptopComponent*> components;

	void printHeader();
	void printFooter();
};