#include<bits/stdc++.h>
#include"item.h"
#include"pQ1.hpp"
#include"locator.h"
// #include"complecs.hpp"

using namespace std;
int main()
{
	//cout<<"i was here";
	sQueue<item,compares> labs1(50);
	sQueue<item,compares> lecs1(50);
	//sQueue<fruits> fruitq;
	//cout<<"yo";
    	FILE *fplabs = fopen("lab.txt", "r");
		FILE *fplecs = fopen("lec.txt", "r");
		
		char type[100];
		int location1[2];
		float area;
		int num;
		int doors;


	   	if(fplabs!=NULL)
		{
			
	    	while(fscanf(fplabs,"%s %f %d  %d %d %d", type,&area,&doors,&location1[0],&location1[1],&num)>0){
	    		
	    		
	   		    item* obj1= new item();
	   		    obj1->settype(type);
	   		    //obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
	   		    obj1->setarea(area);
	   		    obj1->setdoors(doors);
	   		    obj1->setnum(num);
	   		    //obj1->setunits(units1);
	   		    obj1->update(location1[0],location1[1]);
	   		    obj1->setislab(1);
	   		    item &obj=*obj1;
	        	locator k=labs1.insert(obj);
	        	const item &p=labs1.min();
	        	//cout<<p.getarea()<<endl;
	        	//int j=k.getloc();
	        	//cout<<j<<endl;
	    		/*cout<<labs1.size()<<"thiss"<<endl;*/
	   			
	        
	   		}//labs1.display();

	   		cout<<"labs stored in labq!"<<labs1.size()<<endl;
	   	}
	   	else
	   		cout<<"File 'labs.txt'could not be read!"<<endl;
		
	   	if(fplecs!=NULL)
		{
	    	while(fscanf(fplecs,"%s %f %d  %d %d %d", type,&area,&doors,&location1[0],&location1[1],&num)>0){
	    		
	    		
	   		    item* obj1= new item();
	   		    obj1->settype(type);
	   		    //obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
	   		    obj1->setarea(area);
	   		    obj1->setdoors(doors);
	   		    obj1->setnum(num);
	   		    //obj1->setunits(units1);
	   		    obj1->update(location1[0],location1[1]);
	   		    obj1->setislab(0);
	   		    item &obj=*obj1;
	        	locator k=lecs1.insert(obj);

	   			
	        
	   		}
	   		//lecs1.display();
	   		
	   		cout<<"lecture halls stored in lecsq!"<<lecs1.size()<<endl;
	   	}	
	   	else
	   		cout<<"File 'lecs.txt' could not be read!"<<endl;
	   	locator g;
	   	int	flaglab=0;
	   	int flaglec=0;
	   	while(1)
	   	{
	   		
	   		
	   		cout<<"Hi! Welcome to Labs Functions!  ,  Enter:"<<endl;
	   		cout<<"1: Print the names in level order"<<endl;
	   		cout<<"2: Add an element"<<endl;
	   		cout<<"3: Remove the minimum element"<<endl;
	   		cout<<"4: Replace the element just added"<<endl;
	   		cout<<"5: Remove the element just added"<<endl;
	   		cout<<"6: Get the minimum element"<<endl;
	   		cout<<"7: Move to lecture halls functionality"<<endl;
	   		cout<<"8: Close the program!"<<endl;
	   		 int k;
	   		 cin>>k;
	   		 if(k==1)
	   		 {
	   		 	labs1.display();
	   		 }
	   		 else if(k==2)
	   		 {
	   		 	cout<<"Enter type, area, number of doors, x coordinate, y coordinate, number of computers, separated by space"<<endl;
	   		 	scanf("%s %f %d  %d %d %d", type,&area,&doors,&location1[0],&location1[1],&num);
	   		 	item* obj1= new item();
	   		    obj1->settype(type);
	   		    //obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
	   		    obj1->setarea(area);
	   		    obj1->setdoors(doors);
	   		    obj1->setnum(num);
	   		    //obj1->setunits(units1);
	   		    obj1->update(location1[0],location1[1]);
	   		    obj1->setislab(1);
	   		    item &obj=*obj1;
	        	g=labs1.insert(obj);
	        	flaglab=1;
	        	cout<<"Done"<<endl;
	        	//const item &p=labs1.min();
	        	//cout<<p.getarea()<<endl;

	   		 }	
	   		 else if(k==3)
	   		 {
	   		 	labs1.removeMin();
	   		 	cout<<"Done"<<endl;
	   		 }
	   		 else if(k==4)
	   		 {
	   		 	if(flaglab==0)
	   		 		cout<<"No element was added just now!";
	   		 	else
	   		 	{
	   		 		cout<<"Enter type, area, number of doors, x coordinate, y coordinate, number of computers, separated by space"<<endl;
		   		 	scanf("%s %f %d  %d %d %d", type,&area,&doors,&location1[0],&location1[1],&num);
		   		 	item* obj1= new item();
		   		    obj1->settype(type);
		   		    //obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
		   		    obj1->setarea(area);
		   		    obj1->setdoors(doors);
		   		    obj1->setnum(num);
		   		    //obj1->setunits(units1);
		   		    obj1->update(location1[0],location1[1]);
		   		    obj1->setislab(1);
		   		    item &obj=*obj1;
		   		    cout<<g.getloc()<<endl;
		        	g=labs1.replace(g,obj);
		        	
		        	cout<<"Done"<<endl;
	   		 	}
	   		 }
	   		 else if(k==5)
	   		 {
	   		 	if(flaglab==0)
	   		 		cout<<"No element was added just now!";
	   		 	else
	   		 	{
	   		 		cout<<g.getloc()<<endl;
	   		 		labs1.remove(g);
	   		 		cout<<"Done!"<<endl;
	   		 	}
	   		 }
	   		 else if(k==6)
	   		 {
	   		 	const item& min1=labs1.min();
	   		 	min1.print();
	   		 }
	   		 else if(k==8)
	   		 	break;
	   		 else if(k==7)
	   		 {
	   		 while(1)
	   		 {	
	   		 	cout<<"Hi! Welcome to Lecs Functions!  ,  Enter:"<<endl;
		   		cout<<"1: Print the names in level order"<<endl;
		   		cout<<"2: Add an element"<<endl;
		   		cout<<"3: Remove the minimum element"<<endl;
		   		cout<<"4: Replace the element just added"<<endl;
		   		cout<<"5: Remove the element just added"<<endl;
		   		cout<<"6: Get the minimum element"<<endl;
		   		cout<<"7: Move to labs functionality"<<endl;
		   		
		   		 int k;
		   		 cin>>k;
		   		 if(k==1)
		   		 {
		   		 	lecs1.display();
		   		 }
		   		 else if(k==2)
		   		 {
		   		 	cout<<"Enter type, area, number of doors, x coordinate, y coordinate, number of computers, separated by space"<<endl;
		   		 	scanf("%s %f %d  %d %d %d", type,&area,&doors,&location1[0],&location1[1],&num);
		   		 	item* obj1= new item();
		   		    obj1->settype(type);
		   		    //obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
		   		    obj1->setarea(area);
		   		    obj1->setdoors(doors);
		   		    obj1->setnum(num);
		   		    //obj1->setunits(units1);
		   		    obj1->update(location1[0],location1[1]);
		   		    obj1->setislab(0);
		   		    item &obj=*obj1;
		        	g=lecs1.insert(obj);
		        	flaglec=1;
		        	cout<<"Done"<<endl;
		        	//const item &p=labs1.min();
		        	//cout<<p.getarea()<<endl;

		   		 }	
		   		 else if(k==3)
		   		 {
		   		 	lecs1.removeMin();
		   		 	cout<<"Done"<<endl;
		   		 }
		   		 else if(k==4)
		   		 {
		   		 	if(flaglec==0)
		   		 		cout<<"No element was added just now!";
		   		 	else
		   		 	{
		   		 		cout<<"Enter type, area, number of doors, x coordinate, y coordinate, number of chairs, separated by space"<<endl;
			   		 	scanf("%s %f %d  %d %d %d", type,&area,&doors,&location1[0],&location1[1],&num);
			   		 	item* obj1= new item();
			   		    obj1->settype(type);
			   		    //obj1->update(purchase_id1,location1[0],location1[1],type,vpk1,ppk1,calories1,units1);
			   		    obj1->setarea(area);
			   		    obj1->setdoors(doors);
			   		    obj1->setnum(num);
			   		    //obj1->setunits(units1);
			   		    obj1->update(location1[0],location1[1]);
			   		    obj1->setislab(0);
			   		    item &obj=*obj1;
			        	g=lecs1.replace(g,obj);
			        	
			        	cout<<"Done"<<endl;
		   		 	}
		   		 }
		   		 else if(k==5)
		   		 {
		   		 	if(flaglec==0)
		   		 		cout<<"No element was added just now!";
		   		 	else
		   		 	{


		   		 		lecs1.remove(g);
		   		 		cout<<"Done!"<<endl;
		   		 	}
		   		 }
		   		 else if(k==6)
		   		 {
		   		 	const item& min1=lecs1.min();
		   		 	min1.print();
		   		 }
		   		 else if(k==7)
		   		 	break;
		   		 }
	   		 }

	   	}	 		


	return 0;

}