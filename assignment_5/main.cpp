#include<bits/stdc++.h>
#include"entry.h"
#include"node.h"
#include"myavl.hpp"
using namespace std;
int main()
{
	cout<<"Enter the name of the file to take input from !"<<endl;
	string inputname;
	cin>>inputname;
	//inputname="words.txt";
	//cout<<"Enter the size of the table: (Please enter a prime number!)"<<endl;
	//long int mysize;
	//cin>>mysize;
	myavl mytree;
	string word,meaning;
	ifstream myfile (inputname);
	//cout<<"yo"<<endl;
	if (myfile.is_open())
	{
		//cout<<"yo"<<endl;
	while (getline(myfile,word,'\t')&&getline(myfile,meaning))
	{

	 std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	 entry* toin=new entry;
	 toin->setword(word);
	// cout<<word<<endl;
	 toin->setmeaning(meaning);
	 mytree.insert(toin);
	 
	 //cout<<endl<<word;
	 
	 //cout<<word<<endl;
	//myfile.close();
	}
	myfile.close();
	//mytree.Inorder();
	while(1)
{   int c;
	cout<<"Press :"<<endl;
	cout<<"1: Search for a word"<<endl;
	cout<<"2: Remove a word"<<endl;
	cout<<"3: Know the words between two words in the dictionary"<<endl;
	cout<<"4: Know the number of words between two words in the dictionary"<<endl;
	cout<<"5: Enter a new word"<<endl;
	cout<<"6: Print level order"<<endl;
	cout<<"7: Print size"<<endl;

	cout<<"Anything else to exit!"<<endl;
	cin>>c;
	if(c==1)
		{
			cout<<"Enter the word"<<endl;
			string s;
			cin>>s;
			mytree.search(s);
		}
		else if(c==2)
		{
			cout<<"Enter the word"<<endl;
			string s;
			cin>>s;
			mytree.remove(s);
		}
		else if(c==3)
		{
			string a,b;
			cout<<"Enter the words separated by space"<<endl;
			cin>>a>>b;
			mytree.display(a,b);
		}
		else if(c==4)
		{
			string a,b;
			cout<<"Enter the words separated by space"<<endl;
			cin>>a>>b;
			cout<<mytree.count(a,b)<<endl;
		}
		else if(c==5)
		{
			cout<<"Enter the word"<<endl;
			string s;
			//cin.getline(s,200);
			cin.ignore();
			getline(cin,s);
			//cin>>s;
			//mytable.remove(s);
			cout<<"Enter the meaning"<<endl;
			string w;
			getline(cin,w);
			//cin.getline(s,500);
			std::transform(w.begin(), w.end(), w.begin(), ::tolower);
	 		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	 		entry* toin1=new entry;
		 toin1->setword(s);
		// cout<<word<<endl;
		 toin1->setmeaning(w);
		 mytree.insert(toin1);

			
		}
		else if(c==6)
			mytree.print();
		else if(c==7)
		{
			cout<<mytree.getsize()<<endl;
		}
		else
			break;
}
	

}


// 	while(1)
// 	{
// 		cout<<"Press :"<<endl;
// 		cout<<"1: Search for a word"<<endl;
// 		cout<<"2: Remove a word"<<endl;
// 		cout<<"3: Know the number of words in the dictionary"<<endl;
// 		cout<<"4: Enter a new word"<<endl;
// 		cout<<"Anything else to exit!"<<endl;
// 		int c;
// 		cin>>c;
// 		if(c==1)
// 		{
// 			cout<<"Enter the word"<<endl;
// 			string s;
// 			cin>>s;
// 			mytable.spellcheck(s);
// 		}
// 		else if(c==2)
// 		{
// 			cout<<"Enter the word"<<endl;
// 			string s;
// 			cin>>s;
// 			mytable.remove(s);
// 		}
// 		else if(c==3)
// 		{
// 			cout<<mytable.size()<<endl;
// 		}
// 		else if(c==4)
// 		{
// 			cout<<"Enter the word"<<endl;
// 			string s;
// 			//cin.getline(s,200);
// 			cin.ignore();
// 			getline(cin,s);
// 			//cin>>s;
// 			//mytable.remove(s);
// 			cout<<"Enter the meaning"<<endl;
// 			string w;
// 			getline(cin,w);
// 			//cin.getline(s,500);
// 			std::transform(w.begin(), w.end(), w.begin(), ::tolower);
// 	 		std::transform(s.begin(), s.end(), s.begin(), ::tolower);


// 			mytable.insert(s,w);
// 		}
// 		else
// 			break;
// 	}
// }

	else cout << "Unable to open file";
	return 0;

}
