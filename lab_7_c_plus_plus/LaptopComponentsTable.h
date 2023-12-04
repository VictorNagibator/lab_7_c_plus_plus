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

	void AddComponent(LaptopComponent* component);
	void RemoveLastComponent();
private:
	std::vector<LaptopComponent*> components;
};