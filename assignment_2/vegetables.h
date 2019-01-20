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
		string gettype() const;

		float getvpk() const;

		int getppu() const;

		int getcalories() const;
		void settype(string);
		void setppk(int );
		void setvpk(float );
		bool operator>(vegetables) const;
		void setcalories(int );
		void setunits(int );
		int getunits() const;

		void update(ll ,int ,int ,string ,float ,int ,int ,int );
		vegetables();
		void print() const;


};

#endif
