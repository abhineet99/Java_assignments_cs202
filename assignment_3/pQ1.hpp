#include "item.h"
#include "complecs.hpp"
#include "locator.h"
#include<cmath>

#include <bits/stdc++.h>
template <typename E,typename C>
  class sQueue {	
  private:

  class node1
			{
				public:
			    E element;
			    int priority;

			};

  	int curr_size;
  	node1* array;
  	int max_size;		     
  public:

	void swap(node1* a,node1* b);
  	sQueue(int capacity);
    int size() const;				// number of elements
    bool empty() const;				// is the queue empty?
    const E& min() const;			// minimum element
    locator insert(const E& e);		// insert element
    void removeMin();
    int Heapify(int i);				// remove minimum
    void remove(const locator& l);		// remove at location l
    locator replace(const locator& l, const E& e); // replace at position p
    bool compare_values(E const& A, E const& B);
    void display();
    sQueue(E* a,int isize,int max_size);


};
template <typename E,typename C>
sQueue<E,C>::sQueue(E* a,int isize,int max_size)
{
    this->max_size=max_size;
    curr_size=0;
    array= new node1[max_size];
    for(int i=0;i<isize;i++)
    {
        cout<<a[i].gettype()<<endl;
        array[i].element=a[i];
        curr_size++;
    }
    for(int i=(isize/2)+1;i>=0;i--)
        Heapify(i);
}
template <typename E,typename C>
void sQueue<E,C>::display()
{
    int k=0;
    int j=0;
    if(array[0].element.getislab())
    {
        for(int i=0;i<curr_size;i++)
        {

            cout<<array[i].element.gettype()<<'\t';
            if(i==k)
            {
                cout<<endl;
                j++;
                k+=pow(2,j);
                
            }


        } 
    }
    else{
        for(int i=0;i<curr_size;i++)
        {

            cout<<array[i].element.gettype()<<'\t';
            if(i==k)
            {
                cout<<endl;
                j++;
                k+=pow(2,j);               
            }
        } 
  }    
        cout<<endl;   
}
template <typename E,typename C>
bool sQueue<E,C>::empty() const{
 	if(curr_size==0)
 		return 1;
 	else
 		return 0;
 } 
template <typename E,typename C>		
bool sQueue<E,C>::compare_values(E const& A, E const& B)
    {
    	C comparator;
    return comparator(A, B);
	}	


template <typename E,typename C>
void sQueue<E,C>::remove(const locator& l)
{
	int i=l.getloc();
	if(l.getloc()>curr_size)
	{
		cout << "Not Possible!"<<endl;
		return;
        
	}
	else
	{
		array[i]=array[curr_size-1];
		curr_size--;
		Heapify(i);
	}	


}




template <typename E,typename C>
locator sQueue<E,C>::replace(const locator& l, const E& e)
{
	if(l.getloc()>curr_size)
	{
		cout << "Not Possible, returning -1 !"<<endl;
        locator* minus=new locator;
        minus->setloc(-1);
        return *minus;
	}
	else
	{
		if(compare_values((array[l.getloc()]).element,e))
        {
            array[l.getloc()].element=e;
        	int i=l.getloc();
            locator* toret=new locator;
        	while (i != 0 && compare_values((array[(i-1)/2]).element,(array[i]).element))
            {
               swap(&array[i], &array[(i-1)/2]);
                toret->setloc((i-1)/2);
               i = (i-1)/2;
            }
        	
           
            return *toret;
        } 
        else
        {

            array[l.getloc()].element=e;
            int i=l.getloc();
            locator* toret=new locator;
            toret->setloc(Heapify(i));
            return *toret;
        }   
	}
}

template <typename E,typename C>
locator sQueue<E,C>::insert(const E& e)
{
	if (!(curr_size<max_size))
    {
       // cout<<curr_size<<e.getnum() << "Not Possible, returning -1 !"<<endl;
        locator* minus=new locator;
        minus->setloc(-1);
        return *minus;
    }
    
    else
    {
    (array[curr_size]).element=e;
    curr_size++;
    //cout<<e.getnum()<<endl;
    int i = curr_size - 1;
    //array[i]=e;
    locator* toret=new locator;
        
    while (i != 0 && (compare_values((array[(i-1)/2]).element,(array[i]).element)))
    {
       swap(&array[i], &array[(i-1)/2]);
       toret->setloc((i-1)/2);
       i = (i-1)/2;
    }
   
        toret->getloc();
        // cout<<"this is it"<<2*i+1<<endl;
        return *toret;

    }

}	
template <typename E,typename C>
int sQueue<E,C>::size() const
{
	return curr_size;
}

template <typename E,typename C>
sQueue<E,C>::sQueue(int capacity)
		{
			max_size=capacity;
            curr_size=0;
			array= new node1[max_size];
		}

template <typename E,typename C>		
const E&  sQueue<E,C>::min() const
{
	const E& me=(array[0].element);
	return me;
}
template <typename E,typename C>		
void sQueue<E,C>::swap(node1 *x, node1 *y)
{
    node1 temp = *x;
    *x = *y;
    *y = temp;
}

template <typename E,typename C>		
int sQueue<E,C>::Heapify(int i)
{
    int k=i;
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    if (l < curr_size && !(compare_values((array[l]).element,(array[smallest]).element)))
        smallest = l;
    if (r < curr_size && !(compare_values((array[r]).element,(array[smallest]).element)))
        smallest = r;
    if (smallest != i)
    {
        k=smallest;
        swap(&array[i], &array[smallest]);
        return Heapify(smallest);
    }
    else
    {
        return k;
    }    
}	
template <typename E,typename C>		
void sQueue<E,C>::removeMin()
{
	if(curr_size==0)
	{
		cout<<"Nothing in here to remove!!"<<endl;
	}
	else if(curr_size==1)
	{
		curr_size--;
		cout<<"Now the list is empty!!<<endl";
	}
	else
	{
		curr_size--;
		array[0]=array[curr_size];
		Heapify(0);
	}
}	


	      
