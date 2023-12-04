#include "Display.h"

void Display::operator=(Display other) {
	this->modelName = other.getModelName();
	this->width = other.getWidth();
	this->height = other.getHeight();
	this->refreshRate = other.getRefreshRate();
}

std::ostream& operator << (std::ostream& out, const Display& display) {
	out << display.toString();
	return out;
}

Display::Display(int width, int height) {
	tryToSetArguments("", width, height, 0);
}

Display::Display(std::string modelName, int width, int height, int refreshRate) {
	tryToSetArguments(modelName, width, height, refreshRate);
}

std::string Display::getComponentName() const {
	return "Display";
}

std::string Display::getModelName() const {
	return modelName;
}

int Display::getWidth() const {
	return width;
}

int Display::getHeight() const {
	return height;
}

int Display::getRefreshRate() const {
	return refreshRate;
}

void Display::input() {
	std::string modelName;
	int width, height, refreshRate;

	std::cout << "Введите название модели: ";
	std::getline(std::cin, modelName);
	std::cout << "Введите ширину и высоту экрана (в пикселях): ";
	std::cin >> width >> height;
	std::cout << "Введите частоту обновления экрана (в Гц): ";
	std::cin >> refreshRate;
	std::cin.clear();
	while (std::cin.get() != '\n');

	tryToSetArguments(modelName, width, height, refreshRate);
}

std::string Display::toString() const {
	std::string name = modelName + ", " + std::to_string(width) + "x" + std::to_string(height) + ", " + std::to_string(refreshRate) + " Гц";
	return name;
}


bool Display::checkArguments(std::string modelName, int width, int height, int refreshRate) const {
	return width >= 0 && height >= 0 && refreshRate >= 0;
}

void Display::tryToSetArguments(std::string modelName, int width, int height, int refreshRate) {
	if (checkArguments(modelName, width, height, refreshRate)) {
		this->modelName = modelName;
		this->width = width;
		this->height = height;
		this->refreshRate = refreshRate;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}