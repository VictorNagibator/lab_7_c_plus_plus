#pragma once
#include <iostream>
#include <istream>
#include <concepts>
#include "Laptop.h"
#include "StatusType.h"


template <typename T>
concept HasIO = requires(std::ostream & os, std::istream & is, T & t) {
	{ os << t } -> std::same_as<std::ostream&>;
	{ is >> t } -> std::same_as<std::istream&>;
}; //������� ���������� ���������� �����-������ ��� ���� �

template <HasIO T = std::string> //�� ��������� �������������� ���������� - ������
class Order
{
public:
	Order(Laptop laptop);
	Order(Laptop laptop, StatusType status, T additionalInfo);
	~Order() = default;

	template <HasIO U>
	friend std::ostream& operator << (std::ostream& out, Order<U>& order);

	static int getNumOfLastOrder();
	int getNumOfOrder() const;
	const Laptop& getLaptop() const;
	StatusType getStatus() const;
	T getAdditionalInfo() const;
	void input();
	void setStatus(StatusType status);
	void setLaptop(Laptop laptop);
	void setAdditionalInfo(T additionalInfo);
	std::string toString() const;
private:
	static inline int numOfLastOrder{};

	int numOfOrder;
	Laptop laptop = Laptop();
	StatusType status = StatusType::ONHOLD;
	T additionalInfo{};
};


//��� ���������� ���� ������� � ������������ �����, ��� ��� � ���� ������ ��������� ������ �������,
//������ ��� ���������� ������ �� ����� � �������� � .cpp ������

template <HasIO T>
std::ostream& operator << (std::ostream& out, Order<T>& order) {
	out << order.toString() << "\t" << order.getAdditionalInfo();
	return out;
}

template <HasIO T>
Order<T>::Order(Laptop laptop) {
	numOfOrder = ++numOfLastOrder;
	this->laptop = laptop;
}

template <HasIO T>
Order<T>::Order(Laptop laptop, StatusType status, T additionalInfo) : Order(laptop) {
	this->status = status;
	this->additionalInfo = additionalInfo;
}

template <HasIO T>
int Order<T>::getNumOfLastOrder() {
	return numOfLastOrder;
}

template <HasIO T>
int Order<T>::getNumOfOrder() const {
	return numOfOrder;
}

template <HasIO T>
const Laptop& Order<T>::getLaptop() const {
	return laptop;
}

template <HasIO T>
StatusType Order<T>::getStatus() const {
	return status;
}

template <HasIO T>
T Order<T>::getAdditionalInfo() const {
	return additionalInfo;
}

template <HasIO T>
void Order<T>::input() {
	Laptop laptop;
	StatusType type;
	T additionalInfo = T();
	numOfLastOrder++;

	std::cout << "����� ������: " << numOfLastOrder;
	std::cout << "������� ������ ������ (0 - � ��������, 1 - � �������, 2 - ��������������): ";
	std::cin >> type;
	std::cout << "\t���� ���������� ��������\n";
	laptop.input();
	std::cout << "\t���� �������������� ����������\n";
	std::cin >> additionalInfo;

	this->numOfOrder = this->numOfLastOrder;
	this->laptop = laptop;
	this->status = status;
	this->additionalInfo = additionalInfo;
}

template <HasIO T>
void Order<T>::setStatus(StatusType status) {
	this->status = status;
	std::cout << "��������� ������ ������� ��������!\n";
}

template <HasIO T>
void Order<T>::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}

template <HasIO T>
void Order<T>::setAdditionalInfo(T additionalInfo) {
	this->additionalInfo = additionalInfo;
}

template <HasIO T>
std::string Order<T>::toString() const {
	std::string name = std::to_string(this->getNumOfOrder()) + ". " + this->laptop.getModelName() + "\t" + StatusTypeToString(this->getStatus());
	return name;
}