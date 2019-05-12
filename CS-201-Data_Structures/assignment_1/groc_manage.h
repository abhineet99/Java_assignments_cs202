#ifndef GROC_MANAGE_H
#define GROC_MANAGE_H

#include"fruits.h"
#include"vegetables.h"
#include "node.h"
#include"function.h"

typedef long long int ll;

class groc_manage
{
	private:
		node* head=NULL;
		node* end1=NULL;
    public:
        ~groc_manage(); 
        template <typename T>
        int inout(T x1, T y1, T x2, T y2, T x3,T y3, T x4, T y4, T x, T y);
        template <typename T>
        float areatri(T x1, T y1, T x2, T y2, T x3, T y3);
        groc_manage() ;
        void insert(item** );
        int nearer(int, int);
    	void deletenode(int );
        void knowquantity(string );
        void display(int );
    	void display();
    	int insertfromdetails(int ,string ,int ,int ,int ,int ,int ,int ,int );
    	void insertfromid(int ,int );
    	int sellfromtype(string ,int ,int );
        
    	void insiderect(int , int , int , int , int ,int , int , int );
    	int sellfromid(int,int );
    	int insertfromfile();
	    int sellfromcal(int &);
        void update(ll,int,int,string,float,int,int,int);

};
#endif
