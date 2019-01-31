#include<bits/stdc++.h>
#include"htable.h"
#include"entry.h"
using namespace std;
int main()
{
//cout<<"yo"<<endl;
	cout<<"Enter the name of the file to take input from !"<<endl;
	string inputname;
	cin>>inputname;
	cout<<"Enter the size of the table: (Please enter a prime number!)"<<endl;
	long int mysize;
	cin>>mysize;
	htable mytable(mysize);
	string word,meaning;
	ifstream myfile (inputname);
	//cout<<"yo"<<endl;
	if (myfile.is_open())
	{
		//cout<<"yo"<<endl;
	while (getline(myfile,word,'\t')&&getline(myfile,meaning))
	{
		 //cout<<"yo"<<endl;
	 //  getline (myfile,line);
	 //  cout<<line<<" "<<line.size()<<endl;
	 std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	 
	 mytable.insert(word,meaning);
	 if(mytable.size()==mysize)
	 {
	 	cout<<"Table full! Words inserted:"<<mytable.size()<<endl;
	 	break;
	 }
	 
	 //cout<<word<<endl;
	//myfile.close();
	}
	myfile.close();
	//cout<<mytable.getcol()<<endl;
	 //cout<<mytable.size()-mytable.st.size()<<endl;
	// while(1)
	// {
	// 	htable mytable2(4001);
	// 	int comp1,comp2;
	// 	cin>>comp1>>comp2;
	// 	mytable2.setcomp(comp1,comp2);
	// 	string word2,meaning2;
	// ifstream myfile2 ("words.txt");
	// //cout<<"yo"<<endl;
	// if (myfile2.is_open())
	// {
	// 	//cout<<"yo"<<endl;
	// while (getline(myfile2,word2,'\t')&&getline(myfile2,meaning2))
	// {
	// 	// cout<<"yo"<<endl;
	//  //  getline (myfile,line);
	//  //  cout<<line<<" "<<line.size()<<endl;
	//  std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
	//  mytable2.insert(word2,meaning);
	//  //cout<<word<<endl;
	// //myfile.close();
	// }
	// myfile2.close();
	// cout<<mytable2.size()-mytable2.st.size()<<endl;


	// }
	//}
	while(1)
	{
		cout<<"Press :"<<endl;
		cout<<"1: Search for a word"<<endl;
		cout<<"2: Remove a word"<<endl;
		cout<<"3: Know the number of words in the dictionary"<<endl;
		cout<<"4: Enter a new word"<<endl;
		cout<<"Anything else to exit!"<<endl;
		int c;
		cin>>c;
		if(c==1)
		{
			cout<<"Enter the word"<<endl;
			string s;
			cin>>s;
			mytable.spellcheck(s);
		}
		else if(c==2)
		{
			cout<<"Enter the word"<<endl;
			string s;
			cin>>s;
			mytable.remove(s);
		}
		else if(c==3)
		{
			cout<<mytable.size()<<endl;
		}
		else if(c==4)
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


			mytable.insert(s,w);
		}
		else
			break;
	}
}

	else cout << "Unable to open file";
	return 0;
}