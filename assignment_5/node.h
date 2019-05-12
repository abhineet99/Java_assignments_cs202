#ifndef NODE_H
#define NODE_H

using namespace std;
class node
{
private:
	node *right;
 	node *left;
	node *parent;
  	entry *lol;
  	int bachche;
  	int height;
  	friend class myavl;
}  ;
#endif