#include<iostream>
#include"fruits.h"
#include"item.h"


typedef long long int ll;
using namespace std;
		
		string fruits::gettype() const
		{
			
			return type;
		}	

		float fruits::getvpk() const
		{
		
			return wpu;
		}

		int fruits::getppu() const
		{
			return ppu;
		}

		int fruits::getcalories() const
		{
			return calories;
		}
		void fruits:: settype(string s1)
		{
			type=s1;
		}
		void fruits:: setppu(int ppu2)
		{
			ppu=ppu2;
		}
		void fruits:: setwpu(float wpu2)
		{
			wpu=wpu2;
		}
		void fruits:: setcalories(int calories2)
		{
			calories=calories2;
		}
		void fruits:: setunits(int units1)
		{
			units=units1;
		}
		bool fruits::operator>(fruits a) const
		{
			
    		if(this->getcalories()>a.getcalories())
    			return true;
    		else
    			return false;
			
		} 
		int fruits::getunits() const
		{
			return units;	
		}
		void fruits:: print() const
		{
			cout<<retpurchase_id()<<'\t'<<type<<'\t'<<"("<<*retlocation()<<","<<*(retlocation()+1)<<")"<<'\t'<<wpu<<'\t'<<ppu<<'\t'<<calories<<'\t'<<units<<'\t'<<rettime()<<endl;
		}
		void fruits::update(ll purchase_id3,int a,int b,string type1,float vpk2,int ppk2,int calories2,int kg)
		{
			item::update(a,b);
			wpu=vpk2;
			type=type1;
			ppu=ppk2;
			calories=calories2;
			units=kg;
			purchase_id=purchase_id3;
		}

		
		fruits::fruits()
		{
			calories=0;
		}


