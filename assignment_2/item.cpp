#include<iostream>
#include "item.h"
#include<cmath>

typedef long long int ll;
using namespace std;
		void item ::settype(string s1)
		{
			return;
		}
		void item ::setppu(int ppu2)
		{
			return;
		}
		 void item :: setwpu(float wpu2)
		{
			return;
		}
		 void item :: setvpk(float wpu2)
		{
			return;
		}
		 void item :: setcalories(int calories2)
		{
			return;
		}
		 void item :: setunits(int units1)
		{
			return;
		}
		 void item :: setkgs(int units1)
		{
			return;
		}
		 void item :: setppk(int wpu2)
		{
			return;
		}
		 string item ::gettype() const
		{
			//cout<<"sup";
			return NULL;
		}
		 float item ::getvpk() const
		{
			return 0.1;
		}
		 int item ::getppu() const
		{
			return 1;
		}
		 void item :: setwpk(float a)
		{
			return;
		}
		 int item ::getcalories() const
		{
			return 0;
		}
		 int item ::getunits() const
		{
			return 0;
		}

		ll item ::retpurchase_id() const
		{
			return purchase_id;
		}

		const int* item ::retlocation() const
		{
			return location;
		}

		char* item ::rettime() const
		{
			return curr_time;
		}

		void item :: update(ll id)
		{
			purchase_id=id;
			return;
		}

		void item :: settime()
		{
			time_t now = time(0);
			curr_time=ctime(&now);
			return;
		}

		void item :: update(int a,int b)
		{
			location[0]=a;
			location[1]=b;
			return;
		}

		 void item :: print() const
		{
			cout<<"Purchase id is"<<purchase_id<<endl;
			cout<<"Location is ("<<location[0]<<","<<location[1]<<")"<<endl;
			cout<<"The time it was entered is"<<curr_time<<endl;
		}
		bool item::operator>(item a)
		{
			
    		if(this->getcalories()>a.getcalories())
    			return true;
    		else
    			return false;
			
		} 

		void item :: update(ll id,int a,int b)
		{
			update(id);
			update(a,b);
			return;
		}

		item ::item(ll id,int a,int b)
		{
			update(id,a,b);
			settime();
		}
		item ::item()
		{
			settime();
		}




