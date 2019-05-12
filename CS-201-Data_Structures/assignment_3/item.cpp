#include<bits/stdc++.h>
#include"item.h"

using namespace std;
typedef long long int ll;

		float item ::getarea() const
		{
			return area;
		}
		int item ::getdoors() const
		{
			return doors;
		}
		const int* item ::retlocation() const
		{
			return location;
		}

		void item ::update(int a,int b)
		{
			location[0]=a;
			location[1]=b;
			return;
		}

		item ::item()
		{
			return;
		}
		string item ::gettype() const
		{
			
			return type;
		}
		int item ::getnum() const
		{
			return num;
		}	


		void item ::settype(string s1)
		{
			type=s1;
		}
		void item ::setdoors(int ppu2)
		{
			doors=ppu2;
		}
		void item ::setarea(float wpu2)
		{
			area=wpu2;
		}
		void item ::setnum(int calories2)
		{
			num=calories2;
		}

		void item ::print() const
		{
			cout<<type<<'\t'<<"("<<*retlocation()<<","<<*(retlocation()+1)<<")"<<'\t'<<area<<'\t'<<doors<<'\t'<<num<<'\t'<<endl;
		}

		void item ::setislab(bool a)
		{
			islab=a;
		}
		bool item ::getislab()
		{
			return islab;
		}






