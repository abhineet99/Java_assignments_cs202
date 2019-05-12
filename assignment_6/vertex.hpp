#include<bits/stdc++.h>
using namespace std;
 class vertex{
 private:
 	int matrix_num;
 	string name;
 public:
 	void setMatrix_num(int);
 	int getMatrix_num(); 	
 	void setName(string);
 	string getName();
 };

 void vertex::setMatrix_num(int a)
 {
 	matrix_num=a;
 	return;
 }
 int vertex::getMatrix_num()
 {
 	return matrix_num;
 }
 string vertex::getName()
 {
 	return name;
 }
 void vertex::setName(string a)
 {
 	name=a;
 }
