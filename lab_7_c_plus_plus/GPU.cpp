#include "GPU.h"

void GPU::operator=(GPU other) {
	this->modelName = other.getModelName();
	this->frequency = other.getFrequency();
	this->vram = other.getVRAM();
}

std::ostream& operator << (std::ostream& out, const GPU& gpu) {
	out << gpu.toString();
	return out;
}

GPU::GPU(std::string modelName) {
	this->modelName = modelName;
}

GPU::GPU(std::string modelName, float frequency, int vram) {
	tryToSetArguments(modelName, frequency, vram);
}

std::string GPU::getComponentName() const {
	return "GPU";
}

std::string GPU::getModelName() const {
	return modelName;
}

float GPU::getFrequency() const {
	return frequency;
}

int GPU::getVRAM() const {
	return vram;
}

void GPU::input() {
	std::string modelName;
	float frequency;
	int vram;

	std::cout << "������� �������� ����������: ";
	std::getline(std::cin, modelName);
	std::cout << "������� �������� ������� ������������ ���������� (� ���): ";
	std::cin >> frequency;
	std::cout << "������� ����� ����������� (� ��): ";
	std::cin >> vram;
	std::cin.clear();
	while (std::cin.get() != '\n');

	tryToSetArguments(modelName, frequency, vram);
}

std::string GPU::toString() const {
	std::string name = this->getModelName() + ", " + std::format("{:.1f}", this->getFrequency()) + " ���, " + std::to_string(this->getVRAM()) + " ��";
	return name;
}


bool GPU::checkArguments(std::string modelName, float frequency, int vram) const {
	return frequency >= 0 && vram >= 0;
}

void GPU::tryToSetArguments(std::string modelName, float frequency, int vram) {
	if (checkArguments(modelName, frequency, vram)) {
		this->modelName = modelName;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}