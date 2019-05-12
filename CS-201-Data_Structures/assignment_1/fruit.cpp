#include <iostream>
#include <ctime>
#include <cmath>
#include "fruit.h"
#include "item.h"
using namespace std;
fruit::fruit()
	{
		type = "xyz";
		weightpu = 1.0;
		pricepu = 1;
		cal = 1;
		units = 1;
	}
	void fruit::setType(string str)
	{
		this->type = str;
	}
	void fruit::setweightpu(float weight)
	{
		this->weightpu = weight;
	}
	void fruit::setpricepu(int price)
	{
		this->pricepu = price;
	}
	void fruit::setcal(int _cal)
	{
		this->cal = _cal;
	}
	void fruit::setunits(int n)
	{
		this->units = n;
	}
	std::string fruit::getType()
	{
		return type;
	}
	float fruit::getweightpu()
	{
		return weightpu;
	}
	int fruit::getpricepu()
	{
		return pricepu;
	}
	int fruit::getcal()
	{
		return cal;
	}
	int fruit::getunits()
	{
		return units;
	}
	bool fruit::operator == (fruit a)
	{
		cout <<"I have been called"<<endl;
		if(this->getType() == a.getType())
		{
			return true;
		}
		cout <<"not equal"<<endl;
		return false;
	}