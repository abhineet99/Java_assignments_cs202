#include"vegetables.h"
#include"fruits.h"
#include"sQueue.hpp"
#include"item.h"

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
	sQueue<fruits> fruitq;

    	FILE *fpfruits = fopen("fruits.txt", "r");
		FILE *fpveg = fopen("vegetables.txt", "r");
		ll purchase_id1=100001;
		char type[100];
		int location1[2];
		float vpk1;
		int ppk1;
		int calories1;
		int units1;
		
		if(fpfruits!=NULL)
		{
			do
	   		{
	    		fscanf(fpfruits,"%s %d %d %f %d  %d %d", type, &location1[0],&location1[1],&vpk1,&ppk1,&calories1,&units1);
	    		
	    		
	   		    fruits* obj1= new fruits();
	   		    obj1->settype(type);
	   		    obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
	   		    obj1->setwpu(vpk1);
	   		    obj1->setppu(ppk1);
	   		    obj1->setcalories(calories1);
	   		    obj1->setunits(units1);
	   		    fruits &obj=*obj1;
	        	fruitq.enqueue(obj);
	    		
	    		purchase_id1++;
	    		
	        
	   		}
	   		while( !feof(fpfruits) );
	   		cout<<"fruits stored in vegq!"<<endl;
	   	}	
	   	else
	   		cout<<"File 'fruits.txt'could not be read!"<<endl;
	sQueue <vegetables> vegq;   	
	   	if(fpveg!=NULL)
		{
			do
	   		{
	    		fscanf(fpveg,"%s %d %d %f %d  %d %d", type, &location1[0],&location1[1],&vpk1,&ppk1,&calories1,&units1);

	    		vegetables* obj1=new vegetables();
	    	
	   		
	   		    obj1->settype(type);

	   		    obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
	   		    obj1->setvpk(vpk1);
	   		    obj1->setppk(ppk1);
	   		    obj1->setcalories(calories1);
	   		    obj1->setunits(units1);

	   		    purchase_id1++;
	   		    vegetables &obj=*obj1;

	        	vegq.enqueue(obj);
	        
	   		}
	   		while( !feof(fpveg) );
	   		cout<<"vegetables stored in vegq!"<<endl;
	   	}	
	   	else
	   		cout<<"File 'vegetables.txt' could not be read!"<<endl;

	   	int inp=1;
	   	while(inp)
	   	{
	   		int vegf;
	   		cout<<"Enter 1 to do stuff with vegetables, 0 for fruits"<<endl;
	   		cin>>vegf;
	   		if(vegf==1)
	   		{
	   			int what;
	   			cout<<"Enter:"<<endl;
	   			cout<<"1: to know the item with minimum calories"<<endl;
	   			cout<<"2: to know the item kept on top"<<endl;
	   			cout<<"3: to remove the item kept on top"<<endl;
	   			//cout<<"4: to add an item kept on top"<<endl;
	   			cin>>what;
	   			if(what==1)
	   			{	if(!vegq.empty())
	   				{
	   					
	   				vegq.min().print();
	   				}
	   				else
	   					cout<<"NO ELEMENTS!!!"<<endl;
	   			}
	   			else if(what==2)
	   			{
	   				if(!vegq.empty())
	   				vegq.front().print();
	   				else
	   					cout<<"NO ELEMENTS!!!"<<endl;
	   			}	
	   			else if(what==3)
	   			{
	   				if(!vegq.empty())
	   				vegq.dequeue();
	   				else
	   					cout<<"NO ELEMENTS!!!"<<endl;
	   			}	

	   		}
	   		else if(vegf==0)
	   			{
	   			int what;
	   			cout<<"Enter:"<<endl;
	   			cout<<"1: to know the item with minimum calories"<<endl;
	   			cout<<"2: to know the item kept on top"<<endl;
	   			cout<<"3: to remove the item kept on top"<<endl;
	   			//cout<<"4: to add an item kept on top"<<endl;
	   			cin>>what;
	   			if(what==1)
	   			{	if(!fruitq.empty())
	   				fruitq.min().print();
	   				else
	   					cout<<"NO ELEMENTS!!!"<<endl;
	   			}
	   			else if(what==2)
	   			{
	   				if(!fruitq.empty())
	   				fruitq.front().print();
	   				else
	   					cout<<"NO ELEMENTS!!!"<<endl;
	   			}	
	   			else if(what==3)
	   			{
	   				if(!fruitq.empty())
	   				fruitq.dequeue();
	   				else
	   					cout<<"NO ELEMENTS!!!"<<endl;
	   			}	

	   		}
	   		else 
	   		{
	   			cout<<"See you again!";
	   			break;
	   		}

	   	}

	   	
	  
	    	

	
	return 0;

}	