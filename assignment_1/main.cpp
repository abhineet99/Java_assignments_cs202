#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>
#include "item.h"
#include "node.h"
#include "fruit.h"
#include "vegetable.h"
#include "grocery_list.h"
using namespace std;
/*bool std::string::operator ==(const std::string& s1, const std::string& s2)
{
    cout <<"yo!!!!!!!!!!!!!called!!!!!!!!!!"<<endl;
    if(s1.length() != s2. length())
       return false;
    for(int i = 0; i < s1.length(); ++i)
        if(std::toupper(s1[i]) != std::toupper(s2[i])) //tolower would do as well
            return false;
    return true;
}*/


int main()
{
	grocery_list list;
	list.add_items();
	char ch='Y';
    while(ch == 'Y' || ch =='y')
    {
        cout <<"Please choose one of the functionalities by pressing corresponding serial number:"<<endl;
        cout <<"1) Add an item (fruit or vegetable)"<<endl;
        cout <<"2) Buy an item"<<endl;
        cout <<"3) Find current count/amount of a fruit or vegetable"<<endl;
        cout <<"4) Display all items in the store with details"<<endl;
        cout <<"5) Find items in a given region"<<endl;
        cout <<"6) Given calories per Kg or unit, find the maximum count of such an item you can purchase"<<endl;
        int in;
        cin >>in;
        if(in == 1)
        {
            cout <<"What do you wish to add: fruit (Enter 1) or vegetable (Enter 2)?"<<endl;
            int x;
            cin >>x;
            if(x==1)
                list.user_add_fruit();
            else
                list.user_add_vegetable();
        }
        else if(in == 2)
        {
            cout <<"What do you wish to buy: fruit(Enter 1) or vegetable(Enter 2)?"<<endl;
            int x;
            cin >>x;
            if(x==1)
            {
                cout <<"Enter the fruit type you wish to buy:"<<endl;
                string str;
                cin >>str;
                cout <<"Enter the count of the fruit type you wish to buy:"<<endl;
                int n;
                cin >>n;
                list.sellItem1(str,n);
            }
            else
            {
                cout <<"Enter the vegetable type you wish to buy:"<<endl;
                string str;
                cin >>str;
                cout <<"Enter the amount of vegetable type you wish to buy:"<<endl;
                int n;
                cin >>n;
                list.sellItem2(str,n);
            }
        }
        else if(in == 3)
        {
            cout <<"Do you want to know the available quantity of fruit(enter 1) or vegetable(enter 2)?"<<endl;
            int x;
            cin >>x;
            if(x==1)
            {
                cout <<"Enter the type of fruit:"<<endl;
                string str;
                cin >>str;
                cout<<"Items Remaining = "<<list.itemsRemaining(str,"fruit")<<endl;
            }
            else
            {
                cout <<"Enter the type of vegetable:"<<endl;
                string str;
                cin >>str;
                list.itemsRemaining(str,"vegetable");  
            }
        }
        else if(in == 4)
        {
            list.print();
        }
        else if(in == 5)
        {
            cout <<"Enter the coordinates of the upper left corner of the rectangular region:"<<endl;
            int x, y;
            cin >>x;
            cin >>y;
            cout <<"Enter the length and breadth of the rectangular region:"<<endl;
            int l, w;
            cin >>l;
            cin >>w;
            list.itemsInArea(x, y, w, l);
        }
        else if(in == 6)
        {
            cout <<"Do you want to purchase a fruit (enter 1) or vegetable (enter 2)"<<endl;
            int x;
            cin >>x;
            if(x==1)
            {
                int y;
                cout <<"Enter the required calorie amount:"<<endl;
                cin >>y;
                list.maxcount(y,0);
            }
            else if(x==2)
            {
                int y;
                cout <<"Enter the required calorie amount:"<<endl;
                cin >>y;
                list.maxamount(y,0);   
            }
            else
                cout<<"Should enter either 1 or 2"<<endl;
        }

        cout <<"Do you want to continue?(Y/N)"<<endl;
        cin >>ch;
    }
    cout <<"Thanks for using the grocery management portal!!"<<endl;
    
}
