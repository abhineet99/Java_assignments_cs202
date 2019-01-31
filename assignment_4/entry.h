#pragma once
#ifndef ENTRY_H
#define ENTRY_H
#include<string>
using namespace std;
class entry{
private:
	string word;
	string meaning;
public:
	string getword();
	string getmeaning();
	void setword(string a);
	void setmeaning(string b);
	
};

#endif