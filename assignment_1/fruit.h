#ifndef FRUIT_H
#define FRUIT_H
#include "item.h"
class fruit : public item{
private:
	std::string type;
	float weightpu;
	int pricepu;
	int cal;
	int units;
public:
	fruit();
	void setType(std::string str);
	void setweightpu(float weight);
	void setpricepu(int price);
	void setcal(int _cal);
	void setunits(int n);
	std::string getType();
	float getweightpu();
	int getpricepu();
	int getcal();
	int getunits();
	bool operator == (fruit a);
};
#endif