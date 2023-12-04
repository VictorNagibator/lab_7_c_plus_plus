#include <algorithm>
#include <format>
#include "LaptopComponentsTable.h"

LaptopComponentsTable::LaptopComponentsTable(std::vector<LaptopComponent*> components)
{
	this->components = components;
}

void LaptopComponentsTable::addComponent(LaptopComponent* component)
{
	components.push_back(component);
}

void LaptopComponentsTable::removeComponent(std::string modelName)
{
	//создаем итератор, который будет указывать либо на нужный элемент, либо на конец вектора, если элемента не окажется
	auto removable = std::find_if(this->components.begin(), this->components.end(), [&](LaptopComponent* component) {
		return component->getModelName() == modelName;
	}); //используем лямбда-функцию для поиска конкретной модели

	if (removable != this->components.end()) {
		this->components.erase(removable);
	}
	else {
		throw std::runtime_error("Данное комплектующее не найдено!");
	}
}

void LaptopComponentsTable::removeLastComponent()
{
	if (this->components.size() > 0) {
		this->components.pop_back();
	}
	else {
		throw std::runtime_error("В таблице нет комплектующих!");
	}
}

LaptopComponent* LaptopComponentsTable::getComponent(std::string modelName)
{
	//используем тот же итератор из removeComponent()
	auto removable = std::find_if(this->components.begin(), this->components.end(), [&](LaptopComponent* component) {
		return component->getModelName() == modelName;
	});

	if (removable != this->components.end()) {
		return *removable;
	}
	else {
		throw std::runtime_error("Данное комплектующее не найдено!");
	}
}

void LaptopComponentsTable::sortByComponentName()
{
	std::sort(this->components.begin(), this->components.end(), [&](LaptopComponent* first, LaptopComponent* second) {
		return first->getComponentName() < second->getComponentName();
	});
}

void LaptopComponentsTable::sortByModelName()
{
	std::sort(this->components.begin(), this->components.end(), [&](LaptopComponent* first, LaptopComponent* second) {
		return first->getModelName() < second->getModelName();
	});
}

void LaptopComponentsTable::print()
{
	printHeader();
	for (auto component : this->components) {
		std::string res = std::format("*{:^20s}*{:^37s}*", component->getComponentName(), component->getModelName());
		std::cout << res << std::endl;
	}
	printFooter();
}

void LaptopComponentsTable::printHeader()
{
	std::cout << "************************************************************" << std::endl
			  << "* Тип комплектующего *           Название модели           *" << std::endl
			  << "************************************************************" << std::endl;
}

void LaptopComponentsTable::printFooter()
{
	std::cout << "************************************************************" << std::endl;
}