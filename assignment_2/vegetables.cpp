#include<iostream>

#include"vegetables.h"
#include"item.h"


typedef long long int ll;
using namespace std;

		string vegetables::gettype() const
		{
			//cout<<"HEY";
			
			return type;
		}	

		float vegetables::getvpk() const
		{
		
			return vpk;
		}

		int vegetables::getppu() const
		{
			return ppk;
		}

		int vegetables::getcalories() const
		{
			return calories;
		}
		void vegetables:: settype(string s1)
		{
			type=s1;
		}
		void vegetables:: setppk(int ppu2)
		{
			ppk=ppu2;
		}
		void vegetables:: setvpk(float wpu2)
		{
			vpk=wpu2;
		}
		void vegetables:: setcalories(int calories2)
		{
			calories=calories2;
		}
		void vegetables:: setunits(int units1)
		{
			kgs=units1;
		}
		int vegetables::getunits() const
		{
			return kgs;	
		}
		bool vegetables::operator>(vegetables a) const
		{
			
    		if(this->getcalories()>a.getcalories())
    			return true;
    		else
    			return false;
			
		} 

		void vegetables::update(ll purchase_id3,int a,int b,string type1,float vpk2,int ppk2,int calories2,int kg)
		{
			item::update(a,b);
			vpk=vpk2;
			type=type1;
			ppk=ppk2;
			calories=calories2;
			kgs=kg;
			purchase_id=purchase_id3;
		}
		vegetables::vegetables()
		{
			calories=0;
		}
		void vegetables:: print() const
		{
			cout<<retpurchase_id()<<'\t'<<type<<'\t'<<"("<<*retlocation()<<","<<*(retlocation()+1)<<")"<<'\t'<<vpk<<'\t'<<ppk<<'\t'<<calories<<'\t'<<kgs<<'\t'<<rettime()<<endl;
		}


