#include <iostream>
#include <windows.h>
#include "Order.h"
#include "LaptopComponentsTable.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LaptopComponentsTable table = LaptopComponentsTable();
	table.addComponent(new Motherboard("MSI AB350"));
	table.addComponent(new CPU("AMD Ryzen 5 2600"));
	table.addComponent(new RAM("HyperX Fury 8GB"));
	table.addComponent(new HDD("Toshiba 7200M"));
	table.addComponent(new CPU("Intel i5 11400f"));
	table.addComponent(new SSD("Samsung 970 EVO Plus"));
	table.print();
	std::cout << std::endl;

	table.sortByComponentName();
	table.print();
	std::cout << std::endl;

	table.removeComponent("AMD Ryzen 5 2600");
	table.sortByModelName();
	table.print();
	std::cout << std::endl;
	
	table.removeLastComponent();
	table.print();

	return 0;
}