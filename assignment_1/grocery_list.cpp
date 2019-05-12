#define MAX 100000
#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <string>
#include "item.h"
#include "node.h"
#include "fruit.h"
#include "vegetable.h"
#include "grocery_list.h"
using namespace std;
    grocery_list::grocery_list()
    {
        head = NULL;
        tail = NULL;
    }
    void grocery_list::add_items()
    {
        std::string strf;
        int locx, locy, ppu, c, u;
        float wpu;
        int ctr=0;
        ifstream infile;
        infile.open("fruits.txt");

        if(infile.is_open()==true)
        {
        	while(infile>>strf>>locx>>locy>>wpu>>ppu>>c>>u)
        	{
        		
        		node *temp = new node();
        		temp->next = NULL;
        		item *i = new fruit();
        		temp->var = i;
        		i->setType(strf);
        		i->setLocation_x(locx);
        		i->setLocation_y(locy);
        		i->setweightpu(wpu);
        		i->setpricepu(ppu);
        		i->setcal(c);
        		i->setunits(u);
                time_t t = time(NULL);
                char *c1 = ctime(&t);
                i->purchase_time = c1;
        		if(head == NULL)
        		{
        			head = temp;
        			tail = temp;
        			head->var->purchase_id = 1;
        		}
        		else
        		{
        			tail->next = temp;
        			long int x = tail->var->purchase_id;
        			tail = tail->next;
        			tail->var->purchase_id = x+10-(x+10)%10+1;
        		}
        	}
        }
        else
            cout <<"Couldn't open file - fruits.txt"<<endl;
        ifstream infile2;
        infile2.open("vegetables.txt");
        int ppkg, vpkg, a;
        if(infile2.is_open() == true)
        {
        	while(infile2>>strf>>locx>>locy>>ppkg>>vpkg>>c>>a)
        	{        		
        		node *temp = new node();
        		temp->next = NULL;
        		item *i = new vegetable();
        		temp->var = i;
                time_t t = time(NULL);
                char *c1 = ctime(&t);
        		i->purchase_time = c1;
        		i->setType(strf);
        		i->setLocation_x(locx);
        		i->setLocation_y(locy);
        		i->setpricepkg(ppkg);
        		i->setvolpkg(vpkg);
        		i->setcal(c);
        		i->setamount(a);
        		if(head == NULL)
        		{
        			head = temp;
        			tail = temp;
        			head->var->purchase_id = 2;

        		}
        		else
        		{
        			tail->next = temp;
        			long int x = tail->var->purchase_id;
        			tail = tail->next;
        			tail->var->purchase_id = x+10-(x+10)%10+2;
        		}
        	}
        }
    }
    void grocery_list::print(node *temp)
    {
        if((temp->var->purchase_id)%10 == 1)
            {
                cout <<"Type: "<<temp->var->getType()<<endl;
                cout <<"Location_x: "<<temp->var->location_x<<" Location_y = "<<temp->var->location_y<<endl;
                cout <<"Weight per unit: "<<temp->var->getweightpu()<<endl;
                cout <<"Price per unit: "<<temp->var->getpricepu()<<endl;
                cout <<"Calories: "<<temp->var->getcal()<<endl;
                cout <<"Units: "<<temp->var->getunits()<<endl;
                cout <<"Purchase id: "<<temp->var->purchase_id<<endl;
                cout <<"Purchase time: "<<temp->var->purchase_time<<endl;
            }
            else if((temp->var->purchase_id)%10 == 2)
            {
                cout <<"Type: "<<temp->var->getType()<<endl;
                cout <<"Location_x: "<<temp->var->location_x<<" Location_y = "<<temp->var->location_y<<endl;
                cout <<"Price per Kg: "<<temp->var->getpricepkg()<<endl;
                cout <<"Volume per Kg: "<<temp->var->getvolpkg()<<endl;
                cout <<"Calories: "<<temp->var->getcal()<<endl;
                cout <<"Amount: "<<temp->var->getamount()<<endl;
                cout <<"Purchase id: "<<temp->var->purchase_id<<endl;
                cout <<"Purchase time: "<<temp->var->purchase_time<<endl;
            }
    }
    //functionality 4
    void grocery_list::print()
    {
    	node *temp = head;
        if(head == NULL)
        {
            cout <<"Grocery store is empty"<<endl;
            return;
        }
    	while(temp!=NULL)
    	{
    		if((temp->var->purchase_id)%10 == 1)
    		{
    			cout <<"Fruit Object"<<endl;
    			cout <<"Type: "<<temp->var->getType()<<endl;
                cout <<"Location_x: "<<temp->var->location_x<<" Location_y = "<<temp->var->location_y<<endl;
                cout <<"Weight per unit: "<<temp->var->getweightpu()<<endl;
                cout <<"Price per unit: "<<temp->var->getpricepu()<<endl;
                cout <<"Calories: "<<temp->var->getcal()<<endl;
                cout <<"Units: "<<temp->var->getunits()<<endl;
                cout <<"Purchase id: "<<temp->var->purchase_id<<endl;
                cout <<"Purchase time: "<<temp->var->purchase_time<<endl;
    		}
    		else if((temp->var->purchase_id)%10 == 2)
    		{
    			cout <<"Vegetable Object"<<endl;
    			cout <<"Location_x: "<<temp->var->location_x<<" Location_y = "<<temp->var->location_y<<endl;
                cout <<"Price per Kg: "<<temp->var->getpricepkg()<<endl;
                cout <<"Volume per Kg: "<<temp->var->getvolpkg()<<endl;
                cout <<"Calories: "<<temp->var->getcal()<<endl;
                cout <<"Amount: "<<temp->var->getamount()<<endl;
                cout <<"Purchase id: "<<temp->var->purchase_id<<endl;
                cout <<"Purchase time: "<<temp->var->purchase_time<<endl;
    		}
    		temp = temp->next;
    	}

    }
    //Template function in c++
    //The only thing you have to remember is that the member function template definition (in addition to the declaration)
    // should be in the header file, not the cpp, though it does not have to be in the body of the class declaration itself.

    //functionality 1: a
    void grocery_list::user_add_fruit()
    {
    	node *temp = new node();
    	temp->next = NULL;
    	item *i = new fruit();
    	temp->var = i;
    	std::string str;
    	int x, y, ppu, c, u;
        float wpu;
        time_t t = time(NULL);
        char *c1 = ctime(&t);
        i->purchase_time = c1;
    	cout <<"Enter the fruit type: "<<endl;
    	cin >>str;
    	cout <<"Enter the location coordinates (x and y): "<<endl;
    	cin >>x>>y;
        cout <<"Enter the weight per unit of the fruit:"<<endl;
        cin >>wpu;
    	cout <<"Enter price per unit of the fruit: "<<endl;
    	cin>>ppu;
    	cout <<"Enter the calories content of the fruit: "<<endl;
    	cin >>c;
    	cout <<"Enter the number of units of fruit: "<<endl;
    	cin >>u;
    	i->setType(str);
        i->setLocation_x(x);
        i->setLocation_y(y);
        i->setweightpu(wpu);
        i->setpricepu(ppu);
        i->setcal(c);
        i->setunits(u);
        if(head == NULL)
        {
        	head = temp;
        	tail = temp;
        	head->var->purchase_id = 1;
        }
        else
        {
        	tail->next = temp;
        	long int x = tail->var->purchase_id;
        	tail = tail->next;
        	tail->var->purchase_id = x+10-(x+10)%10+1;
        }
    }
    //functionality 1:b
    void grocery_list::user_add_vegetable()
    {
    	node *temp = new node();
    	temp->next = NULL;
    	item *i = new fruit();
    	temp->var = i;
    	std::string str;
    	int x, y, ppkg, vpkg, c, a;

    	cout <<"Enter the vegetable type: "<<endl;
    	cin >>str;
    	cout <<"Enter the location coordinates (x and y): "<<endl;
    	cin >>x>>y;
    	cout <<"Enter price per Kg of the vegetable: "<<endl;
    	cin>>ppkg;
    	cout <<"Enter the volume per kg of the vegetable: "<<endl;
    	cin >>vpkg;
    	cout <<"Enter the calories content of the vegetable: "<<endl;
    	cin >>c;
    	cout <<"Enter the amount of vegetable in Kgs: "<<endl;
    	cin >>a;
        time_t t = time(NULL);
        char *c1 = ctime(&t);
        i->purchase_time = c1;
    	i->setType(str);
        i->setLocation_x(x);
        i->setLocation_y(y);
        i->setpricepkg(ppkg);
        i->setvolpkg(vpkg);
        i->setcal(c);
        i->setamount(a);
        if(head == NULL)
        {
        	head = temp;
        	tail = temp;
        	head->var->purchase_id = 1;
        }
        else
        {
        	tail->next = temp;
        	long int x = tail->var->purchase_id;
        	tail = tail->next;
        	tail->var->purchase_id = x+10-(x+10)%10+1;
        }

    }
    //functionality 3
    int grocery_list::itemsRemaining(std::string str, std::string fv)
    {

    	node *temp = head;
    	int sumf = 0;
    	int sumv = 0;
    	if(fv=="fruit"){
    	while(temp!=NULL)
    	{
    		if((temp->var->purchase_id)%10 == 1 && (temp->var->getType()==str))
    		{
    			sumf = sumf + temp->var->getunits();
    		}
    		temp = temp->next;
    	}
    	return sumf;
    }
    	else {
    	temp = head;
    	while(temp!=NULL)
    	{
    		if((temp->var->purchase_id)%10 == 2 && temp->var->getType()==str)
    		{
    			sumv = sumv + temp->var->getamount();
    		}
    		temp = temp->next;
    	}
    	return sumv;
    }
    }
    //utility function for functionality2
    float grocery_list::distance(int x, int y)
    {
    	float ans = (float)sqrt((1.0*x*x)+(1.0*y*y));
    	return ans;
    }
    //utility function for functionality 2
    void grocery_list::deletenode(node *p)
    {
    	if(p==head)
    	{
    		head= p->next;
    		p->next= NULL;
    		delete p;
    	}
    	else if (p==tail)
    	{
    		node *q= head;
    		while(q->next!=tail)
    		{
    			q = q->next;
    		}
    		tail=q;
    		tail->next=NULL;
    		delete p;
    	}
    	else
    	{
    		node *q = head;
    		while(q->next!=p)
    		{
    			q=q->next;
    		}
    		q->next = p->next;
    		p->next = NULL;
    		delete p;
    	}
    }
    //functionality 2 (for fruits)
    void grocery_list::sellItem1(std::string fruitname, int num)
    {
    	node *temp = head;
    	float min = MAX;
    	while(temp!=NULL)
    	{
    		if(temp->var->getType()==fruitname)
    		{
    			if(distance(temp->var->location_x,temp->var->location_y)<min)
    			{
    				min = distance(temp->var->location_x,temp->var->location_y);
    			}

    		}
    		temp = temp->next;
    	}
    	if(min == MAX)
    	{
    		cout <<"Fruits of this type over/not found, no. of fruits remaining to be given = "<<num<<endl;
    		return;
    	}
    	temp = head;
    	int minprice = MAX;
    	while(temp!=NULL)
    	{
    		if(temp->var->getType()==fruitname && distance(temp->var->location_x,temp->var->location_y)<=min)
    		{
    			if(temp->var->getpricepu()<minprice){
    				minprice = temp->var->getpricepu();
    			}

    		}
    		temp = temp->next;
    	}
    	if(minprice == MAX)
    	{
    		return;
    	}
    	else
    	{
    		temp = head;
    		while(temp!=NULL)
    		{
    			if(distance(temp->var->location_x,temp->var->location_y)==min && temp->var->getType()==fruitname && temp->var->getpricepu()==minprice)
    			{
    				break;
    			} 
    			temp = temp->next;
    		}
    		if(temp == NULL)
    		{
    			return;
    		}
    		else
    		{
    			if(num < temp->var->getunits())
    			{
    				temp->var->setunits( temp->var->getunits()-num);
    				cout <<"Fruits given with following details:"<<endl;
    				cout <<"Type: "<<temp->var->getType()<<endl;
    				cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
    				cout <<"Weight per unit: "<<temp->var->getweightpu()<<endl;
    				cout <<"Price per unit: "<<temp->var->getpricepu()<<endl;
    				cout <<"Calories: "<<temp->var->getcal()<<endl;
                    cout <<"Number of units given: "<<num<<endl;
    				cout <<"Number of units remaining of this particular fruit item in grocery store: "<<temp->var->getunits()<<endl;
                    num = 0;
    				return;
    			}
    			else if(num == temp->var->getunits())
    			{
    				num = 0;
    				cout <<num<<"Fruits given with following details:"<<endl;
    				cout <<"Type: "<<temp->var->getType()<<endl;
    				cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
    				cout <<"Weight per unit: "<<temp->var->getweightpu()<<endl;
    				cout <<"Price per unit: "<<temp->var->getpricepu()<<endl;
    				cout <<"Calories: "<<temp->var->getcal()<<endl;
    				cout <<"Number of units given: "<<temp->var->getunits()<<endl;
                    cout <<"Number of units remaining of this particular fruit item in grocery store: "<<0<<endl;
                    deletenode(temp);
    				return;
    			}
    			else
    			{
    				num = num- temp->var->getunits();
    				cout <<"Fruits given with following details:"<<endl;
    				cout <<"Type: "<<temp->var->getType()<<endl;
    				cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
    				cout <<"Weight per unit: "<<temp->var->getweightpu()<<endl;
    				cout <<"Price per unit: "<<temp->var->getpricepu()<<endl;
    				cout <<"Calories: "<<temp->var->getcal()<<endl;
    				cout <<"Number of units given: "<<temp->var->getunits()<<endl;
                    cout <<"Number of units remaining of this particular fruit item in grocery store: "<<0<<endl;
    				deletenode(temp);
    				sellItem1(fruitname, num);
    			}
    		}

    	}
    }
    //functionality 2(for vegetables)
    void grocery_list::sellItem2(std::string vegname, int num)
    {
        node *temp = head;
        float min = MAX;
        while(temp!=NULL)
        {
            if(temp->var->getType()==vegname)
            {
                if(distance(temp->var->location_x,temp->var->location_y)<min)
                {
                    min = distance(temp->var->location_x,temp->var->location_y);
                }

            }
            temp = temp->next;
        }
        if(min == MAX)
        {
            cout <<"Vegetables of this type over/not found, amount of vegetables remaining to be given (in kgs) = "<<num<<endl;
            return;
        }
        temp = head;
        int minprice = MAX;
        while(temp!=NULL)
        {
            if(temp->var->getType()==vegname && distance(temp->var->location_x,temp->var->location_y)<=min)
            {
                if(temp->var->getpricepkg()<minprice){
                    minprice = temp->var->getpricepkg();
                }

            }
            temp = temp->next;
        }
        if(minprice == MAX)
        {
            return;
        }
        else
        {
            temp = head;
            while(temp!=NULL)
            {
                if(distance(temp->var->location_x,temp->var->location_y)==min && temp->var->getType()==vegname && temp->var->getpricepkg()==minprice)
                {
                    break;
                } 
                temp = temp->next;
            }
            if(temp == NULL)
            {
                return;
            }
           // cout <<"Final node selected:"<<endl;
           // print(temp);
                if(num < temp->var->getamount())
                {
                    //cout <<"num = "<<num<<endl;
                    //cout <<"yo"<<endl;
                    temp->var->setamount( temp->var->getamount()-num);
                    cout <<"Vegetables given with following details:"<<endl;
                    cout <<"Type: "<<temp->var->getType()<<endl;
                    cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
                    cout <<"Price per kg: "<<temp->var->getpricepkg()<<endl;
                    cout <<"Volume per kg: "<<temp->var->getvolpkg()<<endl;
                    cout <<"Calories: "<<temp->var->getcal()<<endl;
                    cout <<"Amount of vegetables given: "<<num<<endl;
                    cout <<"Amount of vegetables of this particular type in grocery store: "<<temp->var->getamount()<<endl;
                                        num = 0;

                    //deletenode(temp);
                    return;
                }
                else if(num == temp->var->getamount())
                {
                    //cout <<"num here = "<<num<<endl;
                    //cout <<"yep!"<<endl;
                    cout <<"Vegetables given with following details:"<<endl;
                    cout <<"Type: "<<temp->var->getType()<<endl;
                    cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
                    cout <<"Price per kg: "<<temp->var->getpricepkg()<<endl;
                    cout <<"Volume per kg: "<<temp->var->getvolpkg()<<endl;
                    cout <<"Calories: "<<temp->var->getcal()<<endl;
                    cout <<"Amount of vegetables given: "<<num<<endl;
                    cout <<"Amount of vegetables of this particular type in grocery store: "<<0<<endl;
                    num = 0;
                    deletenode(temp);
                    return;
                }
                else
                {
                    //cout <<"num here here "<<num<<endl;
                    //cout <<"Third case"<<endl;
                    cout <<"Vegetables given with following details:"<<endl;
                    cout <<"Type: "<<temp->var->getType()<<endl;
                    cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
                    cout <<"Price per kg: "<<temp->var->getpricepkg()<<endl;
                    cout <<"Volume per kg: "<<temp->var->getvolpkg()<<endl;
                    cout <<"Calories: "<<temp->var->getcal()<<endl;
                    cout <<"Amount of vegetables given: "<<temp->var->getamount()<<endl;
                    cout <<"Amount of vegetables of this particular type in grocery store: "<<0<<endl;
                    num = num- temp->var->getamount();

                    deletenode(temp);
                    sellItem2(vegname, num);
                }
            

        }
    }

    //functionality 5 
    void grocery_list::itemsInArea(int x, int y, int w, int l)
    {
    	node *temp = head;
    	int ctr=0;
    	while(temp!=NULL)
    	{
    		if(temp->var->location_x >= x && temp->var->location_x <= (x+w))
    		{
    			if(temp->var->location_y<=y && temp->var->location_y >= (y-l) )
    			{
    			ctr++;
    			if((temp->var->purchase_id)%10 == 1)
    			{
                    ctr++;
                    cout <<"Fruit Object"<<endl;
    				cout <<"Type: "<<temp->var->getType()<<endl;
    				cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
    				cout <<"Weight per unit: "<<temp->var->getweightpu()<<endl;
    				cout <<"Price per unit: "<<temp->var->getpricepu()<<endl;
    				cout <<"Calories: "<<temp->var->getcal()<<endl;
    				cout <<"Number of units: "<<temp->var->getunits()<<endl;
    				cout <<"Purchase id: "<<temp->var->getpurchase_id()<<endl;
                    cout <<"Purchase time: "<<temp->var->purchase_time<<endl;
    			}
    			else
    			{
                    ctr++;
    				cout <<"Vegetable Object"<<endl;
    				cout <<"Type: "<<temp->var->getType()<<endl;
    				cout <<"Location: "<<temp->var->location_x<<" "<<temp->var->location_y<<endl;
    				cout <<"Price per Kg: "<<temp->var->getpricepkg()<<endl;
    				cout <<"Volume per Kg: "<<temp->var->getvolpkg()<<endl;
    				cout <<"Calories: "<<temp->var->getcal()<<endl;
    				cout <<"Amount: "<<temp->var->getamount()<<endl;
    				cout <<"Purchase id: "<<temp->var->purchase_id<<endl;
    				cout <<"Purchase time: "<<temp->var->purchase_time<<endl;
    			}
    			}

    		}
    		temp = temp->next;
    	}
        if(ctr==0)
        {
            cout <<"No items in this region"<<endl;
        }
    }
    //functionality 6
    void grocery_list::maxcount ( int cals, int sum)
    {
            node *temp = head;
            if(head == NULL)
            {
                cout <<"Grocery Store is empty"<<endl;
                return;
            }
            if(cals == 0)
                return;
            int mincal = temp->var->getcal();
            while(temp!=NULL)
            {
                if((temp->var->getpurchase_id())%10 == 1)
                {
                 if(temp->var->getcal()<mincal)
                    {
                        mincal = temp->var->getcal();
                    }
                }
                temp = temp->next;
            }
            temp = head;
            while(temp!=NULL)
            {
                if((temp->var->getpurchase_id())%10 == 1 && temp->var->getcal()==mincal)
                {
                    break;
                }
                temp = temp->next;
            }
            if(temp == NULL)
            {
                cout <<"Fell short of fruits"<<endl;
                return;
            }
            int cal2 = (temp->var->getunits())*(temp->var->getcal());
            int cal1 = temp->var->getcal();
            if(cal2 > cals)
            {
                int num = temp->var->getunits();
                while(num*cal1 > cals)
                {
                    num--;
                }
                if(num == 0)
                {
                    cout <<"Maximum count for given number of calories: "<<sum<<endl;
                    return;
                }
                int calgiven = num*cal1;
                cals = cals - calgiven;
                sum = sum + num;
                int x = temp->var->getunits();
                if(x-num == 0)
                    deletenode(temp);
                else{
                cout <<"Fruits given from following item:"<<endl;
                print(temp);
                temp->var->setunits(x-num);

                if(cals == 0){
                    cout <<"Maximum count for given number of calories: "<<sum<<endl;
                    return;
                }
                else
                {
                    maxcount(cals,sum);
                }
            }
            }
            else if(cal2 == cals)
            {
                cout <<"Fruits given from following item:"<<endl;
                print(temp);
                sum = sum + temp->var->getunits();
                cout <<"Maximum count for given number of calories: "<<sum<<endl;
                deletenode(temp);
                return;
            }
            else
            {
                cals = cals - cal2;
                cout <<"Fruits given from following item:"<<endl;
                print(temp);
                sum = sum + temp->var->getunits();
                maxcount(cals,sum);
            }
    }
    void grocery_list::maxamount ( int cals, int sum)
    {
            node *temp = head;
            if(head == NULL)
            {
                cout <<"Grocery Store is empty"<<endl;
                return;
            }
            if(cals == 0)
                return;
            int mincal = temp->var->getcal();
            while(temp!=NULL)
            {
                if((temp->var->getpurchase_id())%10 == 2)
                {   if(temp->var->getcal()<mincal)
                    {
                        mincal = temp->var->getcal();
                    }
                }
                temp = temp->next;
            }
            temp = head;
            while(temp!=NULL)
            {
                if((temp->var->getpurchase_id())%10 == 2 && temp->var->getcal()==mincal)
                {
                    break;
                }
                temp = temp->next;
            }
            if(temp == NULL)
            {
                cout <<"Fell short of vegetables!"<<endl;
                return;
            }
            int cal2 = (temp->var->getamount())*(temp->var->getcal());
            int cal1 = temp->var->getcal();
            if(cal2 > cals)
            {
                int num = temp->var->getamount();
                while(num*cal1 > cals)
                {
                    num--;
                }
                if(num == 0)
                {
                    cout <<"Maximum count for given number of calories: "<<sum<<endl;
                    return;
                }
                int calgiven = num*cal1;
                cals = cals - calgiven;
                sum = sum + num;
                int x = temp->var->getamount();
                if(x-num == 0)
                    deletenode(temp);
                else{
                cout <<"Vegetables given from following item:"<<endl;
                print(temp);
                temp->var->setamount(x-num);

                if(cals == 0){
                    cout <<"Maximum count for given number of calories: "<<sum<<endl;
                    return;
                }
                else
                {
                    maxamount(cals,sum);
                }
            }
            }
            else if(cal2 == cals)
            {
                cout <<"Vegetables given from following item:"<<endl;
                print(temp);
                sum = sum + temp->var->getamount();
                cout <<"Maximum count for given number of calories: "<<sum<<endl;
                deletenode(temp);
                return;
            }
            else
            {
                cals = cals - cal2;
                cout <<"Vegetables given from following item:"<<endl;
                print(temp);
                sum = sum + temp->var->getamount();
                maxamount(cals,sum);
            }
    }
