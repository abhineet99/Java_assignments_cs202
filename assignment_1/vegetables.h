#ifndef VEGETABLES_H
#define VEGETABLES_H
#include "item.h"
typedef long long int ll;
class vegetables: public item
{
	private:
		string type;
		float vpk;
		int ppk;
		int calories;
		int kgs;

	public:
		string gettype();

		float getvpk();

		int getppu();

		int getcalories();
		void settype(string);
		void setppk(int );
		void setvpk(float );
		void setcalories(int );
		void setunits(int );
		int getunits();

		void update(ll ,int ,int ,string ,float ,int ,int ,int );
		vegetables();
		void print();


};

#endif
