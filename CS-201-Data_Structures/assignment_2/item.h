#pragma once
#ifndef ITEM_H
#define ITEM_H
#include<string>

typedef long long int ll;
using namespace std;
class item
{
	private:
		ll purchase_id;
		int location[2];
		char* curr_time;

	public:

		virtual void settype(string);
		virtual void setppu(int);
		virtual void setwpu(float );
		virtual void setvpk(float );
		virtual void setcalories(int);
		virtual void setunits(int );
		virtual void setkgs(int );
		virtual void setppk(int );
		virtual string gettype() const;
		virtual float getvpk() const;
		virtual int getppu() const;
		virtual void setwpk(float );
		virtual int getcalories() const;
		virtual int getunits() const;
		bool operator>(item);
		ll retpurchase_id() const;

		const int* retlocation() const;

		char* rettime() const;

		void update(ll id);

		void settime();

		void update(int ,int );

		virtual void print() const;

		void update(ll ,int ,int );

		item(ll ,int ,int );
		item();
		friend class fruits;
		friend class vegetables;



};

#endif
