#pragma once
#include <iostream>
#include <string>
#include "LaptopComponent.h"

class Display : public LaptopComponent
{
public:
	Display() = default;
	Display(int width, int height);
	Display(std::string modelName, int width, int height, int refreshRate);
	~Display() = default;

	void operator=(Display other);
	friend std::ostream& operator << (std::ostream& out, const Display& display);

	std::string getComponentName() const override;
	std::string getModelName() const override;
	int getWidth() const;
	int getHeight() const;
	int getRefreshRate() const;
	void input() override;
	std::string toString() const override;
private:
	int width = 0, height = 0, refreshRate = 0;
	std::string modelName;

	bool checkArguments(std::string modelName, int width, int height, int refreshRate) const;
	void tryToSetArguments(std::string modelName, int width, int height, int refreshRate);
};