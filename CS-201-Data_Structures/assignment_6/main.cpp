#include<bits/stdc++.h>
#include"graph.hpp"
#include<fstream>
using namespace std;
int main()
{
	my_graph lol;
	string word,meaning;
	float num;
	ifstream myfile ("capitals.txt");
	//cout<<"yo"<<endl;
	if (myfile.is_open())
	{
		//cout<<"yo"<<endl;
	// while (getline(myfile,word,'\t')&&getline(myfile,meaning,'\t')&&getline(myfile,num))
	// {
	// 		double temp = ::atof(num.c_str());
	// 	 std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	// 	  std::transform(meaning.begin(), meaning.end(), meaning.begin(), ::tolower);
	// 	 cout<<word<<'\t'<<meaning<<"  "<<temp<<endl;
	// 	 vertex* toin= new vertex;
	// 	 vertex* toin2= new vertex;
	// 	 toin->setName(word);
	// 	 toin2->setName(meaning);
	// 	 edge* toin3= new edge;
	// 	 toin3->setDistance(temp);
	// 	 lol.add_edge(toin,toin2,toin3);
	// }
	while(myfile)
	{
		myfile>>word>>meaning>>num;
			 vertex* toin= new vertex;
		 vertex* toin2= new vertex;
		 toin->setName(word);
		 toin2->setName(meaning);
		 edge* toin3= new edge;
		 toin3->setDistance(num);
		 lol.add_edge(toin,toin2,toin3);
	}

		
	myfile.close();
	while(1)
	{
		cout<<"Enter"<<endl;
		cout<<"1: know the shortest path between two cities"<<endl;
		cout<<"2: know the shortest number of hops between two cities"<<endl;
		cout<<"3: know the city with largest area"<<endl;
		cout<<"0: Quit"<<endl;
		int a;
		cin>>a;
		if(a==1)
		{
			string a;
			string b;
			cout<<"Enter the two cities separated by space"<<endl;
			cin>>a>>b;
			//cout<<a<<b;
			//cout<<"k3";
			vertex* ab=new vertex;
			//cout<<"k1";
			ab->setName(a);
			//cout<<"k";
			vertex* ahsaas=new vertex;
			ahsaas->setName(b);
			//cout<<"kk";
			lol.shortest_graph(ab,ahsaas);
		}
		else if(a==2)
		{
			string a;
			string b;
			cout<<"Enter the two cities separated by space"<<endl;
			cin>>a>>b;
			vertex* ab=new vertex;
			ab->setName(a);
			vertex* ahsaas=new vertex;
			ahsaas->setName(b);
			//cout<<"kk";
			lol.shortest_graph2(ab,ahsaas);
		}
		else if(a==3)
		{
			lol.largest();
		}
		else if(a==0) return 0;
		else{
			continue;
		}

	}
	//lol.print_adj()
	}
	//cout<<"Love Everyone!"<<endl;
	return 0;
}