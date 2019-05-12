#include <iostream>
#include <cmath>
#include "vegetable.h"
#include "item.h"
	vegetable::vegetable()
	{
		type = "abc";
		pricepkg = 1;
		volpkg = 1;
		cal = 1;
		amount = 1;
	}
	void vegetable::setType(std::string str)
	{
		this->type = str;
	}
	void vegetable::setpricepkg(int price)
	{
		this->pricepkg = price;
	}
	void vegetable::setvolpkg(int v)
	{
		this->volpkg = v;
	}
	void vegetable::setcal(int _cal)
	{
		this->cal = _cal;
	}
	void vegetable::setamount(int _amount)
	{
		this->amount = _amount;
	}
	std::string vegetable::getType()
	{
		return type;
	}
	int vegetable::getpricepkg()
	{
		return pricepkg;
	}
	int vegetable::getvolpkg()
	{
		return volpkg;
	}
	int vegetable::getcal()
	{
		return cal;
	}
	int vegetable::getamount()
	{
		return amount;
	}