#include "item.h"
#include "vegetables.h"
#include "fruits.h"
#include <bits/stdc++.h>
template <typename E>
  class sQueue {	
  private:
  class node1
			{
				public:
			    E element;
			    node1* next;
			   // friend class groc_manage;
			   // friend template<typename E> class sQueue;
			};
		node1* head1;
		node1* tail1;
		deque <E> minq; 				     
  public:
  	sQueue();
    int size() const;				      // number of items in queue
    bool empty() const;	
    const E& min();			      // is the queue empty?
    const E& front();	      // the front element
    void enqueue (const E& e);			      // enqueue element at rear
    void dequeue();		      // dequeue element at front
  };

template <typename E>
sQueue<E>::sQueue()
		{
			head1=NULL;
			tail1=NULL;
		}
template <typename E>		
		
	    int sQueue<E>::size() const{
	    	node1* temp=head1;
	    	int toret=0;

	    	while(temp!=NULL)
	    	{
	    		toret++;
	    		temp=temp->next;
	    	}
	    	return toret;
	    }
	    template <typename E>				      // number of items in queue
	    bool sQueue<E>::empty() const
	    {
	    	if (head1==NULL)
	    		return true;
	    	else
	    		return false;
	    }	
	    template <typename E>
	    const E& sQueue<E>::min()
	    {
	    	
	    	E &a=minq.front();
	    	return a;
	    }	
	    template <typename E>		     
	    const E& sQueue<E>::front()
	    {
	    	if(head1!=NULL)
	    	{
	    		//cout<<"i was here";
	    		E &a=(head1->element);

	    		return a;

	    	}
	    	

	    }
	    template <typename E>	      
	    void sQueue<E>::enqueue (const E& e)
	    {

	    	node1* temp=new node1;
	    	temp->element=e;
	    	temp->next=NULL;
	    	//cout<<"still workin111"<<endl;
	    	//cout<<head1<<endl;
	    	if(head1==NULL)
	    	{
	    	//	cout<<"idhar aya";
	    		head1=temp;
	    		tail1=temp;
	    	}
	    	else
	    	{
	    	//cout<<"idhar nahi aana tha";
	    	tail1->next=temp;
	    	tail1=tail1->next;
	    	}
	    	//cout<<"still workin222"<<endl;
	    	while(!minq.empty())
	    	{
	    		if(!(e>minq.back()))
	    		{
	    			minq.push_back(e);
	    			break;
	    		}
	    		else
	    			minq.pop_back();
	    	}
	    	if(minq.empty())
	    		minq.push_back(e);




	    }
	    template <typename E>
	    void sQueue<E>::dequeue()
	    {

	    	//cout<<"first element is"<<*(head1->element)<<endl;
	    	if(head1!=NULL)
	    	{
	    		if(((head1->element)>minq.front()))
	    			minq.pop_front();
	    		
	    			

	    		node1* temp=head1;
	    		if(head1->next!=NULL)
	    		{
	    			head1=head1->next;
	    			
	    		}	

	    		else
	    		 head1=NULL;
	    		delete temp;



	    	}
	    	else
	    		cout<<"NO ELEMENTS!"<<endl;

	    }		      
