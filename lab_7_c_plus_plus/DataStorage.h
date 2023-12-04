#pragma once
#include <string>
#include <format>
#include "DataTransferInterface.h"
#include "LaptopComponent.h"

class DataStorage abstract : public LaptopComponent
{
public:
	DataStorage() = default;
	DataStorage(std::string modelName);
	DataStorage(DataTransferInterface transferInterface);
	DataStorage(int capacity, DataTransferInterface transferInterface, std::string modelName, float formFactor);
	~DataStorage() = default;

	void operator=(DataStorage* other);

	virtual std::string getComponentName() const abstract = 0;

	virtual int getCapacity() const;
	virtual DataTransferInterface getInterface() const;
	virtual std::string getModelName() const;
	virtual float getFormFactor() const;

	virtual void input();
	virtual std::string toString() const abstract;
protected:
	int capacity = 0;
	DataTransferInterface transferInterface = DataTransferInterface::SATA;
	float formFactor = 0;
	std::string modelName;

	bool checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor) const;
	void tryToSetArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor);
};