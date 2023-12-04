#include "DataStorage.h"

void DataStorage::operator=(DataStorage* other) {
	this->capacity = other->capacity;
	this->transferInterface = other->transferInterface;
	this->modelName = other->modelName;
	this->formFactor = other->formFactor;
}

DataStorage::DataStorage(DataTransferInterface transferInterface) {
	this->transferInterface = transferInterface;
}

DataStorage::DataStorage(int capacity, DataTransferInterface transferInterface, std::string modelName, float formFactor) {
	tryToSetArguments(capacity, transferInterface, modelName, formFactor);
}

int DataStorage::getCapacity() const {
	return capacity;
}

DataTransferInterface DataStorage::getInterface() const {
	return transferInterface;
}

std::string DataStorage::getModelName() const {
	return modelName;
}

float DataStorage::getFormFactor() const {
	return formFactor;
}

void DataStorage::input() {
	int capacity;
	DataTransferInterface interface;
	std::string modelName;
	float formFactor;

	std::cout << "Введите вместимость (в ГБ): ";
	std::cin >> capacity;
	std::cout << "Введите интерфейс подключения (PATA - 0, SATA - 1, SAS - 2, NVMe - 3): ";
	std::cin >> interface;
	std::cin.clear();
	while (std::cin.get() != '\n');
	std::cout << "Введите название модели: ";
	std::getline(std::cin, modelName);
	std::cout << "Введите форм фактор (в дюймах): ";
	std::cin >> formFactor;
	std::cin.clear();
	while (std::cin.get() != '\n');

	tryToSetArguments(capacity, interface, modelName, formFactor);
}


std::string DataStorage::toString() const {
	std::string name = this->getModelName() + ", " + std::to_string(this->getCapacity()) + " ГБ, " + DataTransferInterfaceToString(this->getInterface()) + ", " + std::format("{:.1f}", this->getFormFactor());
	return name;
}

bool DataStorage::checkArguments(int capacity, DataTransferInterface transferInterface, std::string modelName, float formFactor) const {
	return capacity >= 0 && formFactor >= 0;
}

void DataStorage::tryToSetArguments(int capacity, DataTransferInterface transferInterface, std::string modelName, float formFactor) {
	if (checkArguments(capacity, transferInterface, modelName, formFactor)) {
		this->capacity = capacity;
		this->transferInterface = transferInterface;
		this->modelName = modelName;
		this->formFactor = formFactor;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}