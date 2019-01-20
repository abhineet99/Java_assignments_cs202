#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include "item.h"
using namespace std;
	long int purchase_id;
	int location_x;
	int location_y;
	char* purchase_time;

	item::item ()
	{
		location_x = 0;
		location_y = 0;
		purchase_id = -1;
		purchase_time = "default";
	}
	void item::setPurchase_time(char* _time)
	{
		this->purchase_time = _time; 
	}
	void item::setPurchase_id(long int x)
	{
		this->purchase_id = x;
	}
	void item::setLocation_x(int x)
	{
		this->location_x = x;
	}
	void item::setLocation_y(int y)
	{
		this->location_y = y;
	}
	void item::update(char* c)
	{
		this->purchase_time = c;
	}
	void item::update(int id)
	{
		this->purchase_id = id;
	}
	void item::setType(string str){};
	void item::setweightpu( float ){};
	 void item::setpricepu(int p){};
	 void item::setcal(int c){};
	void item::setunits(int u){};
	void item::setpricepkg(int p){};
	void item::setvolpkg(int v){};
	 void item::setamount(int a){};
	 float item::getweightpu(){};
	 int item::getpricepu(){};
	 int item::getunits(){};
	 string item::getType(){};
     int item::getpricepkg(){};
	 int item::getcal(){};
	 int item::getvolpkg(){};
     int item::getamount(){};
	long int item::getpurchase_id()
	{
		return purchase_id;
	}