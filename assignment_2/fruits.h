#ifndef FRUITS_H
#define FRUITS_H
#include "item.h"
typedef long long int ll;
class fruits: public item
{
	private:
		string type;
		float wpu;
		int ppu;
		int calories;
		int units;

	public:
		string gettype() const;

		float getvpk() const;

		int getppu() const;
		int getcalories() const;
		void settype(string );
		void setppu(int );
		void setwpu(float );
		bool operator>(fruits) const;
		void setcalories(int );
		void setunits(int );
		int getunits() const;
		void print() const;
		void update(ll ,int ,int ,string ,float ,int ,int ,int );
		
		fruits();
		
};

#endif
