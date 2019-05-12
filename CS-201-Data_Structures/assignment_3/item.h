#pragma once
#ifndef ITEM_H
#define ITEM_H
#include<string>

typedef long long int ll;
using namespace std;
class item
{
	private:
		string type;
		int location[2];
		float area;
		int doors;
		int num;
		bool islab;


	public:

		float getarea() const;

		int getdoors() const;

		const int* retlocation() const;


		void update(int a,int b);

		item();

		string gettype() const;

		int getnum() const;

		void settype(string s1);

		void setdoors(int ppu2);

		void setarea(float wpu2);

		void setnum(int calories2);

		void print() const;

		void setislab(bool a);

		bool getislab();

};

#endif
