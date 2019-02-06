#include<bits/stdc++.h>
using namespace std;
 class edge{
 private:
 	float distance;
 public:
 	void setDistance(float);
 	float getDistance(); 	

 };

 void edge::setDistance(float a)
 {
 	distance=a;
 	return;
 }
 float edge::getDistance()
 {
 	return distance;
 }