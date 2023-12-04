#include "HDD.h"

void HDD::operator=(HDD other) {
	DataStorage::operator=(other);
	this->spindleSpeed = other.spindleSpeed;
}

std::ostream& operator << (std::ostream& out, const HDD& hdd) {
	out << hdd.toString();
	return out;
}

HDD::HDD(DataTransferInterface transferInterface)
	: DataStorage(transferInterface) {

}

HDD::HDD(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor, int spindleSpeed)
	: DataStorage(capacity, transferInterface, brand, formFactor) {
	tryToSetArguments(spindleSpeed);
}

std::string HDD::getComponentName() const {
	return "HDD";
}

int HDD::getSpindleSpeed() const {
	return spindleSpeed;
}

void HDD::input() {
	DataStorage::input();
	int spindleSpeed;

	std::cout << "������� c������� �������� ��������: ";
	std::cin >> spindleSpeed;
	std::cin.clear();
	while (std::cin.get() != '\n');

	tryToSetArguments(spindleSpeed);
}

std::string HDD::toString() const {
	std::string name = DataStorage::toString() + ", " + std::to_string(this->getSpindleSpeed());
	return name;
}


bool HDD::checkArguments(int spindleSpeed) const {
	return spindleSpeed >= 0;
}

void HDD::tryToSetArguments(int spindleSpeed) {
	if (checkArguments(spindleSpeed)) {
		this->spindleSpeed = spindleSpeed;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}