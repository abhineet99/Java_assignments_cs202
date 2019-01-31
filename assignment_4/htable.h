#pragma once
#ifndef HTABLE_H
#define HTABLE_H
#include<string>
#include"entry.h"
using namespace std;
class htable{
private:
	entry* myarray;
	unsigned long long int hashfunc1(string s);
	long long int max;
	int comp1=1811;
	int comp2=809;
	int col;
	long long int size1;
	entry* obj1;
	long long int hashfunc2(long long int s);
public:
	set<long long int > st;
	//htable();
	htable(long long int max);
	void remove(string s);
	void insert(string s,string w);
	void search(string s);
	int getcol();

	void setcomp(int a,int b);
	void sugbox(string s);
	//void seachforsug(string s);
	long long int size();
	void spellcheck(string w);
	//void remove(string s);

};

#endif